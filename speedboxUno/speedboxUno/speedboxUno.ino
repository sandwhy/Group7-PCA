#include <TFT.h>  
#include <SPI.h>

// <for the uno> //
// int sck = 13;
// int sdk = 11;
// <for the mega> //
int sck = 52;
int sdk = 51;
// <works for any> //
int cs  = 10;
int dc  = 9;
int rst = 8;

TFT disp = TFT(cs,dc,rst);

// < Mega > //
// int buttons[] = {30,31,32,33,34,35};
// int leds[]    = {36,37,38,39,40,41};
// < Uno > //
int buttons[]       = {3,4,5};
int leds[]       = {6,7,12};

int buzzers[] = {42,43,44,45,46,47};
int delays[] = {1000,1000,2000,2000,2000,2000,3000};
int delaysLen = sizeof(delays)/sizeof(delays[0]);
int hits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// int hits[] = {12,12,0,12,100,0,12,13,0};
int hitsLen = sizeof(hits)/sizeof(hits[0]);

char cstr[16];
// <HOW TO TEXT INT> //
// itoa(//int here//, cstr, 10) //



void setup()
{
  Serial.begin(9600);
  for(int i=0; i<6; i++){
    pinMode(buttons[i], INPUT);
  }
  for(int i=0; i<6; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i],0);
  }

  // scr: boot up sequence
  disp.begin();
  disp.background(0,0,0);
  disp.stroke(255, 255, 255);
  // << text sizes and spacing >> //
  disp.setTextSize(3);
  disp.text("Booting up....", 0,0);

}



int menuOn = 1;
  int menuOptions1 = 0;
  int menuOptions2 = 0;
  String gameMode = "count";
  int countsVal = 15;
  int timedVal = 30000;
int gameOn = 0;
  int gameLoop = 0;
  int roundLoop = 0;
int endMenuOn = 0;

