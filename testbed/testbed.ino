int button1 = 3;
int button2 = 4;
int led1 = 5;
int led2 = 6;

// int buttons[] = {30,31,32,33,34,35};
// int leds[] =    {36,37,38,39,40,41};

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
  // if (digitalRead(button1)==0){
  //   digitalWrite(led1,HIGH);
  // } else if(digitalRead(button2)==0) {
  //   digitalWrite(led2,HIGH);
  // }else {
  //   digitalWrite(led1,LOW);
  //   digitalWrite(led2,LOW);
  // }
  // Serial.println("Button 1: ");
  // Serial.println(digitalRead(button1));
  // Serial.println("Button 2: ");
  // Serial.println(digitalRead(button2));
  // delay(500);
  // for (int a=0;a<3;a++){
  //   if (digitalRead(buttons[0])==0){
  //     digitalWrite(leds[0],HIGH);
  //     Serial.println("Button pressed: ");
  //     Serial.println(a);
  //   } else {
  //     digitalWrite(leds[a],LOW);
  //   }
  // }
  Serial.println("Button 1: ");
  Serial.println(digitalRead(button1));
  // Serial.println(digitalRead(buttons[0]));
  Serial.println("Button 2: ");
  Serial.println(digitalRead(buttons[1]));
  Serial.println("Button 3: ");
  Serial.println(digitalRead(buttons[2]));
  delay(500);

  // for (int a=0;a<3;a++){
  //   Serial.println(a+100);
  //   Serial.println(digitalRead(buttons[a]));
  //   if (digitalRead(buttons[a])==0){
  //     digitalWrite(leds[a],HIGH);
  //   } else if (digitalRead(buttons[a])==1){
  //     digitalWrite(leds[a],LOW);
  //   }
  // }
  // delay(500);
}

