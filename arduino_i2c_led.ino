#include <Wire.h>

// Definição do endereço I2C do Arduino (deve ser o mesmo na Raspberry Pi)
const int ENDERECO_I2C = 0x08;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
  // Inicializa o barramento I2C como dispositivo controlado (responder/slave)
  Wire.begin(ENDERECO_I2C);
  Wire.onReceive(receiveEvent);
  
  Serial.println("Arduino inicializado no barramento I2C.");
}

void loop() {
  delay(100);
}

// Função executada automaticamente quando a Raspberry Pi envia dados
void receiveEvent(int howMany) {
  if (Wire.available()) {
    int comando = Wire.read();
    Serial.print("Comando recebido: ");
    Serial.println(comando);
    
    if (comando == 1) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("Estado: LED ACESO");
    } else if (comando == 0) {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("Estado: LED APAGADO");
    }
  }
}
