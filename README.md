# E-kids

### O Problema
Um dos principais obstáculos que a Fórmula-E enfrenta é a falta de visibilidade do esporte em comparação com outras categorias automobilísticas mais estabelecidas, como a Fórmula-1 ou a NASCAR. Enquanto estas categorias têm décadas de história e uma presença global consolidada, a Fórmula-E ainda está em processo de construção de sua base de fãs e de se estabelecer como uma alternativa emocionante e sustentável no mundo das corridas.

A falta de um público mais amplo, especialmente entre as gerações mais jovens, pode ser atribuída a diversos fatores. Um deles é a percepção de que as corridas de carros elétricos podem não oferecer a mesma emoção e espetáculo das corridas de carros com motores de combustão interna. O som característico dos motores elétricos, que é consideravelmente mais silencioso do que o rugido dos motores a gasolina, pode não ter o mesmo apelo para os entusiastas de corridas que valorizam a sensação de velocidade e poder.

Além disso, a falta de investimento em marketing e promoção também contribui para a baixa visibilidade da Fórmula-E. Enquanto outras categorias automobilísticas contam com orçamentos substanciais para publicidade e eventos promocionais, a Fórmula-E pode não ter os mesmos recursos disponíveis para se destacar em um mercado tão competitivo.

### Nossa Solução
Nossa solução é criar uma plataforma on-line chamada “E-Kids" que se destaca por direcionar sua proposta para crianças e jovens, um público mais receptivo e aberto a novas experiências. Ao contrário de um público mais velho, que pode ter preferências sólidas, as crianças estão prontas para mergulhar em um universo completamente novo e emocionante. Ao cativar esse público em fase de descoberta, não apenas facilitamos a atração inicial, mas também garantimos uma conexão genuína e duradoura com a Fórmula-E. Essa estratégia não só garante o sucesso imediato do nosso site, mas também estabelece uma base de fãs sólida e apaixonada, pronta para crescer e evoluir com o tempo.

Em nossa plataforma, as crianças e os jovens podem acessar conteúdo educativo e atividades relacionadas à Fórmula-E, como sobre os pilotos, equipes, carros, corridas e circuitos. Porém o elemento principal da nossa solução é um álbum de figurinhas virtual, onde as crianças podem colecionar e trocar figurinhas dos pilotos e carros da Fórmula-E com seus amigos. Além disso, há também quizzes e outras atividades interativas relacionadas à Fórmula-E para entreter e educar as crianças. 


# Prototipo de jogo de memoria para ganhar pontos ou figurinhas E-kids
O arduino é utilizado neste projeto para a montagem de um jogo simples de memória para nosso público alvo infantil. Ao ganhat, os participantes têm a chance de acumular pontos ou até mesmo conquistar figurinhas raras para seu álbum virtual da Fórmula-E.

O jogo (conhecido como Simon Game ou Genius) consiste em um dispositivo com quatro botões coloridos que emitem sons e luzes. O objetivo do jogo é repetir uma sequência crescente de luzes e sons gerada aleatoriamente pelo dispositivo. Cada vez que o jogador completa corretamente a sequência, ela se torna mais longa e desafiadora. Se o jogador errar a sequência, o jogo termina. 

## 🎞 Link para o video apresentação
https://youtu.be/3hbB1hQXCTA

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
