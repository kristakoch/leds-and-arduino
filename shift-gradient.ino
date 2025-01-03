#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

uint8_t START_HUE = 0;
uint8_t END_HUE = 123;

// Set colors.
CRGB START_COLOR = CRGB::Black;
CRGB END_COLOR = CRGB::Black;


void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255
}

void loop() {

  // Shift a gradient between two colors by 
  // modifying the hue at each loop.
  // 
  // Both hue values are incremented together
  // so making them closer will create a more 
  // subtle color difference.
  START_COLOR.setHue(START_HUE);
  END_COLOR.setHue(END_HUE);

  fill_gradient_RGB(leds, NUM_LEDS, START_COLOR, END_COLOR);
  FastLED.show();
  
  START_HUE++;
  END_HUE++;

  delay(50);
}

