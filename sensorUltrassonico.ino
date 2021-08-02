void setup()
{
  Serial.begin(9600); // Habilita Comunicação Serial a uma taxa de 9600 bauds.
 
  // Configuração do estado inicial dos pinos Trig e Echo.
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(4, LOW);
  
  // Configuração do pino usado no LED
  pinMode(5, OUTPUT);
}

void loop()
{
  // Pulso de 5V por pelo menos 10us para iniciar medição.
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  
  // Mede quanto tempo o pino de echo ficou no estado alto, ou seja, o tempo de propagação da onda.
  long duracao = pulseIn(3, HIGH);
  
  float distancia = 0.017*duracao;
  
  // Exibe o valor medido
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Define o estado do LED
  if (distancia>50){
  	digitalWrite(5, LOW);
  }else if (distancia<30){
    digitalWrite(5, HIGH);
  }else{
  	// rotina para ligar e desligar o led de acordo com a distância.
      float tempo_desligado = 25*distancia-250;
      digitalWrite(5,HIGH);
      delay(200);
      digitalWrite(5,LOW);
      delay(tempo_desligado);
  }
  
  delay(100);
}