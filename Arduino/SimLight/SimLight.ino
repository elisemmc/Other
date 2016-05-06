#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 24
#define BRIGHTNESS 50

#define POT_PIN A0
int potVal = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  potVal = analogRead(POT_PIN);
  simLight();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, c);
  }
  
  strip.show();
  delay(wait);
}

// Sim plumbob function that goes from red->green and white at the end
void simLight()
{
  if( potVal < 40 )
  {
    colorWipe(strip.Color( 255, 255, 255 ), 50); // White 
  }
  else if( potVal < 45 )
  {
    colorWipe(strip.Color( 0, 255, 0 ), 50); // Green
  }
  else if( potVal < 300 )
  {
    colorWipe(strip.Color( potVal-45, 255, 0 ), 50); // Green-Yellow
  }
  else if( potVal < 555 )
  {
    colorWipe(strip.Color( 255, 255-(potVal - 300), 0 ), 50); // Red-Yellow
  }
  else 
  {
    colorWipe(strip.Color( 255, 0, 0 ), 50); // Red
  }
}
