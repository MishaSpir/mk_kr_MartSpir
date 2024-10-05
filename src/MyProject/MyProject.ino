unsigned long time = 0;



void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    if(millis()-time > 1000 ){
    digitalWrite(LED_BUILTIN,HIGH);
    time = millis();
    }
    if(millis()-time > 1000 ){
    digitalWrite(LED_BUILTIN,LOW);
    time = millis();
    }

    Serial.println(time);
}
