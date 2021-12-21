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
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,0,0,101,0,11,161,0,
  1,0,7,32,24,24,8,31,83,116,
  97,114,116,0,1,0,39,32,23,23,
  8,31,77,101,100,0,1,0,72,32,
  23,23,24,31,72,105,103,104,0,129,
  0,9,21,16,7,2,83,116,97,114,
  116,0,129,0,42,20,18,8,2,77,
  101,100,32,0,129,0,75,20,16,7,
  2,72,105,103,104,0,129,0,24,2,
  54,8,1,66,97,116,99,104,32,67,
  111,110,116,114,111,108,32,0 };
  
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


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_START, OUTPUT);
  pinMode (PIN_MED, OUTPUT);
  pinMode (PIN_HIGH, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_START, (RemoteXY.Start==0)?LOW:HIGH);
  digitalWrite(PIN_MED, (RemoteXY.MED==0)?LOW:HIGH);
  digitalWrite(PIN_HIGH, (RemoteXY.high==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
