/* 
 * Copyright 2017 Isabelle Miller. All rights reserved.
 * Use of this source code is goverened by an MIT-style
 * license that can be found in the LICENSE file.
 */

// #define DEBUG

const int ledPins[2] = { 14, 12 };
const int buttons[2] = {  4,  5 };

#ifndef DEBUG
const unsigned long WaitAfterDinner = 25200000UL; // 7 hours
const unsigned long WaitAfterBreakfast = 21600000UL; // 6 hours
#else
const unsigned long WaitAfterDinner = 10000UL; // 10 seconds :)
const unsigned long WaitAfterBreakfast = 5000UL; // 5 seconds
#endif

typedef bool meal;
#define BREAKFAST false;
#define DINNER true;

unsigned long intervalAfterMeal(meal m) {
  return m  ? WaitAfterDinner : WaitAfterBreakfast;
}

meal previousMeal;

unsigned long lastMealAt = 0;

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }
  reset();
}

void blinkLEDs(int speed, int times, int endState) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    delay(speed);
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    delay(speed);
  }
  digitalWrite(ledPins[0], endState);
  digitalWrite(ledPins[1], endState);
}

void reset() {
  blinkLEDs(100, 5, HIGH);
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], HIGH);
  for (;;) {
    // wait for a button press then make it so the last meal was the other one
    // and the time is "ready for next meal"
    for (int i = 0; i < 2; i++) {
      if (digitalRead(buttons[i]) == LOW) {
        previousMeal = !i;
        lastMealAt = millis() - intervalAfterMeal(previousMeal);

        digitalWrite(ledPins[0], LOW);
        digitalWrite(ledPins[1], LOW);
        delay(200);
        return;
      }
    }
  }
}

void loop() {
  unsigned long t = millis();
  if (digitalRead(buttons[0]) == LOW && digitalRead(buttons[1]) == LOW) {
    reset();
    return;
  }

  // Arduino clock will roll over after about 50 days, but it won't break this code.
  if (t - lastMealAt >= intervalAfterMeal(previousMeal)) {
    digitalWrite(ledPins[!previousMeal], HIGH);

    if (digitalRead(buttons[!previousMeal]) == LOW) {
      previousMeal = !previousMeal;
      digitalWrite(ledPins[previousMeal], LOW);
      lastMealAt = t;
    }
  } else if (!(t%60000)) {
    // blink just so you know it's working
    blinkLEDs(100, 1, LOW);
  }


}
