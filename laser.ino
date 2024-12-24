#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

// Set color and size.
CRGB LASER_COLOR = CRGB::Aquamarine;
int TAIL_LENGTH = 10;

int start = 0;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {

  // Make a laser fly across the string of lights.
  // The laser trail will be 5 lights long, with a bright
  // start and a progressively darker tail. 
  // 
  // Laser color can be set at the top of the file.

  fill_solid(leds, NUM_LEDS, CRGB::Black);

  if (start - TAIL_LENGTH > NUM_LEDS) {
    start = 0;
  }

  CHSV hsv = getHSV(LASER_COLOR);

  for (int i = 1; i < TAIL_LENGTH; i++) {
    if (start - i > 0 && start - i < NUM_LEDS) {
      leds[start - i].setHSV(hsv.h, 255, hsv.v/i);
    }
  }

  FastLED.show();

  delay(100);
  start++;
}


CHSV getHSV(const CRGB &color) {
  CHSV hsv;
  hsv = rgb2hsv_approximate(color);  
  return hsv; 
}


