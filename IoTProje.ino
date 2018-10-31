const int trig = 11;
const int echo = 10;
const int trig2 = 13;
const int echo2 = 12;

const int led = 9;
const int led2 = 8;

const int sol_i = 2;
const int sol_g = 3;
const int sag_i = 4;
const int sag_g = 5;

long sure = 0;
long mesafe = 0;
long sure2 = 0;
long mesafe2 = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(trig, OUTPUT);
 pinMode(trig2, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(echo2, INPUT);
 pinMode(sol_i, OUTPUT);
 pinMode(sol_g, OUTPUT);
 pinMode(sag_i, OUTPUT);
 pinMode(sag_g, OUTPUT);
 pinMode(led, OUTPUT);
 pinMode(led2, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 digitalWrite(trig, HIGH);
 delayMicroseconds(30);
 digitalWrite(trig ,LOW);
 
 sure = pulseIn(echo , HIGH);
 mesafe = (sure/2) / 28.5;
 Serial.println (mesafe);
 
 delayMicroseconds(30);
 
 digitalWrite(trig2, HIGH);
 delayMicroseconds(30);
 digitalWrite(trig2,LOW);
 
 sure2 = pulseIn(echo2 , HIGH);
 mesafe2 = (sure2/2) / 28.5;
 Serial.println (mesafe2);

 
if (mesafe < 30 && mesafe2 < 30)
{
    
  delay(100);
  digitalWrite(led ,HIGH);
  delay(50);
  digitalWrite(led2 ,HIGH);
  delay(250);
  digitalWrite(led ,LOW);
  delay(50);
  digitalWrite(led2 ,LOW);

  digitalWrite(sol_i ,LOW);
  digitalWrite(sol_g ,LOW);
  digitalWrite(sag_i ,LOW);
  digitalWrite(sag_g ,LOW);
}
else if(mesafe > 30 && mesafe2 < 30)
{
  digitalWrite(led2 ,HIGH);
  delay(250);
  digitalWrite(led2 ,LOW);

 digitalWrite(sol_i , LOW);
 digitalWrite(sol_g , HIGH);
 digitalWrite(sag_i , HIGH);
 digitalWrite(sol_g , LOW);
 digitalWrite(sag_g , LOW);
 digitalWrite(sag_i , LOW);
 
 
}
else if(mesafe < 30 && mesafe2 > 30)
{  
 digitalWrite(led ,HIGH);
 delay(250);
 digitalWrite(led ,LOW);
 
 digitalWrite(sol_i , HIGH);
 digitalWrite(sol_g , LOW);
 digitalWrite(sag_i , LOW);
 digitalWrite(sag_g , HIGH);
 digitalWrite(sag_g , LOW);
 digitalWrite(sol_i , LOW);
 

}
else{
 digitalWrite(sol_i , HIGH);
 digitalWrite(sol_g , LOW);
 digitalWrite(sag_i , HIGH);
 digitalWrite(sag_g , LOW);
  digitalWrite(led ,LOW);
  digitalWrite(led2 ,LOW);
  
}
//İleri geri kodları
//Her harekette 3. led yak

}
