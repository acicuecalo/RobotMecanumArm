void iniciarZumbador() {
  pinMode(11, OUTPUT); // zumbador con oscilador conectado en el pin D11
  digitalWrite(11, LOW);
}

void pitidoCorto() {
  digitalWrite(11, HIGH);
  delay(50);
  digitalWrite(11, LOW);
}

void pitidoLargo() {
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(11, LOW);
}
