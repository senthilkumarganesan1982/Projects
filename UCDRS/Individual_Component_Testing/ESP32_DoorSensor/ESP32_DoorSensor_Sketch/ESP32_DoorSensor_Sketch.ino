#define SENSOR_PIN 26
int newstate;
int oldstate;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  oldstate = digitalRead(SENSOR_PIN);
}
void loop() {
  // put your main code here, to run repeatedly:
  newstate = digitalRead(SENSOR_PIN);
  if(oldstate!=newstate)
  {
    if(newstate == HIGH)
    {
      Serial.println("Sliding Window is Open");

    }
    else
    {
      Serial.println("Sliding Window is Closed");

    }
    oldstate = newstate;
  }
}
