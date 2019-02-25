//By Denis_Geek
#include <PS2X_lib.h>                         /* PS2 Controller библиотека */
#include <LiquidCrystal.h>                    /* LiquidCrystal библиотека дисплея 1602 */
PS2X ps2x;                                    
byte Type = 0;
byte vibrate = 0;
int RX=0,RY=0,LX=0,LY=0;
LiquidCrystal lcd(2,3,7, 6, 5, 4);            /* номерация пинов дисплея подключаемых к ардуино*/
void setup(){
   lcd.begin(16, 2);                             /* 16X2 lcd display */
   ps2x.config_gamepad(13,11,10,12, true, true); /* инициализация пинов подключения геймпада:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error*/
   Type = ps2x.readType();                       /* считывание данных с контроллера */
   if(Type==1){                                  
      lcd.setCursor(0, 0);                       
      lcd.print("   DualShock    ");             
      lcd.setCursor(0, 1) ;
      lcd.print("Controller Found");
      delay(1000);
      lcd.clear(); 
   }
}
void loop(){

   ps2x.read_gamepad(false, vibrate);   /* read controller and set large motor to spin at 'vibrate' speed */
   lcd.setCursor(0, 0);                 /* Position the LCD cursor */
   lcd.print("Stick values:   ");       /* Display analog stick values */
   lcd.setCursor(0, 1);
   LY = ps2x.Analog(PSS_LY);          /* Reading Left stick Y axis */
   LX = ps2x.Analog(PSS_LX);          /* Reading Left stick X axis */
   RY = ps2x.Analog(PSS_RY);          /* Reading Right stick Y axis */
   RX = ps2x.Analog(PSS_RX);          /* Reading Right stick X axis */
   if((LY <= 9))                      /* standardize to 3 digit by checking less than 10 */
      lcd.print("00");                /* eg: if LY= 5 then it display as "005" in lcd */
   if((LY >= 9 &&LY <= 99))           /* standardize to 3 digit by checking between 10-99 */
      lcd.print("0");                 /* eg: if LY= 55 then it display as "055" in lcd */     
   lcd.print(LY,DEC);                 /* display left analog stick Y axis */
   lcd.print(",");                    /* separate values using comma */
   if((LX <= 9))                      /* standardize to 3 digit by checking less than 10 */
      lcd.print("00");                /* eg: if LX= 5 then it display as "005" in lcd */
   if((LX >= 9 && LX<=99))            /* standardize to 3 digit by checking between 10-99 */
      lcd.print("0");                 /* eg: if LX= 55 then it display as "055" in lcd */  
   lcd.print(LX,DEC);                 /* display left analog stick X axis */
   lcd.print(",");                    /* separate values using comma */
   if((RY <= 9))                      /* standardize to 3 digit by checking less than 10 */
      lcd.print("00");                /* eg: if RY= 5 then it display as "005" in lcd */
   if((RY >= 9 &&RY<=99))             /* standardize to 3 digit by checking between 10-99 */
      lcd.print("0");                 /* eg: if RY= 55 then it display as "055" in lcd */  
   lcd.print(RY,DEC);                 /* display Right analog stick Y axis               */
   lcd.print(",");                    /* separate values using comma */
   if((RX <= 9))                      /* standardize to 3 digit by checking less than 10 */
      lcd.print("00");                /* eg: if RX= 5 then it display as "005" in lcd */
   if((RX >= 9 &&RX <= 99))           /* standardize to 3 digit by checking between 10-99 */
      lcd.print("0");                 /* eg: if RX= 55 then it display as "055" in lcd */  
   lcd.print(RX,DEC);                 /* display Right analog stick X axis          */
   lcd.print(" ");
   if(ps2x.NewButtonState()) {        /* will be TRUE if any button changes state  */
      lcd.setCursor(0, 0);
      if(ps2x.Button(PSB_START))      /* will be TRUE as long START button is pressed */
         lcd.print("START PRESSED   ");
      if(ps2x.Button(PSB_SELECT))             /* will be TRUE as long SELECT button is pressed */
         lcd.print("SELECT PRESSED  ");
      if(ps2x.Button(PSB_PAD_UP))             /* will be TRUE as long as UP button is pressed */
         lcd.print("UP PRESSED      "); 
      if(ps2x.Button(PSB_PAD_RIGHT))          /* will be TRUE as long as UP button is pressed */
         lcd.print("RIGHT PRESSED   ");
      if(ps2x.Button(PSB_PAD_LEFT))           /* will be TRUE as long as LEFT button is pressed */
         lcd.print("LEFT PRESSED    "); 
      if(ps2x.Button(PSB_PAD_DOWN))           /* will be TRUE as long as DOWN button is pressed */
         lcd.print("DOWN PRESSED    "); 
      if(ps2x.Button(PSB_L1))                 /* will be TRUE as long as L1 button is pressed */
         lcd.print("L1 pressed      ");
      if(ps2x.Button(PSB_R1))                 /* will be TRUE as long as R1 button is pressed */
         lcd.print("R1 pressed      "); 
      if(ps2x.Button(PSB_L2))                 /* will be TRUE as long as L2 button is pressed */
         lcd.print("L2 pressed      ");
      if(ps2x.Button(PSB_R2))                 /* will be TRUE as long as R2 button is pressed */
         lcd.print("R2 pressed      ");
      if(ps2x.Button(PSB_L3))                 /* will be TRUE as long as L3 button is pressed */
         lcd.print("L3 pressed      ");
      if(ps2x.Button(PSB_R3))                 /* will be TRUE as long as R3 button is pressed */
         lcd.print("R3 pressed      ");
      if(ps2x.Button(PSB_GREEN))              /* will be TRUE as long as GREEN/Triangle button is pressed */
         lcd.print("Triangle pressed");
      if(ps2x.Button(PSB_BLUE))                /* will be TRUE as long as BLUE/CROSS/X button is pressed */
         lcd.print("X pressed       "); 
       if(ps2x.Button(PSB_RED))               /* will be TRUE as long as RED/Circle button is pressed */
         lcd.print("Circle pressed  "); 
      if(ps2x.Button(PSB_PINK))               /* will be TRUE as long as PINK/Squre button is pressed */
         lcd.print("Square pressed  "); 
      delay(700);
   }
   else;
}
