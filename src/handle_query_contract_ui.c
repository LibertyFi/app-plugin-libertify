#include "libertify_plugin.h"

// Set UI for the "Send" screen.
static void set_send_ui(ethQueryContractUI_t *msg, one_inch_parameters_t *context) {
    switch (context->selectorIndex) {
        case DEPOSIT:
        case REDEEM:
        case DEPOSIT_ETH:
        case REDEEM_ETH:
            strlcpy(msg->title, "Send", msg->titleLength);
            break;
        default:
            PRINTF("Unhandled selector Index: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // set generic LP symbol or network ticker (ETH, BNB, etc) if needed
    if ((context->selectorIndex == REDEEM) || (context->selectorIndex == REDEEM_ETH)) {
        strlcpy(context->ticker_sent, "LP", sizeof(context->ticker_sent));
    } else if (ADDRESS_IS_NETWORK_TOKEN(context->contract_address_sent)) {
        strlcpy(context->ticker_sent, msg->network_ticker, sizeof(context->ticker_sent));
    }

    // Convert to string.
    if (context->selectorIndex == DEPOSIT_ETH) {
        amountToString(msg->pluginSharedRO->txContent->value.value,
                       msg->pluginSharedRO->txContent->value.length,
                       context->decimals_sent,
                       context->ticker_sent,
                       msg->msg,
                       msg->msgLength);
    } else {
        amountToString(context->amount_sent,
                       INT256_LENGTH,
                       context->decimals_sent,
                       context->ticker_sent,
                       msg->msg,
                       msg->msgLength);
    }
    PRINTF("AMOUNT SENT: %s\n", msg->msg);
}

// Set UI for "Beneficiary" screen.
static void set_beneficiary_ui(ethQueryContractUI_t *msg, one_inch_parameters_t *context) {
    strlcpy(msg->title, "Beneficiary", msg->titleLength);

    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    getEthAddressStringFromBinary((uint8_t *) context->beneficiary,
                                  msg->msg + 2,
                                  msg->pluginSharedRW->sha3,
                                  0);
}

// Set UI for "Warning" screen.
static void set_warning_ui(ethQueryContractUI_t *msg,
                           const one_inch_parameters_t *context __attribute__((unused))) {
    strlcpy(msg->title, "WARNING", msg->titleLength);
    strlcpy(msg->msg, "Unknown token", msg->msgLength);
}

// Helper function that returns the enum corresponding to the screen that should be displayed.
static screens_t get_screen(ethQueryContractUI_t *msg,
                            one_inch_parameters_t *context __attribute__((unused))) {
    uint8_t index = msg->screenIndex;

    bool token_sent_found = context->tokens_found & TOKEN_SENT_FOUND;
    bool token_received_found = context->tokens_found & TOKEN_RECEIVED_FOUND;

    bool both_tokens_found = token_received_found && token_sent_found;
    bool both_tokens_not_found = !token_received_found && !token_sent_found;

    switch (index) {
        case 0:
            if (both_tokens_found) {
                return SEND_SCREEN;
            } else if (both_tokens_not_found) {
                return WARN_SCREEN;
            } else if (token_sent_found) {
                return SEND_SCREEN;
            } else if (token_received_found) {
                return WARN_SCREEN;
            }
            return ERROR;
        case 1:
            return BENEFICIARY_SCREEN;
        default:
            return ERROR;
    }
    return ERROR;
}

void handle_query_contract_ui(void *parameters) {
    ethQueryContractUI_t *msg = (ethQueryContractUI_t *) parameters;
    one_inch_parameters_t *context = (one_inch_parameters_t *) msg->pluginContext;
    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);
    msg->result = ETH_PLUGIN_RESULT_OK;

    screens_t screen = get_screen(msg, context);
    switch (screen) {
        case SEND_SCREEN:
            set_send_ui(msg, context);
            break;
        case BENEFICIARY_SCREEN:
            set_beneficiary_ui(msg, context);
            break;
        case WARN_SCREEN:
            set_warning_ui(msg, context);
            break;
        default:
            PRINTF("Received an invalid screenIndex\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
}
