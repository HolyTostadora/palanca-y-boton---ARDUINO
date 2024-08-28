#include <SoftwareSerial.h>

// Configura un puerto serial software en pines 10 y 11
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
    Serial.begin(9600);    // Puerto Serial principal para el Monitor Serial
    mySerial.begin(9600);  // Puerto Serial software para la comunicación con Unity
}

void loop() { 
    // Leer datos del puerto Serial (desde el Monitor Serial) y enviarlos al puerto Serial software
    if (Serial.available()) {
        String dataFromSerial = Serial.readStringUntil('\n');
        mySerial.println(dataFromSerial);
    }
}
