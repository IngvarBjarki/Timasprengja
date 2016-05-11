//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

  unsigned long TimeLeft = 30;  // timinn sem vid faum ur pafanum
  
  unsigned long TimeToSplit = TimeLeft/ 8; // hofum 2 tvi tad eru adeins t led perur
  unsigned long Timibyrjar, Timataka;

int i = 8;
int fjoldiPera = 8;

void setup() {
  //set pins to output so you can control the shift register
  Serial.begin(9600);  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Timibyrjar= millis();

  
}


void loop() {
  // count from 0 to 255 and display the number 
  // on the LEDs
  
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
     digitalWrite(latchPin, LOW);
      // shift out the bits:
      
      shiftOut(dataPin, clockPin, MSBFIRST, pow(2,i)-1);  
  
      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
  }
  else{
    digitalWrite(latchPin, LOW);
      // shift out the bits:
      
      shiftOut(dataPin, clockPin, MSBFIRST, pow(2,i-1)-1);  
  
      //take the latch pin high so the LEDs will light up:
      digitalWrite(latchPin, HIGH);
  }
  
  

}
