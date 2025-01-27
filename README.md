# STM32WBA-BLE-GATT-Caching

Demonstrate STM32WBA acting as BLE central and GATT client with BLE_GATT_caching_Client and GAP peripheral and GATT server with BLE_GATT_caching_Server.

BLE_GATT_caching_Client application scans and connects to BLE_GATT_caching_Server device.

Both devices support GATT caching feature.
The client stores the discovered attribute handles and Database Hash value. 
Purpose is to show the use of the Database Hash value and the use of Robust caching in Client Supported Feature characteristic.   

For more information regarding BLE GATT Caching feature, please visit BLE GATT Caching Wiki documentation (https://wiki.st.com/stm32mcu/wiki/Connectivity:STM32WB-WBA_GATT_caching).

## Setup
These applications are running on two **NUCLEO-WBA55CGA boards**. 
Applications are derived from BLE_GATT_caching_Client and BLE_GATT_caching_Server applications for use of extended advertising.
Open a VT100 terminal on Central and Peripheral side (ST Link Com Port, @115200 bauds).

At startup, devices are initialized.
 - The peripheral device starts advertising.
 - B1 on central device starts scanning. Scan is stopped if a BLE_GATT_caching_Server is detected.

## Application description
These applications are based on P2P server and P2P client from STM32CubeWBA package v1.4.1.   

 At reset, initialization is done.

 - The peripheral device starts advertising.

 Database Hash characteristic example:

 - Push B1 on central: the central device scans and automatically connects to the peripheral (use of FW_ID_GC_SERVER). 
 After connection:
 - Discovery of service and characteristics.
 - Stores the discovered attribute handles and Database Hash value.

On server side when connected, after Client service and characteristics discoveries:
 - Push B2: delete characteristic 3, this leads to a new value of Database Hash.

On client:
 - Push B2: disconnection request
 - Push B1: scan is started, client checks if the Database Hash value has changed.
 If it has changed, client restarts a database discovery, stores new attribute handles and Hash value.
  
Client Supported Feature characteristic example:

 - Push B1 on central: the central device scans and automatically connects to the peripheral (use of FW_ID_GC_SERVER). 
 After connection:
   - Discovery of service and characteristics.
   - Stores the discovered attribute handles and Database Hash value.
   - Client enables Robust Caching (set "robust caching" bit in Client Supported Feature characteristic)

On client:
 - Push B3: read characteristic 2 value, read is success

On server side when connected, after Client service and characteristics discoveries:
 - Push B2: delete of characteristic 3.

On client:
 - Push B3: read characteristic 2 value: server sends a "Database out-of-sync" error. Client becomes "change aware" from server perspective.
 - Push B3: read characteristic 2 value, ok.

## Troubleshooting

**Caution** : Issues and the pull-requests are **not supported** to submit problems or suggestions related to the software delivered in this repository. The STM32WBA-BLE-GATT-Caching example is being delivered as-is, and not necessarily supported by ST.

**For any other question** related to the product, the hardware performance or characteristics, the tools, the environment, you can submit it to the **ST Community** on the STM32 MCUs related [page](https://community.st.com/s/topic/0TO0X000000BSqSWAW/stm32-mcus).