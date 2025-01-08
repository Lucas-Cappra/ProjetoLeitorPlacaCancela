// OLEDDisplay.h

#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configurações do OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

class OLEDDisplay {
private:
    Adafruit_SSD1306 display;

public:
    // Construtor da classe
    OLEDDisplay();

    // Inicializa o display
    void begin();

    // Mostra uma mensagem no display
    void showMessage(const char* message);

    // Mostra o valor do sensor no display
    void showSensorValue(int value);

    // Mostra mensagem com permissão ou negação de passagem
    void showPassageStatus(int value, bool &passageAllowed);
};

#endif
