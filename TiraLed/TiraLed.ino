#include <FastLED.h>

#define NUM_LEDS 13
#define LED_PIN1 3
#define LED_PIN2 4

CRGB leds1 [NUM_LEDS];
CRGB leds2 [NUM_LEDS];

void setup() {
  
  FastLED.addLeds<WS2812B,LED_PIN1,GRB>(leds1,NUM_LEDS);
  FastLED.addLeds<WS2812B,LED_PIN2,GRB>(leds2,NUM_LEDS);
  
  FastLED.setBrightness(50);

}

void recorrer1(CRGB color, int DELAY) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = color;
    FastLED.show();
    delay(DELAY);

    if (i + 1 < NUM_LEDS) {  // Check to avoid going out of bounds
      leds1[i + 1] = color;
      FastLED.show();
      delay(DELAY);
    }

    leds1[i] = CRGB::Black;  // Turn off the current LED
    FastLED.show();
    delay(DELAY);
  }
}

void recorrer2(CRGB color, int DELAY) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds2[i] = color;
    FastLED.show();
    delay(DELAY);

    if (i + 1 < NUM_LEDS) {  // Check to avoid going out of bounds
      leds2[i + 1] = color;
      FastLED.show();
      delay(DELAY);
    }

    leds2[i] = CRGB::Black;  // Turn off the current LED
    FastLED.show();
    delay(DELAY);
  }
}

void recorrerIdaYVuelta1(CRGB color, int DELAY) {
  // Barrido hacia adelante
  for (int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = color;
    FastLED.show();
    delay(DELAY);

    if (i + 1 < NUM_LEDS) {
      leds1[i + 1] = color;
      FastLED.show();
      delay(DELAY);
    }

    leds1[i] = CRGB::Black;  // Apaga el LED actual
    FastLED.show();
    delay(DELAY);
  }

  // Barrido hacia atrás
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds1[i] = color;
    FastLED.show();
    delay(DELAY);

    if (i - 1 >= 0) {
      leds1[i - 1] = color;
      FastLED.show();
      delay(DELAY);
    }

    leds1[i] = CRGB::Black;  // Apaga el LED actual
    FastLED.show();
    delay(DELAY);
  }
}

void loop() {
  recorrerIdaYVuelta1(CRGB::Blue, 100);  // Llama a la función con el color y el retraso deseado
}
