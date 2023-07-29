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

| Network | Version | Smart Contract                               | Note                         |
| ------- | ------- | -------------------------------------------- | ---------------------------- |
| Polygon | v1.0.0  | `0xb19d68cc120c5139bb83e3b8c11cb4d421eea98d` | Proxy contract for `deposit` |

Vault contracts (v1.1.0) for `redeem`, `depositEth`, `redeemEth`:

```
lify-maticusdt-meerkat-6 L-MATICUSDT-M6 Polygon 0xc9266176B2af324Db2AE362AB998460aF6477f0D
lify-maticusdt-beaver-6 L-MATICUSDT-B6 Polygon 0x0dA444A57DEe390AB77830A2008E82b09cd31572
lify-maticusdt-tiger-6 L-MATICUSDT-T6 Polygon 0x2e8b86C0a19da13cf00818Ca93eDbfB08f0a831F
lify-maticusdt-shark-6 L-MATICUSDT-S6 Polygon 0x3566FB3E4df54297967a21dC662863dEC9003A6F
lify-wbtcusdt-meerkat-6 L-WBTCUSDT-M6 Polygon 0x19B2C6289219A89E340Bef84e56Ee6869e1dCa27
lify-wbtcusdt-beaver-6 L-WBTCUSDT-B6 Polygon 0x4E181ECA60183884596D5B8fd0A80b035a50cfC5
lify-wbtcusdt-tiger-6 L-WBTCUSDT-T6 Polygon 0xC150d4a0C8c1E29Ab62efE05C16aca38372d836A
lify-wbtcusdt-shark-6 L-WBTCUSDT-S6 Polygon 0xA34a030bA833d79d6171f55E8A4E189041b9a1e2
lify-wethusdt-meerkat-6 L-WETHUSDT-M6 Polygon 0x6BA30fa928FCA3C332E297106293860967be6143
lify-wethusdt-beaver-6 L-WETHUSDT-B6 Polygon 0x8302F05dF39be19bf389375690f81b4cd203C0E5
lify-wethusdt-tiger-6 L-WETHUSDT-T6 Polygon 0xe7BF217C40655432dcFc1d7c862A336D1aAe1380
lify-wethusdt-shark-6 L-WETHUSDT-S6 Polygon 0x0aAD89Cf9c4D1f5503e2d468E0a558d83dD8c5f1
lify-manausdt-meerkat-6 L-MANAUSDT-M6 Polygon 0x5da7e1c32eA630fca7Da29B46761E458C02A4B15
lify-manausdt-beaver-6 L-MANAUSDT-B6 Polygon 0x868509DF5abE1fe75ce2348B9F0969406CA8efe5
lify-manausdt-tiger-6 L-MANAUSDT-T6 Polygon 0x6BD8089F00577fD2db7DaE076781bDA1fCB94f92
lify-manausdt-shark-6 L-MANAUSDT-S6 Polygon 0x48569cFa4a93134fAa7f7Eb32f7394339fB63EeD
lify-sandusdt-meerkat-6 L-SANDUSDT-M6 Polygon 0xa5CDe5780b2ebD43CA529c9D3e4b0018ED0d14cD
lify-sandusdt-beaver-6 L-SANDUSDT-B6 Polygon 0xc248377356852DeE191F11CD8D6D842AC27ddFd2
lify-sandusdt-tiger-6 L-SANDUSDT-T6 Polygon 0x80f6672fC258D5f9f099E229975674EfB320EF2C
lify-sandusdt-shark-6 L-SANDUSDT-S6 Polygon 0x91DC52AD3b67b446d861717DC923a00c774df040
lify-aaveusdt-meerkat-6 L-AAVEUSDT-M6 Polygon 0x75fAaF20732f3dD8f7206f0C038c25d9C3AC2819
lify-aaveusdt-beaver-6 L-AAVEUSDT-B6 Polygon 0xfE966384FdCc66EcF36B7D88dE664fF7acBb0E16
lify-aaveusdt-tiger-6 L-AAVEUSDT-T6 Polygon 0x52f51DbCBdb5e57C2ca93b0598f7d4CEeA0df555
lify-aaveusdt-shark-6 L-AAVEUSDT-S6 Polygon 0xe7655743137EC2DdFe7D79C2E8151223Ad042599
lify-uniusdt-meerkat-6 L-UNIUSDT-M6 Polygon 0x18Ac2794d86B363BFCc24CdFED2D7434982a8839
lify-uniusdt-beaver-6 L-UNIUSDT-B6 Polygon 0xc2913B367469c6bD7c3Bc91C4D8b89Eea8E89bDA
lify-uniusdt-tiger-6 L-UNIUSDT-T6 Polygon 0xdE5748fd8E42827Fd147934C787bC25eAa895Fb0
lify-uniusdt-shark-6 L-UNIUSDT-S6 Polygon 0xA43E5fBBC4C75696b374420Fb25d03B957990Ffc
lify-linkusdt-meerkat-6 L-LINKUSDT-M6 Polygon 0x0C7E2219e60A7f2a703d6eff1289D397D2bD3837
lify-linkusdt-beaver-6 L-LINKUSDT-B6 Polygon 0x678F4372C6F2F14dE4f13d1b5d5a2FC1Ff036ebe
lify-linkusdt-tiger-6 L-LINKUSDT-T6 Polygon 0x4Cb6fD78748A342d9276c96b232E26127430Ae9B
lify-linkusdt-shark-6 L-LINKUSDT-S6 Polygon 0xD1A173aD8048B0DbC026BEBf15767A91B0a155cb
```

## Functions implemented:

| Function   | Selector   | Displayed Parameters                                                                                                                                                                                                     |
| ---------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Deposit    | 0xe9c670ad | <table> <tbody> <tr> <td><code>address vault</code></td></tr> <tr><td><code>address token</code></td></tr> <tr><td><code>uint256 assets</code></td></tr> <tr><td><code>bytes data</code></td></tr></tbody> </table>      |
| Redeem     | 0x87515b90 | <table> <tbody> <tr> <td><code>uint256 shares</code></td></tr> <tr><td><code>address receiver</code></td></tr> <tr><td><code>address owner\_</code></td></tr> <tr><td><code>bytes data</code></td></tr></tbody> </table> |
| DepositEth | 0x3b086d4d | <table> <tbody> <tr> <td><code>address receiver</code></td></tr> <tr><td><code>bytes data</code></td></tr></tbody> </table>                                                                                              |
| RedeemEth  | 0xd24febcd | <table> <tbody> <tr> <td><code>uint256 shares</code></td></tr> <tr><td><code>address receiver</code></td></tr> <tr><td><code>address owner\_</code></td></tr> <tr><td><code>bytes data</code></td></tr></tbody> </table> |

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