// << STARTING MENU >> //
void setMenu() {
  // <reset> //
  disp.stroke(255,255,255);
  disp.setTextSize(2);
  disp.text("Game mode: ", 0,0);
  disp.text("- Count", 5,20);
  disp.text("- Timed", 5,40);
}
void setThings () {
  disp.stroke(255,255,255);
  disp.setTextSize(2);
  if (gameMode == "count") {
    disp.text("Set number of targets: ", 0,0);
    disp.text("(10)(15)(20)(25)", 0,20);
  } else if (gameMode == "timed") {
    disp.text("Set Time: ", 0,0);
    disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
  }
}
void delMenu() {
  // <clear> //
  disp.stroke(0,0,0);
  disp.setTextSize(2);
  disp.text("Game mode: ", 0,0);
  disp.text("- Count", 5,20);
  disp.text("> Count <", 5,20);
  disp.text("- Timed", 5,40);
  disp.text("> Timed <", 5,40);
}
void delThings () {
  disp.stroke(0,0,0);
  disp.setTextSize(2);
  if (gameMode == "count") {
    disp.text("Set number of targets: ", 0,0);
    disp.text("(10)(15)(20)(25)", 0,20);
    disp.text("{10}{15}{20}{25}", 0,20);
  } else if (gameMode == "timed") {
    disp.text("Set Time: ", 0,0);
    disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
    disp.text("{20s}{40s}{1min}{1.5min}", 0,20);
  }
}
void setCountdown() {
  disp.stroke(255,255,255);
  disp.text("Starting in:", 0,0);
  delay(1000);
  disp.text("3", 0,20);
  delay(1000);
  disp.text("2", 0,40);
  delay(1000);
  disp.text("1", 0,60);
}
void delCountdown() {
  disp.stroke(0,0,0);
  disp.text("Starting in:", 0,0);
  disp.text("3", 0,20);
  disp.text("2", 0,40);
  disp.text("1", 0,60);
}
// << MAIN MENU FUNCTION >> //
void pMenu() {
  while (menuOn == 1){
    setMenu();
    // <sets default count game mode> //
    disp.stroke(0,0,0);
    disp.text("- Count", 5,20);
    // <select the option> //
    disp.stroke(255,255,255);
    disp.text("> Count <", 5,20);
    menuOptions1 = 1;
    while (menuOptions1 == 1){
      for (int b=0; b<3; b++){
        if (digitalRead(buttons[0]) == 0){
          delMenu();
          setMenu();
          // <del the option> //
          disp.stroke(0,0,0);
          disp.text("- Count", 5,20);
          // <select the option> //
          disp.stroke(255,255,255);
          disp.text("> Count <", 5,20);

          gameMode="count";
        } else if (digitalRead(buttons[2]) == 0){
          delMenu();
          setMenu();
          disp.stroke(0,0,0);
          disp.text("- Timed", 5,40);
          disp.stroke(255,255,255);
          disp.text("> Timed <", 5,40);
          
          gameMode="timed";
        } else if (digitalRead(buttons[1]) == 0){
          delMenu();

          menuOptions1=0;
          menuOptions2=1;

          delay(1000);
        }
    setThings();
    while (menuOptions2 = 1){
      if (gameMode == "count"){
        for (int i; i < 6; i++){
          if (digitalRead(buttons[0])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("{10}(15)(20)(25)", 0,20);
            countsVal = 10;
          } else if (digitalRead(buttons[2])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(10){15}(20)(25)", 0,20);
            countsVal = 15;
          } else if (digitalRead(buttons[1])) {
          // < confirm buttion > //
              delThings();
              setCountdown();
              delCountdown();
              menuOptions1=0;
              menuOptions2=0;
              menuOn=0;
              gameOn=1;
          } else if (digitalRead(buttons[3])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(10)(15){20}(25)", 0,20);
            countsVal = 20;
          } else if (digitalRead(buttons[5])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(10){15}(20){25}", 0,20);
            countsVal = 25;
          }
        }
      } else if (gameMode == "timed"){
        for (int i; i < 6; i++){
          if (digitalRead(buttons[0])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("{20s}(40s)(1min)(1.5min)", 0,20);
            timedVal = 20000;
          } else if (digitalRead(buttons[2])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(20s){40s}(1min)(1.5min)", 0,20);
            timedVal = 40000;
          } else if (digitalRead(buttons[1])) {
          // < confirm buttion > //
            delThings();
            setCountdown();
            delCountdown();
            menuOptions1=0;
            menuOptions2=0;
            menuOn=0;
            gameOn=1;
          } else if (digitalRead(buttons[3])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(20s)(40s){1min}(1.5min)", 0,20);
            timedVal = 60000;
          } else if (digitalRead(buttons[5])) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(20s)(40s)(1min){1.5min}", 0,20);
            timedVal = 90000;
          }
        }
      }
    }
      }
    }
  }
}



