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



## Instalação de dependecias
Para a execução da aplicação será necessária a instalção da biblioteca Liquid Crystal

O sistema é divido entre as três principais grandezas analisadas:

> Os valores de luminosidade e umidade foram convertidos em uma escalas de 0 a 100 com base na amplitude dos seus respectivos sensores para facilitar a analise

### Luminosidade

#### Luminosidade menor que 30
- Enquanto a luminosidade for menor do que 30 o led verde se manterá acesso
- o ambiente está na luminosidade ideal
  
#### Luminosidade maior que 30 e menor que 50
- Enquanto a luminosidade estiver nessa faixa o led amarelo se manterá acesso
- O ambiente está a meia luz
- Manter vigilancia

#### Luminosidade maior 50
- Enquanto a luminosidade estiver nessa faixa o led vermelho se manterá acesso
- O ambiente está com muita luminosidade
- Agir imediatamente
- Alerta sonoro
  

  
### Umidade
#### umidade menor que 50
- Enquanto a umidade estiver nessa faixa, nenhum led se manterá acesso
- Display mostrará a mensagem "umidade baixa"
  
#### umidade maior que 50 e menor que 70
- Enquanto a umidade estiver nessa faixa, o led amarelo se manterá acesso
- Display mostrará a mensagem "umidade OK"
- Alerta sonoro
- Manter vigilancia

#### umidade maior que 70
- Enquanto a umidade estiver nessa faixa, o led vermelho se manterá acesso
- Display mostrará a mensagem "umidade ALTA"
- Alerta sonoro
- Agir imediatamente


  
### Temperatura 
#### temperatura menor que 10
- Enquanto a umidade estiver nessa faixa, nenhum led se manterá acesso
- Display mostrará a mensagem "temperatura baixa"
  
#### temperatura maior que 10 e menor que 15
- Enquanto a umidade estiver nessa faixa, o led amarelo se manterá acesso
- Display mostrará a mensagem "temperatura OK"
- Alerta sonoro
- Manter vigilancia

#### temperatura maior que 15
- Enquanto a umidade estiver nessa faixa, o led vermelho se manterá acesso
- Display mostrará a mensagem "temperatura ALTA"
- Alerta sonoro
- Agir imediatamente


## 🙎‍♂️🙎‍♀️ INTEGRANTES

- Pedro Almeida Camacho rm: 556831
- Camila Pedroza da Cunha rm: 558768
- Isabelle Dallabeneta rm: 554592
- Nicoli Amy Kassa rm: 559104
- Diógenes Henrique do Santos Costa rm: 559127
