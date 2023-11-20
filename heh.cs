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

void Menu(){
  // setup variables
  int stat = 1;
  // setup lcd screen
  lcd.clear();
  lcd.print("Ready to play?");
  lcd.cursor();
  lcd.setCursor(0,1);
  lcd.print("y/n");
  // 
  

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
  lcd.print("Play game?");
}

void loop()
{
  for (int b=0; b<6; b++){
    if (digitalRead(buttons[b]) == 1){
      lcd.setCursor(0,1);
      lcd.print("b: ");
      lcd.print(b);
    }
  }
}
