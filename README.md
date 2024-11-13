# Simulador de Sensor de Estacionamento com Arduino

## Descrição
Simulador de sensor de estacionamento que utiliza Arduino para medir a proximidade de objetos e emitir alertas sonoros e visuais. Ideal para assistência em manobras e prevenção de colisões.

## Objetivo
Reproduzir a funcionalidade de um sensor de estacionamento automotivo, emitindo alertas conforme a proximidade do objeto.

## Implementação 

![WhatsApp Image 2024-11-13 at 15 31 12](https://github.com/user-attachments/assets/f3e5671a-60d6-40c4-946c-c32b3d217efe)

## Componentes Utilizados
- Arduino Uno
- Sensor Ultrassônico HC-SR04
- LED
- Buzzer
- Resistor de 220Ω
- Fios de conexão

## Diagrama de Conexão
![Diagrama de Conexão](images/diagrama_conexao.png)

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

