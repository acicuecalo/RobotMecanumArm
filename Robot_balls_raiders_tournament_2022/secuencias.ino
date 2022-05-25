//Secuencias de funciones

void secuenciaDeInicializaciones() {
  iniciarZumbador();
  pitidoCorto();
  Wire.begin();
  Serial.begin(115200);
  brazoPosicionReposo();
  pitidoCorto();
  iniciarHuskylens();
  iniciarMotorShield();
  iniciarIMU();
  iniciarDisparador();
}

void secuenciaPrincipal() {
  const int numPelotas = 5;
  recogerPelotas(numPelotas);
  girarBaseParaApuntarAlRumbo(180, true); //gira la base hasta los 180 grados para apuntar a la diana con el disparador de la parte trasera
  centrarLaDiana();
  dispararPelotas(numPelotas);
  brazoPosicionReposo();
}

void recogerPelotas(int numeroDePelotasParaRecoger) {
  for (int i = 0; i <= (numeroDePelotasParaRecoger - 1); i++) {
    centrarTagDelTechoHuskylens();
    brazoPosicionReposo();
    girarParaBuscarObjetosDistanciaMenorDe(80); // gira la base hasta encontrar un objeto a menos de 80 centímetros
    avanzarHastaCentrarObjetoHuskylens(); // avanza hasta que la bola queda centrada en pantalla
    cogerPelota();
  }
  brazoPosicionReposo();
}

void cogerPelota(){
  brazoApuntarBolaDesdeArriba();
  brazoAbrirPinza();
  brazoApuntarBolaDesdeAbajo();
  brazoCerrarPinza();
  brazoSobreTolva();
  brazoAbrirPinza();
  brazoCerrarPinza();
  pitidoCorto();
}
