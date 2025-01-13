#include "BuzzerController.h"

// Construtor: define o pino do buzzer
BuzzerController::BuzzerController(int buzzerPin) : buzzerPin(buzzerPin) {}

// Configura o pino do buzzer como saída
void BuzzerController::begin() {
    pinMode(buzzerPin, OUTPUT);
}

// Toca o buzzer pelo tempo especificado (em milissegundos)
void BuzzerController::playSound(int duration, int freq) {
    tone(buzzerPin, freq);
    delay(duration);                // Mantém o buzzer ligado
    noTone(buzzerPin);
}