// <updates scores arrray> //
void Scoring(int position, int target, int time) {
  hits[position] = time;
}
void randomdelay() {
  int ran = random(delaysLen);
  int randDel = delays[ran];
}
// << MAIN GAME >> //
void Game() {
  Serial.println("gameOn");
  Serial.println(gameOn);
  Serial.println("gameLoop");
  Serial.println(gameLoop);
  Serial.println("endMenuOn");
  Serial.println(endMenuOn);
  while(gameOn == 1) {
    Serial.println("looping GAMEON");
    int hitCount = 5;
    int gameLength = 5000;
    int gameStartTime = millis();
    int gameEndTime = gameStartTime + gameLength;
    int position = 0;

    gameLoop = 1;
    while (gameLoop == 1){
      Serial.println("looping GAMELOOP");
      // <make value to count hits> //
      // <choose random button, starts timer> //
      // int randNum = random(6);
      int randNum = random(3); // 3 for testing
      long startTime= millis();
      int targetNum = randNum+1;

      // <light up led display target on display> //
      digitalWrite(leds[randNum],1);
      disp.stroke(255,255,255);
      disp.text("Target:", 0,0);
      disp.text(itoa(targetNum, cstr, 10), 0,20);
      roundLoop = 1;
      
      // <makes arduino wait for specific button hit> //
      while (roundLoop == 1){
        Serial.println("looping ROUNDLOOP");
        if (digitalRead(buttons[randNum]) == 0){
          long endTime= millis();

          digitalWrite(leds[randNum],0);

          int scoreTime = startTime-endTime;
          position++;

          Scoring(position, randNum, scoreTime);
          
          disp.stroke(0,0,0);
          disp.text("Target:", 0,0);
          disp.text(itoa(targetNum, cstr, 10), 0,20);
          
          randomdelay();

          roundLoop=0;
        }    
        if (gameMode=="count"){
          if (position >= hitCount){
            gameOn = 0;
            gameLoop = 0;
            roundLoop = 0;
            endMenuOn = 1;

          }
        }
        // <ends game if current time is equal to or more than gameEndTime> //
        if (gameMode=="timed"){
          int now = millis();
          if (now >= gameEndTime){
            disp.stroke(0,0,0);
            disp.text("Target:", 0,0);
            disp.text(itoa(targetNum, cstr, 10), 0,20);
            gameOn = 0;
            gameLoop = 0;
            roundLoop = 0;
            endMenuOn = 1;
          }
        }
      }
    }
  }
}



// << END MENU >> //
void EndMenu() {
  while (endMenuOn == 1){
    
    // int endMenuDisp = 1;
    // while (endMenuDisp == 1){

      int sSum = 0;
      int sCount = 0;
      for (int i = 0 ; i<hitsLen ; i++){
        if (hits[i] != 0){
          sSum = sSum + hits[i];
          sCount = sCount+1;
          // Serial.println(sSum);
        }
      }
      int score = sSum/sCount;

      if (sCount == 0){
        score = 0;
      }
      disp.stroke(225,225,225);
      disp.setTextSize(2);
      disp.text("GAME OVER", 0,0);
      disp.text("Targets: ",0,40);
      disp.text(itoa(sCount, cstr, 10), 0,60);
      disp.text("Average time: ", 0,80);
      disp.text(itoa(score, cstr, 10),0,100);

      for (int i = 0; i < 6; i ++){
        if (digitalRead(buttons[i]) == 0){
          Serial.println("next");
          menuOn = 1;
            menuOptions1 = 0;
            menuOptions2 = 0;
            gameMode = "count";
            countsVal = 15;
            timedVal = 30000;
          gameOn = 0;
            gameLoop = 0;
            roundLoop = 0;
          endMenuOn = 0;
        }
      }
    // }
  }
}



void button_test() { 
  // << the tactile buttons = no, the push button = nc, writing buttons ==HIGH/LOW, as opposed to led and buzzer == 1/0>> //
  for (int a=0;a<3;a++){
    Serial.println(a+100);
    Serial.println(digitalRead(buttons[a]));
    if (digitalRead(buttons[a])==0){
      digitalWrite(leds[a],HIGH);
    } else if (digitalRead(buttons[a])==1){
      digitalWrite(leds[a],LOW);
    }
  }
  // <check if button is no or nc> //
  //  if (digitalRead(buttons[0])==HIGH){
  //     digitalWrite(leds[0],HIGH);
  //     Serial.println("Button pressed: ");
  //     Serial.println(0);
  //   } else if (digitalRead(buttons[0])==LOW) {
  //     Serial.println("Button pressed: ");
  //     Serial.println(1);
  //   }
  delay(100);
}
void led_test() {
  for (int a=0;a<6;a++){
    delay(500); 
    digitalWrite(leds[a], 0);
    delay(500);
    digitalWrite(leds[a], 1);
  }
}



void loop() {
  led_test();
  // button_test();

  disp.setTextSize(3);
  disp.stroke(0,0,0);
  disp.text("Booting up....", 0,0);

  // pMenu();
  // gameOn = 1;
  // Game();
  // endMenuOn = 1;
  // EndMenu();
}

 