// C++ code
#define ENCA 2 // yellow
#define ENCB 3 // white
#define PWM 5 // white
#define IN2 6 // white
#define IN1 7 

int pos = 0;
long prevT = 0;
float eprev = 0;
float eintegral = 0;

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
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else if(dir == -1){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}


void setup()
{
  Serial.begin(9600);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  pinMode(PWM, OUTPUT);
  //analogWrite(PWM,180);
  //attachInterrupt(digitalPinToInterrupt(pinum), functionToCall, triggerType
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  

}

void loop()
{
  int a = digitalRead(ENCA);
  int b = digitalRead(ENCB);
  //set target position
  int target = 1200;
  
  //PID constants
  float kp = 1;
  float kd = 0;
  float ki = 0;
  
  //time difference
  long currT = micros();
  float deltaT = ((float)(currT-prevT))/1.0e6;
  prevT = currT;
  
  //error
  int e = pos-target;
  
  //derivative
  float dedt = (e-eprev)/(deltaT);
  
  //integral
  eintegral += e*deltaT;
  
  //control signal
  float u = kp*e + kd*dedt + ki*eintegral;
  
  //motor power
  float pwr = fabs(u);
  if(pwr>255){
    pwr = 255;
  }
  
  //motor direction
  int dir = 1;
  if(u<0){
  	dir = -1;	
  }
  
  //signal the motor
  setMotor(dir,pwr,PWM,IN1,IN2);
  
  //store previous error
  eprev = e;
  
  Serial.print(target);
  Serial.print(" ");
  Serial.print(pos);
  Serial.println();



}
