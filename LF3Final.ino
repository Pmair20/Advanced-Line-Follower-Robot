#define rs 2            // Declaration for right sensor
#define ms 3            // Declaration for middle sensor     
#define ls 4            // Declaration for left sensor
#define rt 11           //(optional) right indicator
#define lt 13           //(optional) left indicator
#define lm1 6           // Declaration for left motor control
#define lm2 7
#define rm1 8           // Declaration for right motor control
#define rm2 9
int st = 10,i=0;        // The delay values will change based on your sensor so make sure you calibrate the sensors based on your track and your code
int d1,d2,d3;           // variables to take in the values from the sensor  
void setup() {
  // put your setup code here, to run once:
pinMode(rs,INPUT);
pinMode(ms,INPUT);                  // Sensors will give the input
pinMode(ls,INPUT);
pinMode(rt,OUTPUT);                 //(optional) INdicators will give output
pinMode(lt,OUTPUT);                 
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);                // Both the metors will generate output
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
Serial.begin(9600);
}

void Straight(){
  Serial.print("Straight");
  digitalWrite(rt,LOW);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);              // The motors will generate the rotation in forward direction
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(100);
}

void Stop(){
  Serial.print("Stop");
  digitalWrite(rt,LOW);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,LOW);              // The motors will remain stationary 
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(500);
}

void soft_left(){
  Serial.print("Soft Left");
  digitalWrite(lt,HIGH);
  digitalWrite(rt,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);             // The motors will turn softly in the left direction
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(st);
}

void soft_right(){
  Serial.print("Soft Right");
  digitalWrite(rt,HIGH);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);           // THe motors will turn softly in the right direction
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(st);
}
void sharp_right(){
  delay(1000);
  slow_for();
  Serial.print("Sharp Right");
  digitalWrite(rt,HIGH);
  digitalWrite(lt,LOW);             // THe motors will make a 90 degree right turn
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  delay(525);
  Stop();
}
void sharp_left(){
  delay(1000);
  slow_for();
  Serial.print("Sharp Left");
  digitalWrite(lt,HIGH);
  digitalWrite(rt,LOW);
  digitalWrite(lm1,LOW);           // The motors will make a 90 degree left turn
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(525);
  Stop();
}
void slow_for(){
  Serial.print("Slow Forward");
  digitalWrite(rt,LOW);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);           // This is used to align the bot on the track in case of 90 degree turn
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(525);
  Stop();
}

void loop() {
  // put your main code here, to run repeatedly:
d1=digitalRead(ls);
d2=digitalRead(ms);               // THe values from the infrared sensors are stored here
d3=digitalRead(rs);
Serial.print(d1);
Serial.print("\t");
Serial.print(d2);                 
Serial.print("\t");
Serial.println(d3);
if(d1==0 && d2==1 && d3==0){                   // This code will make the bot follow a black or a very dark line
  Straight();
}
else if(d1==1 && d2==1 && d3==0){
  soft_left();
}
else if(d1==0 && d2==1 && d3==1){
  soft_right();
}
else if(d1==1 && d2==1 && d3==1)
{
  i++;
  if(i==1){
    sharp_right();                         // YOu can insert your own turns here based on your choice,simply denote it with the increment variable i 
  }
  else if(i==2){
    sharp_left();
  }
  else{
    Stop();
  }
}
else 
  Stop();
}
