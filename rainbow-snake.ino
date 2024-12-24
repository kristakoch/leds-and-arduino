#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

uint8_t RAINBOW_SIZE = 0;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {

  // Start from a dark light strip and snake to the end, 
  // building up a rainbow. 
  if (RAINBOW_SIZE > NUM_LEDS) {
    RAINBOW_SIZE = 0;
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }

  fill_rainbow(leds, RAINBOW_SIZE, 0, 255/NUM_LEDS);
  FastLED.show();
  
  RAINBOW_SIZE++;

  delay(50);
}

