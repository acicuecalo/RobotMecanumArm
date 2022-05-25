// Sensor IMU de orientación Adafruit BNO055
// Conectado al arduino por I2C

void iniciarIMU() {
  if (!bno.begin())
  {
    Serial.print("IMU no detectada");
    while (1);
  }
}

int orientacionSensorBno055() {
  sensors_event_t orientationData , linearAccelData;
  bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  return (orientationData.orientation.x);
}
