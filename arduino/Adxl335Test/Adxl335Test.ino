/****************************
Adxl335Test

Este sketch comprueba el funcionamiento basico de un 
acelerometro adxl335.

Author: @goyoregalado

******************************/
int x = 0;
int y = 0;
int z = 0;

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
      }
    }
  }
}

void loop() {
  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);
  if (verbose) {
    Serial.print("X = ");
    Serial.print(x);
    Serial.print(" Y = ");
    Serial.print(y);
    Serial.print(" Z = ");
    Serial.println(z);
  }
  else {
    Serial.print(x);
    Serial.print(";");
    Serial.print(y);
    Serial.print(";");
    Serial.println(z); 
  }
  delay(250);
}
