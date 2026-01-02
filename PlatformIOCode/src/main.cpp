#include <Arduino.h>
#include <FastLED.h>
#include "data.h"

#define LED_PIN     2           // Data pin number
#define NUM_LEDS    235          // Number of LEDs
#define LED_TYPE    WS2812B     // Your LED strip type
#define COLOR_ORDER GRB         // Color channel order

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(2);  // 0-255 (50 = ~20% brightness)

  Serial.begin(115200);
}

int current_year_index = 0;

void loop() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  /* // christmas lights
  for (int group=0; group<=NUM_LEDS/2; group++) {
    int i = group * 2 + (current_led % 2);

    if (i >= NUM_LEDS) continue;

    if (i % 2 == 0)
      leds[i] = CRGB::Red;
    else
      leds[i] = CRGB::Green;
  }
  //fill_solid(leds, 4, CRGB::Red);
  current_led++;
  */

  // light up current year LED
  leds[32+year_index_to_led[current_year_index]] = CRGB::White;

  // check country for each LED and light up country on key
  for (int i=0; i<174; i++) {
    int country = year_index_and_led_to_country_index
                    [current_year_index][i];
    CRGB color = country_index_to_color[country];
    leds[61+i] = color;    // LED on map
    leds[country] = color; // LED on key
  }

  /*
  leds[0] = CRGB(0,0,0);
  leds[1] = CRGB(255,0,0);
  leds[2] = CRGB(255,0,255);
  leds[3] = CRGB(255,255,0);
  leds[4] = CRGB(0,255,0);
  leds[5] = CRGB(0,255,255);
  leds[6] = CRGB(0,0,255);
  leds[7] = CRGB(255,255,255);
  leds[8] = CRGB(128,0,255);
  leds[9] = CRGB(255,0,128);
  leds[10] = CRGB(128,255,0);
  leds[11] = CRGB(255,128,0);
  leds[12] = CRGB(0,128,255);
  leds[13] = CRGB(0,255,128);
  leds[14] = CRGB(128,255,255);
  leds[15] = CRGB(255,128,255);
  leds[16] = CRGB(128,128,255);
  leds[17] = CRGB(255,255,128);
  leds[18] = CRGB(128,128,255);
  */

  current_year_index++;
  current_year_index %= 29;

  FastLED.show();
  Serial.println("running");   // Your code here
  delay(2000);
}