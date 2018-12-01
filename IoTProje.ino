const int trig = 4;
const int echo = 3;
const int trig2 = 5;
const int echo2 = 6;

const int led = 2;
const int led2 = 7;

const int sol_g = 9;
const int sol_i = 8;
const int sag_i = 12;
const int sag_g = 13;

long sure = 0;
long mesafe = 0;
long sure2 = 0;
long mesafe2 = 0;

char msj;
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


msj = Serial.read();   // seri mesaji msj değişkenine aktardık

 digitalWrite(trig, HIGH);
 delayMicroseconds(150);
 digitalWrite(trig ,LOW);
 
 sure = pulseIn(echo , HIGH);
 mesafe = (sure/2) / 29.1;
 
 delayMicroseconds(150);
 
 digitalWrite(trig2, HIGH);
 delayMicroseconds(150);
 digitalWrite(trig2,LOW);
 
 sure2 = pulseIn(echo2 , HIGH);
 mesafe2 = (sure2/2) / 29.1;


// Serial.println (mesafe);
 
 //Serial.println (mesafe2);
 

if(mesafe < 30 && mesafe2 > 30 && msj == '1')
{  
 digitalWrite(led ,HIGH);


 digitalWrite(sag_i , HIGH);
 digitalWrite(sol_i ,LOW );
 digitalWrite(sag_g , LOW);
 digitalWrite(sol_g , HIGH);
 
}
else if(mesafe > 30 && mesafe2 < 30 && msj == '1')
{
    digitalWrite(led2 ,HIGH);
 // digitalWrite(led2 ,LOW);
  digitalWrite(sol_i , HIGH);
  digitalWrite(sol_g , LOW);
  digitalWrite(sag_i , LOW);
  digitalWrite(sag_g , HIGH);
}

 
else if (mesafe < 30 && mesafe2 < 30 && msj == '1')
{
  digitalWrite(led ,HIGH);
  digitalWrite(led2 ,HIGH);
  
  digitalWrite(sol_i ,LOW);
  digitalWrite(sol_g ,LOW);
  digitalWrite(sag_i ,LOW);
  digitalWrite(sag_g ,LOW);
}
else if(mesafe > 30 && mesafe2 > 30 && msj == '1'){
 
 digitalWrite(sag_i , HIGH);
 digitalWrite(sol_i ,HIGH );
 digitalWrite(sag_g , LOW);
 digitalWrite(sol_g , LOW);
  digitalWrite(led ,LOW);
  digitalWrite(led2 ,LOW);
}
 
//if(msj == '1'){                    // gelen veri 1 ise led1 i yak
//
//    digitalWrite(sag_i , HIGH);
// digitalWrite(sol_i ,HIGH );
// digitalWrite(sag_g , HIGH);
// digitalWrite(sol_g , HIGH);
// delay(2500);
//    
//  }
//  if(msj == '2'){                   // gelen veri 2 ise led1 i kapat
// digitalWrite(sag_i , LOW);
// digitalWrite(sol_i ,HIGH );
// digitalWrite(sag_g , HIGH);
// digitalWrite(sol_g , LOW);
//  }
//İleri geri kodları
//Her harekette 3. led yak
}
