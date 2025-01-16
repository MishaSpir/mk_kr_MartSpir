
# define ledPin1 3
# define ledPin2 5
# define ledPin3 6
# define ledPin4 9
# define ledPin5 10
# define ledPin6 11

float Sum(float *intArray) {
  float sum = 0;   // переменная для сложения
  for (byte i = 0; i < N-1; i++) {
    sum += intArray[i];
  }
  return sum;
}

void led_pins_init(){
 pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  pinMode(ledPin5,OUTPUT);
  pinMode(ledPin6,OUTPUT);

}

void data_pin_init(){
 pinMode(dataPin,INPUT);

}

void serial_por_init(){
 Serial.begin(115200);
}




void map_amplitudes_to_pwm(){
    for(int i = 0; i < 6; i++){
    Led[i] = map(Wk[i+7],0,100,0,255);
    Led[i] = constrain(Led[i],0,255);
    if(Led[i]< 100){Led[i]=0;}
    if(Led[i]< 100){Led[i]=0;}
    }

}


void ledsON(){
    analogWrite(ledPin1,Led[0]);
    analogWrite(ledPin2,Led[1]);
    analogWrite(ledPin3,Led[2]);
    analogWrite(ledPin4,Led[3]);
    analogWrite(ledPin5,Led[4]);
    analogWrite(ledPin6,Led[5]);

}