#include "libertify_plugin.h"

void handle_finalize(void *parameters) {
    ethPluginFinalize_t *msg = (ethPluginFinalize_t *) parameters;
    context_t *context = (context_t *) msg->pluginContext;

    msg->uiType = ETH_UI_TYPE_GENERIC;
    msg->numScreens = 2;

    if (context->selectorIndex == DEPOSIT) {
        msg->tokenLookup1 = context->token_sent;
    } else if (context->selectorIndex == WITHDRAW) {
        msg->tokenLookup1 = context->token_received;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}
