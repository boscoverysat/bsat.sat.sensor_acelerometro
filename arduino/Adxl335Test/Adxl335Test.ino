/****************************
Adxl335Test

Este sketch comprueba el funcionamiento basico de un 
acelerometro adxl335.

Author: @goyoregalado
Esta version incluye una referencia temporal basada en el contador
de milisegundos del propio arduino.
No debe considerarse una referencia fiable.

Alimentando el acelerometro con 3.3V deberiamos obtener 360mV/g

La salida del ADC de arduino tiene una capacidad de muestreo de 10 bits,
lo que hace que tengamos un espacio de muestra de 1024. El voltaje de 
referencia del ADC es tambien de 3.3V lo que hace que cada intervalo de
conversion represente 3.3/1024 V = 3.223 mV = 3.223 * 10E-3 V

Por lo tanto, la conversion entre la salida cruda del acelerometro y una
unidad de referencia en g sera:

SalidaADC * 3,223 *10E-3 * 360

En principio estas conversiones estan diseñada
******************************/

int x = 0;
int y = 0;
int z = 0;
int milsec = 0;

char opt = 'x';
boolean verbose = true;

void setup() {
  Serial.begin(9600);
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
        Serial.println("millis;X;Y;Z");
      }
    }
  }
}

void loop() {
  milsec = millis();
  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);
  if (verbose) {
    Serial.print("mS = ");
    Serial.print(milsec);
    Serial.print("X = ");
    Serial.print(x);
    Serial.print(" Y = ");
    Serial.print(y);
    Serial.print(" Z = ");
    Serial.println(z);
  }
  else {
    Serial.print(milsec);
    Serial.print(";");
    Serial.print(x);
    Serial.print(";");
    Serial.print(y);
    Serial.print(";");
    Serial.println(z); 
  }
  delay(250);
}
