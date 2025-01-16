# define dataPin A0  //Пин входа (усиленного и смещенного) звукового сигнала 
# define Ts 200      //Периоддескритезации равный 200мкс (Fs = 5000Гц)


float data;           //перемнная для дискретных значений сигнала 
float pi = 3.1415926; 
const int N = 25;     //Число взятых значений(точек),которые используются в расчете 
float Sin1[N];
float RE[N];          //Вектор действительных составляющих(исп. в расчете)
float IM[N];          //Вектор мнимых составляющих (исп. в расчете)
float re, im;         //(исп. в расчете)
float Wk[20];          //МАССИВ ВЕСОВ КАЖДОЙ ИЗ ЧАСТОТ  
int Led[6];           //Массив ШИМ-сигналов светодиодов
float SumRE,SumIM;    //(исп. в расчете)

# include "SpectroLib.h"







unsigned long timer1;   //таймер-счетчик


void setup() {
  serial_por_init(); //Включить Последовательный порт (115200) 
  led_pins_init();    
  data_pin_init();
  
    
}

int I =0; 
void loop() {
  while(I < 25){                //Делай замеры, пока их не станет 25
  if((micros()-timer1)>=Ts){
    timer1 = micros();
    data = analogRead(dataPin); //тут каждые 0.0002с считывается значения и попадают в массив 
    //Serial.println(data);
    Sin1[I]=data;
  I++;  
  
  }}

   //как только массив полностью определен, идет вычисление весов разных частот(смниже)
   //согласно Дискретному Преобразованию Фурье
  for (int K = 7; K < 13; K++ ) {
    for (int i = 1; i < N+1; i++) {
      RE[i-1] = cos((-2 * pi * K * i) / N);
    }
     
    for (int i = 0; i < N; i++) {
      
      RE[i] = RE[i] * Sin1[i];
      
    }

    for (int i = 1; i < N+1; i++) {
      IM[i-1] = sin((-2 * pi * K * i) / N);
    }
    for (int i = 0; i < N; i++) {
      IM[i] = IM[i] * Sin1[i];
    }

    SumRE = Sum(RE);
    SumIM = Sum(IM);
    

    re = SumRE / N ;
    im = SumIM / N ;

    Wk[K] = sqrt((re * re) + (im * im));   //Массив весов 
    

  }

 
    I=0;     // после вычисления берутся новые значения и производятся новые вычисления 


    
  map_amplitudes_to_pwm(); //Веса частот преобразутся в значения  ШИМ-сигнала для светодиодов 
  ledsON();      
    for (int K = 7; K < 13; K++) {
      Serial.print(Wk[K]);Serial.print("   ");
    //  Serial.print(Led[K-1]);Serial.print("   ");
    }Serial.println("   ");
             
  
    
    
  }
