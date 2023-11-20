#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd(0);

int buttons[] = {2,3,4, 5, 6, 7};
int leds[] =    {8,9,10,11,12,13};

void Menu(){
  lcd.print("whassup");
  delay(200);
  lcd.noDisplay();
  delay(200);
  lcd.display();
}

void setup()
{
  Serial.begin(9600);

  for(int i=0; i<6; i++){
    pinMode(buttons[i], INPUT);
  }

  for(int i=0; i<6; i++){
    pinMode(leds[i], OUTPUT);
  }

  lcd.begin(16,2);
}

int gameOn = 0;
int menuOn = 0;
int roundOn = 0;
int endMenuOn = 0;
// menu i need a system that keeps a static screen. updates when theres an input. then moves on to the next function. Within a system that continuously loops itself
void loop()
{
  while (gameOn == 1){
    for (int b=0; b<6; b++){
      if (digitalRead(buttons[0]) == 1){
        
      }
      // if (digitalRead(buttons[b]) == 1){
      //   if(menuOn == 1){
      //     lcd.clear();
      //     lcd.print("Play Game?");
      //   }

      //   lcd.setCursor(0,1);
      //   lcd.print("b: ");
      //   lcd.print(b);
      // }
      // if (digitalRead(buttons[0])==1){
      //   lcd.clear();
      //   lcd.print("red ");
      //   lcd.print(swi);
      //   delay(2000);
      //   swi = 1;
      //   lcd.clear();
      //   lcd.print("red ");
      //   lcd.print(swi);
      // } else if (digitalRead(buttons[1])==1){
      //   lcd.clear();
      //   lcd.print("blue ");
      //   lcd.print(swi);
      //   delay(2000);
      //   swi = 0;
      //   lcd.clear();
      //   lcd.print("blue ");
      //   lcd.print(swi);
      // }
    }
    while (gameOn == 0){
      lcd.print("Game over buddy")
    }
  }
}