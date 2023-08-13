ct# OtterGesture
This library works with the Gesture sensor on OtterBoard 
![](https://github.com/Vishal01Mehra/OtterGesture/blob/main/Resources/OTTER.jpg)

This Library is based on [SparkFun_APDS-9960_Library](https://github.com/sparkfun/SparkFun_APDS-9960_Sensor_Arduino_Library) and implements Gesture/Color/Distance Sensor for the OtterBoard. Measure Distance (5-20cm), Ambient Light Value, Object Color (RED-GREEN-BLUE) and distinguish between 6 Gestures with OtterBoard.

## Features

 - [x] Detect 6 different gestures (UP/DOWN/LEFT/RIGHT/NEAR/FAR)
 - [x] Measure Ambient Light 
 - [x] Detect Object Colors (RED-GREEN-BLUE)
 - [x] Measure Distance up to 200m.

## Example
### Gesture sensor
``` C++
/**
 * This example turns the OtterBorad into a Gesture detection device.
 */
#include <Wire.h>
#include <OtterGesture.h>

OtterGesture Gesture = OtterGesture();

void setup() {
  Serial.begin(115200);
  if (Gesture.init()) {
    Serial.println(F("Otter Gesture initialization complete"));

    if (Gesture.enableGestureSensor(true)) {
    Serial.println(F("Gesture sensor is now running"));
    if (Gesture.setGestureGain(GGAIN_4X)) {
      Serial.println("Gesture Gain Snet");
    }
  } else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }
}
}

void loop() {
  bool GestureAvailability = Gesture.isGestureAvailable();
  if (GestureAvailability) {
    int GestureType = Gesture.readGesture();
    Serial.println(GestureType);
  }
}
```
## License
This product is open source!

Please review the LICENSE.md [MIT](https://choosealicense.com/licenses/mit/) file for license information.

Please use, reuse, and modify these files as you see fit. Please maintain attribution to Mehra Autonomous systems and release under the same license.

## Contributing
Contributions are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Base Library 
[SparkFun_APDS-9960_Library](https://github.com/Vishal01Mehra/OtterGesture/blob/main/Resources/OTTER.jpg)

