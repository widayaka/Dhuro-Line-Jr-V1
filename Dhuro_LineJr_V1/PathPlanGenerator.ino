void line(int mode, int count, int v_speed, int breaktime){
  if(v_speed > 4 && v_speed < 8)    {kp = 8,  ki = 0, kd = 0.05;}
  if(v_speed > 7 && v_speed < 11)   {kp = 12,  ki = 0, kd = 0.2;}
  if(v_speed > 10 && v_speed < 14)  {kp = 11, ki = 0, kd = 0.15;}
  if(v_speed > 13 && v_speed < 17)  {kp = 20, ki = 0, kd = 0.25;}
  if(v_speed > 16 && v_speed < 21)  {kp = 23, ki = 0, kd = 0.5;}

  v_speed = pwm_conv(v_speed);
  readBinarySensor();

  switch(mode){
    case ff: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[0] != 1 || hasil_sensor[7] != 1) {execute(v_speed);}
        while(hasil_sensor[0] == 1 || hasil_sensor[7] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[0] != 0 || hasil_sensor[7] != 0) {execute(v_speed);}
        while(hasil_sensor[0] == 0 || hasil_sensor[7] == 0) {execute(v_speed);}
      }
    }
    break;

    case fr: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[0] != 1) {execute(v_speed);}
        while(hasil_sensor[0] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[0] != 0) {execute(v_speed);}
        while(hasil_sensor[0] == 0) {execute(v_speed);}
      } 
    }
    break;

    case fl: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[7] != 1) {execute(v_speed);}
        while(hasil_sensor[7] == 1) {execute(v_speed);}
    }
      
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[7] != 0) {execute(v_speed);}
        while(hasil_sensor[7] == 0) {execute(v_speed);}
      } 
    }
    break;
  }
  
  breaktime = map_brake_value(breaktime);
  if(breaktime < 0)       {drive_motor(v_speed, v_speed);    delay(-breaktime); drive_motor(0,0);}
  else if(breaktime > 0)  {drive_motor(-v_speed, -v_speed);  delay(breaktime);  drive_motor(0,0);}
}


void sline(int mode, int count, int v_speed, int breaktime){
  if(v_speed > 4 && v_speed < 8)    {kp = 8,  ki = 0, kd = 0.05;}
  if(v_speed > 7 && v_speed < 11)   {kp = 12,  ki = 0, kd = 0.2;}
  if(v_speed > 10 && v_speed < 14)  {kp = 11, ki = 0, kd = 0.15;}
  if(v_speed > 13 && v_speed < 17)  {kp = 20, ki = 0, kd = 0.25;}
  if(v_speed > 16 && v_speed < 21)  {kp = 23, ki = 0, kd = 0.5;}

  v_speed = pwm_conv(v_speed);
  readBinarySensor();

  switch(mode){
    case s0: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[0] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[0] != 0) {execute(v_speed);}
      }
    }
    break;

    case s1: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[1] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[1] != 0) {execute(v_speed);}
      }
    }
    break;

    case s2: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[2] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[2] != 0) {execute(v_speed);}
      }
    }
    break;

    case s3: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[3] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[3] != 0) {execute(v_speed);}
      }
    }
    break;

    case s4: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[4] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[4] != 0) {execute(v_speed);}
      }
    }
    break;

    case s5: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[5] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[5] != 0) {execute(v_speed);}
      }
    }
    break;

    case s6: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[6] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[6] != 0) {execute(v_speed);}
      }
    }
    break;

    case s7: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[7] != 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[7] != 0) {execute(v_speed);}
      }
    }
    break;

    case s0+s1: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[0] != 1 && hasil_sensor[1] != 1) {execute(v_speed);}
        while(hasil_sensor[0] == 1 && hasil_sensor[1] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[0] != 0 && hasil_sensor[1] != 0) {execute(v_speed);}
        while(hasil_sensor[0] == 0 && hasil_sensor[1] == 0) {execute(v_speed);}
      } 
    }
    break;

    case s1+s2: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[1] != 1 && hasil_sensor[2] != 1) {execute(v_speed);}
        while(hasil_sensor[1] == 1 && hasil_sensor[2] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[1] != 0 && hasil_sensor[2] != 0) {execute(v_speed);}
        while(hasil_sensor[1] == 0 && hasil_sensor[2] == 0) {execute(v_speed);}
      } 
    }
    break;

    case s0+s1+s2: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[0] != 1 && hasil_sensor[1] != 1 && hasil_sensor[2] != 1) {execute(v_speed);}
        while(hasil_sensor[0] == 1 && hasil_sensor[1] == 1 && hasil_sensor[2] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[0] != 0 && hasil_sensor[1] != 0 && hasil_sensor[2] != 0) {execute(v_speed);}
        while(hasil_sensor[0] == 0 && hasil_sensor[1] == 0 && hasil_sensor[2] == 0) {execute(v_speed);}
      } 
    }
    break;

    case s5+s6+s7: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[5] != 1 && hasil_sensor[6] != 1 && hasil_sensor[7] != 1) {execute(v_speed);}
        while(hasil_sensor[5] == 1 && hasil_sensor[6] == 1 && hasil_sensor[7] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[5] != 0 && hasil_sensor[6] != 0 && hasil_sensor[7] != 0) {execute(v_speed);}
        while(hasil_sensor[5] == 0 && hasil_sensor[6] == 0 && hasil_sensor[7] == 0) {execute(v_speed);}
      } 
    }
    break;

    case s5+s6: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[5] != 1 && hasil_sensor[6] != 1) {execute(v_speed);}
        while(hasil_sensor[5] == 1 && hasil_sensor[6] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[5] != 0 && hasil_sensor[6]) {execute(v_speed);}
        while(hasil_sensor[5] == 0 && hasil_sensor[6]) {execute(v_speed);}
      } 
    }
    break;

    case s6+s7: 
    for(int i = 0; i < count; i++){
    if(line_color == black){
        readBinarySensor();
        while(hasil_sensor[6] != 1 && hasil_sensor[7] != 1) {execute(v_speed);}
        while(hasil_sensor[6] == 1 && hasil_sensor[7] == 1) {execute(v_speed);}
    }
    
    if(line_color == white){
        readBinarySensor();
        while(hasil_sensor[6] != 0 && hasil_sensor[7] != 0) {execute(v_speed);}
        while(hasil_sensor[6] == 0 && hasil_sensor[7] == 0) {execute(v_speed);}
      } 
    }
    break;
  
  breaktime = map_brake_value(breaktime);
  if(breaktime < 0)       {drive_motor(v_speed, v_speed);    delay(-breaktime); drive_motor(0,0);}
  else if(breaktime > 0)  {drive_motor(-v_speed, -v_speed);  delay(breaktime);  drive_motor(0,0);}
}
}


