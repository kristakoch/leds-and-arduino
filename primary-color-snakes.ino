#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255

  fill_solid(leds, NUM_LEDS, CRGB::Red);
}

void loop() {

  // set red
  for (int i = 0; i < NUM_LEDS; i+=1) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(25);
  }
  
  // set yellow
  for (int i = 0; i < NUM_LEDS; i+=2) {
    leds[i] = CRGB::Gold;
    FastLED.show();
    delay(50);
  }

  // set blue
  for (int i = 0; i < NUM_LEDS; i+=3) {
    leds[i] = CRGB::Teal;
    FastLED.show();
    delay(100);
  }
}

