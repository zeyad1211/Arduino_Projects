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
  	digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    int start = millis();
    while(pos < position){
      Serial.println("GOING TO POS");
    }
    int finishTime = millis() - start;
    digitalWrite(IN2, LOW);
    Serial.print("Finished in: ");
    Serial.println(finishTime);
  }
  else if(position < pos){
  	digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
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
  analogWrite(PWM, 180);
  //attachInterrupt(digitalPinToInterrupt(pinum), functionToCall, triggerType
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  

}
float checkSpeed(int ms)
{
  float speed;
  float timeInSec = ms/1000;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  int start = millis();
  while(millis()-start < ms){
  	Serial.println("running");
  }
  digitalWrite(IN1, LOW);
  Serial.println(pos);
  speed = float(pos/timeInSec)*float(60.0/225.0);
  return speed;
  
}
void loop()
{
  int a = digitalRead(ENCA);
  int b = digitalRead(ENCB);
 // Serial.print(a);
//Serial.print(" ");
 // Serial.print(b);
//  Serial.println();
  // Serial.println(pos);
//  int time = millis();
// setMotor(1, 20, PWM, IN1, IN2);
//  if(time >= 1000){
  //	Serial.print("second completed: ");
    //Serial.println(pos);
  //	goToPos(180);
  //	delay(1000);
 float RevPerMin;
 RevPerMin = checkSpeed(10000);
  
 Serial.print("the speed of the motor in RPM is: ");
 Serial.println(RevPerMin);
 delay(5000);
  //}
}
