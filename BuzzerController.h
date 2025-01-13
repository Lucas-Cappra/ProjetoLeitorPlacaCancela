#ifndef BUZZERCONTROLLER_H
#define BUZZERCONTROLLER_H

#include <Arduino.h>

class BuzzerController {
public:
    // Construtor
    BuzzerController(int buzzerPin);

    // Inicializa o pino do buzzer
    void begin();

    // Toca o buzzer por uma duração específica
    void playSound(int duration, int freq);

private:
    int buzzerPin;  // Pino do buzzer
};

#endif  // BUZZERCONTROLLER_H
