Documentation in this [link](https://protosupplies.com/product/jsn-sr04t-v3-0-waterproof-ultrasonic-range-finder/)
# Basic Operation mode
## Ping mode
1) Module is idle.
2) Activated by a 20 microsecond or wider pusle. 
3) Module emit 40khz sounds and set echo pin to high.
4) When detect echo set echo pin to low.
5) Measure time for echo pin to go from high to low. 
5.1) Formula for distance is **Time for echo * speed of sound (343m/s) / 2**

## Serial mode
Operate at 9600 buad.

The way Serial mode works is as follows:

1) The module is normally idle.
2) A command bye of 0x55 on the RX pin initiates a detection cycle.
3) The module responds with 4 bytes of information
3.1) Start bye of 0xFF
3.2) Most Significant Byte (MSB)
3.3) Least Significant Byte (LSB)
3.4) Checksum Byte
4) Formula of value returned **(MSB * 256) + LSB**
5) The checksum byte is calculated using **0xFF + MSB + LSB**.  It returns the least significant byte of the calculation only.

# Operating Modes
![alt text](https://protosupplies.com/wp-content/uploads/2022/01/JSN-SR04T-V3.0-Waterproof-Ultrasonic-Range-Finder-Mode-Select-Pads.jpg "image of modes")

## Mode 0 (Ping mode)
**Setup**
Default
**Description**
Trigger pin held around 20 microseconds, to activate sensor module. Read on top for more info. Sample code in the link on top.

## Mode 1 (Automatic Serial)
**Setup**
To enter mode 1, short m1 page or place 47k resistor between mode pad.
**Description**
The module continuously takes measurements approximately every 100mS and outputs the distance on the TX pin at 9600 baud where it can be read using a serial RX pin on an MCU.

## Mode 2 (MCU Controlled Serial Mode)
**Setup**
To enter Mode 2, the M2 pads are shorted OR a resistor value of 120K is placed across the MODE pads.
**Description**
Send signal 0x55 to RX pin to activate module to take a single measurement. Minumum trigger cycle time 60ms.

## Mode 3 (Automatic Ping mode)
**Setup**
To enter Mode 3, a resistor value of 200K is placed across the MODE pads. across the MODE pads.
**Description**
Mode 3 is similar to Mode 0 (ping mode) except that it automatically generates the ping every 200mS and outputs a pulse width high level corresponding to the distance.

## MODE 4: (Low power Ping mode)
**Setup**
To enter Mode 4, a resistor value of 360K is placed across the MODE pads.
**Description**
This mode is the same as Mode 0 except that the module is set to low power in between Pings with a stated current consumption of < 70uA.

## MODE 5: (Threshold Switch Output)
**Setup**
To enter Mode 5, a resistor value of 470K is placed across the MODE pads.
**Description**
read distance every 200ms. Echo pin high if distance is higher than threshold value. Vice versa. Default threshold value is 1.5m.

