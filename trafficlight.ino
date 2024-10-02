// working code
#define gtime 5000
#define ytime 1500
#define rtime 2000
unsigned long currentTime = 0;
unsigned long startTime = 0;

int IR1 = 0, IR2 = 0, IR3 = 0, IR4 = 0;
int IRdata[4]; 
int green = 13;
int yellow = 12;
int red = 11;
bool redOff = 1;
bool yellowOff = 1;
bool greenOff = 1;
int cycledone = 0;
int pins[] = {9,8,10,7,6,5,4,3,2,11,12,13};

void runcycle(int x);
void updatesensors(int i);


void setup(){
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  for(int i = 0; i < 12; i++){
  	pinMode(pins[i], OUTPUT);
  }
}

void loop(){
  currentTime = millis();
  if(redOff && yellowOff){
    cycledone = 0;
 	  digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    greenOff = 0;
    if(currentTime - startTime >= gtime){
 	    digitalWrite(green, LOW);
      greenOff = 1;
      startTime = currentTime;
    }
  }
  if(redOff && greenOff){
    cycledone = 0;
    digitalWrite(yellow, HIGH);
    yellowOff = 0;
    if(currentTime - startTime >= ytime){
      digitalWrite(yellow, LOW);
      yellowOff = 1;
      startTime = currentTime;
    }
  }
  if(greenOff && yellowOff){
    cycledone = 1;
    digitalWrite(red, HIGH);
    redOff = 0;
    if(currentTime - startTime >= rtime){
      redOff = 1;
      startTime = currentTime;
      green -= 3; yellow -= 3; red -= 3;
      if (green == 1){
        green = 13; yellow = 12; red = 11;
      }
    }
  }
  switch (green){
    case 13:
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(2, HIGH);
      break;
    case 10:
      digitalWrite(11, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(2, HIGH);
      break;
    case 7:
      digitalWrite(8, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(2, HIGH);
      break;
    case 4:
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(11, HIGH);
      break;
	}
  
  for(int i = 0;i < 4; i++){
   	updatesensors(i);
    if(IRdata[i] ==  0){
       continue;
    }
    else{
      if(cycledone == 1){
      	runcycle(i);
      }
    }
  }
}

void runcycle(int x){
  switch(x){
    case 0:
    green = 13;
    yellow = 12;
    red = 11;
    break;
    case 1:
    green = 10;
    yellow = 9;
    red = 8;      
    break;
    case 2:
    green = 7;
    yellow = 6;
    red = 5;
    break;
    case 3:
    green = 4;
    yellow = 3;
    red = 2;
    break;   		
  }
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    delay(gtime);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(ytime);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(rtime);
}
void updatesensors(int i){
    IR1 = digitalRead(A1);
    IR2 = digitalRead(A2);
    IR3 = digitalRead(A3);
    IR4 = digitalRead(A4); 
    switch(i){
      case 0:
      	IRdata[0] = IR1;
      	break;
      case 1:
      	IRdata[1] = IR2;
      	break;
      case 2:
      	IRdata[2] = IR3;
      	break;
      case 3:
      	IRdata[3] = IR4;
      	break;
    }
}