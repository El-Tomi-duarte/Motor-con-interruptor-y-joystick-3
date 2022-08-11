#include <Arduino.h>

#include <Servo.h>
Servo pinza;
int angulo_pinza=44;
int boton=45;

Servo brazo;
int angulo_brazo=90;

Servo giro;
int angulo_giro=90;

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
  //Joystick para el brazo
  if (analogRead(A1)<200 && angulo_brazo<180){
    angulo_brazo++;
    brazo.write(angulo_brazo);
  }
  if (analogRead(A1)>700 && angulo_brazo>0){
    angulo_brazo--;
    brazo.write(angulo_brazo);
  }
  
  //Joystick para el giro
  if (analogRead(A2)<200 && angulo_giro<180){
    angulo_giro++;
    giro.write(angulo_giro);
  }
  if (analogRead(A2)>700 && angulo_giro>0){
    angulo_giro--;
    giro.write(angulo_giro);
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
