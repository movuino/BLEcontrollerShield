# BLEcontrollerShield
BLE Controller Shield for movuino

It uses capacitive pins of Movuino ESP32

It uses this BLE HID keyboard library

https://github.com/T-vK/ESP32-BLE-Keyboard


- hardware design is based on makey makey  https://github.com/sparkfun/MaKeyMaKey

The MaKey MaKey is a collaboration with Jay Silver and Eric Rosenbaum. You can find more information about them [here]. (http://www.makeymakey.com/)

Makey Makey is a registered trademark of JoyLabz LLC.


What is working :
- Keys UP,DOWN,RIGHT,LEFT
- Key Space
- average

To be done :
- switch for activating sending of commands
- click key (maybe it requires ble mouse ? )
- compatibility with Movuino NRF52 & movuino esp8266 to be tested
- the pin io13 is shared with PB hold pin on movuino ESP32 maybe change pin in future
- test if threshold is always good
