#include "delayx.h"

// Forward declare the callback functions
void toggleLED1();
void toggleLED2();
void toggleLED3();

// LED pins
#define LED1_PIN 11
#define LED2_PIN 12
#define LED3_PIN 13

// LED states (on or off)
bool led1State = false;
bool led2State = false;
bool led3State = false;

// Delay timers for each LED
delayx delay1(1000, toggleLED1);  // 1 second delay for LED 1
delayx delay2(2000, toggleLED2);  // 1 second delay for LED 2
delayx delay3(3000, toggleLED3);  // 1 second delay for LED 3

void setup() {
  // Initialize LEDs as OUTPUT
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  // Optionally, start with all LEDs off
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
}

void loop() {
  // Regular code running in the loop

  // Update delay timers
  delay1.update();
  delay2.update();
  delay3.update();
}

// Callback functions to toggle LEDs
void toggleLED1() {
  led1State = !led1State;  // Toggle the state
  digitalWrite(LED1_PIN, led1State ? HIGH : LOW);  // Set the LED state
}

void toggleLED2() {
  led2State = !led2State;  // Toggle the state
  digitalWrite(LED2_PIN, led2State ? HIGH : LOW);  // Set the LED state
}

void toggleLED3() {
  led3State = !led3State;  // Toggle the state
  digitalWrite(LED3_PIN, led3State ? HIGH : LOW);  // Set the LED state
}
