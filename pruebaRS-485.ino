
# include <SoftwareSerial.h>
# define ENRS485 9

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  
  //Puerto serial USB de ARDUINO
  Serial.begin(57600);
  while (!Serial);
  // Puerto TTL <--> RS-485
  mySerial.begin(19200);
  pinMode(ENRS485, OUTPUT);
  digitalWrite(ENRS485, LOW);
  mySerial.write("Test RS-485\r\n");
  
}

void loop() {
  
  if (mySerial.available()) {
    delay(1);
    Serial.write(mySerial.read());
    delay(5);
  }
  
  if (Serial.available()) {
    digitalWrite(ENRS485, HIGH);
    delay(10);
    mySerial.write(Serial.read());
    digitalWrite(ENRS485, LOW);
    delay(10);
  }
  
}
