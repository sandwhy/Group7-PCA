#include <TFT.h>  
#include <SPI.h>

// <for the uno> //
// int sck = 13;
// int sdk = 11;
// <for the mega> //

// <works for any> //
int cs  = 10;
int dc  = 9; 
int rst = 8;

TFT disp = TFT(cs,dc,rst);

int buttons[] = {30,31,32,33,34,35};
int leds[] =    {36,37,38,39,40,41};
// int buzzers[] = {42,43,44,45,46,47};
int delays[] = {200,1000,1500,2000,2500,1000,1500,2000,2500,3000};
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
  // < turn off all led > //
  for(int i=0; i<6; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i],1);
  }

  // scr: boot up sequence
  disp.begin();
  disp.background(0,0,0);
  disp.stroke(255, 255, 255);
  // << text sizes and spacing >> //
  disp.setTextSize(3);
  disp.text("Booting up....", 0,0);

  // println
  Serial.println("Booting up ....");
}



int menuOn = 1;
  int menuOptions1 = 0;
  int menuOptions2 = 0;
  String gameMode = "count";
  int countsVal = 15;
  int timedVal = 5000;
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
    disp.setTextSize(1);
    disp.text("(10)(15)(20)(25)", 0,20);
  } else if (gameMode == "timed") {
    disp.text("Set Time: ", 0,0);
    disp.setTextSize(1);
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
    disp.setTextSize(1);
    disp.text("(10)(15)(20)(25)", 0,20);
    disp.text("{10}{15}{20}{25}", 0,20);
  } else if (gameMode == "timed") {
    disp.text("Set Time: ", 0,0);
    disp.setTextSize(1);
    disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
    disp.text("{20s}{40s}{1min}{1.5min}", 0,20);
  }
}
void setCountdown() {
  disp.stroke(255,255,255);
  disp.setTextSize(2);
  disp.text("Starting in:", 0,0);
  //
  Serial.println("Starting in: ");
  delay(1000);
  disp.text("3", 0,20);
  //
  Serial.println("3");
  delay(1000);
  disp.text("2", 0,40);
  //
  Serial.println("2");
  delay(1000);
  disp.text("1", 0,60);
  //
  Serial.println("1");
}
void delCountdown() {
  disp.stroke(0,0,0);
  disp.setTextSize(2);
  disp.text("Starting in:", 0,0);
  disp.text("3", 0,20);
  disp.text("2", 0,40);
  disp.text("1", 0,60);
}
void resetLed(){
  Serial.println("Reseting leds");
  for (int b=0; b<6; b++){
    digitalWrite(leds[b],HIGH);
  }
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

    // println
    Serial.println("Game Modes: (count / timed)");
    Serial.println("- Count");

    menuOptions1 = 1;
    while (menuOptions1 == 1){
      for (int b=0; b<3; b++){
        // Serial.println(digitalRead(buttons[0]));
        // Serial.println(digitalRead(buttons[1]));
        // Serial.println(digitalRead(buttons[2]));

        if (digitalRead(buttons[0]) == 1){
          delMenu();
          setMenu();
          // <del the option> //
          disp.stroke(0,0,0);
          disp.text("- Count", 5,20);
          // <select the option> //
          disp.stroke(255,255,255);
          disp.text("> Count <", 5,20);

          //println
          Serial.println("- Count");

          gameMode="count";
        } else if (digitalRead(buttons[2]) == 1){
          delMenu();
          setMenu();
          disp.stroke(0,0,0);
          disp.text("- Timed", 5,40);
          disp.stroke(255,255,255);
          disp.text("> Timed <", 5,40);

          //println
          Serial.println("- Timed");
          
          gameMode="timed";
        } else if (digitalRead(buttons[1]) == 1){
          delMenu();

          menuOptions1=0;
          menuOptions2=1;

          delay(1000);
        }
      }
    }
    setThings();
      if (gameMode == "count") {
        // println
        Serial.println("Set count: (10)(15)(20)(25)");
      } else if (gameMode == "timed") {
        // println
        Serial.println("Set time: (20s)(40s)(1min)(1.5min)");
      }
       
    while (menuOptions2 == 1){
      // <setup led for navigation> //
        digitalWrite(leds[5],LOW);
        digitalWrite(leds[4],LOW);
        digitalWrite(leds[1],LOW);
        digitalWrite(leds[2],LOW);
      // Serial.println(gameMode);

      if (gameMode == "count"){
        for (int i=0; i < 6; i++){
          if (digitalRead(buttons[5]) == 1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("{10}(15)(20)(25)", 0,20);

            Serial.println("- 10");

            countsVal = 10;
          } else if (digitalRead(buttons[4]) == 1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(10){15}(20)(25)", 0,20);

            Serial.println("- 15");

            countsVal = 15;
          } else if (digitalRead(buttons[0]) == 1) {
          // < confirm buttion > //
              menuOptions1=0;
              menuOptions2=0;
              menuOn=0;
              gameOn=1;

              Serial.println("heading over to here");
              Serial.println(menuOptions1);
              Serial.println(menuOptions2);
              Serial.println(menuOn);
              Serial.println(gameOn);

              delThings();
              setCountdown();
              delCountdown();
              resetLed();

          } else if (digitalRead(buttons[1])==1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(10)(15){20}(25)", 0,20);

            Serial.println("- 20");

            countsVal = 20;
          } else if (digitalRead(buttons[2]) == 1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(10)(15)(20)(25)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(10){15}(20){25}", 0,20);

            Serial.println("- 25");

            countsVal = 25;
          }
        }
      } else if (gameMode == "timed"){  
        for (int i=0; i < 6; i++){
          if (digitalRead(buttons[5])==1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("{20s}(40s)(1min)(1.5min)", 0,20);

            Serial.println("over here");
            Serial.println("- 20s");

            timedVal = 20000;
          } else if (digitalRead(buttons[4])==1) {
            // if (digitalRead(buttons[4]==1)){
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(20s){40s}(1min)(1.5min)", 0,20);

            Serial.println("- 40s");

            timedVal = 40000;
          } else if (digitalRead(buttons[0])==1) {
          // < confirm buttion > //
            menuOptions1=0;
            menuOptions2=0;
            menuOn=0;
            gameOn=1;

            delThings();
            setCountdown();
            delCountdown();
            resetLed();


          } else if (digitalRead(buttons[1])==1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(20s)(40s){1min}(1.5min)", 0,20);

            Serial.println("- 1min");

            timedVal = 60000;
          } else if (digitalRead(buttons[2])==1) {
            delThings();
            setThings();
            disp.stroke(0,0,0);
            disp.setTextSize(1);
            disp.text("(20s)(40s)(1min)(1.5min)", 0,20);
            disp.stroke(255,255,255);
            disp.text("(20s)(40s)(1min){1.5min}", 0,20);

            Serial.println("- 1.5min");

            timedVal = 90000;
          }
        }
      }
        digitalWrite(leds[0],HIGH);
        digitalWrite(leds[1],HIGH);
        digitalWrite(leds[3],HIGH);
        digitalWrite(leds[4],HIGH);
    }
  }
}



