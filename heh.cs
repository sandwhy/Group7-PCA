// Define pin numbers
const int ledPin = 2;        // Pin connected to the LEDs
const int buttonPin = 3;     // Pin connected to the push button
const int buzzerPin = 4;     // Pin connected to the audible speaker

// Number of LEDs
const int numLEDs = 7;

// Arrays to store LED states and time intervals
bool ledStates[numLEDs];
unsigned long previousMillis;
unsigned long interval = 1000;  // Time interval in milliseconds

// Variables to control the game
bool gameRunning = false;
unsigned long gameDuration = 30000;  // Game duration in milliseconds (default 30 seconds)
unsigned long gameStartTime;

void setup() {
  // Initialize pins
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  
  // Initial LED state
  for (int i = 0; i < numLEDs; i++) {
    ledStates[i] = LOW;
  }

  // Seed random number generator
  randomSeed(analogRead(0));

  // Start serial communication (for debugging if needed)
  Serial.begin(9600);
}

void loop() {
  if (!gameRunning) {
    // Game setup
    gameSetup();
  } else {
    // Game in progress
    playGame();
  }
}

void gameSetup() {
  // Allow user to set game duration through the pad's HUD
  // Start the game when button is pressed
  if (digitalRead(buttonPin) == LOW) {
    gameRunning = true;
    gameStartTime = millis();
    Serial.println("Game started!");
  }
}

void playGame() {
  unsigned long currentMillis = millis();

  // Gener. Random LED Pattern
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int randomLED = random(numLEDs);
    for (int i = 0; i < numLEDs; i++) {
      if (i == randomLED) {
        ledStates[i] = HIGH;
      } else {
        ledStates[i] = LOW;
      }
    }
  }

  // Disp. LED pattern
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPin, ledStates[i]);
    delay(50); // Adjust delay for LED visibility
  }

  // Check if push button got hit
  if (digitalRead(buttonPin) == LOW) {
    // Player hit the pad
    // Add your logic for hit detection and response here
    // For example, you can turn off the LEDs and trigger a sound
    for (int i = 0; i < numLEDs; i++) {
      ledStates[i] = LOW;
    }
    digitalWrite(ledPin, LOW); // Turn off LEDs
    tone(buzzerPin, 1000);     // Sound tone for hit
    delay(500);                // Sound duration
    noTone(buzzerPin);         // Stop sound
  }

  // cek kalo ud slesai
  if (currentMillis - gameStartTime >= gameDuration) {
    endGame();
  }
}

void endGame() {
  gameRunning = false;
  Serial.println("Game ended!");
  tone(buzzerPin, 1500);  // Sound to signal end of game
  delay(5000);            // Sound duration
  noTone(buzzerPin);      // Stop sound
}