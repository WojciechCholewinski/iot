#include "LedControl.h"
#include <Arduino.h>  // Zawiera funkcje takie jak digitalWrite, pinMode

// Pin diody (możesz zmienić w zależności od swojego układu)
const int ledPin = 13;
const int pwmPin = 5;           // Pin, do którego podłączony jest brzęczek
const int pwmFrequency = 2000;  // Częstotliwość PWM
const int pwmResolution = 8;    // Rozdzielczość PWM (0-255)

// Tablica pinów, do których podłączone są diody LED
int LedPins[] = { 13, 12, 14, 27, 26, 25, 33, 32, 18, 19 };
int pinCount = sizeof(LedPins) / sizeof(LedPins[0]);  // Liczba pinów w tablicy

bool ledState = false;  // Zmienna kontrolująca, czy animacja LED jest aktywna
int animationStep = 0;  // Zmienna przechowująca aktualny krok animacji

// Ustawienie pinów diód oraz brzęczka jako wyjść
void setupLed() {
  for (int i = 0; i < pinCount; i++) {
    pinMode(LedPins[i], OUTPUT);
  }
  pinMode(pwmPin, OUTPUT);
  ledcAttach(pwmPin, pwmFrequency, pwmResolution);
}

// Włączenie diody
void turnOnLed() {
  ledState = true;    // Włącz animację diod
  animationStep = 0;  // Resetuj krok animacji
  Serial.println("Diody włączone");
}
// Wyłączenie diody
void turnOffLed() {
  ledState = false;  // Wyłącz animację diod
  for (int i = 0; i < pinCount; i++) {
    digitalWrite(LedPins[i], LOW);  // Wyłącz wszystkie diody
  }
  Serial.println("Diody wyłączone");
}

// Funkcja odpowiedzialna za aktualizację animacji LED
void updateLedAnimation() {
  if (ledState) {  // Jeśli animacja LED jest aktywna
    for (int i = 0; i < pinCount; i++) {
      if (i % 2 == animationStep % 2) {
        digitalWrite(LedPins[i], HIGH);
      } else {
        digitalWrite(LedPins[i], LOW);
      }
    }
    ledcWrite(pwmPin, animationStep / 2);
    delay(250);
    ledcWrite(pwmPin, 0);
    delay(100);
    ledcWrite(pwmPin, animationStep / 3);
    delay(250);
    ledcWrite(pwmPin, 0);

    delay(1000);
    animationStep++;  // Zwiększ krok animacji
  }
}