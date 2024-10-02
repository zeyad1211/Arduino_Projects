SoftwareSerial mySerial (3, 4); //RX, TX

int enabMot1 = 5; // left motor
int dir1Mot1 = 6;
int dir2Mot1 = 7;
int dir1Mot2 = 8;
#include <SoftwareSerial.h>
int dir2Mot2 = 9;
int enabMot2 = 10; // right motor
int greenled = 12;
int redled = 2;

int speed2 = 250; // right motor
int speed1 = map(speed2, 0, 250, 0, 230); // left motor

void setup() {

  Serial.begin(9600);

  pinMode(dir1Mot1, OUTPUT);
  pinMode(dir2Mot1, OUTPUT);
  pinMode(dir1Mot2, OUTPUT);
  pinMode(dir2Mot2, OUTPUT);
  pinMode(enabMot1, OUTPUT);
  pinMode(enabMot2, OUTPUT);
  pinMode(enabMot2, OUTPUT);

  // pinMode(2, OUTPUT);
  // digitalWrite(2, HIGH);

  Serial.println("Enter AT commands: ");
  mySerial.begin(9600);

}

void loop() {

  /*if (mySerial.available())
  Serial.write(mySerial.read());

  if (Serial.available())
  mySerial.write(Serial.read());*/

  if (mySerial.available()){
    char state = mySerial.read();
    if (state == 'F')
      forward();

    if (state == 'B')
      backward();

    if (state == 'R')
      right();

    if (state == 'L')
      left();

    if (state == 'S')
      stop();

    if (state == 'W')
      greenledon();

    if (state == 'w')
      greenledoff();

    if (state == 'U')
      redledon();

    if (state == 'u')
      redledoff();

    if (state == 'G')
      forwardleft();

    if (state == 'I')
      forwardright();

    if (state == 'H')
      backwardleft();

    if (state == 'J')
      backwardright();
  }

}

void forward() {
  analogWrite (enabMot1, speed1);
  digitalWrite(dir1Mot1, HIGH);
  digitalWrite(dir2Mot1, LOW );
  
  analogWrite(enabMot2, speed2);
  digitalWrite(dir1Mot2, HIGH);
  digitalWrite(dir2Mot2, LOW );
}

void backward() {
  analogWrite (enabMot1, speed1);
  digitalWrite(dir1Mot1, LOW);
  digitalWrite(dir2Mot1, HIGH );
  
  analogWrite(enabMot2, speed2);
  digitalWrite(dir1Mot2, LOW);
  digitalWrite(dir2Mot2, HIGH );
}

void right() {
  analogWrite (enabMot1, speed1);
  digitalWrite(dir1Mot1, HIGH);
  digitalWrite(dir2Mot1, LOW );
  
  analogWrite(enabMot2,  (speed2/5));
  digitalWrite(dir1Mot2, HIGH);
  digitalWrite(dir2Mot2, LOW );}

void left() {
  analogWrite (enabMot1, (speed1/5));
  digitalWrite(dir1Mot1, HIGH);
  digitalWrite(dir2Mot1, LOW );
  
  analogWrite(enabMot2, speed2);
  digitalWrite(dir1Mot2, HIGH);
  digitalWrite(dir2Mot2, LOW );
}

void forwardright() {
  analogWrite (enabMot1, speed1);
  digitalWrite(dir1Mot1, HIGH);
  digitalWrite(dir2Mot1, LOW );
  
  analogWrite(enabMot2, (speed2/3));
  digitalWrite(dir1Mot2, HIGH);
  digitalWrite(dir2Mot2, LOW );
}

void forwardleft() {
  analogWrite (enabMot1, (speed1/3));
  digitalWrite(dir1Mot1, HIGH);
  digitalWrite(dir2Mot1, LOW );
  
  analogWrite(enabMot2, speed2);
  digitalWrite(dir1Mot2, HIGH);
  digitalWrite(dir2Mot2, LOW );
}

void backwardleft() {
  analogWrite (enabMot1, (speed1/3));
  digitalWrite(dir1Mot1, LOW);
  digitalWrite(dir2Mot1, HIGH );
  
  analogWrite(enabMot2, speed2);
  digitalWrite(dir1Mot2, LOW);
  digitalWrite(dir2Mot2, HIGH );
}

void backwardright() {
  analogWrite (enabMot1, speed1);
  digitalWrite(dir1Mot1, LOW);
  digitalWrite(dir2Mot1, HIGH );
  
  analogWrite(enabMot2, (speed2/3));
  digitalWrite(dir1Mot2, LOW);
  digitalWrite(dir2Mot2, HIGH );
}

void stop() {
  analogWrite (enabMot1, 0);
  analogWrite (enabMot2, 0);
}
