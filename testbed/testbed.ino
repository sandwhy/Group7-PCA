// int buttons[] = {2,3,4,5,6,7};
// int leds[] = {8,9,10,11,12,13};
int buttons[] = {30,31,32,33,34,35};
int leds[] =    {36,37,38,39,40,41};
void setup(){
  Serial.begin(9600);
  for(int i=0; i<6; i++){
    pinMode(buttons[i], INPUT);
  }
  for(int i=0; i<6; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i],0);
  }

        
      Serial.println("writing leds");
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],1);
      digitalWrite(leds[3],1);
      digitalWrite(leds[4],1);
      digitalWrite(leds[5],1);
}

void button_test() { 
  // << the tactile buttons = no, the push button = nc, writing buttons ==HIGH/LOW, as opposed to led and buzzer == 1/0>> //
  for (int a=0;a<6;a++){
      Serial.println("");
      Serial.println(digitalRead(buttons[0]));
      Serial.println(digitalRead(buttons[1]));
      Serial.println(digitalRead(buttons[2]));
      Serial.println(digitalRead(buttons[3]));
      Serial.println(digitalRead(buttons[4]));
      Serial.println(digitalRead(buttons[5]));

      delay(100);
    // Serial.println(a+100);
    // Serial.println(digitalRead(buttons[a]));
    // if (digitalRead(buttons[a])==0){

    //   digitalWrite(leds[a],HIGH);
    // } else if (digitalRead(buttons[a])==1){
    //   digitalWrite(leds[a],LOW);
    // }
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
}
void led_test() {
  for (int a=0;a<6;a++){
    if (buttons[0]==1){
      digitalWrite(leds[0],1);
      digitalWrite(leds[1],1);
      digitalWrite(leds[2],1);
    } else if (buttons[0]==0){
      digitalWrite(leds[0],0);
      digitalWrite(leds[1],0);
      digitalWrite(leds[2],0);
    }
    // Serial.println("passthrough");
    // Serial.println("");
    // delay(500); 
    // digitalWrite(leds[a], 0);
    // delay(500);
    // digitalWrite(leds[a], 1);
  }
}
void loop(){
  button_test();
  // led_test();
}