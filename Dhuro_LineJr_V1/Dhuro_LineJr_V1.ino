#include <EEPROM.h>
#include <Servo.h>

#define ff    0
#define FF    0
#define fl    1
#define FL    1
#define fr    2
#define FR    2
#define fl2   3
#define FL2   3
#define fr2   4
#define FR2   4
#define fl3   5
#define FL3   5
#define fr3   6
#define FR3   6

#define s0  1
#define s1  3
#define s2  5
#define s3  11
#define s4  13
#define s5  17
#define s6  19
#define s7  23

#define black 1
#define BLACK 1
#define white 0
#define WHITE 0

#define pin_button_ok 12 
#define pin_button_plus 11 
#define pin_button_minus 8

#define PUSH_BUTTON_OK_IS_PRESSED    digitalRead(pin_button_ok) == LOW
#define PUSH_BUTTON_PLUS_IS_PRESSED  digitalRead(pin_button_plus) == LOW
#define PUSH_BUTTON_MINUS_IS_PRESSED digitalRead(pin_button_minus) == LOW

int line_color = black;

void linecolor(int linecolor){
  if(linecolor == black)  line_color = black;
  if(linecolor == white)  line_color = white;
}

//PID Controller Parameter Declaration
float kp, ki, kd, PID,
      error,
      d_error,
      i_error,
      last_error,
      T_sampling = 10,
      time_sampling;
      
//int PID, 
//    error, 
//    last_error, 
//    T_sampling = 10;

unsigned long time,
              current_time,
              prev_time;
    
int out_led       = 13;
int sel_led[3]    = {4, 2, 3};
int in_sensor     = A0;
int sel_sensor[3] = {A1, A2, A3};
//int pin_button_ok   = 12, 
//    pin_button_plus = 11, 
//    pin_button_minus  = 8;
int pin_motor_left_a  = 10, 
    pin_motor_left_b  = 9;
int pin_motor_right_a = 6,  
    pin_motor_right_b = 5;
int bar_led[8]={0,0,0,0,0,0,0,0};

int adc_putih[8]  = {255,255,255,255,255,255,255,255};
int adc_hitam[8]  = {1,1,1,1,1,1,1,1};
int adc_tengah[8] = {1,1,1,1,1,1,1,1};
int adc_sensor[8], hasil_sensor[8];
int color = black;
int sensorbin;
int menu = 0, pilih;

void setup(){
  Serial.begin(9600);
  
  pinMode(out_led, OUTPUT);  for(int i = 0; i < 4; i++){pinMode(sel_led[i], OUTPUT);}
  pinMode(in_sensor, INPUT); for(int i = 0; i < 4; i++){pinMode(sel_sensor[i], OUTPUT);}
  
  pinMode(pin_button_ok,    INPUT_PULLUP);
  pinMode(pin_button_plus,  INPUT_PULLUP);
  pinMode(pin_button_minus, INPUT_PULLUP);
  
  pinMode(pin_motor_left_a, OUTPUT);  
  pinMode(pin_motor_left_b, OUTPUT);
  pinMode(pin_motor_right_a, OUTPUT); 
  pinMode(pin_motor_right_b, OUTPUT);
  
  time_sampling = (float)T_sampling/1000;
}

void loop(){
  while(menu == 0){homescreen();}
  while(menu == 1){setPathPlan(); stop_end();}
  while(menu == 2){sensorCalibration();}
  while(menu == 3){displayBinarySensor();}
}

void running_led(int delayled){
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led0
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led1
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led2
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led3
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led4
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led5
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led6
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led7
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led6
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led5
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led4
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0], HIGH);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led3
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led2
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1], HIGH);  digitalWrite(sel_led[2],  LOW);    delay(delayled); //led1
  digitalWrite(out_led, HIGH);  digitalWrite(sel_led[0],  LOW);   digitalWrite(sel_led[1],  LOW);  digitalWrite(sel_led[2], HIGH);    delay(delayled); //led0
}

