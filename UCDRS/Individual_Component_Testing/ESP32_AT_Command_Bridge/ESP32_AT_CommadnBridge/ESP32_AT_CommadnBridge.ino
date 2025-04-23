#include <HardwareSerial.h>


HardwareSerial sim800(1); // UART1 on GPIO16 (RX), GPIO17 (TX)

void setup() {
  Serial.begin(115200);             // USB Serial to PC
  sim800.begin(9600, SERIAL_8N1, 16, 17); // SIM800L Serial
  
  delay(1000);
  Serial.println("AT Command Tester Ready");
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    sim800.write(Serial.read());  // Send from PC to SIM800
  }
  if (sim800.available()) {
    Serial.write(sim800.read());  // Send response back to PC
  }
}
