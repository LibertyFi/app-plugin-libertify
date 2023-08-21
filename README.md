# Badges

[![Code style check](https://github.com/blooo-io/app-plugin-1inch/actions/workflows/lint-workflow.yml/badge.svg)](https://github.com/blooo-io/app-plugin-1inch/actions/workflows/lint-workflow.yml)
[![Compilation & tests](https://github.com/blooo-io/app-plugin-1inch/actions/workflows/ci-workflow.yml/badge.svg)](https://github.com/blooo-io/app-plugin-1inch/actions/workflows/ci-workflow.yml)

# Ledger Libertify Plugin

This is a plugin for the Ethereum application which helps parsing and displaying relevant information when signing a Libertify transaction.

## Prerequisite

Clone the plugin to a new folder.

```shell
git clone https://github.com/libertify/app-plugin-libertify.git
```

Then in the same folder clone two more repositories, which is the plugin-tools and app-ethereum.

```shell
git clone https://github.com/LedgerHQ/plugin-tools.git                          #plugin-tools
git clone --recurse-submodules https://github.com/LedgerHQ/app-ethereum.git     #app-ethereum
```

## Documentation

Need more information about the interface, the architecture, or general stuff about ethereum plugins? You can find more about them in the [ethereum-app documentation](https://github.com/LedgerHQ/app-ethereum/blob/master/doc/ethapp_plugins.asc).

## Smart Contracts

Smart contracts covered by this plugin are:

| Network | Version | Smart Contract                               | Note                                    |
| ------- | ------- | -------------------------------------------- | --------------------------------------- |
| Polygon | v1.0.0  | `0x3899623b60552CFacD5AF014E56BFadd14E116c6` | Proxy contract for operations on vaults |

## Functions implemented:

| Function   | Selector   | Displayed Parameters                                                                                                                                                                                                     |
| ---------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| DepositWithSymbolCheck | 0x50806b50 | <table><tbody> <tr><td><code>uint256 amountIn</code></td></tr> <tr><td><code>address srcToken</code></td></tr> <tr><td><code>string vaultSymbol</code></td></tr> </tbody></table> |
| WithdrawWithSymbolCheck | 0xa34a09ec | <table><tbody> <tr><td><code>uint256 amountIn</code></td></tr> <tr><td><code>address dstToken</code></td></tr> <tr><td><code>uint256 minAmountOut</code></td></tr> <tr><td><code>string vaultSymbol</code></td></tr> </tbody></table> |
| DepositEthWithSymbolCheck | 0x7a894791 | <table><tbody> <tr><td><code>msg.value</code></td></tr> <tr><td><code>string vaultSymbol</code></td></tr> </tbody></table> |
| WithdrawEthWithSymbolCheck | 0x1c731999 | <table><tbody> <tr><td><code>uint256 amountIn</code></td></tr> <tr><td><code>uint256 minAmountOut</code></td></tr> <tr><td><code>string vaultSymbol</code></td></tr> </tbody></table> |

## Build

Go to the plugin-tools folder and run the "./start" script.

```shell
cd plugin-tools  # go to plugin folder
./start.sh       # run the script start.sh
```

The script will build a docker image and attach a console.
When the docker image is running go to the "app-plugin-libertify" folder and build the ".elf" files.

```shell
cd app-plugin-libertify/tests   # go to the tests folder in app-plugin-libertify
./build_local_test_elfs.sh      # run the script build_local_test_elfs.sh
```

## Tests

To test the plugin go to the tests folder from the "app-plugin-libertify" and run the script "test"

```shell
cd app-plugin-libertify/tests   # go to the tests folder in app-plugin-libertify
yarn test                       # run the script test
```

## Continuous Integration

The flow processed in [GitHub Actions](https://github.com/features/actions) is the following:

- Code formatting with [clang-format](http://clang.llvm.org/docs/ClangFormat.html)
- Compilation of the application for Ledger Nano S in [ledger-app-builder](https://github.com/LedgerHQ/ledger-app-builder)