// <updates scores arrray> //
void Scoring(int position, int target, int time) {
  // < concactinating strings > //
  // int a = 1;
  // int b = 069;
  // int newNumber = int.Parse(a.ToString() + b.ToString());
  // Serial.println("Updating Scores Array");
  // Serial.println("Position");
  // Serial.println(position);
  // Serial.println("Target");
  // Serial.println(target);
  // Serial.println("Time");
  // Serial.println(time);

  hits[position] = time;
}
void randomdelay() {
  int ran = random(delaysLen);
  int randDel = delays[ran];
  delay(randDel);
}
// << MAIN GAME >> //
void Game() {
  // Serial.println("gameOn");
  // Serial.println(gameOn);
  // Serial.println("gameLoop");
  // Serial.println(gameLoop);
  // Serial.println("endMenuOn");
  // Serial.println(endMenuOn);
  while(gameOn == 1) {
    Serial.println("looping GAMEON");
    Serial.print("Game length: ");
    Serial.println(timedVal);
    Serial.print("Game mode: ");
    Serial.println(gameMode);

    long gameStartTime = millis();
    long gameEndTime = gameStartTime + timedVal;
    int position = 0;

    Serial.print("Game start time: ");
    Serial.println(gameStartTime);
    Serial.print("Game end time: ");
    Serial.println(gameEndTime);

    gameLoop = 1;
    while (gameLoop == 1){
      // Serial.println("looping GAMELOOP");
      // <make value to count hits> //
      // <choose random button, starts timer> //
      int randNum = random(6);
      // int randNum = random(3); // 3 for testing
      long startTime= millis();
      int targetNum = randNum+1;

      // <light up led display target on display> //
      digitalWrite(leds[randNum],LOW);
      disp.stroke(255,255,255);
      disp.setTextSize(2);
      disp.text("Target:", 0,0);
      disp.text(itoa(targetNum, cstr, 10), 0,20);
      // println
      Serial.print("Target: ");
      Serial.println(targetNum);
      roundLoop = 1;
      
      // <makes arduino wait for specific button hit> //
      while (roundLoop == 1){
        // Serial.println("looping ROUNDLOOP");
        if (digitalRead(buttons[randNum]) == 1){
          long endTime= millis();

          digitalWrite(leds[randNum],HIGH);

          long scoreTime = startTime-endTime;
          position++;

          Scoring(position, randNum, scoreTime);
          // println
          Serial.print("Time: ");
          Serial.println(scoreTime);
          
          // <delete current displayed target> //
          disp.stroke(0,0,0);
          disp.text("Target:", 0,0);
          disp.text(itoa(targetNum, cstr, 10), 0,20);
          
          randomdelay();

          roundLoop=0;
        }    
        // << check if game end satisfied >> //
        if (gameMode=="count"){
          if (position >= countsVal){
            disp.stroke(0,0,0);
            disp.text("Target:", 0,0);
            disp.text(itoa(targetNum, cstr, 10), 0,20);

            gameOn = 0;
            gameLoop = 0;
            roundLoop = 0;
            endMenuOn = 1;

          }
        } else if (gameMode=="timed"){
          // <ends game if current time is equal to or more than gameEndTime> //
          long now = millis();

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
    resetLed();
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

      //println
      Serial.println("GAME-OVER");
      Serial.print("Targets: ");
      Serial.println(sCount);
      Serial.print("Average time: ");
      Serial.println(score);

      for (int i = 0; i < 6; i ++){
        if (digitalRead(buttons[i]) == 1){
          disp.stroke(0,0,0);
          disp.setTextSize(2);
          disp.text("GAME OVER", 0,0);
          disp.text("Targets: ",0,40);
          disp.text(itoa(sCount, cstr, 10), 0,60);
          disp.text("Average time: ", 0,80);
          disp.text(itoa(score, cstr, 10),0,100);
          // < resets hits and points > //
          for (int i=0; i < hitsLen; i ++){
            hits[i] = 0;
          }
          sSum=0;
          sCount=0;

          Serial.println("next game ....");
          menuOn = 1;
            menuOptions1 = 0;
            menuOptions2 = 0;
            gameMode = "count";
            countsVal = 15;
            timedVal = 5000;
          gameOn = 0;
            gameLoop = 0;
            roundLoop = 0;
          endMenuOn = 0;
        }
      }
    // }
  }
}


void loop() {
  disp.setTextSize(3);
  disp.stroke(0,0,0);
  disp.text("Booting up....", 0,0);

  pMenu();
  // gameOn = 1;
  Game();
  // endMenuOn = 1;
  EndMenu();
}

 