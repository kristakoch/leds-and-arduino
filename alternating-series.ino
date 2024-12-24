#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

CRGB series[5] = {CRGB::DodgerBlue, CRGB::Red, CRGB::Yellow, CRGB::OrangeRed, CRGB::Green};
int seriesLength = 5;

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = series[i%5];
  }

  FastLED.show();
  delay(750);

  shiftSeries();
}


void shiftSeries() {
  CRGB first = series[0]; 

  for (int i = 0; i < seriesLength - 1; i++) {
    series[i] = series[i + 1];
  }
  
  series[seriesLength - 1] = first;
}
