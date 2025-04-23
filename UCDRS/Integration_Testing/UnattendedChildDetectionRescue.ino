// ------------------ Include Files -- Start -----------
#include "DHT.h"
//------------------ Include Files -- End --------------


//Sensors
#define TRIG_PIN 4      // UltraSonic Sensors
#define ECHO_PIN 15     // UltraSonic Sensors
#define DHTPIN 13         // Temp sensor -- ESP32 GPIO connected to DHT11 data pin
#define DHTTYPE DHT11    // Temp Sensor -- Change to DHT22 if you're using it

//Actuators
#define LED_BUILTIN 2
#define RESCUE_OUTPUT_PIN 26

//Variable Declaration
long duration;
float distance;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RESCUE_OUTPUT_PIN, OUTPUT);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(RESCUE_OUTPUT_PIN, LOW);
  //------------- UltraSonic - Driver Presence -- Start --------
  // Send a 10us HIGH pulse to trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);  
  // Measure the time for echo
  duration = pulseIn(ECHO_PIN, HIGH);  
  // Convert time to distance (cm)
  distance = duration * 0.034 / 2;
  if(distance>=10)      // If toy removed then reading around 13 cm
  {
    Serial.println("Driver Absent");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RESCUE_OUTPUT_PIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RESCUE_OUTPUT_PIN, LOW);
    delay(500);
  }
  Serial.print("Driver Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //------------- UltraSonic - Driver Presence -- End --------
  //------------ DHT -- start -------
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Default is Celsius
// Check if any reads failed
  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  //------------- DHT -- end -------------

}
