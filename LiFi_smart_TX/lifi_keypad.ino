#include <Keypad.h>

// Pin definitions
const int tx_sig = 11;  // Signal pin
const int led = 13;     // LED for visual indication

// Keypad settings
const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns
char keys[ROWS][COLS] = {
  {'7', '8', '9', 'A'}, 
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {6, 7, 8, 9};  // Rows connected to these pins
byte colPins[COLS] = {2, 3, 4, 5};  // Columns connected to these pins
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char customKey;

void setup() {
  Serial.begin(9600);
  pinMode(tx_sig, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.println("it's like simple smart home with LiFi tech");
  Serial.println("set option :");
  Serial.println("1) Turn on motor 1");
  Serial.println("2) Turn off motor 1");
  Serial.println("3) Turn on motor 2");
  Serial.println("4) Turn off motor 2");
  Serial.println("5) Turn on lamp");
  Serial.println("6) Turn off lamp");
  Serial.println("7) Turn on lamp");
  Serial.println("8) Turn off lamp");
  Serial.println("+) increase speed motor 1");
  Serial.println("-) decrease speed motor 1");
  Serial.println("x) increase speed motor 2");
  Serial.println("/) decrease speed motor 2");
}

void sendSignal(int duration) {
  digitalWrite(tx_sig, HIGH);
  digitalWrite(led, HIGH);
  delay(duration);  // Send the pulse for the specified duration
  digitalWrite(tx_sig, LOW);
  digitalWrite(led, LOW);
}

void loop() {
  customKey = customKeypad.getKey();
  if (customKey) {  // If a key is pressed
    switch (customKey) {
      case '1': sendSignal(10); break;
      case '2': sendSignal(20); break;
      case '3': sendSignal(30); break;
      case '4': sendSignal(40); break;
      case '5': sendSignal(50); break;
      case '6': sendSignal(60); break;
      case '7': sendSignal(70); break;
      case '8': sendSignal(80); break;
      case '9': sendSignal(90); break;
      case '*': sendSignal(100); break;
      case '0': sendSignal(110); break;
      case '#': sendSignal(120); break;
      case 'A': sendSignal(130); break;
      case 'B': sendSignal(140); break;
      case 'C': sendSignal(150); break;
      case 'D': sendSignal(160); break;
    }
  }
}
