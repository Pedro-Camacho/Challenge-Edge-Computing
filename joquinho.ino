// Incluindo biblioteca LiquidCrystal para o lcd
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);

// Declarando pins dos botões e colocando dentro de um array
int buttons[4] = {2, 3, 4, 5};

// Declarando pins dos leds e colocando dentro de um array
int leds[4]  = {8, 9, 10, 11};

// Declara o array button como boolean e inicia todos os elementos como false (0), se for verdadeiro será 1
boolean button[4] = {0, 0, 0, 0};

// Definindo o pin do buzzer
#define buzzer 6

// Definindo a quantidade de níveis do jogo
#define niveisJogo 5

// Criando arrays para o jogo
int bt_jogo[100]; 
int led_jogo[100]; 

// Criando a variável perdeu que será true ou false
boolean perdeu;

// Declarando outras variáveis
int jogar, nivel, estado;

void setup()
{ 
  // Iniciando serial
  Serial.begin(9600);

  // Iniciando os pins
  for(int i=0; i<=3; i++) 
  {
    pinMode(buttons[i], INPUT_PULLUP); // BUTTONS -> Porta de entrada
    pinMode(leds[i], OUTPUT); // LEDS -> Porta de saída
  }

  // Iniciando o buzer como porta de saída
  pinMode(buzzer, OUTPUT); 

  // Iniciando o lcd
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0); // Primeira linha do lcd
  lcd.print(" Bem-vindo(a)! ");
  lcd.setCursor(0,1); // Segunda linha do lcd
  lcd.print(" <- E - Kids -> ");
  delay(2000); 
  lcd.clear(); 

  // Gera números aleatórios
  randomSeed(analogRead(0));
}

