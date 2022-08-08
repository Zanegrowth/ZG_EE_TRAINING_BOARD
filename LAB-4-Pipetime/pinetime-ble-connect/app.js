const https = require("https"); /* To use HTTPS */
var noble = require("noble"); /* To use BLE */

noble.on("stateChange", async function (state) {
  if (state === "poweredOn") {
    startScan();
  } else {
  }
});

noble.on("scanStart", function () {
  console.log("Scan started");
});
noble.on("scanStop", function () {
  console.log("Scan stopped");
});

noble.on("discover", async function (peripheral) {
  const PINETIME_MAC_ADDRESS = "e0:e0:5f:ca:14:9f";
  /* Battery */
  const BATTERY_SERVICE_UUID = "180f";
  const BATTERY_CHARACTERISTIC_UUID = "2a19";
  /* Heart Rate */
  const HEARTRATE_SERVICE_UUID = "180d";
  const HEARTRATE_CHARACTERISTIC_UUID = "2a37";

  if (peripheral.address === PINETIME_MAC_ADDRESS) {
    console.log("Found !!");
    stopScan();
    peripheral.connect(async function (error) {
      console.log("Connected");
      const serviceUUIDs = [BATTERY_SERVICE_UUID, HEARTRATE_SERVICE_UUID];
      const characteristicUUIDs = [
        BATTERY_CHARACTERISTIC_UUID,
        HEARTRATE_CHARACTERISTIC_UUID,
      ];

      peripheral.discoverSomeServicesAndCharacteristics(
        serviceUUIDs,
        characteristicUUIDs,
        (error, services, characteristics) => {
          /* initialize battery and heart rate value */
          let batt = -1,
            hr = 0;

          /* Read battery and heart rate every 5 second */
          setInterval(() => {
            console.log("Reading...");
            const BATTERY_CHARACTERISTIC = characteristics[0];
            BATTERY_CHARACTERISTIC.read((error, data) => {
              batt = data[0];
            });

            const HEARTRATE_CHARACTERISTIC = characteristics[1];
            HEARTRATE_CHARACTERISTIC.read((error, data) => {
              hr = data[1];
            });

            if (batt > -1 && hr > 0) {
              sendData(peripheral.address, batt, hr);
            }
          }, 10 * 1000);
        }
      );
    });
  }
});

// start scan function
function startScan() {
  var bleState = noble.state;
  if (bleState == "poweredOn") {
    noble.startScanning([], true);
  } else {
    noble.stopScanning();
  }
}

// stop scan function
function stopScan() {
  var bleState = noble.state;
  if (bleState == "poweredOn") {
    noble.stopScanning();
  } else {
    noble.stopScanning();
  }
}

function sendData(macAddress, battery, heartRate) {
  console.log("Sending data...");
  const payload = {
    id: macAddress.toUpperCase().replace(/:/g, ""),
    type: 380001,
    data: {
      dts: new Date().getTime(),
      seq: 1,
      status: 1,
      fwVersion: "1.0.1",
      pinetime: {
        hr: heartRate,
        batt: battery,
      },
    },
  };

  data = JSON.stringify(payload);

  const options = {
    hostname: "api.aidery.io",
    path: "/data-log",
    method: "POST",
    headers: {
      Authorization: `Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjYyOGNhZWRkMTgxODU5MDAxMjg4MjIzZCIsInJvbGUiOjUwLCJpYXQiOjE2NTMzODY5NzN9.6quw2KM9YWYshU1i5dJa3K-UbUJAkjZj6kIWdUv7uRY`,
      "Content-Type": "application/json",
      "Content-Length": data.length,
    },
  };

  const req = https
    .request(options, (res) => {
      let data = "";
      res.on("data", (chunk) => {
        data += chunk;
      });
      res.on("end", () => {
        console.log("Sending success !");
        console.log(
          "Mac Address >> ",
          macAddress.toUpperCase().replace(/:/g, "")
        );
        console.log("battery >> ", battery);
        console.log("heartRate >> ", heartRate);
      });
    })
    .on("error", (err) => {
      console.log("HTTP Request Fail !");
    });

  req.write(data);
  req.end();
}
