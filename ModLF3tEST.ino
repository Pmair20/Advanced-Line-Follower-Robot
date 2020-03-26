#define rs 2
#define ms 3
#define ls 4
#define rt 11
#define lt 13
#define lm1 6
#define lm2 7
#define rm1 8
#define rm2 9
int st = 10,i=0;
int d1,d2,d3;
void setup() {
  // put your setup code here, to run once:
pinMode(rs,INPUT);
pinMode(ms,INPUT);
pinMode(ls,INPUT);
pinMode(rt,OUTPUT);
pinMode(lt,OUTPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
Serial.begin(9600);
}

void Straight(){
  Serial.print("Straight");
  digitalWrite(rt,LOW);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(100);
}

void Stop(){
  Serial.print("Stop");
  digitalWrite(rt,LOW);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,LOW);
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
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(st);
}

void soft_right(){
  Serial.print("Soft Right");
  digitalWrite(rt,HIGH);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(st);
}
void sharp_right(){
  slow_for();
  Serial.print("Sharp Right");
  digitalWrite(rt,HIGH);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  delay(510);
  Stop();
}
void sharp_left(){
  slow_for();
  Serial.print("Sharp Left");
  digitalWrite(lt,HIGH);
  digitalWrite(rt,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(510);
  Stop();
}
void slow_for(){
  Stop();
  Serial.print("Slow Forward");
  digitalWrite(rt,LOW);
  digitalWrite(lt,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(410);
  Stop();
}

void loop() {
  // put your main code here, to run repeatedly:
d1=digitalRead(ls);
d2=digitalRead(ms);
d3=digitalRead(rs);
Serial.print(d1);
Serial.print("\t");
Serial.print(d2);
Serial.print("\t");
Serial.println(d3);
if(d1==0 && d2==1 && d3==0){
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
    sharp_right();
  }
  else if(i==2){
    sharp_right();
  }
  else if(i==3){
    sharp_right();
  }
  else if(i==4){
    sharp_left();
  }
  else{
    Stop();
  }
}
else 
  Stop();
}
