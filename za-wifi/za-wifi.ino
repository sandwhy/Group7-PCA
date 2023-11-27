// #include <Adafruit_LiquidCrystal.h>

int seconds = 0;

// Adafruit_LiquidCrystal lcd(0);

int buttons[] = {2,3,4, 5, 6, 7};
int leds[] =    {8,9,10,11,12,13};

void setup()
{
  Serial.begin(9600);
  for(int i=0; i<6; i++){
    pinMode(buttons[i], INPUT);
  }
  for(int i=0; i<6; i++){
    pinMode(leds[i], OUTPUT);
  }
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);

  // lcd.begin(16,2);
  // lcd.print("Booting up....");
}
// menu i need a system that keeps a static screen. updates when theres an input. then moves on to the next function. Within a system that continuously loops itself
// set screen before while
// set inputs and outcomes inside while, within (if)

int gameOn = 0;
int menuOn = 1;
int roundOn = 0;
int endMenuOn = 0;
String mode = "hit";

// void pMenu() {
//   lcd.clear();
//   lcd.print("Game modes:");
//   lcd.setCursor(0,1);
//   lcd.print("hit|sec");
//   lcd.setCursor(0,1);
//   lcd.cursor();
//   while (menuOn == 1){
//     for (int b=0; b<3; b++){
//       if (digitalRead(buttons[0]) == 1){
//         lcd.setCursor(0,1);
//         mode="hit";
//       } else if (digitalRead(buttons[2]) == 1){
//         lcd.setCursor(4,1);
//         mode="sec";
//       } else if (digitalRead(buttons[1]) == 1){
//         menuOn=0;
//         gameOn=1;
//         lcd.clear();
//         lcd.noCursor();
//         lcd.setCursor(0,0);
//         lcd.print("ok");
//         delay(1000);
//       }
//     }
//   }
// }
int a = 0;
void loop()
{
  // for(int b=0; b<3; b++){
  //     if (digitalRead(buttons[0]) == 1){
  //       Serial.println("Pressed button a");
  //       digitalWrite(leds[0], HIGH);
  //     } else if (digitalRead(buttons[1]) == 1){
  //       Serial.println("Pressed button b");
  //       digitalWrite(leds[1], HIGH);
  //     } else if (digitalRead(buttons[2]) == 1){
  //       digitalWrite(leds[2], HIGH);
  //     }
  //     else{
  //       digitalWrite(leds[0], LOW);
  //       digitalWrite(leds[1], LOW);
  //     }
  // }
  Serial.println(buttons[0]);
  a = a+1;
  Serial.println(a);
  delay(500);
}