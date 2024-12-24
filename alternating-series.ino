#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

// Set colors. Fix size.
CRGB SERIES[5] = {CRGB::DodgerBlue, CRGB::Red, CRGB::Yellow, CRGB::OrangeRed, CRGB::Green};
int SERIES_LEN = 5;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {

  // Set the full string of lights to the colors of the series
  // in the order they were declared above. The series will shift 
  // after each run so the series will appear to shift across
  // the light string.
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = SERIES[i%5];
  }

  FastLED.show();
  delay(750);

  shiftSeries();
}


void shiftSeries() {
  CRGB first = SERIES[0]; 

  for (int i = 0; i < SERIES_LEN - 1; i++) {
    SERIES[i] = SERIES[i + 1];
  }
  
  SERIES[SERIES_LEN - 1] = first;
}
