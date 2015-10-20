
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

int AcX, AcY, AcZ, temp, GyX, GyY, GyZ;
void setup() {
  AcX = 0;
  AcY = 0;
  AcZ = 0;
  temp = 0;
  GyX = 0;
  GyY = 0;
  GyZ = 0;
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
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
  
  Serial.println("Acelerometro: ");
  Serial.print("AcX = ");
  Serial.print(AcX);
  Serial.print("| AcY = ");
  Serial.print(AcY);
  Serial.print("| AcZ = ");
  Serial.println(AcZ);
  
  Serial.println("Temperatura: ");
  Serial.print("T= ");
  Serial.println(temp/340.00+36.53);
  
  Serial.println("Giroscopo: ");
  Serial.print("GyX = ");
  Serial.print(GyX);
  Serial.print("| GyY = ");
  Serial.print(GyY);
  Serial.print("| GyZ = ");
  Serial.println(GyZ);
  delay(333); 
}
