# Control inercial
Análisis, pruebas y documentación del sensor MPU6050 que integra acelerómetro, giróscopo y sensor de temperatura digital.


## Salidas del giróscopo.

La resolución del giróscopo así como su escala de medida, depende de un campo denominado FS_SEL.

Los valores de este campo se relacionan con la escala y con la resolución según la siguiente tabla:

|Valor FS_SEL|Rango máximo de medida|Sensibilidad|
|------------|----------------------|------------|
|0           | +-250º/s             | 131 LSB/(º/s)|
|1           | +-500º/s             | 65.5 LSB/(º/s)|
|2           | +-1000º/s            | 32.8 LSB/(º/s)|
|3           | +-2000º/s            | 16.4 LSB/(º/s)|

El campo FS_SEL está formado por los bits 3 y 4 del registro GYRO_CONFIG, cuya dirección es 0x1B.

## Salidas del acelerómetro:
Las salidas del acelerómetro, según el datasheet se representan en una unidad denominada LSB/g. El significado
de la salida depende de un registro, que se denomina AFS_SEL y que puede tomar los siguientes valores:
AFS_SEL = 0 --> Resolución de la salida 16,384 LSB/g
AFS_SEL = 1 --> Resolución de la salida 8,192 LSB/g
AFS_SEL = 2 --> Resolución de la salida 4,096 LSB/g
AFS_SEL = 3 --> Resolución de la salida 2,048 LSB/g

Sabemos que la resolución de las salidas se representan en 16 bits en complemento a 2. Lo que provoca que tengamos
un rango asimétrico de medidas que abarca desde:

[+32765, -32766]

La unidad LSB representa el valor del bit menos significativo.

En el caso en el que AFS_SEL=0, tendremos una resolución de 16,384 LSB/g, por lo tanto, dividiremos 16,384/32765
Lo que da como resultado: 0.0005000457805585228 lo que se correspondería con el valor de cada tramo del ADC.
