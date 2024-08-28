void setup() {
  // Inicia la comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    // Lee la línea completa recibida desde Unity
    String inputString = Serial.readStringUntil('\n');

    // Envía el string recibido al Monitor Serial de Arduino
    Serial.println("String recibido: " + inputString);
  }
}
