const int MPU=0x68;

/*
Este registro se utiliza para establecer la direccion I2C del dispositivo.
Por defecto, tiene el valor 0x68.
*/
const int WHOAMI=0x75;

/*
PWR_MGMT_1: Este registro permite configurar el modo de alimentacion y el
origen de la señal de reloj.
Poniendo el bit 6 (SLEEP) a 1 pasa a modo sleep.
Si no esta en modo sleep y se habilita el bit 5 (CYCLE) el dispositivo
hace ciclos de una ´nica lectura del acelerometro a un ritmo determinado por
LP_WAKE_CTRL en el registro PWR_MGMT_2
Los bits del 0 al 2 CLKSEL[2:0] establecen la fuente de reloj. A cero usa
oscilador interno a 8MHz.

*/
const int PWR_MGMT_1=0x6B;


/*
PWR_MGMT_2: Este registro permite configurar la frecuencia de wake-ups en modo de bajo
consumo solo acelerometro.
Permite poner ejes del acelerometro y giroscopo en modo standby.
Por defecto, tiene el valor 0x40
*/
const int PWR_MGMT_2=0x6C;

/*
Registros relativos a los acelerometros y y giroscopos.
*/
const int ACCEL_XOUT_H=0x3B;
const int ACCEL_XOUT_L=0x3C;
const int ACCEL_YOUT_H=0x3D;
const int ACCEL_YOUT_L=0x3E;
const int ACCEL_ZOUT_H=0x3F;
const int ACCEL_ZOUT_L=0x40;
const int TEMP_OUT_H=0x41;
const int TEMP_OUT_L=0x42;
const int GYRO_XOUT_H=0x43;
const int GYRO_XOUT_L=0x44;
const int GYRO_YOUT_H=0x45;
const int GYRO_Y_OUT_L=0x46;
const int GYRO_Z_OUT_H=0x47;
const int GYRO_Z_OUT_L=0x48;


