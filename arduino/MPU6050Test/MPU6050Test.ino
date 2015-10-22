
/****************************
 MPU6050Test

  Este sketch comprueba el funcionamiento basico de un sensor mixto acelerometro
  y magnetometro MPU6050

  Author: @goyoregalado
  Esta version incluye una referencia temporal basada en el contador
  de milisegundos del propio arduino.
  No debe considerarse una referencia fiable.
  
  Este codigo se deriva del que se encuentra en:
  http://playground.arduino.cc/Main/MPU-6050#sketch
  
******************************/
#include "MPU6050Constants.h"
#include <Wire.h>

int temp;
unsigned int AcX, AcY, AcZ, GyX, GyY, GyZ; 
int valor = 0;
unsigned int milsec = 0;

char opt = 'x';
boolean verbose = true;

void setup() {
  AcX = 0;
  AcY = 0;
  AcZ = 0;
  temp = 0;
  GyX = 0;
  GyY = 0;
  GyZ = 0;
  Serial.begin(9600);
  
  Wire.begin();
  
  Wire.beginTransmission(MPU);
  Wire.write(PWR_MGMT_1);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 1, true);
  valor = Wire.read();
  
  Serial.print("PWR_MGMT_1: ");
  Serial.println(valor, BIN);  
  
  Wire.beginTransmission(MPU);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
  

  
  Wire.beginTransmission(MPU);
  Wire.write(WHOAMI);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 1, true);
  valor = Wire.read();
  
  Serial.print("WHOAMI: ");
  Serial.println(valor,BIN);

  
  Wire.beginTransmission(MPU);
  Wire.write(ACCEL_CONFIG);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 1, true);
  valor = Wire.read();
  
  Serial.println("###################################################");
  Serial.print("ACCEL_CONFIG: ");
  Serial.println(valor, BIN);
  Serial.println("###################################################");
  
  valor = valor & FULL_SCALE_MASK;
  valor = valor >> 3;
  print_accelerometer_settings(valor);
  
  Wire.beginTransmission(MPU);
  Wire.write(GYRO_CONFIG);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 1, true);
  valor = Wire.read();
  
  Serial.println("###################################################");
  Serial.print("GYRO_CONFIG: ");
  Serial.println(valor, BIN);
  Serial.println("###################################################");
  print_gyro_settings(valor);
  
  Serial.println("Pulse [V] para modo verbose");
  Serial.println("Pulse [C] para modo CSV");
  while (opt == 'x') {
    if (Serial.available() != 0) {
      opt = Serial.read();
      if (opt == 'v' || opt == 'V') {
        verbose = true;
      }
      else if( opt =='c' || opt == 'C') {
        verbose = false;
        Serial.println("millis;AcX;AcY;AcZ;T(Celsius);GyX;GyY;GyZ");
      }
    }
  }
   
}

void loop() {
  milsec = millis();

  Wire.beginTransmission(MPU);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);
  AcX = Wire.read() <<8| Wire.read();
  AcY = Wire.read() <<8| Wire.read();
  AcZ = Wire.read() <<8| Wire.read();
  temp = Wire.read() <<8| Wire.read();
  GyX = Wire.read() <<8| Wire.read();
  GyY = Wire.read() <<8| Wire.read();
  GyZ = Wire.read() <<8| Wire.read();
  
  if (verbose) {
    Serial.println("Acelerometro: ");
    Serial.print("AcX = ");
    Serial.print(AcX);
    Serial.print(" | AcY = ");
    Serial.print(AcY);
    Serial.print(" | AcZ = ");
    Serial.println(AcZ);
    
    Serial.println("Temperatura: ");
    Serial.print("T= ");
    Serial.println(temp/340.00+36.53);
    
    Serial.println("Giroscopo: ");
    Serial.print("GyX = ");
    Serial.print(GyX);
    Serial.print(" | GyY = ");
    Serial.print(GyY);
    Serial.print(" | GyZ = ");
    Serial.println(GyZ);
  }
  else {
    Serial.print(milsec);
    Serial.print(";");
    Serial.print(AcX);
    Serial.print(";");
    Serial.print(AcY);
    Serial.print(";");
    Serial.print(AcZ);
    
    Serial.print(";");
    Serial.print(temp/340.00+36.53);
    
    Serial.print(";");
    Serial.print(GyX);
    Serial.print(";");
    Serial.print(GyY);
    Serial.print(";");
    Serial.println(GyZ);
  }
  delay(333); 
}

void print_accelerometer_settings(int valor) {
  String cad = "\tRango max de medida: ";
  valor = valor & FULL_SCALE_MASK;
  valor = valor >> 3;
  if (valor == 0) {
    cad += "+-2g\n";
  }
  else if (valor == 1) {
    cad += "+-4g\n";
  }
  else if (valor == 2) {
    cad += "+-8g\n";
  }
  else if (valor == 3) {
    cad += "+-16g\n";
  }
  else {
    cad += "[¡¡¡¡Error de config.!!!]\n";
  }
  cad += "\tSensitividad: ";
  if (valor == 0) {
    cad += "16384 LSB/g\n";
  }
  else if (valor == 1) {
    cad += "8192 LSB/g\n";
  }
  else if (valor == 2) {
    cad += "4096 LSB/g\n";
  }
  else if (valor == 3) {
   cad += "2048 LSB/g\n";
  }
  else {
    cad += "[¡¡¡¡Error de config.!!!]\n";
  }
 Serial.println(cad); 
  
}

void print_gyro_settings(int valor) {
  String cad = "\tRango max de medida: ";
  valor = valor & FULL_SCALE_MASK;
  valor = valor >> 3;
  if (valor == 0) {
    cad += "+-250º/s\n";
  }
  else if (valor == 1) {
    cad += "+-500º/s\n";
  }
  else if (valor == 2) {
    cad += "+-1000º/s\n";
  }
  else if (valor == 3) {
    cad += "+-2000º/s\n";
  }
  else {
    cad += "[¡¡¡¡Error de config.!!!]\n";
  }
  cad += "\tSensitividad: ";
  if (valor == 0) {
    cad += "131 LSB/(º/s)\n";
  }
  else if (valor == 1) {
    cad += "65.5 LSB/(º/s)\n";
  }
  else if (valor == 2) {
    cad += "32.8 LSB/(º/s)\n";
  }
  else if (valor == 3) {
   cad += "16.4LSB/(º/s)\n";
  }
  else {
    cad += "[¡¡¡¡Error de config.!!!]\n";
  }
 Serial.println(cad); 
  
}

