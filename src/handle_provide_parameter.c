#include "libertify_plugin.h"

// Store the amount sent in the form of a string, without any ticker or decimals. These will be
// added when displaying.
static void handle_amount_sent(ethPluginProvideParameter_t *msg, one_inch_parameters_t *context) {
    memcpy(context->amount_sent, msg->parameter, INT256_LENGTH);
}

static void handle_beneficiary(ethPluginProvideParameter_t *msg, one_inch_parameters_t *context) {
    memset(context->beneficiary, 0, sizeof(context->beneficiary));
    memcpy(context->beneficiary,
           &msg->parameter[PARAMETER_LENGTH - ADDRESS_LENGTH],
           sizeof(context->beneficiary));
    printf_hex_array("BENEFICIARY: ", ADDRESS_LENGTH, context->beneficiary);
}

static void handle_token_sent(ethPluginProvideParameter_t *msg, one_inch_parameters_t *context) {
    memset(context->contract_address_sent, 0, sizeof(context->contract_address_sent));
    memcpy(context->contract_address_sent,
           &msg->parameter[PARAMETER_LENGTH - ADDRESS_LENGTH],
           ADDRESS_LENGTH);
    printf_hex_array("TOKEN SENT: ", ADDRESS_LENGTH, context->contract_address_sent);
}

static void handle_deposit(ethPluginProvideParameter_t *msg, one_inch_parameters_t *context) {
    switch (context->next_param) {
        case TOKEN_SENT:  // token
            handle_token_sent(msg, context);
            context->next_param = AMOUNT_SENT;
            break;
        case AMOUNT_SENT:  // assets
            handle_amount_sent(msg, context);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

static void handle_redeem(ethPluginProvideParameter_t *msg, one_inch_parameters_t *context) {
    switch (context->next_param) {
        case AMOUNT_SENT:  // shares
            handle_amount_sent(msg, context);
            context->next_param = DST_RECEIVER;
            break;
        case DST_RECEIVER:  // receiver
            handle_beneficiary(msg, context);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

static void handle_deposit_eth(ethPluginProvideParameter_t *msg, one_inch_parameters_t *context) {
    switch (context->next_param) {
        case DST_RECEIVER:  // receiver
            handle_beneficiary(msg, context);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

void handle_provide_parameter(void *parameters) {
    ethPluginProvideParameter_t *msg = (ethPluginProvideParameter_t *) parameters;
    one_inch_parameters_t *context = (one_inch_parameters_t *) msg->pluginContext;
    printf_hex_array("1inch plugin provide parameter: ", PARAMETER_LENGTH, msg->parameter);

    msg->result = ETH_PLUGIN_RESULT_OK;

    if (context->skip) {
        // Skip this step, and don't forget to decrease skipping counter.
        context->skip--;
    } else {
        if ((context->offset) && msg->parameterOffset != context->checkpoint + context->offset) {
            PRINTF("offset: %d, checkpoint: %d, parameterOffset: %d\n",
                   context->offset,
                   context->checkpoint,
                   msg->parameterOffset);
            return;
        }

        context->offset = 0;  // Reset offset
        switch (context->selectorIndex) {
            case DEPOSIT: {
                handle_deposit(msg, context);
                break;
            }
            case REDEEM:
            case REDEEM_ETH: {
                handle_redeem(msg, context);
                break;
            }
            case DEPOSIT_ETH: {
                handle_deposit_eth(msg, context);
                break;
            }
            default:
                PRINTF("Selector Index %d not supported\n", context->selectorIndex);
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                break;
        }
    }
}
