# Prototipo de jogo de memoria para ganhar pontos no E-kids
O arduino é utilizado neste projeto para a montagem de um jogo simples de memória para nosso público alvo infantil.


## 🎞 Link para o video apresentação
!!

## 💎 Link do Tinkercad
https://wokwi.com/projects/400532287525314561

## 🔨 Montagem
### Componentes necessários
1. Arduino Uno
2. Buzzer
3. 4 LEDs (vermelho, verde, amarelo, azul)
5. 1 resistores de 10 kohm
6. 4 botões (vermelho, verde, amarelo, azul)
7. Display LCD 16x2

   
### Buzzer
1. Conecte a perna positiva do buzzer a uma porta digital 6 do arduino.
2. Conecte a perna negativa do buzzer ao GND (terra) do Arduino.
   
### LEDs
1. Conecte cada perna positiva dos LEDs a um resistor de 10kohm.
2. Conecte as pernas negativas a ccorrente GND
3. Conecte as pernas positiva dos LEDs verde, amarelo e vermelho as portas "8", "9", "10" e "11" respectivamente.

### Display lcd
1. Conecte a porta "GND" ao terra e a porta "VCC" a corrente 5 volts
2. Conecte a porta "SDA" a porta analógica "A4"
3. Conecte a porta "SCL" a porta analógica "A5"

### Botôes 
1. Concte as portas "2, "3", "4" e "5" as "perninhas" dos botões e um ao GND
   
## ⚙ Funcionamento
![imagem_prototipo](https://github.com/Pedro-Camacho/Challenge-Edge-Computing/assets/49591140/026dd98d-9577-4e96-a6bc-0a47b0cd490d)


## Instalação de dependecias
Para a execução da aplicação será necessária a instalção da biblioteca Liquid Crystal

Nosso projeto funciona da seguinte maneira, iniciamos todas as variáveis globais como portas de saídas e entradas de componente,
todos os LEDs, botões, buzzer, assim inciamos as variáveis de botões jogados, o estado de jogo e o nível.
Assim entramos no nosso setup onde inciamos cada componente e o monitor serial, e logo em seguida no nosso loop principal, onde o código verifica o estado do jogo atual e procede conforme o estado que esteja, onde o caso 0 é quando iremos inciar o jogo em seguida o caso 1 temos nosso primeiro nivel que toca uma nota relacionada a um dos leds e assim você em seguida deve acertar a nota aertando o botão relacionado, assim o código verifica se você acertou a ordem e vai para os proximos casos 2,3,4,5 e se você errar mostramos no display que o jogo se encerra.



## 🙎‍♂️🙎‍♀️ INTEGRANTES

- Pedro Almeida Camacho rm: 556831
- Camila Pedroza da Cunha rm: 558768
- Isabelle Dallabeneta rm: 554592
- Nicoli Amy Kassa rm: 559104
- Diógenes Henrique do Santos Costa rm: 559127
