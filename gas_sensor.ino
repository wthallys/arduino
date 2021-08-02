/*
	### Detector de gás ###
    # Verde = Seguro #
    # Amarelo = Alerta #
    # Laranja = Perigo #
    # Vermelho = Área Contaminada #
*/

int const PINO_SGAS = A1;
int LED_VERDE = 7;
int LED_AMARELO = 6;
int LED_VERMELHO1 = 5;
int LED_VERMELHO2 = 4;
int BUZZER = 3;
int trig = 9;
int echo = 10;
float distancia;
float tempo;

void setup(){
  	pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERMELHO1, OUTPUT);
    pinMode(LED_VERMELHO2, OUTPUT);
  	pinMode(BUZZER, OUTPUT);
  	pinMode(trig, OUTPUT);
  	pinMode(echo, INPUT);
  
    Serial.begin(9600);
}

void loop(){
    int valor = analogRead(PINO_SGAS);
    valor = map(valor, 300, 750, 0, 100);
    digitalWrite(LED_VERDE, HIGH);
  	digitalWrite(LED_AMARELO, valor >= 30 ? HIGH : LOW);
    digitalWrite(LED_VERMELHO1, valor >= 50 ? HIGH : LOW);
    digitalWrite(LED_VERMELHO2, valor >= 80 ? HIGH : LOW);
  	if (valor >= 80){
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(BUZZER, LOW);
    }
  
  	distancia = Ultrassom();
  	if (distancia >= 160){
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(BUZZER, LOW);
    }
  	
  	Serial.println(distancia);
  
  delay(100);
}

float Ultrassom() {
	digitalWrite(trig, HIGH);
    delayMicroseconds(10);
  	digitalWrite(trig, LOW);
  
  	tempo = pulseIn(echo, HIGH);
  	return tempo / 29.38 / 2;
  
}