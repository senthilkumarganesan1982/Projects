#define TRIG_PIN 4
#define ECHO_PIN 15
#define LED_BUILTIN 2
#define RESCUE_PIN 26

long duration;
float distance;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RESCUE_PIN, OUTPUT);
  
}

void loop() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(RESCUE_PIN, LOW);
  delayMicroseconds(2);
  
  // Send a 10us HIGH pulse to trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the time for echo
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Convert time to distance (cm)
  distance = duration * 0.034 / 2;

  if(distance>=10)
  {
    Serial.println("Driver Absent");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RESCUE_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RESCUE_PIN, LOW);
    delay(1000);

  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}