# 📘 Study Overview: GPIO via Registers (without Arduino.h) & Bit Manipulation

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

Set pin as INPUT

DDRB &= ~(1 << PB5);  // PB5 = input


⸻

1.4 Writing to an Output Pin

Set pin HIGH

PORTB |= (1 << PB5);

Set pin LOW

PORTB &= ~(1 << PB5);


⸻

1.5 Reading an Input Pin

if (PINB & (1 << PB4)) {
    // Pin is HIGH
} else {
    // Pin is LOW
}


⸻

1.6 Internal Pull-Up (Register Level)

Internal Pull-Up is enabled by:
	1.	Pin is INPUT
	2.	PORTx bit is set to 1

DDRB &= ~(1 << PB4);   // input
PORTB |= (1 << PB4);   // enable pull-up

Logic:
	•	Not pressed → HIGH
	•	Pressed → LOW

⸻

1.7 Complete Register-Based GPIO Example

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
⸻

🟩 2. Bit Manipulation

Bit manipulation is mandatory for register-level programming.

⸻

2.1 Why Bit Manipulation?
	•	Registers are 8-bit values
	•	Each bit controls one hardware function
	•	You must:
	•	set bits
	•	clear bits
	•	toggle bits
	•	check bits

⸻

2.2 Bitwise Operators

Operator	Meaning
`	`
&	AND
~	NOT
^	XOR
<<	Shift left
>>	Shift right


⸻

2.3 Setting a Bit (to 1)

PORTB |= (1 << PB5);

Explanation:
	•	1 << PB5 → binary mask
	•	OR (|=) sets only this bit

⸻

2.4 Clearing a Bit (to 0)

PORTB &= ~(1 << PB5);

Explanation:
	•	~ inverts the mask
	•	AND clears the bit safely

⸻

2.5 Toggling a Bit

PORTB ^= (1 << PB5);

Explanation:
	•	XOR flips the bit
	•	1 → 0
	•	0 → 1

⸻

2.6 Reading a Bit

if (PINB & (1 << PB4)) {
    // bit is 1 (HIGH)
}


⸻

2.7 Bit Mask Concept

(1 << PB4)

Creates a binary mask like:

00010000

Used to isolate or modify a single bit.

⸻

2.8 Common Bit Manipulation Patterns

Set multiple bits

PORTB |= (1 << PB5) | (1 << PB3);

Clear multiple bits

PORTB &= ~((1 << PB5) | (1 << PB3));


⸻

🟨 3. GPIO + Bit Manipulation Combined

Example: Toggle LED on Button Press

if (!(PINB & (1 << PB4))) {
    PORTB ^= (1 << PB5);   // toggle LED
}


⸻

🟥 4. Typical Errors (IMPORTANT)

Error	Explanation
Using = instead of `	=`
Forgetting ~ when clearing	Clears wrong bits
Not setting DDR	Pin does nothing
Floating input	No pull-up or pull-down


⸻

🎓 Summary / Learning Goals

GPIO Registers
	•	Understand DDRx, PORTx, PINx
	•	Configure input/output
	•	Enable internal pull-ups
	•	Read and write pins directly

Bit Manipulation
	•	Use masks correctly
	•	Set, clear, toggle bits safely
	•	Combine multiple bit operations
	•	Avoid register overwrite bugs
