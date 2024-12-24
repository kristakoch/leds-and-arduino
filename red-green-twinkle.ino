#include <FastLED.h>

#define NUM_LEDS 50
#define LED_PIN 4

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS); // RGB is color order
  FastLED.setBrightness(50); // 0-255

  fill_gradient_RGB(leds, NUM_LEDS, CRGB::Green, CRGB::Red);
  FastLED.show();
}

void loop() {

  // The light string is set to a gradient of red to green. 
  // We'll pick a random light and dim it at random intervals.
  int rand_i = random(0, NUM_LEDS);
  CHSV hsv = getHue(leds[rand_i]);

  // dim and undim
  //   CRGB darkcolor  = CHSV(hue,255,192); // pure hue, three-quarters brightness
  //   CRGB lightcolor = CHSV(hue,128,255); // half 'whitened', full brightness

  int brightness = hsv.v;
  int inc = hsv.v / 10;
  for (int i = 0; i < 10; i++) {
    leds[rand_i].setHSV(hsv.h, 255, brightness);
    FastLED.show();
    delay(10);
    
    brightness -= inc;
  }
  for (int i = 0; i < 10; i++) {
    leds[rand_i].setHSV(hsv.h, 255, brightness);
    FastLED.show();
    delay(10);

    brightness += inc;
  }

  int rand_d = random(0,750);
  delay(rand_d);
}

CHSV getHue(const CRGB &color) {
  CHSV hsv;
  hsv = rgb2hsv_approximate(color);  
  return hsv; 
}
