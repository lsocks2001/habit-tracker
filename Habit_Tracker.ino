const int buttonPinEx = 22;
const int buttonPinRead = 23;
const int buttonPinMind = 25;
const int buttonPinFood = 24;
const int ledPinsEx[] = { 46, 48, 50, 52 };
const int ledPinsRead[] = { 47, 49, 51, 53};
const int ledPinsMind[] = { 42, 43, 44, 45 };
const int ledPinsFood[] = { 38, 39, 40, 41 };
int currentLedEx = 0;
int currentLedRead = 0;
int currentLedMind = 0;
int currentLedFood = 0;
bool isOnEx = false;
bool isOnRead = false;
bool isOnMind = false;
bool isOnFood = false;
int speaker = 4;

void setup() {

  pinMode(buttonPinEx, INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPinsEx[i], OUTPUT);
    digitalWrite(ledPinsEx[i], LOW);
  }

  pinMode(buttonPinRead, INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPinsRead[i], OUTPUT);
    digitalWrite(ledPinsRead[i], LOW);
  }

  pinMode(buttonPinMind, INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPinsMind[i], OUTPUT);
    digitalWrite(ledPinsMind[i], LOW);
  }

  pinMode(buttonPinFood, INPUT_PULLUP);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPinsFood[i], OUTPUT);
    digitalWrite(ledPinsFood[i], LOW);
  }
}

void loop() {
  int buttonStateEx = digitalRead(buttonPinEx);
  int buttonStateRead = digitalRead(buttonPinRead);
  int buttonStateMind = digitalRead(buttonPinMind);
  int buttonStateFood = digitalRead(buttonPinFood);

  // EXERCIZE -------------------------------------
  if (buttonStateEx == LOW && !isOnEx) {
    isOnEx = true;
    digitalWrite(ledPinsEx[currentLedEx], HIGH);
    if (currentLedEx == 0) {
      tone(speaker, 261.6, 50);
    } else if (currentLedEx == 1) {
      tone(speaker, 329.6, 60);
    } else if (currentLedEx == 2) {
      tone(speaker, 392, 50);
    } else if (currentLedEx == 3) {
      tone(speaker, 532.2, 50);
    }
    if (currentLedEx == 3) {
      delay(800);
      fanfare();
    }
    currentLedEx = (currentLedEx + 1);  // Increase modulo to 5 for reset

    delay(100);
  } else if (buttonStateEx == HIGH && isOnEx) {
    isOnEx = false;
    delay(100);
  }

  // Check if the button was pressed five times to reset
  if (currentLedEx == 5 && !isOnEx) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinsEx[i], LOW);  // Turn off all LEDs
    }
    currentLedEx = 0;  // Reset the LED sequence
  }

  // READ -------------------------------------
  if (buttonStateRead == LOW && !isOnRead) {
    isOnRead = true;
    digitalWrite(ledPinsRead[currentLedRead], HIGH);
    if (currentLedRead == 0) {
      tone(speaker, 261.6, 50);
    } else if (currentLedRead == 1) {
      tone(speaker, 329.6, 60);
    } else if (currentLedRead == 2) {
      tone(speaker, 392, 50);
    } else if (currentLedRead == 3) {
      tone(speaker, 532.2, 50);
    }
    if (currentLedRead == 3) {
      delay(800);
      fanfare();
    }
    currentLedRead = (currentLedRead + 1);  // Increase modulo to 5 for reset

    delay(100);
  } else if (buttonStateRead == HIGH && isOnRead) {
    isOnRead = false;
    delay(100);
  }

  // Check if the button was pressed five times to reset
  if (currentLedRead == 5 && !isOnRead) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinsRead[i], LOW);  // Turn off all LEDs
    }
    currentLedRead = 0;  // Reset the LED sequence
  }

  // MIND -------------------------------------
  if (buttonStateMind == LOW && !isOnMind) {
    isOnMind = true;
    digitalWrite(ledPinsMind[currentLedMind], HIGH);
    if (currentLedMind == 0) {
      tone(speaker, 261.6, 50);
    } else if (currentLedMind == 1) {
      tone(speaker, 329.6, 60);
    } else if (currentLedMind == 2) {
      tone(speaker, 392, 50);
    } else if (currentLedMind == 3) {
      tone(speaker, 532.2, 50);
    }
    if (currentLedMind == 3) {
      delay(800);
      fanfare();
    }
    currentLedMind = (currentLedMind + 1);  // Increase modulo to 5 for reset

    delay(100);
  } else if (buttonStateMind == HIGH && isOnMind) {
    isOnMind = false;
    delay(100);
  }

  // Check if the button was pressed five times to reset
  if (currentLedMind == 5 && !isOnMind) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinsMind[i], LOW);  // Turn off all LEDs
    }
    currentLedMind = 0;  // Reset the LED sequence
  }

  // FOOD -------------------------------------
  if (buttonStateFood == LOW && !isOnFood) {
    isOnFood = true;
    digitalWrite(ledPinsFood[currentLedFood], HIGH);
    if (currentLedFood == 0) {
      tone(speaker, 261.6, 50);
    } else if (currentLedFood == 1) {
      tone(speaker, 329.6, 60);
    } else if (currentLedFood == 2) {
      tone(speaker, 392, 50);
    } else if (currentLedFood == 3) {
      tone(speaker, 532.2, 50);
    }
    if (currentLedFood == 3) {
      delay(800);
      fanfare();
    }
    currentLedFood = (currentLedFood + 1);  // Increase modulo to 5 for reset

    delay(100);
  } else if (buttonStateFood == HIGH && isOnFood) {
    isOnFood = false;
    delay(100);
  }

  // Check if the button was pressed five times to reset
  if (currentLedFood == 5 && !isOnFood) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinsFood[i], LOW);  // Turn off all LEDs
    }
    currentLedFood = 0;  // Reset the LED sequence
  }
}  //loop bracket

void fanfare() {
  tone(speaker, 196, 200);
  delay(200);
  tone(speaker, 261.0, 200);
  delay(200);
  tone(speaker, 329.0, 200);
  delay(200);
  tone(speaker, 392.0, 400);
  delay(400);
  tone(speaker, 329.0, 200);
  delay(200);
  tone(speaker, 392.0, 800);
  delay(800);
}
