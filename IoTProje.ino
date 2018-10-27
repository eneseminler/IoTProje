const int trig = 10;
const int echo = 8;
const int echo2 = 9;

const int sol_i = 2;
const int sol_g = 3;
const int sag_i = 4;
const int sag_g = 5;

int sure = 0;
int mesafe = 0;
int sure2 = 0;
int mesafe2 = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(echo2, INPUT);
 pinMode(sol_i, OUTPUT);
 pinMode(sol_g, OUTPUT);
 pinMode(sag_i, OUTPUT);
 pinMode(sag_g, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 digitalWrite(trig, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trig ,LOW);

 sure = pulseIn(echo , HIGH);
 mesafe = (sure/2) / 28.5;
 Serial.println (mesafe);

  sure2 = pulseIn(echo2 , HIGH);
 mesafe2 = (sure2/2) / 28.5;
 Serial.println (mesafe2);

 
if ( mesafe < 30 && mesafe2 > 30)
{
  digitalWrite(sol_i ,HIGH);
  digitalWrite(sol_g ,LOW);
  digitalWrite(sag_i ,LOW);
  digitalWrite(sag_g ,LOW);
  //Sol Led yak
}
else if(mesafe > 30 && mesafe2 < 30)
{
 digitalWrite(sol_i , LOW);
 digitalWrite(sol_g , LOW);
 digitalWrite(sag_i , HIGH);
 digitalWrite(sag_g , LOW);
  //Sağ Led yak
}
else if(mesafe < 30 && mesafe2 < 30)
{  
 digitalWrite(sol_i , LOW);
 digitalWrite(sol_g , LOW);
 digitalWrite(sag_i , LOW);
 digitalWrite(sag_g , LOW);
  //Çift Led yak
}
else{
 digitalWrite(sol_i , HIGH);
 digitalWrite(sol_g , LOW);
 digitalWrite(sag_i , HIGH);
 digitalWrite(sag_g , LOW);
}
//İleri geri kodları
//Her harekette 3. led yak

}
