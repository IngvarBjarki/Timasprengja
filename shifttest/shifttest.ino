//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

unsigned long TimeLeft = 30;  // timinn sem vid faum ur pafanum
unsigned long TimeToSplit = TimeLeft/ 10; // hofum 2 tvi tad eru adeins t led perur
unsigned long Timibyrjar, Timataka;

int i = 10;
int fjoldiPera = 10;

void setup() {
  //set pins to output so you can control the shift register
  Serial.begin(9600);  
  pinMode(latchPin, OUTPUT);
  //pinMode(clockPin, OUTPUT);
  //pinMode(dataPin, OUTPUT);
  
  Timibyrjar= millis();
}


void loop() {
  // count from 0 to 255 and display the number 
  // on the LEDs
  while(i>0){
  Timataka=floor((millis() - Timibyrjar)/1000);
  
  float bla = Timataka*100;
  float blabla = TimeLeft*100;

  
  i = ceil((1 - float(Timataka)/float(TimeLeft)) * fjoldiPera) ;
  
  Serial.print(i);
  Serial.print("        ");
  Serial.print(Timataka);
Serial.print("        ");
  Serial.println(((bla/blabla)));
  

  
  if(Timataka % 2 == 0 ){

    if(i>8){
      digitalWrite(latchPin, LOW);

      shiftOut(dataPin, clockPin, ceil(pow(2,i-6)-2)); 
      shiftOut(dataPin, clockPin, ceil(pow(2,i)-1)); 

      digitalWrite(latchPin, HIGH);
    }
    else{
     digitalWrite(latchPin, LOW);
      // shift out the bits:
      shiftOut(dataPin, clockPin, 2); 
      shiftOut(dataPin, clockPin, ceil(pow(2,i)-1)); 
      Serial.println(pow(2,8));
      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
    }
  }
  else{

        if(i>8){
      digitalWrite(latchPin, LOW);

      shiftOut(dataPin, clockPin, ceil(pow(2,i-7)-2)); 
      shiftOut(dataPin, clockPin, ceil(pow(2,i)-1)); 

      digitalWrite(latchPin, HIGH);
    }
    else{
    digitalWrite(latchPin, LOW);
      // shift out the bits:
      
      shiftOut(dataPin, clockPin,  2);  
      shiftOut(dataPin, clockPin, ceil(pow(2,i-1)-1));  
  
      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
    }
  }
  }
  while(i<1){
    digitalWrite(latchPin, LOW);

      shiftOut(dataPin, clockPin, 1); 
      shiftOut(dataPin, clockPin, 0); 

      digitalWrite(latchPin, HIGH);
      delay(1000);
  }
  

}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

//internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

 //clear everything out just in case to
 //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}
