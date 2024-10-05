#include "led.h"


constexpr unsigned int PERIOD{1};               //замена define
constexpr unsigned int HALF_PERIOD{PERIOD/2};


void setup(){
    BuiltInLed::Init();

}

void loop(){
    BuiltInLed::On();
    delayS(PERIOD);
    BuiltInLed::Off();
    delayS(HALF_PERIOD);
}