 #include <Servo.h>
 #include <Arduino.h>
 #include "BasicStepperDriver.h"
 #include "A4988.h"


 #define encoder0PinA 20
 #define encoder0PinI 21
 #define encoder0PinB 19
 #define encoder1PinA 2
 #define encoder1PinI 18
 #define encoder1PinB 3
 #define tirette 32
 #define sharpread A1
 #define sharpread1 A2
 #define ticklength  0.226194
 #define pin_bras 11
 #define pin_releaseFish 10
 #define DIR0 41
 #define STEP0 43
 #define DIR1 37
 #define STEP1 39
 #define MICROSTEPS 1
 #define MOTOR_STEPS 400
 #define FW 1
 #define BK -1
 #define MAX_RPM 200




 A4988 stepper0(MOTOR_STEPS, DIR0, STEP0);
 A4988 stepper1(MOTOR_STEPS, DIR1, STEP1);
 Servo bras; //servo base fixe robot
 Servo releaseFish; //servo 
 Servo parasol;
        	 

volatile long int encoder0Pos = 0;
volatile int precEncoder0Pos = 0;
volatile int encoder0Turn = 0;
volatile long int encoder1Pos = 0;
volatile int precEncoder1Pos = 0;
volatile int encoder1Turn = 0;
volatile long int dist = 0;
volatile int angle = 0;

volatile int dir = 0;
volatile int dir1 = 0;


int begincount = 0;
volatile int count = 0;
int timer3_counter;

void setup()
{
  pinMode(pin_bras, OUTPUT);
  pinMode(pin_releaseFish, OUTPUT);
  
  parasol.attach(13);
  parasol.write(10);

  bras.attach(pin_bras);
  bras.write(180);
 
  releaseFish.attach(pin_releaseFish);
  releaseFish.write(180);

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  timer3_counter = 3036;   // preload timer 65536-16MHz/256/2Hz
  TCNT3 = timer3_counter;   // preload timer
  TCCR3B |= (1 << CS12);    // 256 prescaler 
  TIMSK3 |= (1 << TOIE3);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts

  
  stepper0.setRPM(200);
  stepper0.setMicrostep(MICROSTEPS);
  stepper1.setRPM(200);
  stepper1.setMicrostep(MICROSTEPS);

  pinMode(tirette , INPUT);
  pinMode(sharpread , INPUT);
  pinMode(sharpread1 , INPUT);
  /* 
  pinMode(encoder0PinB, INPUT); 
  pinMode(encoder0PinI, INPUT); 

  pinMode(encoder1PinA, INPUT); 
  pinMode(encoder1PinB, INPUT); 
  pinMode(encoder1PinI, INPUT); 

  attachInterrupt(0, initcount, CHANGE);/*
  attachInterrupt(1, resetEncoder0, RISING);
*/
  attachInterrupt(3, doEncoder0, CHANGE);
  attachInterrupt(1, doEncoder1, CHANGE);

  Serial.begin (9600);
}



void doEncoder0(){

  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) { 

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {  
      encoder0Pos = encoder0Pos + 1*ticklength;         // CW
      dir = 0;
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
      dir = 1;
    }
  }

  
  Serial.println (encoder0Pos, DEC);          

}

void doEncoder1(){

  // look for a low-to-high on channel A
  if (digitalRead(encoder1PinA) == HIGH) { 

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder1PinB) == LOW) {  
      encoder1Pos = encoder1Pos + 1*ticklength;         // CW
      dir = 0;
    } 
    else {
      encoder1Pos = encoder1Pos - 1;         // CCW
      dir1 = 1;
    }
  }

  
  Serial.println (encoder0Pos, DEC);          

}
/*
void resetEncoder0()
{
    //increment nb of turns
    if (dir == 0)
    {
      encoder0Turn = encoder0Turn + 1;
    }
    else if(dir == 1)
    {
      encoder0Turn = encoder0Turn - 1;
    }
    //reset position
    Serial.println ("turn");
    Serial.println (encoder0Turn, DEC);
}

void resetEncoder1()
{
    //increment nb of turns
    if (dir == 0)
    {
      encoder1Turn = encoder1Turn + 1;
    }
    else if(dir == 1)
    {
      encoder1Turn = encoder1Turn - 1;
    }
    //reset position
    Serial.println ("turn");
    Serial.println (encoder1Turn, DEC);
}
*/