void lineleft(int v_speed, int delayValue, int breaktime){
  
}

void lineright(int v_speed, int delayValue, int breaktime){
  
}

void lostline(int v_speed, int delayValue, int breaktime){
  
}

void findline(int v_speed, int delayValue, int breaktime){
  
}

void linedelay(int v_speed, int delayValue, int breaktime){
  if(v_speed > 4 && v_speed < 8)    {kp = 8,  ki = 0, kd = 0.05;}
  if(v_speed > 7 && v_speed < 11)   {kp = 12,  ki = 0, kd = 0.2;}
  if(v_speed > 10 && v_speed < 14)  {kp = 11, ki = 0, kd = 0.15;}
  if(v_speed > 13 && v_speed < 17)  {kp = 20, ki = 0, kd = 0.25;}
  if(v_speed > 16 && v_speed < 21)  {kp = 23, ki = 0, kd = 0.5;}

  v_speed = pwm_conv(v_speed);
  readBinarySensor();

  do{
    for (int i = 0; i < 50; i++){
      execute(v_speed); 
    }
  } while(delayValue--);

  breaktime = map_brake_value(breaktime);
  if(breaktime < 0)       {drive_motor(v_speed, v_speed);    delay(-breaktime); drive_motor(0,0);}
  else if(breaktime > 0)  {drive_motor(-v_speed, -v_speed);  delay(breaktime);  drive_motor(0,0);}
}

void left(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[5] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[5] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[5] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[5] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left0(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[0] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[0] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[0] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[0] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left1(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[1] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[1] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[1] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[1] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left2(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[2] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[2] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[2] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[2] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left3(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[3] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[3] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[3] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[3] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left4(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[4] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[4] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[4] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[4] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left5(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[5] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[5] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[5] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[5] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left6(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[6] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[6] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[6] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[6] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void left7(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
  if(line_color == black){
    readBinarySensor();
    call_motor(vl, vr);
    while(hasil_sensor[7] != 1)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[7] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
    
  if(line_color == white){
    readBinarySensor();
    call_motor(vl,vr);
    while(hasil_sensor[7] != 0)  {readBinarySensor(); call_motor(vl,vr);}
    while(hasil_sensor[7] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                  delay(dtime); drive_motor(0,0);}
  }
}

void right(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[2] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[2] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[2] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[2] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right0(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[0] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[0] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[0] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[0] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right1(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[1] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[1] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[1] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[1] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right2(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[2] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[2] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[2] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[2] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right3(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[3] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[3] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[3] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[3] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right4(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[4] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[4] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[4] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[4] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right5(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[5] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[5] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[5] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[5] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right6(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[6] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[6] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[6] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[6] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}

void right7(int vl, int vr, int dtime){
  vl = pwm_conv(vl);  vr = pwm_conv(vr);
  call_motor(vl,vr);
  
    if(line_color == black){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[7] != 1)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[7] == 1)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
    
    if(line_color == white){
      readBinarySensor();
      call_motor(vl,vr);
      while(hasil_sensor[7] != 0)  {readBinarySensor(); call_motor(vl,vr);}
      while(hasil_sensor[7] == 0)  {readBinarySensor(); call_motor(vl,vr); 
                                    delay(dtime); drive_motor(0,0);}
    }
}
