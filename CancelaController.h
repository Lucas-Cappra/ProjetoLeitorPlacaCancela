#ifndef CANCELACONTROLLER_H
#define CANCELACONTROLLER_H

#include "OLEDDisplay.h"
#include <Servo.h>
#include "BuzzerController.h"

// Definições de pinos
#define DISTANCE_SENSOR_PIN A0
#define BUZZER_PIN 5
#define SERVO_PIN 9

class CancelaController {
public:
    // Construtor
    CancelaController();

    // Funções públicas
    void begin();         // Inicialização
    void loop();          // Loop principal
    void playStartupSound();  // Toca som de inicialização
    void abrirCancela();      // Abre a cancela
    void fecharCancela();     // Fecha a cancela

private:
    // Membros privados
    Servo myservo;           // Servo motor para a cancela
    OLEDDisplay oled;        // Instância do display OLED
    BuzzerController buzzer; // Instância do buzzer
    int pos;                 // Posição do servo
    bool passageAllowed;     // Controle de permissão de passagem
    int sensorValue;         // Valor lido do sensor de distância
};

#endif
