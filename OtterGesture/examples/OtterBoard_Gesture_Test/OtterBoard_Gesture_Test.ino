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