void ledbar0(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0],  LOW); digitalWrite(sel_led[1],  LOW); digitalWrite(sel_led[2], HIGH); delay(1);} //led0
void ledbar1(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0],  LOW); digitalWrite(sel_led[1], HIGH); digitalWrite(sel_led[2],  LOW); delay(1);} //led1
void ledbar2(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0],  LOW); digitalWrite(sel_led[1], HIGH); digitalWrite(sel_led[2], HIGH); delay(1);} //led2
void ledbar3(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0], HIGH); digitalWrite(sel_led[1],  LOW); digitalWrite(sel_led[2],  LOW); delay(1);} //led3
void ledbar4(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0], HIGH); digitalWrite(sel_led[1], HIGH); digitalWrite(sel_led[2], HIGH); delay(1);} //led4
void ledbar5(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0],  LOW); digitalWrite(sel_led[1],  LOW); digitalWrite(sel_led[2],  LOW); delay(1);} //led5
void ledbar6(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0], HIGH); digitalWrite(sel_led[1],  LOW); digitalWrite(sel_led[2], HIGH); delay(1);} //led6
void ledbar7(bool on){digitalWrite(out_led, on);  digitalWrite(sel_led[0], HIGH); digitalWrite(sel_led[1], HIGH); digitalWrite(sel_led[2],  LOW); delay(1);} //led7

void ledbarSet(int led0, int led1, int led2, int led3, int led4, int led5, int led6, int led7){
  ledbar0(led0);
  ledbar1(led1);
  ledbar2(led2);
  ledbar3(led3);
  ledbar4(led4);
  ledbar5(led5);
  ledbar6(led6);
  ledbar7(led7);
}

void readAnalogSensor(){
  digitalWrite(sel_sensor[0], HIGH);   digitalWrite(sel_sensor[1], HIGH);  digitalWrite(sel_sensor[2], HIGH);   adc_sensor[0] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0],  LOW);   digitalWrite(sel_sensor[1], HIGH);  digitalWrite(sel_sensor[2], HIGH);   adc_sensor[1] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0],  LOW);   digitalWrite(sel_sensor[1],  LOW);  digitalWrite(sel_sensor[2], HIGH);   adc_sensor[2] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0], HIGH);   digitalWrite(sel_sensor[1],  LOW);  digitalWrite(sel_sensor[2], HIGH);   adc_sensor[3] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0],  LOW);   digitalWrite(sel_sensor[1], HIGH);  digitalWrite(sel_sensor[2],  LOW);   adc_sensor[4] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0], HIGH);   digitalWrite(sel_sensor[1], HIGH);  digitalWrite(sel_sensor[2],  LOW);   adc_sensor[5] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0],  LOW);   digitalWrite(sel_sensor[1],  LOW);  digitalWrite(sel_sensor[2],  LOW);   adc_sensor[6] = analogRead(in_sensor);
  digitalWrite(sel_sensor[0], HIGH);   digitalWrite(sel_sensor[1],  LOW);  digitalWrite(sel_sensor[2],  LOW);   adc_sensor[7] = analogRead(in_sensor);
  for(int i = 0; i < 8; i++){adc_sensor[i] = map(adc_sensor[i],0,1023,0,255);}
}

void sensorCalibration(){
  readAnalogSensor();
  for(int i = 0; i < 8; i++){
    if(adc_sensor[i] > adc_hitam[i]) adc_hitam[i] = adc_sensor[i];
    if(adc_sensor[i] < adc_putih[i]) adc_putih[i] = adc_sensor[i];
    adc_tengah[i] = adc_putih[i] + (adc_hitam[i] - adc_putih[i]) / 2;
    if(adc_sensor[i] > adc_tengah[i]) hasil_sensor[i] = 1;
    if(adc_sensor[i] < adc_tengah[i]) hasil_sensor[i] = 0;
  }
  
  if(hasil_sensor[0] == 1){ledbar0(0);} else{ledbar0(1);} 
  if(hasil_sensor[1] == 1){ledbar1(0);} else{ledbar1(1);}
  if(hasil_sensor[2] == 1){ledbar2(0);} else{ledbar2(1);} 
  if(hasil_sensor[3] == 1){ledbar3(0);} else{ledbar3(1);}
  if(hasil_sensor[4] == 1){ledbar4(0);} else{ledbar4(1);} 
  if(hasil_sensor[5] == 1){ledbar5(0);} else{ledbar5(1);}
  if(hasil_sensor[6] == 1){ledbar6(0);} else{ledbar6(1);} 
  if(hasil_sensor[7] == 1){ledbar7(0);} else{ledbar7(1);}
  
  while(PUSH_BUTTON_OK_IS_PRESSED){for(int i = 0; i < 8; i++){EEPROM.update(i, adc_tengah[i]); delay(5); menu = 0;}}
}

