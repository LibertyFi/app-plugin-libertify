#include "libertify_plugin.h"

// Need more information about the interface for plugins? Please read the README.md!

// Function: deposit(address vault,address token,uint256 assets,bytes data)
// MethodID: 0xe9c670ad
static const uint8_t LIBERTI_PROXY_DEPOSIT_SELECTOR[SELECTOR_SIZE] = {0xe9, 0xc6, 0x70, 0xad};

// Function: redeem(uint256 shares,address receiver,address owner_,bytes data)
// MethodID: 0x87515b90
static const uint8_t LIBERTI_VAULT_REDEEM_SELECTOR[SELECTOR_SIZE] = {0x87, 0x51, 0x5b, 0x90};

// Function: depositEth(address receiver,bytes data)
// MethodID: 0x3b086d4d
static const uint8_t LIBERTI_VAULT_DEPOSIT_ETH_SELECTOR[SELECTOR_SIZE] = {0x3b, 0x08, 0x6d, 0x4d};

// Function: redeemEth(uint256 shares,address receiver,address _owner,bytes data)
// MethodID: 0xd24febcd
static const uint8_t LIBERTI_VAULT_REDEEM_ETH_SELECTOR[SELECTOR_SIZE] = {0xd2, 0x4f, 0xeb, 0xcd};

// Array of all the different 1inch selectors.
const uint8_t *const LIBERTIFY_SELECTORS[NUM_LIBERTIFY_SELECTORS] = {
    LIBERTI_PROXY_DEPOSIT_SELECTOR,
    LIBERTI_VAULT_REDEEM_SELECTOR,
    LIBERTI_VAULT_DEPOSIT_ETH_SELECTOR,
    LIBERTI_VAULT_REDEEM_ETH_SELECTOR,
};

// 1inch uses `0xeeeee` as a dummy address to represent ETH.
const uint8_t ONE_INCH_ETH_ADDRESS[ADDRESS_LENGTH] = {0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
                                                      0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
                                                      0xee, 0xee, 0xee, 0xee, 0xee, 0xee};

// Used to indicate that the beneficiary should be the sender.
const uint8_t NULL_ETH_ADDRESS[ADDRESS_LENGTH] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