ISR(TIMER3_OVF_vect)        // interrupt service routine 
{
  TCNT3 = timer3_counter;
  if (count < 90 && begincount != 0)
  {
    count = count + 1;// preload timer
    //Serial.println (count, DEC);

  }
  dist = (encoder0Pos + encoder1Pos)/2;
  angle = encoder0Pos - encoder1Pos;
 


        
       
 // speed and acceleration encoder 0
// encoder0Speed = encoder0Pos*10 - precEncoder0Pos;
 //precEncoder0Pos = encoder0Pos;
 //encoder0Acc = encoder0Speed - precEncoder0Speed;
 //precEncoder0Speed = encoder0Speed;

 //1 tick = 0.226194

    /*Serial.println ("speed");
    Serial.println (encoder0Speed, DEC);

    Serial.println ("acc");
    Serial.println (encoder0Acc, DEC);*/

 
}



void fish(int k)
{
  if(k==0) //position initiale du bac poisson = arrivée au bac poisson
  {
    //Stop robot
    bras.write(110);
    //Redémarrage du robot
  }
  if(k==1) //position finiale  du bac poisson
  {
    //Stop robot
    bras.write(145);
    //Redémarrage du robot
  }
  if(k==2) // decrochage au dessus du filet
  {
    //Stop robot
    bras.write(110);
    delay(300);
    releaseFish.write(100);
    delay(1000);
    releaseFish.write(180);
    delay(300);
    bras.write(180);
    //Redémarrage du robot
  } 
}


void stepperGoto(int rsteps) {
  int steps = abs(rsteps);
  int vDouille=0;

  for (int i=0; i<steps; ++i) {
    if (i>steps*0.2) {
      //rpm = rpm + i/( steps*STEPS_TO_CM*MAX_RPM*spd/100 
      stepper0.setRPM( 200);
      stepper1.setRPM( 200 );
      if (i>steps*0.4) {
        stepper0.setRPM( 200 );
        stepper1.setRPM( 200 );
    
        if (i>steps*0.6) {
          //rpm = rpm - rpm*(i - (1/3)*steps*STEPS_TO_CM)/( ( (2/3)*steps*STEPS_TO_CM ) );
          stepper0.setRPM( 200 );
          stepper1.setRPM( 200 );
    
          if (i>steps*0.8) {
            //rpm = rpm - rpm*(i - (1/3)*steps*STEPS_TO_CM)/( ( (2/3)*steps*STEPS_TO_CM ) );
            stepper0.setRPM( 200 );
            stepper1.setRPM( 200 );
          }
        }
      }
    }
    vDouille=0;
    while((analogRead(sharpread)>400 && rsteps > 0)) {
      if(!vDouille) {
            stepper0.setRPM( 70 );
            stepper1.setRPM( 70 );

            stepper0.move( 50 );
            stepper1.move( 50 );

            vDouille = 1;
            delay(500);

      }
    }
      while(analogRead(sharpread1)>400 && rsteps <0) {
      if(!vDouille) {
            stepper0.setRPM( 70 );
            stepper1.setRPM( 70 );

            stepper0.move( -50 );
            stepper1.move( -50 );

            vDouille = 1;
            delay(500);
        }
      }

    stepper0.move( (rsteps/steps)*FW );
    stepper1.move( -FW*(rsteps/steps) );
  }
}

void turnplus (int endturnplus)
{
  while(angle <= endturnplus)
  {
    if(digitalRead(sharpread)<80)
    {
      stepper0.move(1);
      stepper1.move(-1);
    }
  }
}

void turnminus (int endturnminus)
{
  while(angle >= endturnminus)
  {
    if(digitalRead(sharpread)<80)
    {
      stepper0.move(-1);
      stepper1.move(1);
    }
  }
}


