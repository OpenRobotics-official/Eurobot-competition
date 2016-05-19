 #include <Servo.h>
 #define encoder0PinA 2
 #define encoder0PinI 3
 #define encoder0PinB 4
 #define encoder1PinA 2
 #define encoder1PinI 3
 #define encoder1PinB 4
 #define tirette 8
 #define sharpread A0
 #define ticklength  0.226194

 Servo parasol;
 Servo moteur1;
 Servo moteur2;
/*
volatile long int encoder0Pos = 0;
volatile int precEncoder0Pos = 0;
volatile int encoder0Speed = 0;
volatile int encoder0Acc = 0;
volatile int precEncoder0Speed = 0;
volatile int encoder0Turn = 0;
volatile long int encoder1Pos = 0;
volatile int precEncoder1Pos = 0;
volatile int encoder1Speed = 0;
volatile int encoder1Acc = 0;
volatile int precEncoder1Speed = 0;
volatile int encoder1Turn = 0;

volatile int dir = 0;
volatile int dir1 = 0;
*/
int begincount = 0;
volatile int count = 0;
int timer3_counter;

void setup()
{

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

  parasol.attach(13);
  parasol.write(10);
  moteur1.attach(10);
  moteur1.write(90);
  moteur2.attach(12);
  moteur2.write(90);

  pinMode(tirette , INPUT);
  pinMode(sharpread , INPUT);
  /* 
  pinMode(encoder0PinB, INPUT); 
  pinMode(encoder0PinI, INPUT); 

  pinMode(encoder1PinA, INPUT); 
  pinMode(encoder1PinB, INPUT); 
  pinMode(encoder1PinI, INPUT); 

  attachInterrupt(0, initcount, CHANGE);/*
  attachInterrupt(1, resetEncoder0, RISING);

  attachInterrupt(0, doEncoder1, CHANGE);
  attachInterrupt(1, resetEncoder1, RISING);
*/
  Serial.begin (9600);
}


/*
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

void loop()
{
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

    if(count <= 3 && analogRead(sharpread)<80)
    {
        moteur1.write(97);
        moteur2.write(97);
    }
    else
    {
        moteur1.write(50);
        moteur2.write(50);
    }
  }
}

  if (count == 90)
  {
       moteur1.write(90);
       moteur2.write(90);
       parasol.write(180);
    while(1)
    {
    }
  }

}
