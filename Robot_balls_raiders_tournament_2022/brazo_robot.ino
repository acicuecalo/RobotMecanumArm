// Funciones de movimientos del brazo robot.
// Los comandos serie se envían al controlador de servos Lynxmotion SSC32 por la línea TX del serial del arduino, pin D1
// Servo cintura, canal 16
// Servo hombro, canal 17
// Servo codo, canal 18
// Servo muñeca, canal 19
// Servo pinza, canal 20

void brazoPosicionReposo() {
  brazoPararPinza();
  Serial.println(F("#16P1540 #17P2089 #18P500 #19P1815 T2000"));
  delay(2000);
}

void brazoAbrirPinza() {
  Serial.println(F("#20P1595"));
  delay(2400);
  brazoPararPinza();
}

void brazoCerrarPinza() {
  Serial.println(F("#20P1425"));
  delay(2400);
  brazoPararPinza();
}

void brazoPararPinza() {
  Serial.println(F("#20P1500"));
}

void brazoApuntarBolaDesdeArriba() {
  brazoPararPinza();
  Serial.println(F("#17P1346 #18P1090 #19P1979 T1000"));
  delay(1000);
}

void brazoApuntarBolaDesdeAbajo() {
  brazoPararPinza();
  Serial.println(F("#17P1305 #18P1004 #19P1864 T500"));
  delay(500);
}

void brazoMirarAtrasDesdeAbajo() {
  Serial.println(F("#17P1063 #18P2249 #19P873 T3000"));
  delay(3000);
}

void brazoSobreTolva() {
  Serial.println(F("#17P1299 #18P2044 #19P1086 T3000"));
  delay(3000);
}

void brazoMirarAlTecho() {
  Serial.println(F("#17P1657 #18P810 #19P611 T1000"));
  delay(1000);
}
