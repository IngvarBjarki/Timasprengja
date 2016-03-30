void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  
  
  // þennan tima fae eg fra pafanum, timinn sem er eftir af leiknum
  unsigned long TimeLeft = 10000; 
  unsigned long TimeToSplit = TimeLeft/ 3; // hofum 2 tvi tad eru adeins t led perur
 
  // Keikjum a ollum perunum
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);
  Serial.println("hellow");
  
  // her er breyta sem seigir hvort eigi ad kvekja eda slokkva a led, fyrir blik
  int witchLED = 0;



while(1){

  
  TimeLeft = millis();
  
  // lykjja tul ad blikka, kveikjum
  if(TimeLeft < TimeToSplit &&  TimeLeft % 500 == 0 && witchLED == 1){
    Serial.println("I am turning on!!");
    digitalWrite(12,HIGH);
    witchLED = 0;
  }  

  // tetta er lykja til ad blikka, slokkvum
  if(TimeLeft < TimeToSplit &&  TimeLeft % 500 == 0 && witchLED == 0){
    Serial.println("i am in turning offf");
    digitalWrite(12,LOW);
    witchLED = 1;
  }

  
  // slokvum a pinna 12
  if(TimeLeft >= TimeToSplit){
      Serial.println("LED number 12 LOW");
      digitalWrite(12,LOW);
      witchLED = 1;
    }
    
  // latum pina 13 blika, kveikjum  
    if(TimeLeft > TimeToSplit && TimeLeft < 2*TimeToSplit &&  TimeLeft % 500 == 0 && witchLED == 1){
     digitalWrite(13,HIGH);
     witchLED = 0;
   }
  
  
    // latum pinna 13 blikka, slokkvum
   if(TimeLeft > TimeToSplit && TimeLeft < 2*TimeToSplit &&  TimeLeft % 1000 == 0 && witchLED == 0){
      digitalWrite(13,LOW);
      witchLED = 1;
  }
  
  
  if(TimeLeft >= 2*TimeToSplit){
    Serial.println("LED number 13 LOW");
    digitalWrite(13,LOW);
    
    }
    
   
    
  }
}
void loop(){
}
