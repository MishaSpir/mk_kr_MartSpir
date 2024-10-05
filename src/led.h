namespace BuiltInLed{ 

void Init(){
    pinMode(LED_BUILTIN,OUTPUT);
}

void On(){
    digitalWrite(LED_BUILTIN,1);
}
void Off(){
    digitalWrite(LED_BUILTIN,0);
}

}
void delayS(unsigned int s){
    delay(1000 * s);
}


