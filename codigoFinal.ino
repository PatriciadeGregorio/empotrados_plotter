#include <SoftwareSerial.h>
#include <Servo.h>
//Definición de los pines del limitSwitch
int limitSwitch1=10; //El limit Switch 1, conectado al puerto 10 de la placa Arduino
int limitSwitch2=11; //El limit Switch 2, conectado al puerto 11 de la placa de Arduino
int limitSwitch3=4; //El limit Switch 3, conectado al puerto 4 de la placa de Arduino
int limitSwitch4=3; //El limit Switch 4, conectado al puerto 3 de la placa de Arduino

//Señales para leer cuando están activos los limitsSwitch
int senal1;
int senal2;
int senal3;
int senal4;

//Definición del pin del altavoz
int pin_altavoz;
int pin_altavoz2;

//Propiedades del altavoz
int frecuencia=220;    // frecuencia correspondiente a la nota La
int contador;          // variable para el contador
float m=1.059;         // constante para multiplicar frecuencia
int frecuencia2 = 0;
/* declaración de variables */
int bottonPin = 2;
int val;
Servo myservo;                                       



void setup() {
  
  Serial.begin(9600);
  pinMode(limitSwitch1,INPUT_PULLUP);
  pinMode(limitSwitch2,INPUT_PULLUP);
  pinMode(limitSwitch3,INPUT_PULLUP);
  pinMode(limitSwitch4,INPUT_PULLUP);
  myservo.attach(9);
  frecuencia = frecuencia*m;
  frecuencia2 = frecuencia*m*m*m*m*m;
}

void loop() {

  val = digitalRead (bottonPin);
  val = map(val, 0, 1, -30, 60);  
  //Serial.println(val);
  myservo.write(val);
  delay(50);
  
  pin_altavoz=13;
  pin_altavoz2=12;
  senal1 = digitalRead(limitSwitch1);
  senal2 = digitalRead(limitSwitch2);
  senal3 = digitalRead(limitSwitch3);
  senal4 = digitalRead(limitSwitch4);
  

  if (!senal1){
        Serial.print("La señal 1 es: ");
        Serial.println(senal1);
        tone(pin_altavoz, frecuencia); 
   
  }
  
  else if (!senal2) {
        Serial.print("La señal 2 es: ");
        Serial.println(senal2);
        tone(pin_altavoz,frecuencia); // emite el tono
  }
  
  else if (!senal3) {
        Serial.print("La señal 3 es: ");
        Serial.println(senal3);
        tone(pin_altavoz2,frecuencia2); // emite el tono
  }
 
  else if (!senal4) {
        Serial.print("La señal 4 es: ");
        Serial.println(senal4);
        tone(pin_altavoz2,frecuencia2); // emite el tono
  }else{
    noTone(pin_altavoz);
    noTone(pin_altavoz2);
  }


}
   
