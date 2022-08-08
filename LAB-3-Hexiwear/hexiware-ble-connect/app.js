var noble = require("noble");
const https = require("https");

/* Constant Defination */
const DEVICE_MAC_ADDRESS = "00:35:50:04:00:10";
const BATTERY_SERVICE_UUID = "180f";
const BATTERY_CHARACTERISTIC_UUID = "2a19";
const SENSOR_SERVICE_UUID = "2000";
const ACCELEROMETER_CHARACTERISTIC_UUID = "2001";

noble.on("stateChange", async function (state) {
  if (state === "poweredOn") {
    startScan();
  }
});

noble.on("scanStart", function () {
  console.log("Scan started");
});
noble.on("scanStop", function () {
  console.log("Scan stopped");
});

noble.on("discover", async function (peripheral) {
  if (peripheral.address === DEVICE_MAC_ADDRESS) {
    stopScan();
    peripheral.connect(async function (error) {
      const serviceUUIDs = [BATTERY_SERVICE_UUID, SENSOR_SERVICE_UUID];
      const characteristicUUIDs = [
        BATTERY_CHARACTERISTIC_UUID,
        ACCELEROMETER_CHARACTERISTIC_UUID,
      ];
      peripheral.discoverSomeServicesAndCharacteristics(
        serviceUUIDs,
        characteristicUUIDs,
        (error, services, characteristics) => {
          console.log("Connected to peripheral: " + peripheral.uuid);

          const ACCELEROMETER_CHARACTERISTIC = characteristics.find(
            (char) => char.uuid === ACCELEROMETER_CHARACTERISTIC_UUID
          );

          const BATTERY_CHARACTERISTIC = characteristics.find(
            (char) => char.uuid === BATTERY_CHARACTERISTIC_UUID
          );

          let accel_x = undefined,
            accel_y = undefined,
            accel_z = undefined,
            batt = -1;

          setInterval(() => {
            console.log("Reading Data ...");
            ACCELEROMETER_CHARACTERISTIC.read((error, data) => {
              [accel_x, accel_y, accel_z] = convertAccelerometerData(data);
              console.log(
                "Accelerometer Data >>> ",
                `X:${accel_x}, Y:${accel_y}, Z:${accel_z}`
              );
            });
            BATTERY_CHARACTERISTIC.read((error, data) => {
              batt = data[0];
              console.log("Battery Data >>> ", `${batt}%`);
            });
          }, 5000);

          BATTERY_CHARACTERISTIC.on("data", (data, isNotification) => {
            sendData(peripheral.address, accel_x, accel_y, accel_z, batt);
          });
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

function convertAccelerometerData(data) {
  var swap = data.swap16();
  var x = swap.slice(0, 2).readInt16LE() / 100;
  var y = swap.slice(2, 4).readInt16LE() / 100;
  var z = swap.slice(4, 6).readInt16LE() / 100;
  return [x, y, z];
}

function sendData(macAddress, accel_x, accel_y, accel_z, batt) {
  const payload = {
    id: macAddress.toUpperCase().replace(/:/g, ""),
    type: 380001,
    data: {
      dts: new Date().getTime(),
      seq: 1,
      status: 1,
      fwVersion: "1.0.0",
      hexiwear: {
        accel_x: accel_x,
        accel_y: accel_y,
        accel_z: accel_z,
        batt: batt,
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
      });
    })
    .on("error", (err) => {
      console.log("HTTP Request Fail !");
    });

  req.write(data);
  req.end();
}