void loop()
{



  int side = digitalRead(36);         /** SELECT SIDE HERE, 
               						 0 FOR GREEN, 1 FOR PURPLE **/



 if(begincount == 0 && digitalRead(tirette))
  {
    begincount = begincount + 1;
  }

  if (begincount == 0)
  {
      count = 0;
  }
  else
    {
    if (begincount == 1)
    {
      

      /** Blocks pushing movement **/     
      
      stepperGoto(900); //Move front  
      delay(200);
    if (side == 1)
    {
	    turn(45, side);   // Slite turn to push blocks in zone 
	   	delay(200);
	    stepperGoto(400);  //Push blocks
	      delay(200);
	      stepperGoto(400);  //Push blocks
	      delay(200);
	      turn(55, side); 
	      delay(200);
	      stepperGoto(400);  //Push blocks
	      delay(200);
    }
      if (side == 0)
    {
		turn(55, side);   		// Slite turn to push blocks in zone 
		delay(200);
		stepperGoto(400); //Push blocks
		delay(200);
		turn(55, side);   // Correction turn
		delay(200);
		stepperGoto(300); //Push blocks
		delay(200);
		turn(56, side);   // Correction turn 
		delay(200);
		stepperGoto(250); //Push blocks
		delay(200);
	   // Correction turn 
		stepperGoto(400); //Push Blocks
		  delay(200);
		  turn(-85, side);
		 stepperGoto(800);
    }
      
      stepperGoto(-3200); //Move back on towel
      delay(500);
      

      /** Cabin door movement **/
      
      stepperGoto(645);   //Slitly foward
      delay(500);
      if(side == 1)
      {
        turn(375, side);    // Turn 90deg to face backward the cabins 
        delay(100);
        stepperGoto(-2400);   // Backward movement to the cabin
        delay(200); 
      }
      if(side == 0)
      {
        turn(335, side);    // Turn 90deg to face backward the cabins 
        delay(100);
        stepperGoto(-2400);   // Backward movement to the cabin
        delay(200); 
      }
      
      // Check 1
      stepperGoto(300);   
      delay(200);
      stepperGoto(-800);    
      delay(200);

      // Check 2
      stepperGoto(500);   
      delay(200);
      if(side == 0)
      {
            //recalage entre les deux tentatives de portes
        turn(-375, side);
        delay(200); 
        stepperGoto(-900);
        delay(200);
        stepperGoto(800); 
        delay(200);
        turn(335, side);

      }
      if(side == 1)
      {
        //recalage entre les deux tentatives de portes
        delay(200); 
        turn(-335, side);
        delay(200); 
        stepperGoto(-800);
        delay(200);
        stepperGoto(800); 
        delay(200);
        turn(375, side);
      }

      // Check 3
      stepperGoto(-1000);   
      delay(200);

      /** Recadrage **/
      
      stepperGoto(500);
      delay(200);
      if(side == 1)
      {
        turn(375, 0);   // Turn 90deg to face backward the start 
        delay(100);
        stepperGoto(-1200);   
        delay(200); 
      }
      if(side == 0)
      {
        turn(335, 1);   // Turn 90deg to face backward the start 
        delay(100);
        stepperGoto(-1200);   
        delay(200); 
      }



      /** Fish movement**/
      
      stepperGoto(645);   //Slitly foward
      delay(200);
      if(side == 1)
      {
        turn(375, side);    // Turn 90deg to face frontward  the fish
        delay(100);
        //stepperGoto(-2100);   
        //delay(200); 
      }
      if(side == 0)
      {
        turn(335, side);    // Turn 90deg to face 'frontward the fish' 
        delay(100);
        //stepperGoto(-2100);   
        //delay(200); 
      }
      stepperGoto(3700);    // To the fish, frontward movement
      delay(200);

      stepperGoto(-220);
      delay(200);
      turn(370, 1);     // 
      delay(200);

      
      //fish(0);          // Drop the fish catcher								/// Fish Function

      delay(100);
      

      
      if (side == 0)
      {
      	//fish(0);																/// Fish Function
        stepperGoto(-500);
        delay(200);
        stepperGoto(700);
        delay(200);
      }

      if (side == 1)
      {
      	//fish(0);																/// Fish Function
        stepperGoto(500);
        delay(200);
        stepperGoto(-700);
        delay(200);
      }

     //fish(1);        														/// Fish Function

      if (side == 0)
      {
        stepperGoto(700);
        delay(200);
      }

      if (side == 1)
      {
        stepperGoto(-700);
        delay(200);
        
      }

     // fish(2);          // Release tthe fishs									/// Fish Function
      delay(200);
    
    
    
      /** Coquillqge test **/

      /*
      stepperGoto(400);
      delay(200);
      //turn(725, side);  
      turn(375, side);
      delay(50);
      turn(375, side);  
      delay(250);
      stepperGoto(200);*/

      // RAJOUTER FUNNY ACTION?


      //stepperGoto(-4000);
      //delay(5000);
      //stepperGoto(-2000);
      ///bras.write(90);
      
   //action du robot
    while(1){
    	if (count == 90)
        {
        	 
  		
          //moteur1.write(90);
          //moteur2.write(90);
          	//bras.write(180);

          	
            parasol.write(150);
        }
            


        }
      }
  }

  }


void turn(int steps, unsigned char side)
{
  int abs_steps = abs(steps);
  if (side == 0)    // To be modified
  {
    for(int i=0; i<abs_steps; i++)
    {
        stepper0.setRPM(150);
        stepper1.setRPM(150);
        stepper0.move( (steps/abs_steps)*FW );
      stepper1.move( FW*(steps/abs_steps) );
    }
    
  }
  if (side == 1)    // To be modified
  {
    for(int i=0; i<abs_steps; i++)
    {
        stepper0.setRPM(150);
        stepper1.setRPM(150);
        stepper0.move( (steps/abs_steps)*(-FW) );
      stepper1.move( -FW*(steps/abs_steps) );
    }
    
  }
} 
