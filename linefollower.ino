
#define EN_L 5
#define ML1 6
#define ML2 7
#define MR1 8
#define MR2 9
#define EN_R 10

#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 11

int LineSensor1;
int LineSensor2;
int LineSensor3;
int LineSensor4;

int speed = 120;
int speedlow = 120*0.75;


void setup()
{
  Serial.begin(9600);
  pinMode(EN_L, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(EN_R, OUTPUT);



  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);


}

void loop()
{
  int LineSensor4 = digitalRead(IR4);
  int LineSensor3 = digitalRead(IR3);
  int LineSensor2 = digitalRead(IR2);
  int LineSensor1 = digitalRead(IR1);

  if (LineSensor1 == LOW && LineSensor2 == HIGH && LineSensor3 == HIGH && LineSensor4 == LOW){
    forward();
    Serial.print("forward  n");
    }

  if (LineSensor1 == LOW && LineSensor2 == LOW && LineSensor3 == HIGH && LineSensor4 == LOW)
    rightzig();
    
  if (LineSensor1 == LOW && LineSensor2 == HIGH && LineSensor3 == LOW && LineSensor4 == LOW)
    leftzig();
  
  if (LineSensor4 = HIGH)
    right();

  // if (LineSensor3 == HIGH && LineSensor4 == HIGH){
  //   right();
  //   delay(50);
  // }
  if (LineSensor1 == HIGH)
    left();

  if (LineSensor1 == HIGH && LineSensor2 == HIGH){
    left();
    delay(50);
  }  
  if (LineSensor4 == HIGH && LineSensor3 == HIGH && LineSensor2 == HIGH && LineSensor1 == HIGH){
    rightalways();
    //delay(200);
  }

  // if(digitalRead(IR1)){
  //   Serial.println("Object not detected");
  //   digitalWrite(13,LOW);}
  // else{
  //   Serial.println("Object detected");
  //   digitalWrite(13,HIGH);}
    
}
void forward() {
  analogWrite (EN_R, speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );
}
void right() {
  analogWrite (EN_R, speed*0.6);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );
}
void forwardright() {
  analogWrite (EN_R, speed/3);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );  
}
void forwardleft() {
  analogWrite (EN_R, speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speed/3);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );  
}
void left() {
  analogWrite (EN_R, speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speed*0.6);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );
}
void rightzig() {
  analogWrite (EN_R, speedlow);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH );
      
  analogWrite(EN_L, speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );
}
void leftzig() {
  analogWrite (EN_R, speed);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speedlow);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH );
}
void rightalways() {
  analogWrite (EN_R, 0);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW );
      
  analogWrite(EN_L, speed);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW );
}




