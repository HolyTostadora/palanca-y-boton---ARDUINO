#include <FastLED.h>

#define NUM_LEDS 5
#define LED_PIN 3

#define DELAY 20

CRGB leds [NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B,LED_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(50);

}
void blinkLeds(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(DELAY);

    if (i + 1 < NUM_LEDS) {  // Check to avoid going out of bounds
      leds[i + 1] = color;
      FastLED.show();
      delay(DELAY);
    }

    leds[i] = CRGB::Black;  // Turn off the current LED
    FastLED.show();
    delay(DELAY);
  }
}

void loop() {
  blinkLeds(CRGB::Blue);  // Call the function with any color you want, like CRGB::Blue
}
