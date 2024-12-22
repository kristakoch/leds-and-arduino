#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

uint8_t startHue = 0;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {
  fill_rainbow(leds, NUM_LEDS, startHue, 255/NUM_LEDS);
  FastLED.show();
  
  delay(50);
  startHue++;
}

