
class Leds {
	
  int LedPin;
  int LedState;
  unsigned long previousMillis;
  int TimeOn;
  int TimeOff;
  
  public:
  Leds( int pin, int on, int off){
   LedPin = pin;
    pinMode(LedPin, OUTPUT);
    
    TimeOn = on;
    TimeOff = off;
    
    LedState = LOW;
    previousMillis =0;
  }


  void atualizar() {

    if(millis() - previousMillis >= TimeOn && LedState == LOW) {
      previousMillis = millis();   

    LedState = HIGH;

      digitalWrite(LedPin, LedState);
    }
    if(millis() - previousMillis >= TimeOff && LedState == HIGH) {
      previousMillis = millis();   

    LedState = LOW;

      digitalWrite(LedPin, LedState);
    }
  } 
};

Leds led1(7,500,1000);
Leds led2(8,100,500);


void setup() { 

}
 
void loop()
{	
 led1.atualizar();
 led2.atualizar();
}