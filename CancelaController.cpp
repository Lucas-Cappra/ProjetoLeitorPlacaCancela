#include "CancelaController.h"

// Construtor da classe
CancelaController::CancelaController() : buzzer(BUZZER_PIN), oled(), passageAllowed(false), pos(0) {}

// Função de inicialização
void CancelaController::begin() {
    Serial.begin(9600);

    // Inicializa o servo, display e buzzer
    myservo.attach(SERVO_PIN);
    oled.begin();
    buzzer.begin();
    playStartupSound();

    // Mensagem inicial no OLED
    oled.showMessage("Inicializando...");

    // Cancela começa fechada
    for (pos = pos; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
    }
    pinMode(DISTANCE_SENSOR_PIN, INPUT);

    Serial.println("Sistema Pronto. Envie 'X' para abrir ou 'Y' para fechar.");
}

// Função principal de loop
void CancelaController::loop() {
    // Lê o valor analógico do sensor de distância
    sensorValue = analogRead(DISTANCE_SENSOR_PIN);
    Serial.println(sensorValue);
    // Verifica se há comandos pela Serial
    if (Serial.available() > 0) {
        string comando = Serial.readString();

        if (comando == 'X' && sensorValue <= 30) {
            passageAllowed = true;
            buzzer.playSound(100, 2000);  // Som de permissão (alta frequência)
            buzzer.playSound(100, 4000);  // Som de permissão (média frequência)
            abrirCancela();
        } else if (comando == 'Y' && sensorValue <= 30) {
            passageAllowed = false;
            buzzer.playSound(100, 100);   // Som de negação (baixa frequência)
            buzzer.playSound(100, 2000);  // Som de negação (alta frequência)
            fecharCancela();
        }
    }

    // Fechar automaticamente a cancela se o carro passar e o sensor detectar um valor alto
    if (sensorValue > 30 && passageAllowed) {
        fecharCancela();
        passageAllowed = false;  // A cancela é fechada e a permissão é negada
    }

    // Exibe o status da passagem no OLED
    oled.showPassageStatus(passageAllowed);
}

// Função para abrir a cancela
void CancelaController::abrirCancela() {
    for (pos = pos; pos <= 90; pos += 1) {
        myservo.write(pos);
        delay(15);
    }
    Serial.println("Cancela aberta.");
}

// Função para fechar a cancela
void CancelaController::fecharCancela() {
    for (pos = pos; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
    }
    Serial.println("Cancela fechada.");
}

// Função para o som de inicialização
void CancelaController::playStartupSound() {
    int initialFrequency = 2000;  // Frequência inicial em Hz
    int finalFrequency = 2500;    // Frequência final em Hz
    int duration = 40;            // Duração de cada nota em ms

    // Gradualmente aumenta a frequência
    for (int freq = initialFrequency; freq <= finalFrequency; freq += 50) {
        tone(BUZZER_PIN, freq, duration);
        delay(duration);  // Atraso entre as notas
    }
}
