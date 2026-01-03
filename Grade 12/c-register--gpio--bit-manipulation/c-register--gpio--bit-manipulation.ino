/******************************************************
 * Arduino Register-Level GPIO Example
 * 
 * Topics covered:
 *  - GPIO without Arduino.h abstraction
 *  - DDRx, PORTx, PINx registers
 *  - Bit manipulation (set, clear, toggle, read)
 *  - Internal Pull-Up resistor
 * 
 * Hardware:
 *  - LED  -> PB5 (Arduino Pin 13)
 *  - Button -> PB4 (Arduino Pin 12)
 ******************************************************/

#include <avr/io.h>      // Access to AVR registers
#include <util/delay.h> // For _delay_ms()

/******************************************************
 * BIT DEFINITIONS (for readability)
 ******************************************************/

#define LED_PIN     PB5     // Bit position for LED
#define BUTTON_PIN  PB4     // Bit position for Button

/******************************************************
 * MAIN FUNCTION
 ******************************************************/

int main(void) {

    /**************************************************
     * GPIO CONFIGURATION
     **************************************************/

    // --- LED as OUTPUT ---
    // Set bit PB5 in DDRB to 1 → output
    DDRB |= (1 << LED_PIN);

    // --- Button as INPUT ---
    // Clear bit PB4 in DDRB → input
    DDRB &= ~(1 << BUTTON_PIN);

    // --- Enable internal Pull-Up for button ---
    // Set PB4 in PORTB while pin is input
    PORTB |= (1 << BUTTON_PIN);

    /**************************************************
     * MAIN LOOP
     **************************************************/
    while (1) {

        /**********************************************
         * READ BUTTON STATE
         * Pull-Up logic:
         *  - Not pressed → HIGH (1)
         *  - Pressed     → LOW  (0)
         **********************************************/

        if (!(PINB & (1 << BUTTON_PIN))) {
            // Button pressed (LOW)

            // Toggle LED using XOR
            PORTB ^= (1 << LED_PIN);

            // Simple debounce delay
            _delay_ms(300);
        }
    }

    // Never reached
    return 0;
}