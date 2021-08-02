#include <IRremote.h>

int const PINO_RECEPTOR = 11;
int LED_VERMELHO = 10;
int LED_VERDE = 9;
int LED_LARANJA = 8;
int LED_AZUL = 7;

int butao_Power = 16580863;
int vol_mais;
int vol_menos;
int skip;
int back;
int stop;
int butao_0;
int butao_1;
int butao_2;
int butao_3;
int butao_4;
int butao_5;
int butao_6;
int butao_7;
int butao_8;
int butao_9;


IRrecv receptor(PINO_RECEPTOR);

decode_results valorSaida;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_LARANJA, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  receptor.enableIRIn(); //Inicia o receptor
}

void loop() {
  if (receptor.decode(&valorSaida)) {
    receptor.resume(); // Recebe o próximo valor
    
    Serial.println(valorSaida.value);
    delay(100);
    
    
    if (valorSaida.value == 0xFD08F7){
      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_LARANJA, LOW);
      digitalWrite(LED_AZUL, LOW);
    }else if (valorSaida.value == 0xFD8877) {
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_LARANJA, LOW);
      digitalWrite(LED_AZUL, LOW);
    }else if (valorSaida.value == 0xFD48B7){
      digitalWrite(LED_LARANJA, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_AZUL, LOW);
    }else if (valorSaida.value == 0xFD28D7){
      digitalWrite(LED_AZUL, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, LOW);
      digitalWrite(LED_LARANJA, LOW); 
    }
  }
  delay(100);
}