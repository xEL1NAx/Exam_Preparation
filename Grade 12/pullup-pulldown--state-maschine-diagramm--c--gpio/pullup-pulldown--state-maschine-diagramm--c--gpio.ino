/******************************************************
 * COMPLETE ARDUINO PROJECT
 * Covers:
 *  - Pull-Up / Pull-Down
 *  - GPIO with Arduino.h
 *  - Functions in C/C++
 *  - State Machine (UML-style)
 *  - main() and setup(), loop()
 *  - 100% fully commented example
 ******************************************************/

#include <Arduino.h>   // gives us pinMode, digitalWrite, millis, etc.

/******************************************************
 *                 PIN DEFINITIONS
 ******************************************************/

const int LED_PIN     = 13;   // LED (built-in on many boards)
const int BUTTON_PIN  = 7;    // Button input pin (uses Pull-Up)

/******************************************************
 *           STATE MACHINE (UML converted to C)
 * States of our simple system:
 *  IDLE      -> LED off, waiting for button press
 *  WAIT      -> small delay after press (debounce/transition)
 *  ACTIVE    -> LED blinking until button released
 ******************************************************/

enum State {
  IDLE,
  WAIT,
  ACTIVE
};

State currentState = IDLE;    // start state

unsigned long waitStartTime = 0;   // for timing transitions

/******************************************************
 *              FUNCTION DECLARATIONS
 ******************************************************/

// reads the button (LOW = pressed because INPUT_PULLUP!)
bool buttonPressed();

// blinks LED for X milliseconds
void blinkOnce(int ms);

/******************************************************
 *              FUNCTION IMPLEMENTATIONS
 ******************************************************/

// ----------------------------------------------------
// Reads button with inverted logic because INPUT_PULLUP
// ----------------------------------------------------
bool buttonPressed() {
  // Button is wired with internal pull-up → pressed = LOW
  return (digitalRead(BUTTON_PIN) == LOW);
}

// ----------------------------------------------------
// Blink LED once for ms milliseconds
// Demonstrates: functions + GPIO control
// ----------------------------------------------------
void blinkOnce(int ms) {
  digitalWrite(LED_PIN, HIGH);
  delay(ms);
  digitalWrite(LED_PIN, LOW);
  delay(ms);
}

/******************************************************
 *                ARDUINO INITIALIZATION
 ******************************************************/

void setup() {
  // Set LED as output
  pinMode(LED_PIN, OUTPUT);

  // Use internal pull-up for button
  // → no external resistor required
  // → button connects pin to GND when pressed
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Start Serial for debugging
  Serial.begin(9600);
  Serial.println("System started. Waiting for input...");
}

/******************************************************
 *                    MAIN LOOP
 * Implements a full state machine
 * using switch-case logic.
 ******************************************************/

void loop() {
  switch (currentState) {

    // ------------------------------------------------
    // IDLE → LED off, wait for button press
    // ------------------------------------------------
    case IDLE:
      digitalWrite(LED_PIN, LOW);   // ensure LED off
      if (buttonPressed()) {
        currentState = WAIT;        // go to next state
        waitStartTime = millis();   // begin timer
        Serial.println("STATE CHANGE: IDLE → WAIT");
      }
      break;

    // ------------------------------------------------
    // WAIT → small delay to avoid bounce and simulate
    //        a transition state (similar to UML)
    // ------------------------------------------------
    case WAIT:
      if (millis() - waitStartTime > 200) { // 200ms
        currentState = ACTIVE;
        Serial.println("STATE CHANGE: WAIT → ACTIVE");
      }
      break;

    // ------------------------------------------------
    // ACTIVE → LED blinks until button is released
    // ------------------------------------------------
    case ACTIVE:
      blinkOnce(150);               // blink LED
      if (!buttonPressed()) {       // released?
        currentState = IDLE;
        Serial.println("STATE CHANGE: ACTIVE → IDLE");
      }
      break;
  }
}

/******************************************************
 *                  OPTIONAL main()
 * Arduino normally generates this automatically,
 * but you requested a main method.
 *
 * If this main() is included:
 *  - Arduino still calls init()
 *  - setup() runs once
 *  - loop() runs forever
 *
 * This makes the file valid C++ with a clear entry point.
 ******************************************************/

int main() {
  init();        // Arduino core initialization

  setup();       // call Arduino setup()

  // main program loop
  while (true) {
    loop();      // call Arduino loop()
  }

  // This line is never reached
  return 0;
}