void displayBinarySensor(){
  readAnalogSensor();
  for (int i = 0; i < 8; i++){
    if (adc_sensor[i] > EEPROM.read(i))  hasil_sensor[i] = 1;
    if (adc_sensor[i] < EEPROM.read(i))  hasil_sensor[i] = 0;
  }
  
  if(hasil_sensor[0] == 1){ledbar0(0);} else{ledbar0(1);} 
  if(hasil_sensor[1] == 1){ledbar1(0);} else{ledbar1(1);}
  if(hasil_sensor[2] == 1){ledbar2(0);} else{ledbar2(1);} 
  if(hasil_sensor[3] == 1){ledbar3(0);} else{ledbar3(1);}
  if(hasil_sensor[4] == 1){ledbar4(0);} else{ledbar4(1);} 
  if(hasil_sensor[5] == 1){ledbar5(0);} else{ledbar5(1);}
  if(hasil_sensor[6] == 1){ledbar6(0);} else{ledbar6(1);} 
  if(hasil_sensor[7] == 1){ledbar7(0);} else{ledbar7(1);}
  while(PUSH_BUTTON_OK_IS_PRESSED)  {delay(5); menu = 0;}
}

void readBinarySensor(){
  if(color == black){
    readAnalogSensor();
    for (int i = 0; i < 8; i++){
      readAnalogSensor();
      if (adc_sensor[i] > EEPROM.read(i))  hasil_sensor[i] = 1;
      if (adc_sensor[i] < EEPROM.read(i))  hasil_sensor[i] = 0;
    }
  }
  
  if(color == white){
    readAnalogSensor();
    for (int i = 0; i < 8; i++){
      readAnalogSensor();
      if (adc_sensor[i] > EEPROM.read(i))  hasil_sensor[i] = 0;
      if (adc_sensor[i] < EEPROM.read(i))  hasil_sensor[i] = 1;
    }
  }
  
  sensorbin = (hasil_sensor[0] * 1) + 
              (hasil_sensor[1] * 2) + 
              (hasil_sensor[2] * 4) + 
              (hasil_sensor[3] * 8) + 
              (hasil_sensor[4] * 16) + 
              (hasil_sensor[5] * 32) + 
              (hasil_sensor[6] * 64) + 
              (hasil_sensor[7] * 128);
              
  if(hasil_sensor[0] == 1){ledbar0(0);} else{ledbar0(1);} 
  if(hasil_sensor[1] == 1){ledbar1(0);} else{ledbar1(1);}
  if(hasil_sensor[2] == 1){ledbar2(0);} else{ledbar2(1);} 
  if(hasil_sensor[3] == 1){ledbar3(0);} else{ledbar3(1);}
  if(hasil_sensor[4] == 1){ledbar4(0);} else{ledbar4(1);} 
  if(hasil_sensor[5] == 1){ledbar5(0);} else{ledbar5(1);}
  if(hasil_sensor[6] == 1){ledbar6(0);} else{ledbar6(1);} 
  if(hasil_sensor[7] == 1){ledbar7(0);} else{ledbar7(1);}
}

