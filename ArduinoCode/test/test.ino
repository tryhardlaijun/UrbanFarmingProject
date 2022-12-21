#include <M5StickCPlus.h>

#define DEVICE_ADDRESS 0x39
#define NUM_BYTES_TO_RECEIVE 3

void setup() {
  Wire.begin();
  M5.Lcd.println("M5StickC I2C Tester");
}

void loop() {
  Wire.requestFrom(DEVICE_ADDRESS, NUM_BYTES_TO_RECEIVE);
  while (Wire.available()) {
    byte data = Wire.read();
    Serial.println(data);
  }

}