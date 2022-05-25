// Robot con base tipo mecanum, brazo robot y sensor de visión artificial
// Para el concurso del reto de @esdrufao
// abril y mayo de 2022
// Por Paco Carabaza

#include <Wire.h>

#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();             // Crea los objetos para la shield de motores con la dirección I2C por defecto
Adafruit_DCMotor *motorDelanteroIzquierdo = AFMS.getMotor(1);   // Motor 1
Adafruit_DCMotor *motorDelanteroDerecho = AFMS.getMotor(2);     // Motor 2
Adafruit_DCMotor *motorTraseroDerecho = AFMS.getMotor(3);       // Motor 3
Adafruit_DCMotor *motorTraseroIzquierdo = AFMS.getMotor(4);     // Motor 4

#include <TFLI2C.h>  // Librería para sensor de distancia TFLuna-I2C de Benewake
TFLI2C tflI2C;

#include <Adafruit_Sensor.h> 
#include <Adafruit_BNO055.h> // Librería para sensor IMU Adafruit BNO055
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28); //id, address (dirección por defecto 0x28)

#include "HUSKYLENS.h"  // Librería para el sensor de visión artificial HuskyLens
HUSKYLENS huskylens;

void setup()
{
  secuenciaDeInicializaciones();
  secuenciaPrincipal();
}

void loop() {
}
