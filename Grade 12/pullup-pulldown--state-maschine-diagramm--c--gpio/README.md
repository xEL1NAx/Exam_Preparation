# 📘 Comprehensive Study Overview: Pull-Up / Pull-Down, UML, C/Arduino, GPIO, State Machine

---

## 🟦 1. Pull-Up / Pull-Down Resistors

### 1.1 Purpose
- Digital inputs need a **defined logic level**.  
- Pull-Up/Pull-Down resistors stabilize the input to **HIGH or LOW** when no signal is applied.

### 1.2 Pull-Up
- Connects **pin → VCC** through a resistor  
- Input reads **HIGH** when unpressed  
- Button connects to **GND → LOW** when pressed

### 1.3 Pull-Down
- Connects **pin → GND** through a resistor  
- Input reads **LOW** when unpressed  
- Button connects to **VCC → HIGH** when pressed

### 1.4 Arduino Example (internal Pull-Up)
```c
pinMode(2, INPUT_PULLUP); // Internal Pull-Up activated
````

* Typical resistor values (external): 4.7 kΩ – 10 kΩ
* Arduino internal Pull-Ups available; internal Pull-Downs are **not** available

---

## 🟩 2. UML State Machines

### 2.1 Purpose

* Model system behavior
* Useful for embedded systems, games, devices, menu navigation

### 2.2 Elements

| Element    | Meaning                               |
| ---------- | ------------------------------------- |
| State      | Specific system status                |
| Transition | Change from one state to another      |
| Trigger    | Event causing the transition          |
| Guard      | Condition that must be true           |
| Action     | Operation performed during transition |
| Entry/Exit | Actions on entering/exiting a state   |

### 2.3 Example States

* `IDLE`, `WAIT`, `ACTIVE`

---

## 🟧 3. State Machine Diagram (ASCII UML)

```
 ┌──────────┐     Button Pressed      ┌──────────┐      After 200 ms      ┌────────────┐
 │   IDLE   │ ----------------------→ │   WAIT   │ ----------------------→ │   ACTIVE    │
 └────┬─────┘                         └────┬─────┘                         └──────┬─────┘
      │                                    │                                    │
      │ Button Released                     │ (nothing else)                     │ Button Released
      └─────────────────────────────────────┴────────────────────────────────────┘
                                                goes back to:
                                                   IDLE
```

### 3.1 State Descriptions

#### 🟩 IDLE

* LED off
* Waits for button press
* Transition: when buttonPressed() → WAIT

#### 🟨 WAIT

* 200 ms stabilization time
* Debounce & transition buffer
* Transition: after timer done → ACTIVE

#### 🟥 ACTIVE

* LED blinks
* Transition: when buttonReleased() → IDLE

### 3.2 Transition Table

| Current | Event          | Next   | Action         |
| ------- | -------------- | ------ | -------------- |
| IDLE    | ButtonPressed  | WAIT   | start timer    |
| WAIT    | TimerDone      | ACTIVE | start blinking |
| ACTIVE  | ButtonReleased | IDLE   | stop blinking  |

---

## 🟦 4. C/Arduino Programming

### 4.1 Basic Structure

```c
#include <Arduino.h>

void setup() {
  // run once
}

void loop() {
  // run forever
}
```

### 4.2 Functions

```c
int sum(int a, int b) {
  return a + b;
}

void blink(int pin, int ms) {
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
  delay(ms);
}
```

### 4.3 Parameters & Return

* Call by value (default in C)
* Types: int, void, float, char*, structs

### 4.4 Divide-and-Conquer

* Split problems into smaller sub-problems
* Solve separately
* Combine results

---

## 🟧 5. GPIO & Arduino.h

### 5.1 Pin Modes

```c
pinMode(13, OUTPUT);
pinMode(7, INPUT_PULLUP);
```

### 5.2 Writing and Reading Pins

```c
digitalWrite(13, HIGH);
digitalWrite(13, LOW);

int state = digitalRead(7);
```

### 5.3 Example: LED controlled by Button

```c
void setup() {
    pinMode(13, OUTPUT);
    pinMode(7, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(7) == LOW) {
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
}
```

### 5.4 Timers with millis()

* Non-blocking delays for state transitions

```c
unsigned long start = millis();
if (millis() - start > 1000) { /* do something */ }
```

---

## 🟨 6. State Machine Implementation in Arduino Code

```c
switch (currentState) {
  case IDLE:
    digitalWrite(LED_PIN, LOW);
    if (buttonPressed()) {
      currentState = WAIT;
      waitStartTime = millis();
    }
    break;

  case WAIT:
    if (millis() - waitStartTime > 200) {
      currentState = ACTIVE;
    }
    break;

  case ACTIVE:
    blinkOnce(150);
    if (!buttonPressed()) {
      currentState = IDLE;
    }
    break;
}
```

---

## 🟪 7. Optional Advanced Topics

* **Debouncing:** `delay(25)` or RC filter
* **PWM / ADC / I2C / SPI**
* **Timers and millis() for non-blocking operations**
* **Multiple modes and events**

---

## 🎓 Summary / Learning Goals

### Pull-Up / Pull-Down

* Understand input stabilization
* Arduino INPUT_PULLUP vs external resistors

### GPIO

* pinMode / digitalWrite / digitalRead
* Non-blocking timing
* Debouncing

### C / Arduino

* Functions, parameters, return types
* Divide-and-Conquer logic
* Enums & switch-case

### State Machines

* Model states & transitions
* Implement with switch-case and timers
* Map UML diagrams to Arduino code
