void setup() {
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() > 0) { // Verifica si hay datos disponibles en el puerto serial
    String receivedText = Serial.readString(); // Lee la cadena de texto recibida
    Serial.print(recievedText);
  }

}
