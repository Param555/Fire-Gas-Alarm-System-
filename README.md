# Fire-Gas-Alarm-System-
This is a fire/gas alarm system designed and implemented using Arduino UNO.

🛠 Components Used
MQ-2 Gas Sensor
Arduino UNO
5 x LEDs (Danger Indicators)
2 x Servo Motors (Gate1 & Gate2)
1 x Buzzer
Resistors
Breadboard
Jumper Wires
USB Cable or Power Supply

⚙️ How It Works
The MQ-2 sensor detects the concentration of gas in the air.
When the gas level crosses a predefined threshold, the system goes into alarm mode:

🚨 Buzzer starts beeping

💡 All 5 LEDs turn ON

🔄 Both servo motors rotate to 90° (simulate opening gates for emergency escape)

When the gas level is normal (below threshold):

🔕 Buzzer is OFF

⚫ LEDs are OFF

🔁 Servo motors reset to 0° (gates closed)

🚀 Future Improvements

Add temperature or flame sensor for multi-layer detection.

Send alerts via GSM or IoT module (e.g., ESP8266 or Blynk).

Power backup for emergency use.
