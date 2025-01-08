#include "OLEDDisplay.h"
#include <Servo.h>
Servo myservo;
// Instância do objeto OLEDDisplay
OLEDDisplay oled;

// Configuração do pino do sensor de distância
#define DISTANCE_SENSOR_PIN A0

bool passageAllowed = false;
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);

    // Inicializa o display
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    oled.begin();

    // Mostra uma mensagem inicial
    oled.showMessage("Initializing...");

    // Configura o pino do sensor como entrada
    pinMode(DISTANCE_SENSOR_PIN, INPUT);
    
}

void loop() {

    // Lê o valor analógico do sensor de distância
    int sensorValue = analogRead(DISTANCE_SENSOR_PIN);

    // Atualiza o status de passagem e exibe no display
    oled.showPassageStatus(sensorValue, passageAllowed);

    // Aqui você pode usar 'passageAllowed' para outras ações
    if (passageAllowed) {
        // Permitir passagem
        Serial.println("Permitir passagem");
        for (pos = pos; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(15);
        }                           // waits for the servo to get there
    } else {
        // Negar passagem
        Serial.println("Negar passagem");
        for (pos = pos; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);
        delay(15);                           // waits for the servo to get there
        }
    }

    // Atraso para evitar atualizações muito rápidas
    delay(500);
}
