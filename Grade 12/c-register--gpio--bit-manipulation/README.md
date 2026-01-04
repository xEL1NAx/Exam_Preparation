# 📘 Study Overview: GPIO via Registers (without Arduino.h), Bit Manipulation & Interrupts

---

## 🟦 1. GPIO Programming via Registers (NO Arduino.h)

This section covers **direct hardware access** on AVR microcontrollers  
(e.g. ATmega328P on Arduino Uno), **without** `Arduino.h`.

---

## 1.1 Why use registers?
- Faster than Arduino functions
- Full control over hardware
- Required for:
  - low-level programming
  - embedded systems exams
  - understanding how Arduino really works

---

## 1.2 AVR GPIO Register Overview

Each port (B, C, D) has **three important registers**:

| Register | Purpose |
|--------|--------|
| `DDRx` | Data Direction Register (Input / Output) |
| `PORTx` | Output value / Pull-Up activation |
| `PINx` | Read input value |

Where `x` is:
- `B` → Port B
- `C` → Port C
- `D` → Port D

---

## 1.3 Pin Direction (Input / Output)

### Set pin as OUTPUT
```c
DDRB |= (1 << PB5);   // PB5 = output
```

### Set pin as INPUT
```c
DDRB &= ~(1 << PB5);  // PB5 = input
```

---

## 1.4 Writing to an Output Pin

### Set pin HIGH
```c
PORTB |= (1 << PB5);
```

### Set pin LOW
```c
PORTB &= ~(1 << PB5);
```

---

## 1.5 Reading an Input Pin
```c
if (PINB & (1 << PB4)) {
    // Pin is HIGH
} else {
    // Pin is LOW
}
```

---

## 1.6 Internal Pull-Up (Register Level)

### Internal Pull-Up is enabled by:
1. Pin is INPUT
2. PORTx bit is set to 1

```c
DDRB &= ~(1 << PB4);   // input
PORTB |= (1 << PB4);   // enable pull-up
```

**Logic:**
- Not pressed → HIGH
- Pressed → LOW

---

## 1.7 Complete Register-Based GPIO Example
```c
#include <avr/io.h>

int main(void) {

    // LED on PB5
    DDRB |= (1 << PB5);

    // Button on PB4 with pull-up
    DDRB &= ~(1 << PB4);
    PORTB |= (1 << PB4);

    while (1) {
        if (!(PINB & (1 << PB4))) {
            PORTB |= (1 << PB5);   // LED ON
        } else {
            PORTB &= ~(1 << PB5);  // LED OFF
        }
    }
}
```

---

## 🟩 2. Bit Manipulation

Bit manipulation is **mandatory** for register-level programming.

---

## 2.1 Why Bit Manipulation?
- Registers are **8-bit values**
- Each bit controls **one hardware function**
- Needed to:
  - set bits
  - clear bits
  - toggle bits
  - read bits safely

---

## 2.2 Bitwise Operators

| Operator | Meaning |
|---------|---------|
| `|` | OR |
| `&` | AND |
| `~` | NOT |
| `^` | XOR |
| `<<` | Shift left |
| `>>` | Shift right |

---

## 2.3 Setting a Bit (to 1)
```c
PORTB |= (1 << PB5);
```

---

## 2.4 Clearing a Bit (to 0)
```c
PORTB &= ~(1 << PB5);
```

---

## 2.5 Toggling a Bit
```c
PORTB ^= (1 << PB5);
```

---

## 2.6 Reading a Bit
```c
if (PINB & (1 << PB4)) {
    // bit is HIGH
}
```

---

## 2.7 Bit Mask Concept
```c
(1 << PB4)
```

Creates:
```
00010000
```

---

## 2.8 Common Bit Manipulation Patterns

### Set multiple bits
```c
PORTB |= (1 << PB5) | (1 << PB3);
```

### Clear multiple bits
```c
PORTB &= ~((1 << PB5) | (1 << PB3));
```

---

## 🟨 3. GPIO + Bit Manipulation Combined

### Toggle LED on Button Press
```c
if (!(PINB & (1 << PB4))) {
    PORTB ^= (1 << PB5);
}
```

---

## 🟧 4. Interrupts (External Interrupt INT0)

Interrupts allow the MCU to **react immediately** to events  
without polling in the main loop.

---

## 4.1 Required Header Files
```c
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
```

---

## 4.2 Interrupt Service Routine (ISR)

- Runs **automatically**
- Interrupts main program execution
- Must be **short and efficient**

```c
ISR(INT0_vect) {
    PORTB |= (1 << PB5);   // LED ON
    _delay_ms(5000);       // stay ON for 5 seconds
}
```

---

## 4.3 Interrupt Setup Explanation

### Configure LED pin
```c
DDRB |= (1 << PB5);
```

### Configure Button pin (INT0 = PD2)
```c
DDRD &= ~(1 << PD2);   // input
PORTD &= ~(1 << PD2);  // no pull-up
```

### Configure interrupt trigger (rising edge)
```c
EICRA |= (1 << ISC01) | (1 << ISC00);
```

### Enable INT0
```c
EIMSK |= (1 << INT0);
```

### Enable global interrupts
```c
sei();
```

---

## 4.4 Complete Interrupt Example (Register-Level)

```c
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// --- INTERRUPT FUNCTION ---
ISR(INT0_vect) {
    PORTB |= (1 << PB5);   // LED ON
    _delay_ms(5000);       // keep LED ON for 5 seconds
}

void setup() {
    // LED as output
    DDRB |= (1 << PB5);

    // Button as input (INT0 = PD2)
    DDRD &= ~(1 << PD2);
    PORTD &= ~(1 << PD2);

    // Rising edge on INT0
    EICRA |= (1 << ISC01) | (1 << ISC00);
    EIMSK |= (1 << INT0);

    sei(); // global interrupts ON
}

int main() {
    setup();

    while (1) {
        // Normal LED blinking
        PORTB |= (1 << PB5);
        _delay_ms(300);
        PORTB &= ~(1 << PB5);
        _delay_ms(300);
    }
}
```

---

## 🟥 5. Typical Errors (IMPORTANT)

| Error | Explanation |
|------|------------|
| Using `=` instead of `|=` or `&=` | Overwrites register |
| Forgetting `DDRx` | Pin does nothing |
| Blocking code in ISR | Freezes system |
| Floating input | Random triggers |
| Forgetting `sei()` | Interrupt never fires |

---

## 🎓 Final Learning Goals

### GPIO
- Use `DDRx`, `PORTx`, `PINx`
- Configure inputs/outputs
- Enable pull-ups
- Read hardware directly

### Bit Manipulation
- Masks and bitwise operators
- Safe register access
- Multi-bit operations

### Interrupts
- Understand ISR concept
- Configure INT0
- Use global interrupts
- Combine interrupts with main loop
