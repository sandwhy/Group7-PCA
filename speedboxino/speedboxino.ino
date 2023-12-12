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

int buttons[] = {30,31,32,33,34,35};
int leds[] =    {36,37,38,39,40,41};
int buzzers[] = {42,43,44,45,46,47};
int delays[] = {100,200,500,1000,2000,3000};
int delaysLen = sizeof(delays)/sizeof(delays[0]);
int hits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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

  // scr: boot up sequence
  disp.begin();
  disp.background(0,0,0);
  disp.stroke(255, 255, 255);
  // << text sizes and spacing >> //
  disp.setTextSize(3);
  disp.text("Booting up....", 0,0);
}



int menuOn = 1;
int gameOn = 0;
int roundOn = 0;
int endMenuOn = 0;
String mode = "hit";



// << STARTING MENU >> //
void setMenu() {
  // <reset> //
  disp.stroke(255,255,255);
  disp.setTextSize(2);
  disp.text("Game mode: ", 0,0);
  disp.text("- Count", 5,20);
  disp.text("- Timed", 5,40);
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
  // < set gamemodes > //
  setMenu();
  while (menuOn == 1){
    for (int b=0; b<3; b++){
      if (digitalRead(buttons[0]) == 1){
        delMenu();
        setMenu();
        // has to print out the menu, change one line
        // <del the option> //
        disp.stroke(0,0,0);
        disp.text("- Count", 5,20);
        // <select the option> //
        disp.stroke(255,255,255);
        disp.text("> Count <", 5,20);

        mode="hit";
      } else if (digitalRead(buttons[2]) == 1){
        delMenu();
        setMenu();
        disp.stroke(0,0,0);
        disp.text("- Timed", 5,40);
        disp.stroke(255,255,255);
        disp.text("> Timed <", 5,40);
        
        mode="sec";
      } else if (digitalRead(buttons[1]) == 1){
        delMenu();
        setCountdown();
        delCountdown();
        menuOn=0;
        gameOn=1;

        delay(1000);
      }
    }
  }
}



// <updates scores arrray> //
void Scoring(int pos, int target, int time) {
  // < concactinating strings > //
  // int a = 1;
  // int b = 069;
  // int newNumber = int.Parse(a.ToString() + b.ToString());

  hits[pos] = time;
}
void randomdelay() {
  int ran = random(delaysLen);
  int randDel = delays[ran];

  delay(randDel);
}
// << MAIN GAME >> //
// void Game() {
//   if (mode == "hit"){
//     int hitCount = 10;
//   } else if (mode == "sec"){
//     int gameLength = 25000;
//     int gameStartTime = millis();
//     int gameEndTime = gameStartTime + gameLength;
//   } 

//   while (gameOn = 1){
//     // int position = 0;
//     // if (mode == "hit"){
//     //   if (position == hitCount){
//     //     gameOn = 0;
//     //     endMenuOn = 1;
//     //   }
//     // } else if (mode == "sec"){
//     //   int now = millis();
//     //   if (now >= gameEndTime){
//     //     gameOn = 0;
//     //     endMenuOn = 1;
//     //   }
//     // } 

//     int randNum = random(6);
//     int targetNum = randNum+1;  
//     long startTime= millis();
//     // <light up led> //
//     digitalWrite(leds[randNum],1);
    
//     roundOn = 1;
//     while (roundOn == 1){
//       if (digitalRead(buttons[randNum])==LOW){
//         long endTime= millis();

//         digitalWrite(leds[randNum],0);

//         int scoreTime = startTime-endTime;
//         // int pos = position+1
//         Scoring(pos, randNum, scoreTime);
//         roundOn = 0;
//         randomdelay();
//       }    
//     }
//   }
// }


// // << END MENU >> //
// void EndMenu () {
//   while (endMenuOn==1){
//     // >>make led end animation //
//     // >>print out game end formalities //
//     disp.stroke(255,255,255);
//     disp.setTextSize(2);
//     disp.text("GAME END", 0,0);
//     disp.setTextSize(1);

//     // >>print out average game score //
//     int sCount = 0;
//     int sTotal = 0;
//     int sAverage = 0;
//     for (int i = 0; i < 60 ; i++){
//       if (hits[i] != 0){
//         sCount = sCount++;
//       }
//       sTotal += hits[i];
//     }
//     sAverage = sTotal/sCount;
//     disp.text("Score:", 0,20);
//     disp.setTextSize(3);
//     disp.text(sAverage)
//     // >>ask if wanna play again //

//   }
// }



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
  delay(1000);
}
void led_test() {
  for (int a=0;a<3;a++){
    delay(500);
    digitalWrite(leds[a], 1);
    delay(500); 
    digitalWrite(leds[a], 0);
  }
}



void loop() {
  // led_test();
  button_test();
  // <delete booting up text> //
  // disp.setTextSize(3);
  // disp.stroke(0,0,0);
  // disp.text("Booting up....", 0,0);
  // pMenu();
  // Game();
  // EndMenu();
}

