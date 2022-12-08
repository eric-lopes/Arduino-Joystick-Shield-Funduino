#include "Joystick.h"

//From the examples, creates a customised controller
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  6, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

//These pins are for my shield  
//digital
const int Button_A=2;
const int Button_B=3;
const int Button_C=4;
const int Button_D=5;
const int Button_E=6;
const int Button_F=7;
//analog
const int Axis_X=0;
const int Axis_Y=1;

void setup() {
  pinMode(Button_A,INPUT_PULLUP);
  pinMode(Button_B,INPUT_PULLUP);
  pinMode(Button_C,INPUT_PULLUP);
  pinMode(Button_D,INPUT_PULLUP);
  pinMode(Button_E,INPUT_PULLUP);
  pinMode(Button_F,INPUT_PULLUP);
  
  Joystick.begin(false); //autosend off
  Joystick.setXAxisRange(-127, 127);
  Joystick.setYAxisRange(-127, 127);
}


int Value_X=0,Value_Y=0;
void loop() {
  //Reads the analog values
  Value_X=analogRead(Axis_X)/2.5-127;
  Value_Y=-analogRead(Axis_Y)/2.5+127; //Value_Y inverted :/
  //Set the usb joypad Axis to the value read.
  Joystick.setXAxis(Value_X);
  Joystick.setYAxis(Value_Y);

  //Read each button(Arduino) and set buttons(USB) accordingly
  if(digitalRead(Button_A)==LOW){
    Joystick.setButton(0, 1);  
  }else{
    Joystick.setButton(0, 0);  
  }
  
  if(digitalRead(Button_B)==LOW){
    Joystick.setButton(1, 1);  
  }else{
    Joystick.setButton(1, 0);  
  }
  
  if(digitalRead(Button_C)==LOW){
    Joystick.setButton(2, 1);  
  }else{
    Joystick.setButton(2, 0);  
  }
  
  if(digitalRead(Button_D)==LOW){
    Joystick.setButton(3, 1);  
  }else{
    Joystick.setButton(3, 0);  
  }
  
  if(digitalRead(Button_E)==LOW){
    Joystick.setButton(4, 1);
  }else{
    Joystick.setButton(4, 0);  
  }
  
  if(digitalRead(Button_F)==LOW){
    Joystick.setButton(5, 1);  
  }else{
    Joystick.setButton(5, 0);  
  }

  //Report state thru USB
  Joystick.sendState();
  delay(10); 
}
