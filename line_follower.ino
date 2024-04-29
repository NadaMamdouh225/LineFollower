
int IN1= 2 ; int IN2 = 4; int  ENA = 3;   // right motor
int IN3= 7 ; int IN4 = 8; int  ENB = 6;   // left motor
int C ; int R; int L; int SR; int SL;     // sensors

#define MOTORSPEED    150

void setup() {
  Serial.begin(9600);
  // Set Motor pins mode to output
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  //sensors pins
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(13,INPUT);
  pinMode(6,INPUT);
  pinMode(10,INPUT);

}

void loop() {
  R  = digitalRead(11);      
  C  = digitalRead(13);         
  L  = digitalRead(9);
  SL = digitalRead(12);       
  SR = digitalRead(10); 
       
/* // For debug
   Serial.print("R_Sensor: ");
   Serial.print(R);
   Serial.print("  C_Sensor: ");
   Serial.print(C);
   Serial.print("  L_Sensor: ");
   Serial.println(L);
   Serial.print("  SL_Sensor: ");
   Serial.println(SL);
   Serial.print("SR_Sensor: ");
   Serial.println(SR);
   //Forward(100,100);
   delay(400);*/

  if (SL == 0 && SR == 0 && C == 1 && R== 0 && SR== 0)
  {
    Forward(MOTORSPEED+20,MOTORSPEED+20);         //forward
   }
   else if (SL == 0 && L == 1 && C == 0 && R == 0 && SR == 0 ) 
   {
     Forward(MOTORSPEED,MOTORSPEED+50) ;          //slight left
   }
   else if (SL == 1 && L == 1 && C == 0 && R == 0 && SR == 0) 
   {
      Forward(MOTORSPEED-30,MOTORSPEED+50) ;      //slight left +
   }
   else if (SL == 0 && L == 0 && C == 0 && R == 1 && SR == 0 ) 
   {
     Forward(MOTORSPEED+50,MOTORSPEED) ;          //slight right
   }
   else if (SL ==  0 && L== 0 &&  C== 0 && SR == 1 && R==1)
   {
      Forward(MOTORSPEED+50,MOTORSPEED-30) ;      //slight right +
   }
   else if((SL == 1 && L== 0 &&  C== 0 && SR == 0 && R==0)) 
   {
     TurnLeft(MOTORSPEED-45,MOTORSPEED+75) ;      // significant left

   }
   else if((SL == 0 && L == 0 && C == 0 && R == 0 && SR == 1 ))
   {
      TurnRight(MOTORSPEED+75,MOTORSPEED-45) ;    // significant right
   }
  
}
void Motor_Stop(void)
{
  analogWrite(ENA,0); 
  analogWrite(ENB,0);
}
void Forward(int LMotorSpeed,int RMotorSpeed)
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,RMotorSpeed);
  analogWrite(ENA,LMotorSpeed);
}
void TurnLeft(int LMotorSpeed,int RMotorSpeed)
{
  //left motor => move backward
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,LMotorSpeed);
  
// right Motor => move forward
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,RMotorSpeed);
}
void TurnRight(int LMotorSpeed,int RMotorSpeed)
{
  //left motor => move forward
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,LMotorSpeed);
  
  // right motor => move backward
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,RMotorSpeed);
}
