// C++ code
#define ENCA 2 // yellow
#define ENCB 3 // white
#define PWM 5 // white
#define IN2 6 // white
#define IN1 7 

int pos = 0;
void readEncoder(){
  int b = digitalRead(ENCB);
  if(b>0){
    pos++;
  }
  else{
    pos--;
  }
}
void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
void goToPos(int position){
  if(position > pos){
  	digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    int start = millis();
    while(pos < position){
      Serial.println("GOING TO POS");
    }
    int finishTime = millis() - start;
    digitalWrite(IN1, LOW);
    Serial.print("Finished in: ");
    Serial.println(finishTime);
  }
  else if(position < pos){
  	digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  else{
  	digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  pinMode(PWM, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(pinum), functionToCall, triggerType
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  

}

void loop()
{
//  int a = digitalRead(ENCA);
 // int b = digitalRead(ENCB);
 // Serial.print(a);
//Serial.print(" ");
 // Serial.print(b);
 // Serial.println();
   Serial.println(pos);
//  int time = millis();
 // setMotor(1, 20, PWM, IN1, IN2);
//  if(time >= 1000){
  //	Serial.print("second completed: ");
    //Serial.println(pos);
  	goToPos(180);
  	delay(1000);
  
  //}
}