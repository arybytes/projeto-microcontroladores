#define trigPin 9
#define echoPin 10
#define ledPin 13
#define buzzerPin 11

const float limite1 = 30.0; // Limite de 30 cm 
const float limite2 = 20.0; // Limite de 20 cm 
const float limite3 = 10.0; // Limite de 10 cm 
const float limite4 = 5.0;  // Limite de 5 cm 

void setup() {
    Serial.begin(9600);           // Inicializa a comunicação serial 
    pinMode(trigPin, OUTPUT);     // Configura o pino Trig como saída 
    pinMode(echoPin, INPUT);      // Configura o pino Echo como entrada 
    pinMode(ledPin, OUTPUT);      // Configura o pino LED como saída 
    pinMode(buzzerPin, OUTPUT);   // Configura o pino Buzzer como saída 
    desligarLED(); 
}

void loop() { 
    inicializarTrigger();                 // Envia o pulso de Trigger 
    float distancia = calcularDistancia(); // Calcula a distância medida 
    desligarLED();                        // Garante que o LED está apagado 
    if (distancia < limite1) {            // Se estiver na zona de alerta 
        alertas(distancia);               // Aciona os alertas conforme a faixa 
    } 
    delay(100);                           // Reduz a pausa entre as leituras para tornar mais ágil 
}

// Função para desligar o LED 
void desligarLED() { 
    digitalWrite(ledPin, LOW); 
}

// Função de alerta visual e sonoro com base na distância 
void alertas(float distancia) { 
    int frequencia;      // Frequência do som do buzzer 
    int duracaoBipe;     // Duração do bipe 
    int intervaloBipe;   // Intervalo entre bipes

    if (distancia < limite1 && distancia >= limite2) { 
        frequencia = 1000;  // Frequência mais baixa (simulando uma voz mais baixa)
        duracaoBipe = 200; 
        intervaloBipe = 300; // Pausa de 300 ms entre bipes para zona de 30 cm a 20 cm 
    } else if (distancia < limite2 && distancia >= limite3) { 
        frequencia = 1500;  // Frequência média (simulando uma voz mais alta)
        duracaoBipe = 150; 
        intervaloBipe = 200; // Pausa de 200 ms entre bipes para zona de 20 cm a 10 cm 
    } else if (distancia < limite3 && distancia >= limite4) { 
        frequencia = 2000;  // Frequência mais alta (simulando uma voz mais aguda)
        duracaoBipe = 100; 
        intervaloBipe = 100; // Pausa de 100 ms entre bipes para zona de 10 cm a 5 cm 
    } else if (distancia < limite4) { 
        frequencia = 2500;  // Frequência muito alta (simulando um alerta urgente)
        duracaoBipe = 50; 
        intervaloBipe = 50;  // Pausa de 50 ms entre bipes para zona de menos de 5 cm, quase contínuo 
    } 

    digitalWrite(ledPin, HIGH);        // Acende o LED
    tone(buzzerPin, frequencia, duracaoBipe); // Emite o som do buzzer
    delay(duracaoBipe + intervaloBipe); // Aguarda o tempo da duração mais intervalo entre bipes
    digitalWrite(ledPin, LOW);         // Apaga o LED durante a pausa
}

// Função para calcular a distância com o sensor ultrassônico 
float calcularDistancia() { 
    unsigned long duration = pulseIn(echoPin, HIGH); 
    float distancia = duration * 0.034 / 2.0; 
    Serial.print("Distância: "); 
    Serial.print(distancia); 
    Serial.println(" cm"); 
    return distancia; 
}

// Função para inicializar o pulso do Trig 
void inicializarTrigger() { 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
}
