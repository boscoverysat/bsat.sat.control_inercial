# Control inercial
Análisis, pruebas y documentación del sensor MPU6050 que integra acelerómetro, giróscopo y sensor de temperatura.


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
