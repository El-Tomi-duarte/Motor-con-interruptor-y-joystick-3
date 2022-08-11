#include <Arduino.h>

#include <Servo.h>
Servo pinza;
int angulo_pinza=45;
int boton=45;

Servo brazo;
int angulo_brazo=90;

Servo giro;
int angulo_giro=90;

//Valoresanteriores leidos
int A0_anterior = 0;
int A1_anterior = 0;
int A2_anterior = 0;

//Valores actuales
int A0_actual;
int A1_actual;
int A2_actual;

void setup(){
  pinza.attach(13, 500, 1480);
  pinza.write(45);
  
  brazo.attach(7);
  brazo.write(90);
  
  giro.attach(6);
  giro.write(90);
  
  pinMode(A0,INPUT);
}
void loop(){
A0_actual = analogRead(A0);  
A1_actual = analogRead(A1);  
A2_actual = analogRead(A2);  
  //Joystick para el brazo
  if (A1_actual != A1_anterior){
    A1_anterior = A1_actual;
  if (A1_actual<200 &&  angulo_brazo<180){
    
    angulo_brazo++;
    brazo.write(angulo_brazo);
  }
  if (analogRead(A1)>700 && angulo_brazo>0){
    angulo_brazo--;
    brazo.write(angulo_brazo);
  }
  }
  //Joystick para el giro
   if (A2_actual != A2_anterior){
    A2_anterior = A2_actual;
  if (analogRead(A2)<200 && angulo_giro<180){
    angulo_giro++;
    giro.write(angulo_giro);
  }
  if (analogRead(A2)>700 && angulo_giro>0){
    angulo_giro--;
    giro.write(angulo_giro);
  }
   }
  //Interruptor de la pinza
  boton=digitalRead(A0);
  
  if(boton==HIGH){
     angulo_pinza=180;
     pinza.write(angulo_pinza);
  }
  if(boton==LOW){
    angulo_pinza=0;
    pinza.write(angulo_pinza);
  }
    delay(15);
}