void lineTrace(int speed){
  int spr, spl;
  readBinarySensor();
  switch(sensorbin){
    case 0b00000001: error = 12;  break;
    case 0b00000011: error = 10;  break;
    case 0b00000010: error = 8;   break;
    case 0b00000110: error = 6;   break;
    case 0b00000100: error = 4;   break;
    case 0b00001100: error = 2;   break;
    case 0b00001000: error = 1;   break;
    case 0b00011000: error = 0;   break;
    case 0b00010000: error = -1;  break;
    case 0b00110000: error = -2;  break;
    case 0b00100000: error = -4;  break;
    case 0b01100000: error = -6;  break;
    case 0b01000000: error = -8;  break;
    case 0b11000000: error = -10; break;
    case 0b10000000: error = -12; break;
  }
  
  // kp = 8, ki = 0, kd = 0.05; //speed 5,6,7
  // kp = 9, ki = 0, kd = 0.05; //speed 8,9,10
  // kp = 20, ki = 0, kd = 0.2; //speed 11,12,13
  // kp = 20, ki = 0, kd = 0.25; //speed 14,15,16
  // kp = 23, ki = 0, kd = 0.5; //speed 17,18,19,20
  time = millis();
  i_error = i_error + ((float)error * time_sampling);
  d_error = ((float)(error - last_error)) / time_sampling;
  
  PID = ((float)error * kp) + (d_error * kd) + (i_error * ki);
  
  spr = speed - PID;
  spl = speed + PID;
  
  if(spl > 255)  {spl = 255;} else if(spl < -255)  {spl = -255;}
  if(spr > 255)  {spr = 255;} else if(spr < -255)  {spr = -255;}
  
  call_motor(spl,spr);
  last_error = error;
}

int pwm_conv(int val){
    if (val > 20) val = 20;
    else if (val < -20) val = -20;
    
    val = map(val, -20, 20, -255, 255);
    
    return val;
}

void call_motor(int vl, int vr){
    if(vl < 0)      {analogWrite(pin_motor_left_a, 0);    analogWrite(pin_motor_left_b,vl * -1);}
    else if(vl > 0) {analogWrite(pin_motor_left_a,vl);    analogWrite(pin_motor_left_b,  0);}
    else            {analogWrite(pin_motor_left_a, 0);    analogWrite(pin_motor_left_b,  0);}

    if(vr < 0)      {analogWrite(pin_motor_right_a, 0);   analogWrite(pin_motor_right_b,vr * -1);}
    else if(vr > 0) {analogWrite(pin_motor_right_a,vr);   analogWrite(pin_motor_right_b,  0);}
    else            {analogWrite(pin_motor_right_a, 0);   analogWrite(pin_motor_right_b,  0);}
}

void drive_motor(int vl, int vr){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
}

void motor(int vl, int vr, int timer, int vbreaktime){
  vbreaktime = map_brake_value(vbreaktime);
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr); delay(timer);
  call_motor(-vl,-vr); delay(vbreaktime);
  call_motor(0,0);
}

int map_brake_value(int vbreaktime){
  if (vbreaktime > 20)vbreaktime = 20;
  else if (vbreaktime < -20)vbreaktime = -20;
  vbreaktime = map(vbreaktime,-20,20,-500,500);
  return vbreaktime;
}

void stop_end(){
    call_motor(0,0);
    while(1);
}

void execute(int v_speed){
  current_time = millis();
  if(current_time - prev_time >= T_sampling)  {lineTrace(v_speed);  prev_time = current_time;}
}

void homescreen(){
  switch(pilih){
    case 0: 
      pilih = 1; 
    break;

    // run path planning
    case 1:
      ledbar0(1); 
      ledbar1(1); 
      ledbar2(1); 
      ledbar3(1); 
      ledbar4(0); 
      ledbar5(0); 
      ledbar6(0); 
      ledbar7(0); 
      while(PUSH_BUTTON_OK_IS_PRESSED)  menu = 1; break;

    // run calibration
    case 2: 
      ledbar0(0); 
      ledbar1(0); 
      ledbar2(1); 
      ledbar3(1); 
      ledbar4(1); 
      ledbar5(1); 
      ledbar6(0); 
      ledbar7(0); 
      while(PUSH_BUTTON_OK_IS_PRESSED)  menu = 2; break;

    //run display binary
    case 3: 
      ledbar0(0); 
      ledbar1(0); 
      ledbar2(0); 
      ledbar3(0); 
      ledbar4(1); 
      ledbar5(1); 
      ledbar6(1); 
      ledbar7(1); 
      while(PUSH_BUTTON_OK_IS_PRESSED)  menu = 3; break;
    
    case 4: 
      pilih = 3; 
    break;
  }
  if(PUSH_BUTTON_MINUS_IS_PRESSED) {delay(200); pilih++;}
  if(PUSH_BUTTON_PLUS_IS_PRESSED)  {delay(200); pilih--;}
}
