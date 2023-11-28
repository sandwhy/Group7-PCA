int led = 3;
int button = 4;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop(){
  // Serial.write(digitalRead(button));
  Serial.println(digitalRead(button));
  if(digitalRead(button)== LOW){
    digitalWrite(led,HIGH);
    Serial.println("1");
  } 
  if(digitalRead(button)== HIGH) {
    digitalWrite(led,LOW);
    Serial.println("0");
  }
  delay(1000);
}