// Funciones de movimientos disparador de bolas
// Los comandos serie se envían al controlador de servos Lynxmotion SSC32 por la línea TX del serial del arduino, pin D1
// Relé de la bobina solenoide, canal 7
// Servo de entrada de bolas, canal 8
// Servo de salida de bolas, canal 9

void iniciarDisparador() {
  cerrarServoEntradaBolas();
  cerrarServoSalidaBolas();
}

void dispararPelotas (int numeroDePelotas) {
  const int tiempoCortoEsperaServo = 400;
  const int tiempoLargoEsperaServo = 500;
  for (int i = 0; i <= (numeroDePelotas - 1); i++) {
    abrirServoEntradaBolas();
    delay(tiempoCortoEsperaServo);
    cerrarServoEntradaBolas();
    delay(tiempoCortoEsperaServo);
    abrirServoSalidaBolas();
    delay(tiempoCortoEsperaServo);
    cerrarServoSalidaBolas();
    delay(tiempoLargoEsperaServo);
    solenoidePulsoCorto();
  }
  pitidoLargo();
}

void solenoidePulsoCorto() {
  const int tiempoDisparo = 50; //50 milisegundos de disparo
  Serial.println(F("#7P2000")); //Solenoide activada
  delay (tiempoDisparo);
  Serial.println(F("#7P1000")); //Solenoide desactivada
}

void cerrarServoEntradaBolas() {
  Serial.println(F("#8P1882"));
}

void abrirServoEntradaBolas() {
  Serial.println(F("#8P855"));
}

void cerrarServoSalidaBolas() {
  Serial.println(F("#9P2022"));
}

void abrirServoSalidaBolas() {
  Serial.println(F("#9P1025"));
}
