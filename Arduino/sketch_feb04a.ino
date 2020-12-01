#include<Servo.h>   //adding Servo library
Servo gate;
int EnterGateSensor = 3;
int y=0; 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
String sensor1; 
String sensor2; 
String sensor3; 
String cdata="";

// LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup()
{ 
 pinMode(A0,INPUT);
 pinMode(A2,INPUT);
  pinMode(A4,INPUT);
 pinMode(13,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(4,OUTPUT);

 gate.attach(7);
 pinMode(EnterGateSensor,INPUT);
 pinMode(ExitGateSensor,INPUT);
 Serial.begin(9600);

   
//  lcd.begin(16, 2);
//  
//  lcd.setCursor(0, 0);
//  lcd.print("Allez Si Brahim !!");
   
 } 
 
void loop()
{   
    slot1();
    slot2();
    slot3();
  
  cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 + ",";  
    // comma will be used a delimeter
   Serial.println(cdata); 
  
   
//    nodemcu.println(cdata);
   delay(2000); // 2 seconds
   cdata = "";
   //digitalWrite(6,LOW);
  // digitalWrite(7,LOW);
  // digitalWrite(13,LOW);
   

   
   int value=analogRead(A0);
   int value1=analogRead(A2);
   int value2=analogRead(A4);
   
   if(   !(digitalRead(gateSensor)) && digitalRead(slot1) && digitalRead(slot2))   //slot1 & slot2 empty
     {
      Serial.println("Welcome, Available: sLOT1, sLOT2");  //print slot1 and slo2 available
      digitalWrite(slot1_l,HIGH);
      digitalWrite(slot2_l,HIGH);
      delay(1000);
      digitalWrite(gate_grn,HIGH);
      gate.write(75); //gate will open after the dealy of 1 second
     }
  
   delay(500);
    if(value1>900){
    digitalWrite(4,LOW);
   
   }
   else{
     digitalWrite(4,HIGH);
   }
  
    if(value>900){
    digitalWrite(13,LOW);
   
   }
   else{
     digitalWrite(13,HIGH);
     delay(200);  
   }

   
   if(value2>900){
    digitalWrite(7,LOW);
   
   }
   else{
     digitalWrite(7,HIGH);
   }

   
   
}
 void slot3(){
      if(digitalRead(7)==LOW){
    
     sensor3 = "3FF";  
     delay(200);  
   
   }
   if(digitalRead(7)==HIGH){
     sensor3 = "3NN";
     delay(200);  
   }
      
      }

 void slot1(){
    if(digitalRead(4)==LOW){
    
     sensor1 = "1FF";  
     delay(200);  
   
   }
   if(digitalRead(4)==HIGH){
     sensor1 = "1NN";
    
    }
   
   }
       void slot2(){
  if(digitalRead(13)==LOW){
    
     sensor2 = "2FF";  
     delay(200);  
   
   }
    if(digitalRead(13)==HIGH){
     sensor2 = "2NN";
     delay(200);  
   }
  }
