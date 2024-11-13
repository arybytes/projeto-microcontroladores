# Simulador de Sensor de Estacionamento com Arduino

## Descrição
Simulador de sensor de estacionamento que utiliza Arduino para medir a proximidade de objetos e emitir alertas sonoros e visuais. Ideal para assistência em manobras e prevenção de colisões.

## Objetivo
Reproduzir a funcionalidade de um sensor de estacionamento automotivo, emitindo alertas conforme a proximidade do objeto.

## Implementação 

![Projeto](https://github.com/user-attachments/assets/2cbe785e-6388-4968-b97f-d29ab5b4ca6f)

## Componentes Utilizados
- Arduino Uno
- Sensor Ultrassônico HC-SR04
- LED
- Buzzer
- Resistor de 220Ω
- Fios de conexão

## Diagrama de Conexão
![diagrama](https://github.com/user-attachments/assets/bcb8a0f0-ecc1-444c-9dbf-30bda78fdb2f)

## Funcionamento
1. O sensor mede a distância do objeto.
2. O Arduino processa a informação.
3. Dependendo da proximidade, o LED e o buzzer são acionados com intensidade crescente.

## Código
O código fonte do projeto pode ser encontrado na pasta `/src`.

## Exemplo de Uso
1. Monte o circuito conforme o diagrama de conexão.
2. Carregue o código no Arduino.
3. Teste o sistema aproximando objetos do sensor para ver o alerta visual e sonoro.

