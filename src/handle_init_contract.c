#include "libertify_plugin.h"

// Called once to init.
void handle_init_contract(void *parameters) {
    ethPluginInitContract_t *msg = (ethPluginInitContract_t *) parameters;

    if (msg->interfaceVersion != ETH_PLUGIN_INTERFACE_VERSION_LATEST) {
        msg->result = ETH_PLUGIN_RESULT_UNAVAILABLE;
        return;
    }

    if (msg->pluginContextLength < sizeof(one_inch_parameters_t)) {
        msg->result = ETH_PLUGIN_RESULT_ERROR;
        return;
    }

    one_inch_parameters_t *context = (one_inch_parameters_t *) msg->pluginContext;
    memset(context, 0, sizeof(*context));

    // Determine a function to call
    size_t i;
    for (i = 0; i < NUM_LIBERTIFY_SELECTORS; i++) {
        if (memcmp((uint8_t *) PIC(LIBERTIFY_SELECTORS[i]), msg->selector, SELECTOR_SIZE) == 0) {
            context->selectorIndex = i;
            break;
        }
    }

    if (i == NUM_LIBERTIFY_SELECTORS) {
        // Selector was not found
        msg->result = ETH_PLUGIN_RESULT_ERROR;
        return;
    }

    // Set `next_param` to be the first field we expect to parse.
    switch (context->selectorIndex) {
        case DEPOSIT:
            context->skip = 1;  // Skip `vault` parameter
            context->next_param = TOKEN_SENT;
            break;
        case REDEEM:
            context->next_param = AMOUNT_SENT;
            break;
        case DEPOSIT_ETH:
            context->next_param = DST_RECEIVER;
            break;
        case REDEEM_ETH:
            context->next_param = AMOUNT_SENT;
            break;
        default:
            PRINTF("Missing selectorIndex\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}
