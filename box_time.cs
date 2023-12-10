#include <Adafruit_LiquidCrystal.h>
#include <string>

int seconds = 0;

Adafruit_LiquidCrystal lcd(0);

int buttons[] = {2,3,4, 5, 6, 7};
int leds[] =    {8,9,10,11,12,13};
int delays[] = {100,200,500,1000,2000,3000};
int delaysLen = sizeof(delays)/sizeof(delays[0]);
String hits[] = {"na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na","na",};
int hitsLen = 60;

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
String mode = "hit";

// gives gamemode option
void pMenu() {
  lcd.clear();
  lcd.print("Game modes:");
  lcd.setCursor(0,1);
  lcd.print("hit|sec");
  lcd.setCursor(0,1);
  lcd.cursor();
  while (menuOn == 1){
    for (int b=0; b<3; b++){
      if (digitalRead(buttons[0]) == 1){
        lcd.setCursor(0,1);
        mode="hit";
      } else if (digitalRead(buttons[2]) == 1){
        lcd.setCursor(4,1);
        mode="sec";
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
}

// updates scores arrray
void Scoring(int target,int time) {
  // String targie = to_string(target);
  // String timeie = to_string(time);
  int combine(int a, int b) {
   int times = 1;
   while (times <= b)
      times *= 10;
   return a*times + b;
  }  
  // int thing = target
  Serial.println(combine(target,time));
}

// makes random delay from between button lightups, random from list
void randomdelay() {
  int ran = random(delaysLen);
  int randDel = delays[ran];

  delay(randDel);
}

// get light up random buttons then calculates time from light to buttonpress
void Game() {
  while (gameOn = 1){
    int randNum = random(6);
    int targetNum = randNum+1;

    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Target: ");
    lcd.print(targetNum);
    
    digitalWrite(leds[randNum], HIGH);
    long startTime= millis();

    lcd.setCursor(0,1);
    
    roundOn = 1;
    while (roundOn == 1){
      if (digitalRead(buttons[randNum]) == 1){
        long endTime= millis();
        
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("HIT");
        
        digitalWrite(leds[randNum],LOW);

        lcd.setCursor(0,1);
        lcd.print("Hitsped: ");
        lcd.print(startTime-endTime);
        int stime = startTime-endTime;
        Scoring(targetNum,stime);
        
        roundOn = 0;
        randomdelay();
      }
    }
  }
}

void loop() {
  // pMenu();
  Game();
}

