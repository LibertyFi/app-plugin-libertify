#include "libertify_plugin.h"

void handle_query_contract_id(void *parameters) {
    ethQueryContractID_t *msg = (ethQueryContractID_t *) parameters;
    one_inch_parameters_t *context = (one_inch_parameters_t *) msg->pluginContext;

    strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);

    switch (context->selectorIndex) {
        case DEPOSIT:
        case DEPOSIT_ETH:
            strlcpy(msg->version, "Deposit", msg->versionLength);
            break;
        case REDEEM:
        case REDEEM_ETH:
            strlcpy(msg->version, "Withdraw", msg->versionLength);
            break;
        default:
            PRINTF("Selector Index :%d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}
