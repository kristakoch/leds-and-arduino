#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

// Set colors.
CRGB COLOR_ONE = CRGB::FairyLight;
CRGB COLOR_TWO = CRGB::Red;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {

  // Set bulbs to alternating colors.
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i % 2 == 0) {
      leds[i] = COLOR_ONE;
    } else {
      leds[i] = COLOR_TWO;
    }
  }

  FastLED.show();
  delay(250);

  // Now set them to the opposite for a zesty blink effect.
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i % 2 != 0) {
      leds[i] = COLOR_ONE;
    } else {
      leds[i] = COLOR_TWO;
    }
  }

  FastLED.show();
  delay(250);
}