void loop() 
{
  switch(estado)
  {
    /* 
    +-----------------------------------------+
    | ESTADO 0 => Verifica botão para iniciar |
    +-----------------------------------------+
    */
    case 0:
      lcd.setCursor(0, 0); lcd.print(" Botao vermelho "); // Primeira linha
      lcd.setCursor(0, 1); lcd.print(" > para jogar < "); // Segunda linha

      /* Lê o estado do botão que está conectado no pino 0 (vermelho) e 
        armazenando na variável button[0]*/
      button[0] = digitalRead(buttons[0]); 

      // Lê continuamente o estado do botão enquanto ele for pressionado
      while(button[0] == HIGH) 
      {
        button[0] = digitalRead(buttons[0]);
      }

      // Depois de pressionar o botão vermelho para jogar
      jogar = 1;

      // Vai para o primeiro nível 
      nivel = 1;

      // E muda para o primeior estado
      estado = 1;

      break;
    
    /* 
    +--------------------------------------------------+
    | ESTADO 1 => Mostra o nível e a sequência de leds |
    +--------------------------------------------------+
    */
    case 1:
      // Limpar o lcd
      lcd.clear();

      // Mostra o nível que o jogador está
      lcd.setCursor(3,0);
      lcd.print("Nivel: ");
      lcd.print((nivel/10)%10);
      lcd.print(nivel%10);
      lcd.setCursor(0,1);
      lcd.print("  -- Espere --  ");
      delay(1500);

      // Preenche o array com números(cores) aleatórios
      led_jogo[nivel] = random(8, 12); 

      // Enquanto o i for menor que o nível
      for(int i=1; i<=nivel; i++) 
      {
        // Liga o led 
        digitalWrite(led_jogo[i], HIGH);

        // Toca o buzzer
        tocarBuzzer(led_jogo[i]-7);

        // Desliga o led do 
        digitalWrite(led_jogo[i], LOW);

        delay(400);
      }
      delay(500);
      
      // Muda para o segundo estado
      estado = 2;
      break;
    
    /* 
    +---------------------------------------------------+
    | ESTADO 2 => Fala para o usuário tocar a sequência |
    +---------------------------------------------------+
    */
    case 2:
      // Muda para o terceiro estado
      estado = 3;
      lcd.setCursor(0, 1); 
      lcd.print("   -- Play --   "); 
      break;

    /* 
    +---------------------------------------+
    | ESTADO 3 => Lê os botões pressionados |
    +---------------------------------------+
    */
    case 3:
     for(int i=0; i<=3; i++)
     {
        /* Lê a sequência dos botões pressionados e armazenando na variável button[0]*/
        button[i] = digitalRead(buttons[i]);

        if(button[i] == LOW)
        {
          bt_jogo[jogar] = leds[i];

          // Liga o led
          digitalWrite(leds[i], HIGH);

          // Faz o som do botão pressionado (certo ou errado)
          tocarBuzzer(i+1); 

          // Lê continuamente o estado do botão enquanto ele for pressionado
          while(button[i] == LOW)
          {
            button[i] = digitalRead(buttons[i]);
          }
          delay(50);
          
          // Desliga o led
          digitalWrite(leds[i], LOW);

          jogar++;

          // Se a variavel jogar - 1 for igual ao nível
          if(jogar-1 == nivel)
          {
            // Reinicia a variável
            jogar = 1;
            // Passa para o quarto estado
            estado = 4;
            break;
          }
        }
      }
      delay(10);
      break;

    /* 
    +----------------------------------------------+
    | ESTADO 4 => Verifica a sequência dos botões  |
    +----------------------------------------------+
    */
    case 4:
      lcd.setCursor(0, 1); 
      lcd.print("  Verificando  ");
      delay(1000);

      // Enquanto i for menor que o nível
      for(int i=1; i<=nivel; i++)
      {
        // Se os botões forem diferentes dos leds
        if(led_jogo[i] != bt_jogo[i])
        {
          // O estado da variável perdeu muda para 1 (verdadeiro)
          perdeu = 1;
          break;
        }
      }      
      
      // Se a pessoa perder (perdeu = 1)
      if(perdeu==1)
      { 
        // Vai para o quinto estado
        estado = 5;
      }
      // Se a pessoa não perdeu
      else 
      {
        // Vai para o sexto estado
        estado = 6;
      }
      break;

    /* 
    +-----------------------+
    | ESTADO 4 => GAME OVER |
    +-----------------------+
    */
    case 5:
      lcd.clear();

      lcd.setCursor(0, 1); 
      lcd.print("!! GAME  OVER !!");
      // Toca a música de game over
      tone(buzzer, 350); 
      
      for(int i=0; i<=3; i++) 
      {
        // Liga o led
        digitalWrite(leds[i], HIGH);  
      }
      delay(1000);

      lcd.setCursor(0, 1); 
      lcd.print("!! GAME  OVER !!");

      lcd.clear();
      
      // Desliga o buzzer
      noTone(buzzer);
      delay(1000);

      for(int i=0; i<=3; i++) 
      {
        // Desliga o led
        digitalWrite(leds[i], LOW);  
      }

      // Volta para o nível 1
      nivel = 1;

      // Volta para o estado 0 
      estado = 0;

      // A variável perder será falsa
      perdeu = 0;
      break;

    /* 
    +--------------------+
    | ESTADO 6 => GANHOU |
    +--------------------+
    */
    case 6:
      // Se o nível for igual ao nível máximo do jogo (5)
      if(nivel == niveisJogo)
      {
        lcd.clear(); 
        // Parabeniza o jogador  
        lcd.setCursor(0, 0); 
        lcd.print("   Parabens!!!   "); 
        lcd.setCursor(0, 1); 
        lcd.print("  Voce ganhou!  ");
        delay(3000); 
        lcd.clear(); 
        // Volta para o nível 1          
        nivel = 1;          

        // Volta para o estado 0
        estado = 0;
      }
      else
      {
        lcd.setCursor(0, 1); 
        lcd.print("Proximo nivel...");
        delay(1000);   

        // Se o nível for menor que nível máximo do jogo (5)
        if(nivel < niveisJogo)
        {
          // Passa para o próximo nível
          nivel++;       
        }
        // Pula o estado 0 e vai para o primeiro estado
        estado = 1;
      }
      break;

    default:
      break;
  }
}

// Função para tocar o buzzer
void tocarBuzzer(int x) 
{
  // Liga o buzzer
  tone(buzzer, 650+(x*100));
  // Espera 300 milissegundos
  delay(300);
  // Desliga o buzzer
  noTone(buzzer);
}

