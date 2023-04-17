#include<Wire.h>
#include<SPI.h>
#include"SSD1306Wire.h"

#define TRIGGOR_PIN D5
#define ECHO_PIN D6
#define SDA_PIN D3
#define SCL_PIN D2
#define BUZZER_PIN D4
#define THRESHOLD_DIST 10

SSD1306Wire display(0x3c, SCL_PIN, SDA_PIN);

void setup() {
  Serial.begin(112500);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

 pinMode(TRIGGOR_PIN ,OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 pinMode(BUZZER_PIN, OUTPUT);


}

void loop() {
  digitalWrite(TRIGGOR_PIN,HIGH);
  delayMicroseconds(100);
  digitalWrite(TRIGGOR_PIN,LOW);

  long duration=pulseIn(ECHO_PIN, HIGH);

  int distance = duration/58.2;

  display.clear();
  display.drawString(0,0,"Distance: " + String(distance) + "cm");
  display.display();
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println("cm");

  if(distance<THRESHOLD_DIST)
  {
     digitalWrite(BUZZER_PIN, HIGH);
  }
  else
  {
    digitalWrite(BUZZER_PIN,LOW);
  }
  delay(200);
  
}
