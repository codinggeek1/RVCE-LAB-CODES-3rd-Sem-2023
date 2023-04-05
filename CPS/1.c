#include <Wire.h>
#include "SSD1306Wire.h"
#include <SPI.h>
const int BUZZER_PIN = 2;
const int ECHO_PIN = 14;
const int TRIGGER_PIN = 12;
const int SDA_PIN = 4;
const int SCL_PIN = 5;
#define BUZZER_PIN 2
#define ECHO_PIN 14
#define TRIGGER_PIN 12
#define SDA_PIN 4
#define SCL_PIN 5
#define DISTANCE_THRESHOLD 10


SSD1306Wire display(0x3c,SCL_PIN , SDA_PIN);

void setup()
{
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  int distance = duration / 58.2;

  display.clear();
  display.drawString(0, 0, "Distance: " + String(distance) + " cm");
  display.display();

  if (distance < DISTANCE_THRESHOLD) 
  {
    digitalWrite(BUZZER_PIN, HIGH);
  } 
  else 
  {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(100);
}
