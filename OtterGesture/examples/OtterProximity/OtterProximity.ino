#include <Wire.h>
#include <OtterGesture.h>

// Global Variables
OtterGesture Proxi = OtterGesture();
uint8_t proximity_data = 0;

void setup() {
  
  // Initialize Serial port
  Serial.begin(115200);
  // Initialize Proxi-9960 (configure I2C and initial values)
  if ( Proxi.init() ) {
    Serial.println(F("Proxi-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during Proxi-9960 init!"));
  }
  
  // Adjust the Proximity sensor gain
  if ( !Proxi.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the Proxi-9960 proximity sensor (no interrupts)
  if ( Proxi.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }
}

void loop() {
  
  // Read the proximity value
  if ( !Proxi.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    // Serial.print("Proximity: ");
    Serial.println(proximity_data);
  }
  delay(100);
}