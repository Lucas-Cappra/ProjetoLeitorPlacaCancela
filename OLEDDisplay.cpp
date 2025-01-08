// OLEDDisplay.cpp

#include "OLEDDisplay.h"

// Construtor da classe
OLEDDisplay::OLEDDisplay() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

// Inicializa o display
void OLEDDisplay::begin() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        // Caso o display não seja encontrado
        for (;;);
    }
    display.clearDisplay();
    display.display();
}

// Mostra uma mensagem no display
void OLEDDisplay::showMessage(const char* message) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print(message);
    display.display();
}

// Mostra o valor do sensor no display
void OLEDDisplay::showSensorValue(int value) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Sensor Value:");
    display.setCursor(0, 10);
    display.print(value);
    display.display();
}

// Mostra mensagem com permissão ou negação de passagem
void OLEDDisplay::showPassageStatus(int value, bool &passageAllowed) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);

    if (value <= 50) {
        passageAllowed = true;
        display.print("Passage Allowed");
    } else {
        passageAllowed = false;
        display.print("Passage Denied");
    }

    display.setCursor(0, 10);
    display.print("Sensor Value:");
    display.setCursor(0, 20);
    display.print(value);
    display.display();
}
