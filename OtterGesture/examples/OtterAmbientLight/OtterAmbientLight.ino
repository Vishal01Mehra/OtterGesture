#include <Wire.h>
#include <OtterGesture.h>

// Pins
#define APDS9960_INT 2  // Needs to be an interrupt pin
#define LED_PIN 13      // LED for showing interrupt

// Constants
#define LIGHT_INT_HIGH 1000  // High light level for interrupt
#define LIGHT_INT_LOW 10     // Low light level for interrupt

// Global variables
OtterGesture apds = OtterGesture();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int isr_flag = 0;
uint16_t threshold = 0;

void setup() {
  // Initialize Serial port
  Serial.begin(115200);

  if (apds.init()) {
    Serial.println(F("Otter Ambient Light sensor initialization complete"));
  } else {
    Serial.println(F("Something went wrong during Ambient Light sensor init!"));
  }

  // Set high and low interrupt thresholds
  if (!apds.setLightIntLowThreshold(LIGHT_INT_LOW)) {
    Serial.println(F("Error writing low threshold"));
  }
  if (!apds.setLightIntHighThreshold(LIGHT_INT_HIGH)) {
    Serial.println(F("Error writing high threshold"));
  }

  // Start running the APDS-9960 light sensor (no interrupts)
  if (apds.enableLightSensor(false)) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

  // Read high and low interrupt thresholds
  if (!apds.getLightIntLowThreshold(threshold)) {
    Serial.println(F("Error reading low threshold"));
  } else {
    Serial.print(F("Low Threshold: "));
    Serial.println(threshold);
  }
  if (!apds.getLightIntHighThreshold(threshold)) {
    Serial.println(F("Error reading high threshold"));
  } else {
    Serial.print(F("High Threshold: "));
    Serial.println(threshold);
  }

  // Enable interrupts
  if (!apds.setAmbientLightIntEnable(1)) {
    Serial.println(F("Error enabling interrupts"));
  }

  // Wait for initialization and calibration to finish
  delay(500);
}

void loop() {
  // Read the light levels (ambient, red, green, blue) and print
  if (!apds.readAmbientLight(ambient_light) || !apds.readRedLight(red_light) || !apds.readGreenLight(green_light) || !apds.readBlueLight(blue_light)) {
    Serial.println("Error reading light values");
  } else {
    // Serial.print("Ambient: ");
    Serial.print(ambient_light);
    Serial.print(" ");
    // Serial.print(" R: ");
    Serial.print(red_light);
    Serial.print(" ");
    // Serial.print(" G: ");
    Serial.print(green_light);
    Serial.print(" ");
    // Serial.print(" B: ");
    Serial.println(blue_light);
  }
  // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)
  apds.clearAmbientLightInt();
}