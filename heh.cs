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
  lcd.print("Booting up....");
}

int gameOn = 0;
int menuOn = 1;
int roundOn = 0;
int endMenuOn = 0;
// menu i need a system that keeps a static screen. updates when theres an input. then moves on to the next function. Within a system that continuously loops itself
// set screen before while
// set inputs and outcomes inside while, within (if)
void loop()
{
    lcd.clear();
    lcd.print("Welcome, choose your gamemode");
    lcd.setCursor(0,1);
    lcd.print("hits (20)|seconds(30)");
    lcd.setCursor(0,1);
    lcd.cursor();
  while (menuOn == 1){
    for (int b=0; b<3; b++){
      if (digitalRead(buttons[0]) == 1){
        lcd.setCursor(0,1);
      } else if (digitalRead(buttons[2]) == 1){
        lcd.setCursor(10,1);
      } else if (digitalRead(buttons[1]) == 1){
        menuOn=0;
        gameOn=1;
        lcd.clear();
        lcd.noCursor();
        lcd.setCursor(0,0);
        lcd.print("ok");
        delay(1000);
      }
    }
  }
  while (gameOn=1){
    lcd.clear();
    lcd.print("here we go");
  }
}