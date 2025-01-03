#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

uint8_t START_HUE = 0;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {

  // Set the string of lights to a rainbow and make it undulate
  // by shifting the starting hue by one each time the loop goes.
  fill_rainbow(leds, NUM_LEDS, START_HUE, 255/NUM_LEDS);
  FastLED.show();
  
  delay(50);
  startHue++;
}

