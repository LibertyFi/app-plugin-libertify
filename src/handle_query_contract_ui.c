#include "libertify_plugin.h"

static void set_send_ui(ethQueryContractUI_t *msg, const context_t *context) {
    strlcpy(msg->title, "Send", msg->titleLength);

    uint8_t decimals = context->decimals;
    const char *ticker = context->ticker;

    // If the token look up failed, use the default network ticker along with the default decimals.
    if (!context->token_found) {
        decimals = WEI_TO_ETHER;
        ticker = msg->network_ticker;
    }

    amountToString(context->amount_sent,
                   sizeof(context->amount_sent),
                   decimals,
                   ticker,
                   msg->msg,
                   msg->msgLength);
}

static void set_send_eth_ui(ethQueryContractUI_t *msg) {
    strlcpy(msg->title, "Send", msg->titleLength);

    const uint8_t *eth_amount = msg->pluginSharedRO->txContent->value.value;
    uint8_t eth_amount_size = msg->pluginSharedRO->txContent->value.length;

    // Converts the uint256 number located in `eth_amount` to its string representation and
    // copies this to `msg->msg`.
    // amountToString(eth_amount, eth_amount_size, WEI_TO_ETHER, "ETH", msg->msg, msg->msgLength);
    amountToString(eth_amount,
                   eth_amount_size,
                   WEI_TO_ETHER,
                   msg->network_ticker,
                   msg->msg,
                   msg->msgLength);
}

static void set_withdraw_send_ui(ethQueryContractUI_t *msg, const context_t *context) {
    strlcpy(msg->title, "Send", msg->titleLength);

    uint8_t decimals = context->decimals;
    const char *ticker = context->ticker;

    // If the token look up failed, use the default network ticker along with the default decimals.
    if (!context->token_found) {
        decimals = WEI_TO_ETHER;
        ticker = msg->network_ticker;
    }

    amountToString(context->amount_sent,
                   sizeof(context->amount_sent),
                   decimals,
                   context->vault_symbol,
                   msg->msg,
                   msg->msgLength);
}

static void set_withdraw_receive_ui(ethQueryContractUI_t *msg, const context_t *context) {
    strlcpy(msg->title, "Receive Min", msg->titleLength);

    uint8_t decimals = context->decimals;
    const char *ticker = context->ticker;

    // If the token look up failed, use the default network ticker along with the default decimals.
    if (!context->token_found) {
        decimals = WEI_TO_ETHER;
        ticker = msg->network_ticker;
    }

    amountToString(context->amount_received,
                   sizeof(context->amount_received),
                   decimals,
                   ticker,
                   msg->msg,
                   msg->msgLength);
}

static void set_vault_ui(ethQueryContractUI_t *msg, const context_t *context) {
    strlcpy(msg->title, "Vault", msg->titleLength);
    strlcpy(msg->msg, context->vault_symbol, context->vault_symbol_length + 1);
}

void handle_query_contract_ui(void *parameters) {
    ethQueryContractUI_t *msg = (ethQueryContractUI_t *) parameters;
    context_t *context = (context_t *) msg->pluginContext;

    // msg->title is the upper line displayed on the device.
    // msg->msg is the lower line displayed on the device.

    // Clean the display fields.
    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);

    msg->result = ETH_PLUGIN_RESULT_OK;

    if (context->selectorIndex == DEPOSIT) {
        switch (msg->screenIndex) {
            case 0:
                set_send_ui(msg, context);
                break;
            case 1:
                set_vault_ui(msg, context);
                break;
            default:
                PRINTF("Received an invalid screenIndex\n");
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                return;
        }
    } else if (context->selectorIndex == DEPOSIT_ETH) {
        switch (msg->screenIndex) {
            case 0:
                set_send_eth_ui(msg);
                break;
            case 1:
                set_vault_ui(msg, context);
                break;
            default:
                PRINTF("Received an invalid screenIndex\n");
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                return;
        }
    } else if ((context->selectorIndex == WITHDRAW) || (context->selectorIndex == WITHDRAW_ETH)) {
        switch (msg->screenIndex) {
            case 0:
                set_withdraw_send_ui(msg, context);
                break;
            case 1:
                set_withdraw_receive_ui(msg, context);
                break;
            default:
                PRINTF("Received an invalid screenIndex\n");
                msg->result = ETH_PLUGIN_RESULT_ERROR;
                return;
        }
    } else {
        msg->result = ETH_PLUGIN_RESULT_ERROR;
    }
}
