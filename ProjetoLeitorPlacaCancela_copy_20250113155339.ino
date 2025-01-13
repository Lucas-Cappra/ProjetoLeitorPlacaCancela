#include "CancelaController.h"

// Cria uma instância do controlador de cancela
CancelaController cancelaController;

void setup() {
  // Inicializa o controlador
  cancelaController.begin();
}

void loop() {
  // Chama o loop principal do controlador de cancela
  cancelaController.loop();
}
