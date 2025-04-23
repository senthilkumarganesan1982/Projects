#define PIR_PIN 14    // Change this to whatever GPIO you're using
#define LED_PIN 2     // Built-in LED for visual feedback

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);

  if (motionDetected) {
    Serial.println("Motion detected!");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("No motion");
    digitalWrite(LED_PIN, LOW);
  }

  delay(500); // adjust as needed
}
