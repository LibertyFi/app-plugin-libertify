import { processTest, populateTransaction } from "../../test.fixture";

const contractName = "LibertiV2Proxy";

const testLabel = "withdrawEthWithSymbolCheck"; // <= Name of the test
const testDirSuffix = "withdraw_eth_with_symbol_check"; // <= directory to compare device snapshots to
const testNetwork = "polygon";
const signedPlugin = false;

const contractAddr = "0x3899623b60552CFacD5AF014E56BFadd14E116c6";
const chainID = 137;

// From : https://polygonscan.com/tx/0x256b858459f10eb01656fef4cdb8bc351928f89fa050c94f9d290d9938479b95
const inputData =
    "0x1c73199900000000000000000000000000000000000000000000000003de1fdf6f6d78640000000000000000000000008b59e61065de08ec02bd44bc2f121f0343ed536e000000000000000000000000000000000000000000000000010f7840c4eefb0600000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000000e000000000000000000000000000000000000000000000000000000000000000086c69574d415449430000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000002a0000000000000000000000000000000000000000000000000000000000000022812aa3caf000000000000000000000000ce9cc1fa6df298854f77e92042fd2a3e7fb27eff0000000000000000000000000d500b1d8e8ef31e21c99d1db9a6444d3adf1270000000000000000000000000eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee000000000000000000000000ce9cc1fa6df298854f77e92042fd2a3e7fb27eff000000000000000000000000484f6cec15080ba2efb2c9ccbe84372aed5771380000000000000000000000000000000000000000000000000063032ff18af2700000000000000000000000000000000000000000000000000062e9d71046f7d30000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000014000000000000000000000000000000000000000000000000000000000000001600000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000008a00000000000000000000000000000000000000000000006c00005600001a0020d6bdbf780d500b1d8e8ef31e21c99d1db9a6444d3adf127041210d500b1d8e8ef31e21c99d1db9a6444d3adf127000042e1a7d4d0000000000000000000000000000000000000000000000000000000000000000c0611111111254eeb25477b68fb85ed929f73a96058200000000000000000000000000000000000000000000458441b3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000026812aa3caf000000000000000000000000ce9cc1fa6df298854f77e92042fd2a3e7fb27eff000000000000000000000000c2132d05d31c914a87c6611c10748aeb04b58e8f000000000000000000000000eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee000000000000000000000000604229c960e5cacf2aaeac8be68ac07ba9df81c3000000000000000000000000484f6cec15080ba2efb2c9ccbe84372aed5771380000000000000000000000000000000000000000000000000000000000006cde00000000000000000000000000000000000000000000000000ac48eaaa382852000000000000000000000000000000000000000000000000000000000000000400000000000000000000000000000000000000000000000000000000000001400000000000000000000000000000000000000000000000000000000000000160000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000dd0000000000000000000000000000000000000000bf0000a900006d00001a0020d6bdbf78c2132d05d31c914a87c6611c10748aeb04b58e8f00206ae4071118002dc6c0604229c960e5cacf2aaeac8be68ac07ba9df81c30000000000000000000000000000000000000000000000000000000000000001c2132d05d31c914a87c6611c10748aeb04b58e8f41010d500b1d8e8ef31e21c99d1db9a6444d3adf127000042e1a7d4d0000000000000000000000000000000000000000000000000000000000000000c0611111111254eeb25477b68fb85ed929f73a960582000000458441b3000000000000000000000000000000000000000000000000";

const serializedTx = populateTransaction(contractAddr, inputData, chainID);

const devices = [
    {
        name: "nanos",
        label: "Nano S",
        steps: 10, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanox",
        label: "Nano X",
        steps: 6, // <= Define the number of steps for this test case and this device
    },
    {
        name: "nanosp",
        label: "Nano S+",
        steps: 6, // <= Define the number of steps for this test case and this device
    },
];

devices.forEach((device) => {
    processTest(
        device,
        contractName,
        testLabel,
        testDirSuffix,
        "",
        signedPlugin,
        serializedTx,
        testNetwork
    );
});
