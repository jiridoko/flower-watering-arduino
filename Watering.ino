#define RASPBERRY_PUMP 4
#define CURRANT_PUMP 5

#define RASPBERRY_INPUT A4
#define CURRANT_INPUT A5

void setup() {
  pinMode(RASPBERRY_PUMP, OUTPUT);
  pinMode(CURRANT_PUMP, OUTPUT);
  
  digitalWrite(RASPBERRY_PUMP, HIGH);
  digitalWrite(CURRANT_PUMP, HIGH);
  
  pinMode(RASPBERRY_INPUT, INPUT);
  pinMode(CURRANT_INPUT, INPUT);

  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case '0':
        digitalWrite(RASPBERRY_PUMP, HIGH);
        digitalWrite(CURRANT_PUMP, HIGH);
        break;
      case '1':
        digitalWrite(RASPBERRY_PUMP, LOW);
        digitalWrite(CURRANT_PUMP, HIGH);
        break;
      case '2':
        digitalWrite(RASPBERRY_PUMP, HIGH);
        digitalWrite(CURRANT_PUMP, LOW);
        break;
      case '3':
        digitalWrite(RASPBERRY_PUMP, LOW);
        digitalWrite(CURRANT_PUMP, LOW);
        break;
      case 'R':
        int raspberry = analogRead(RASPBERRY_INPUT);
        int currant = analogRead(CURRANT_INPUT);
        Serial.print("RASP: ");
        Serial.println(raspberry);
        Serial.print("CURR: ");
        Serial.println(currant);
        break;
      default:
        break;
    }
  }
}
