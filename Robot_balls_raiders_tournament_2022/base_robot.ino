//Funciones de movimientos de la base mecanum

void iniciarMotorShield() {
  AFMS.begin();
  pararMotores();
}

void girarParaBuscarObjetosDistanciaMenorDe(int distanciaMinima) {
  moverBaseRobot(0, 0, 15, false); // rotar a derecha despacio. El false hace que no haya control de mínima velocidad
  while (distanciaSensorTfLuna() > distanciaMinima);
  pararMotores();
  pitidoCorto();
}

void girarBaseParaApuntarAlRumbo(int rumbo, bool giroaDerechas) {
  const int ejeX = 0;
  const int ejeY = 0;
  const int velocidadGiro = 20;
  bool limitarMinimo = true;
  while (int(orientacionSensorBno055()) != rumbo) {
    if (giroaDerechas == true) {
      moverBaseRobot(ejeX, ejeY, velocidadGiro, limitarMinimo);
    }
    else { // giro a izquierdas
      moverBaseRobot(ejeX, ejeY, -velocidadGiro, limitarMinimo);
    }
  }
  pararMotores();
}

void moverBaseRobot(int ejeX, int ejeY, int ejeZ, bool limitarVelocidadMinimaMotores) // Los valores de control de -100 a 100
{
  const int numMotores = 4;
  const int velocidadMotorMinima = 30; // originalmente en 20
  int velocidadMotor[numMotores];

  // Entradas
  ejeX = constrain(ejeX, -100, 100);
  ejeX = map(ejeX, -100, 100, -255, 255);
  ejeY = constrain(ejeY, -100, 100);
  ejeY = map(ejeY, -100, 100, -255, 255);
  ejeZ = constrain(ejeZ, -100, 100);
  ejeZ = map(ejeZ, -100, 100, -255, 255);

  // Mezclador
  velocidadMotor[0] = ejeY + ejeZ + ejeX; //motorDelanteroIzquierdo
  velocidadMotor[1] = ejeY - ejeZ - ejeX; //motorDelanteroDerecho
  velocidadMotor[2] = ejeY - ejeZ + ejeX; //motorTraseroDerecho
  velocidadMotor[3] = ejeY + ejeZ - ejeX; // motorTraseroIzquierdo

  //ajuste de velocidad mínima con banda muerta
  if (limitarVelocidadMinimaMotores == true) {
    for (int i = 0; i < numMotores; i++) {
      if (velocidadMotor[i] == 0) {
        break;
      }
      else if (velocidadMotor[i] < 0) {
        velocidadMotor[i] = constrain (velocidadMotor[i], -255, -velocidadMotorMinima);
      }
      else if (velocidadMotor[i] > 0) {
        velocidadMotor[i] = constrain(velocidadMotor[i], velocidadMotorMinima, 255);
      }
    }
  }

  // Salidas Motores
  motorDelanteroIzquierdo->setSpeed(abs(velocidadMotor[0]));
  if (velocidadMotor[0] == 0) {
    motorDelanteroIzquierdo->run(RELEASE);
  }
  if (velocidadMotor[0] > 0) {
    motorDelanteroIzquierdo->run(FORWARD);
  }
  if (velocidadMotor[0] < 0) {
    motorDelanteroIzquierdo->run(BACKWARD);
  }
  motorDelanteroDerecho->setSpeed(abs(velocidadMotor[1]));
  if (velocidadMotor[1] == 0) {
    motorDelanteroDerecho->run(RELEASE);
  }
  if (velocidadMotor[1] > 0) {
    motorDelanteroDerecho->run(FORWARD);
  }
  if (velocidadMotor[1] < 0) {
    motorDelanteroDerecho->run(BACKWARD);
  }
  motorTraseroDerecho->setSpeed(abs(velocidadMotor[2]));
  if (velocidadMotor[2] == 0) {
    motorTraseroDerecho->run(RELEASE);
  }
  if (velocidadMotor[2] > 0) {
    motorTraseroDerecho->run(FORWARD);
  }
  if (velocidadMotor[2] < 0) {
    motorTraseroDerecho->run(BACKWARD);
  }
  motorTraseroIzquierdo->setSpeed(abs(velocidadMotor[3]));
  if (velocidadMotor[3] == 0) {
    motorTraseroIzquierdo->run(RELEASE);
  }
  if (velocidadMotor[3] > 0) {
    motorTraseroIzquierdo->run(FORWARD);
  }
  if (velocidadMotor[3] < 0) {
    motorTraseroIzquierdo->run(BACKWARD);
  }
}

void pararMotores()
{
  motorDelanteroIzquierdo->run(RELEASE);
  motorDelanteroDerecho->run(RELEASE);
  motorTraseroDerecho->run(RELEASE);
  motorTraseroIzquierdo->run(RELEASE);
}
