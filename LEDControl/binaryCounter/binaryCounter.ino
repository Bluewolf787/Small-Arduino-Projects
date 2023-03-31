int inByte = 0;
String inString = "";
int inNum = 0;

int dec1 = 13;
int dec2 = 12;
int dec4 = 11;
int dec8 = 10;

void setup() {
  Serial.begin(9600);

  pinMode(dec1, OUTPUT);
  pinMode(dec2, OUTPUT);
  pinMode(dec4, OUTPUT);
  pinMode(dec8, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    inByte = Serial.read();
    
    inString += (char)inByte;

    if (inByte == '\n') {
      inNum = inString.toInt();
      Serial.println(inNum);
      inString = "";
    }
  }

  if (inNum % 2 > 0) {
    digitalWrite(dec1, HIGH);
  } else {
    digitalWrite(dec1, LOW);
  }

  if (inNum % 4 > 1) {
    digitalWrite(dec2, HIGH);
  } else {
    digitalWrite(dec2, LOW);
  }

  if (inNum % 8 > 3) {
    digitalWrite(dec4, HIGH);
  } else {
    digitalWrite(dec4, LOW);
  }

  if (inNum % 16 > 7) {
    digitalWrite(dec8, HIGH);
  } else {
    digitalWrite(dec8, LOW);
  }
}
