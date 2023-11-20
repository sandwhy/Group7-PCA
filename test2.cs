int rightbutton = 12;
int leftbutton = 13;
int leftred = 2;
int leftred1 = 3;
int leftyellow = 4;
int leftyellow1 = 5;
int green = 6;
int rightyellow1 = 7;
int rightyellow = 8;
int rightred1 = 9;
int rightred = 10;
int score = 6;
// Before the void setup, we use int to give each part of our circuit a name. So instead of calling the green LE number 6, I am able to call it green. This can option can help us understand code and write it more easil without any confusion.
void setup() {
    pinMode (rightbutton, INPUT);
    pinMode (leftbutton, INPUT);
    pinMode (leftred, OUTPUT);
    pinMode (leftred1, OUTPUT);
    pinMode (leftyellow, OUTPUT);
    pinMode (leftyellow1, OUTPUT);
    pinMode (green, OUTPUT);
    pinMode (rightyellow1, OUTPUT);
    pinMode (rightyellow, OUTPUT);
    pinMode (rightred1, OUTPUT);
    pinMode (rightred, OUTPUT);
    digitalWrite (rightred, LOW);
    digitalWrite (rightred1, LOW);
    digitalWrite (leftred, LOW);
    digitalWrite (leftred1, LOW);
    digitalWrite (leftyellow, LOW);
    digitalWrite (leftyellow1, LOW);
    digitalWrite (green, HIGH);
    digitalWrite (rightyellow, LOW);
    digitalWrite (rightyellow1, LOW);
}
// In void setup, we setup the input and output parts of our circuit by using the command 'pinMode'. If we do not do that, we would not be able to control our parts that are in our circuit. Then, you can see that there is  command called 'digitalWrite' that is being used instead of 'pinMode'. This is so that we would be able to tell the Arduino software which LEDs we want to have turned on and which LEDs we want to have turned off at th start 
void loop() {
    while (digitalRead(rightbutton) == 0 and digitalRead(leftbutton) == 0){}
    if (digitalRead(rightbutton) == 1){
    while (digitalRead(rightbutton) == 1){}
    delay (50);
    score = score-1;
    if (score == 1){
        score=2;
        }

// Here, what I am saying is that while both the right button and left buttons are not being pressed, if the rightbutton is being pressed, then the light should move one step to the left. This is because when the score = score-1It means that the number of the score is reduced by one and therefore the LED that is connected to that numberis the one that lights up. There is a delay of 50 milliseconds so that the button-pressing is consistent. Also, at theend where it says 'if (score == 1) score=2;', this means that I am creating a barrier. So if the score becomes 1, then it should go back to 2. This is important so that the light does not disappear into a non existant LED.
    } else {
        while (digitalRead(leftbutton) == 1){}
        delay (50);
        score = score+1;
        if (score == 11){
            score=10;
        }
    }
    digitalWrite (score, HIGH);
    digitalWrite (score+1, LOW);
    digitalWrite (score-1, LOW);
}
// Where it says 'digitalWrite (score, HIGH); digitalWrite (score+1, LOW); digitalWrite (score-1, LOW);', I am tellingthe software to only turn on the LED that has the same number as the score. Anything that is 1 under or 1 abovethe score must be turned off.</p>