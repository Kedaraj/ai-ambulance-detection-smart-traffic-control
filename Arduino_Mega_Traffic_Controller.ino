/*
  Arduino Mega Traffic Signal Controller
  Receives:
    'A' = Ambulance detected
    'N' = Normal traffic

  Serial1 RX1 (Pin 19) <- ESP32-CAM TX
  Serial1 TX1 (Pin 18) -> ESP32-CAM RX
*/

#define R1 2
#define Y1 3
#define G1 4

#define R2 5
#define Y2 6
#define G2 7

#define R3 8
#define Y3 9
#define G3 10

#define R4 11
#define Y4 12
#define G4 13

bool ambulance = false;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  pinMode(R1,OUTPUT); pinMode(Y1,OUTPUT); pinMode(G1,OUTPUT);
  pinMode(R2,OUTPUT); pinMode(Y2,OUTPUT); pinMode(G2,OUTPUT);
  pinMode(R3,OUTPUT); pinMode(Y3,OUTPUT); pinMode(G3,OUTPUT);
  pinMode(R4,OUTPUT); pinMode(Y4,OUTPUT); pinMode(G4,OUTPUT);

  allRed();
}

void loop() {
  if (Serial1.available()) {
    char c = Serial1.read();
    if (c == 'A') ambulance = true;
    if (c == 'N') ambulance = false;
  }

  if (ambulance)
    greenCorridor();
  else
    normalTraffic();
}

void allRed() {
  digitalWrite(R1,HIGH); digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH); digitalWrite(R4,HIGH);

  digitalWrite(Y1,LOW); digitalWrite(Y2,LOW);
  digitalWrite(Y3,LOW); digitalWrite(Y4,LOW);

  digitalWrite(G1,LOW); digitalWrite(G2,LOW);
  digitalWrite(G3,LOW); digitalWrite(G4,LOW);
}

void greenCorridor() {
  digitalWrite(R1,LOW);
  digitalWrite(G1,HIGH);

  digitalWrite(R2,HIGH); digitalWrite(R3,HIGH); digitalWrite(R4,HIGH);
  digitalWrite(G2,LOW); digitalWrite(G3,LOW); digitalWrite(G4,LOW);
}

void normalTraffic() {

  digitalWrite(R1,LOW); digitalWrite(G1,HIGH);
  delay(5000);
  digitalWrite(G1,LOW); digitalWrite(Y1,HIGH);
  delay(2000);
  digitalWrite(Y1,LOW); digitalWrite(R1,HIGH);

  digitalWrite(R2,LOW); digitalWrite(G2,HIGH);
  delay(5000);
  digitalWrite(G2,LOW); digitalWrite(Y2,HIGH);
  delay(2000);
  digitalWrite(Y2,LOW); digitalWrite(R2,HIGH);

  digitalWrite(R3,LOW); digitalWrite(G3,HIGH);
  delay(5000);
  digitalWrite(G3,LOW); digitalWrite(Y3,HIGH);
  delay(2000);
  digitalWrite(Y3,LOW); digitalWrite(R3,HIGH);

  digitalWrite(R4,LOW); digitalWrite(G4,HIGH);
  delay(5000);
  digitalWrite(G4,LOW); digitalWrite(Y4,HIGH);
  delay(2000);
  digitalWrite(Y4,LOW); digitalWrite(R4,HIGH);
}
