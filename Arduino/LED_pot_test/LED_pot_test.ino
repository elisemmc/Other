#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 24
#define BRIGHTNESS 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
//  #if defined (__AVR_ATtiny85__)
//    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
//  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() 
{
  //simLight();
  Serial.print( analogRead(A0) >> 2 );
  Serial.print( " : " );
  Serial.print( analogRead(A1) >> 2 );
  Serial.print( " : " );
  Serial.print( analogRead(A2) >> 2 );
  Serial.print( "\n" );
  //colorWipe( strip.Color( analogRead(A0) >> 2, analogRead(A1) >> 2, analogRead(A2) >> 2 ), 100 );
  simLight();
  delay(1000);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, c);
    delay(wait);
  }
  
  strip.show();
}

void simLight()
{
  int potVal = analogRead(A0) >> 1;
  
  if( potVal < 256 )
  {
    colorWipe( strip.Color(255, potVal, 0 ), 10 );
  }
  else
  {
    colorWipe( strip.Color(255-(potVal>>1), 255, 0), 10);
  }
}

