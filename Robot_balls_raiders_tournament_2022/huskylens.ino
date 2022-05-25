// Funciones para el control del sensor de visión artificial Huskylens
// Conectado al arduino por I2C

void iniciarHuskylens() {
  while (!huskylens.begin(Wire))
  {
    Serial.println(F("HuskyLens begin failed!"));
    delay(100);
  }
  huskylens.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);
}

void centrarLaDiana() {
  int centroBloqueX = 160;
  int centroBloqueY = 200;
  int xMapeada = 0;
  int yMapeada = 0;
  int alturaBloque = 0;
  int anchuraBloque = 0;
  bool flagSeguirBuscando = true;
  int ID0 = 0; //not learned results. Grey result on HUSKYLENS screen
  int ID1 = 1; //primer TAG aprendido
  const int bandaMuertaHuskylens = 5;
  const int porcentajeVelocidadY = 30;
  const int porcentajeVelocidadX = 30;
  brazoMirarAtrasDesdeAbajo();
  huskylens.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);
  while (flagSeguirBuscando == true) {
    if (huskylens.request(ID1)) //busca el tag ID1
    {
      HUSKYLENSResult result = huskylens.get(ID1, 0);
      if (result.command == COMMAND_RETURN_BLOCK)//result is a block
      {
        centroBloqueX = result.xCenter;
        xMapeada = map(centroBloqueX, 0, 320, -porcentajeVelocidadX, porcentajeVelocidadX);
        xMapeada = constrain(xMapeada, -porcentajeVelocidadX, porcentajeVelocidadX);
        anchuraBloque = result.width;
        yMapeada = map(anchuraBloque, 30, 50, -porcentajeVelocidadY, porcentajeVelocidadY);
        yMapeada = constrain(yMapeada, -porcentajeVelocidadY, porcentajeVelocidadY);
        moverBaseRobot (xMapeada, yMapeada, 0, true); //traslaciónizquierda/derecha, adelante/atras, rotación izquierda/derecha
        if (xMapeada > -bandaMuertaHuskylens && xMapeada < bandaMuertaHuskylens && yMapeada > -bandaMuertaHuskylens && yMapeada < bandaMuertaHuskylens) {
          flagSeguirBuscando = false;
          pararMotores();
        }
      }
      else { //No se encuentra el tag ID1.
        pararMotores();
      }
    }
  }
  pitidoCorto();
}

void centrarTagDelTechoHuskylens() {
  int centroBloqueX = 160;
  int centroBloqueY = 200;
  int xMapeada = 0;
  int yMapeada = 0;
  int alturaBloque = 0;
  int anchuraBloque = 0;
  bool flagSeguirBuscando = true;
  int ID0 = 0; //not learned results. Grey result on HUSKYLENS screen
  int ID1 = 1; //primer TAG aprendido
  const int bandaMuertaHuskylens = 2; // orininal en 2
  const int porcentajeVelocidadY = 50; // original en 75
  const int porcentajeVelocidadX = 80; // original en 75
  brazoMirarAlTecho();
  huskylens.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);
  while (flagSeguirBuscando == true) {
    if (huskylens.request(ID1)) //request blocks and arrows tangged ID == ID1 from HUSKYLENS
    {
      HUSKYLENSResult result = huskylens.get(ID1, 0);
      if (result.command == COMMAND_RETURN_BLOCK)//result is a block
      {
        centroBloqueX = result.xCenter;
        xMapeada = map(centroBloqueX, 0, 320, -porcentajeVelocidadX, porcentajeVelocidadX);
        xMapeada = constrain(xMapeada, -porcentajeVelocidadX, porcentajeVelocidadX);
        centroBloqueY = result.yCenter;
        yMapeada = map(centroBloqueY, 0, 240, -porcentajeVelocidadY, porcentajeVelocidadY);
        yMapeada = constrain(yMapeada, -porcentajeVelocidadY, porcentajeVelocidadY);
        moverBaseRobot (xMapeada, yMapeada, 0, true); //traslaciónizquierda/derecha, adelante/atras, rotación izquierda/derecha
        if (xMapeada > -bandaMuertaHuskylens && xMapeada < bandaMuertaHuskylens && yMapeada > -bandaMuertaHuskylens && yMapeada < bandaMuertaHuskylens) {
          flagSeguirBuscando = false;
          pararMotores();
        }
      }
      else { //No se encuentra el tag ID1.
        //pararMotores();
      }
    }
  }
  pitidoCorto();
}

void avanzarHastaCentrarObjetoHuskylens() {
  int centroBloqueX = 160;
  int centroBloqueY = 200;
  int xMapeada = 0;
  int yMapeada = 0;
  int alturaBloque = 0;
  int anchuraBloque = 0;
  bool flagSeguirBuscando = true;
  int ID0 = 0; //not learned results. Grey result on HUSKYLENS screen
  int ID1 = 1; //first learned results. colored result on HUSKYLENS screen
  const int bandaMuertaHuskylens = 2;
  const int porcentajeVelocidadY = 30;
  const int porcentajeVelocidadX = 30;
  huskylens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
  while (flagSeguirBuscando == true) {
    if (huskylens.request(ID1)) //request blocks and arrows tangged ID == ID1 from HUSKYLENS
    {
      HUSKYLENSResult result = huskylens.get(ID1, 0);
      if (result.command == COMMAND_RETURN_BLOCK)//result is a block
      {
        centroBloqueX = result.xCenter;
        xMapeada = map(centroBloqueX, 0, 320, -porcentajeVelocidadX, porcentajeVelocidadX);
        centroBloqueY = result.yCenter;
        yMapeada = map(centroBloqueY, 0, 240, porcentajeVelocidadY, -porcentajeVelocidadY);
        moverBaseRobot (xMapeada, yMapeada, 0, true); //traslaciónizquierda/derecha, adelante/atras, rotación izquierda/derecha
        if (xMapeada > -bandaMuertaHuskylens && xMapeada < bandaMuertaHuskylens && yMapeada > -bandaMuertaHuskylens && yMapeada < bandaMuertaHuskylens) {
          flagSeguirBuscando = false;
          pararMotores();
        }
      }
      else { //No se encuentra ningún objeto del color ID1.
        moverBaseRobot (0, 20, 0, true);
      }
    }
  }
  pararMotores();
  pitidoCorto();
}
