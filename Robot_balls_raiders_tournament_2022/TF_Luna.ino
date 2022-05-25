// Sensor de distancia
// Conectado al arduino por I2C

int distanciaSensorTfLuna() {
  int16_t  tfDist; // distancia en centímetros
  const int16_t  tfAddr = TFL_DEF_ADR;  // Usar la dirección I2C por defecto
  if ( tflI2C.getData( tfDist, tfAddr)) // Si se puede leer el sensor correctamente...
  {
    return (tfDist);
  }
  else return 8000; // Máxima distancia en cm que puede leer el sensor de distancia
}
