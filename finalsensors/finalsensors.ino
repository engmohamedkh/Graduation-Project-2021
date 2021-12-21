/*
   -- xxxxxx --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.6 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.7.12 or later version;
     - for iOS 1.4.7 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,0,0,64,0,11,161,0,
  1,0,2,25,24,24,8,31,83,116,
  97,114,116,0,1,0,36,27,23,23,
  8,31,77,101,100,0,1,0,70,28,
  23,23,24,31,72,105,103,104,0,129,
  0,24,2,54,8,1,80,97,116,99,
  104,32,67,111,110,116,114,111,108,32,
  0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t Start; // =1 if button pressed, else =0 
  uint8_t MED; // =1 if button pressed, else =0 
  uint8_t high; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_START 12
#define PIN_MED 11
#define PIN_HIGH 10

#define trigpin 7  
#define echopin 6


int led1 = A0; 
int led2 = A1; 
int led3 = A2;

int value=0;
float voltage;

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_START, OUTPUT);
  pinMode (PIN_MED, OUTPUT);
  pinMode (PIN_HIGH, OUTPUT);


Serial.begin(9600);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);


   digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_START, (RemoteXY.Start==0)?LOW:HIGH);
  digitalWrite(PIN_MED, (RemoteXY.MED==0)?LOW:HIGH);
  digitalWrite(PIN_HIGH, (RemoteXY.high==0)?LOW:HIGH);



    int duration, distance;
 digitalWrite(trigpin, HIGH);
 
delayMicroseconds(1000);  
digitalWrite(trigpin, LOW);
 
 
duration = pulseIn(echopin,HIGH);
 
distance = ( duration / 2) / 29.1;
Serial.println("cm:"); 
Serial.println(distance);
 
 
if(   (distance <= 10) &&(distance>0)   ) 
{
  digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH); 
      digitalWrite(led3, HIGH); 
 
  Serial.println("highlevel");
}

else
if(   (distance <= 14) && (distance>10)&& (distance>0)  ) 
{
 
digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);

 digitalWrite(led3, HIGH); 
     Serial.println("midlevel");

 
} else
 
if(  (distance > 13) && (distance<=17) && (distance>0)  ) 
 
{
 
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
   Serial.println("lowlevel");

} else
if(distance>18  && (distance>0)&& (distance<21))
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
   Serial.println("nolevel");

  }
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 

delay(2000);
}
