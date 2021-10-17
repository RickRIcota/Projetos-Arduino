#include <Servo.h>
int tempoAnt = 0;

Servo motor;

class ServoMoveLed{
  Servo motor;
  int pos;
  int incrementar;
  int atualizarIntervalo;
  int pino;
  unsigned long lasTime;

  public:

  //CONSTRUTOR
  ServoMove(int pin, int interval){
    atualizarIntervalo = interval;
    incrementar = 1;
    pino = pin;
  }

  void Update(){
    Servo.attach(pino);
    if((millis()-lasTime) > atualizarIntervalo){
      lasTime = millis();

      pos+=incrementar;
      motor.write(pos);

      if(pos >= 180 || pos <= 0){
        incrementar = -incrementar;
      }
    }
  }
};
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

ServoMove MotorA(8,100);

void setup()
{
  motor.attach(8);
  Serial.begin(9600);
}

void loop(){
  MotorA.Update();

  motor.write(180);
}