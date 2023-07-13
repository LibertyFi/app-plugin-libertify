import { processTest, populateTransaction } from "../../test.fixture";

const contractName = "LibertiVault";

const testLabel = "redeem"; // <= Name of the test
const testDirSuffix = "redeem"; // <= directory to compare device snapshots to
const testNetwork = "polygon";
const signedPlugin = false;

const contractAddr = "0x9c80a455ecaca7025a45f5fa3b85fd6a462a447b";
const chainID = 137;

// From : https://polygonscan.com/tx/0xf18481c6f7c382287a23b44ade8c7b74ea8955ba87d1a008603791c2668273b9
const inputData =
    "0x87515b9000000000000000000000000000000000000000000000000001c1fb3e63de499b0000000000000000000000004369cfd11f32575a539c9e64346e0f2dc531e17b0000000000000000000000004369cfd11f32575a539c9e64346e0f2dc531e17b00000000000000000000000000000000000000000000000000000000000000800000000000000000000000000000000000000000000000000000000000000000";

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
