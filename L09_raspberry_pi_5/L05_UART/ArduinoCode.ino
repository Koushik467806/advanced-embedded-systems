void setup() {
  Serial.begin(9600); // 9600 Baud Rate
  delay(3500); // So that we dont lose info while clearing initial buffer
}

void loop() {
  if(Serial.available() > 0){
    // Read until new line
    String inputString = Serial.readStringUntil('\n');

    int num = inputString.toInt();

    int res = num * num; // Max till 32767 (Max int value)

    Serial.print("Squared: ");
    Serial.println(res);
  }
}
