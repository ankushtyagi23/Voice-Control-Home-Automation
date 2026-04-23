#include <SoftwareSerial.h>
// Bluetooth module pins
const int bluetoothTx = 2;
const int bluetoothRx = 3;
// LED pin
const int ledPin = 6;
// Relay pin
const int relayPin = 4;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup() {
Serial.begin(9600);
bluetooth.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(relayPin, OUTPUT);
}
void loop() {
// Receive voice command from Bluetooth module
String voiceCommand = bluetooth.readString();
if (voiceCommand == "turn on LED") {
digitalWrite(ledPin, HIGH);
} else if (voiceCommand == "turn off LED") {
digitalWrite(ledPin, LOW);
} else if (voiceCommand == "turn on fan") {
digitalWrite(relayPin, HIGH);
} else if (voiceCommand == "turn off fan") {
digitalWrite(relayPin, LOW);
}
}
