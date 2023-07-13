import { processTest, populateTransaction } from "../../test.fixture";

const contractName = "LibertiVault";

const testLabel = "depositEth"; // <= Name of the test
const testDirSuffix = "deposit_eth"; // <= directory to compare device snapshots to
const testNetwork = "polygon";
const signedPlugin = false;

const contractAddr = "0x2e8b86c0a19da13cf00818ca93edbfb08f0a831f";
const chainID = 137;

// From : https://polygonscan.com/tx/0xbd99adba4e5c99ad91bc3f25b2dff3798e3c753351949b0f910f578aaf4b4249
const inputData =
  "0x3b086d4d0000000000000000000000009e97d9e1c8abc901c0a7de2b90685a80c8c291c500000000000000000000000000000000000000000000000000000000000000400000000000000000000000000000000000000000000000000000000000000000";

const serializedTx = populateTransaction(
  contractAddr,
  inputData,
  chainID,
  "4.009217033468839314"
);

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
