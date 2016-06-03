#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(144, 5, NEO_GRBW + NEO_KHZ800);

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
  int i;

  Serial.print( analogRead(A0) );
  Serial.print( " : " );
  Serial.print( analogRead(A1) );
  Serial.print( " : " );
  Serial.print( analogRead(A2) );
  Serial.print( "\n" );
  //strip.setBrightness( analogRead(A1) >> 2 );
  //simLight();

  uint32_t ku2[] = { strip.Color(255, 0, 0), strip.Color(0, 0, 255) };
  uint32_t ku4[] = { strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(0, 0, 255), strip.Color(0, 0, 255) };
  uint32_t ku6[] = { strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255) };
  uint32_t ku8[] = { strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255) };
  uint32_t ku12[] = { strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0)
                      , strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255) };
  uint32_t ku24[] = { strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0)
                      , strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0), strip.Color(255, 0, 0)
                      , strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255)
                      , strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255), strip.Color(0, 0, 255)
                    };

  uint32_t kuFade12[] = { strip.Color(255, 0, 0), strip.Color(127, 0, 0), strip.Color(63, 0, 0), strip.Color(31, 0, 0), strip.Color(15, 0, 0), strip.Color(0, 0, 0)
                          , strip.Color(0, 0, 255), strip.Color(0, 0, 127), strip.Color(0, 0, 63), strip.Color(0, 0, 31), strip.Color(0, 0, 15), strip.Color(0, 0, 0)
                        };
  uint32_t red8[] = { strip.Color(255, 0, 0), strip.Color(127, 0, 0), strip.Color(127, 0, 0), strip.Color(63, 0, 0), strip.Color(63, 0, 0), strip.Color(31, 0, 0), strip.Color(15, 0, 0), strip.Color(0, 0, 0) };
  uint32_t blue8[] = { strip.Color(0, 0, 255), strip.Color(0, 0, 127), strip.Color(0, 0, 127), strip.Color(0, 0, 63), strip.Color(0, 0, 63), strip.Color(0, 0, 31), strip.Color(0, 0, 15), strip.Color(0, 0, 0) };

  for( i=0; i<10; i++ )
    counterclockwiseSpin( kuFade12, 12, 100 );

  for( i=0; i<10; i++ )
    clockwiseSpin( kuFade12, 12, 100 );
  
  for( i=0; i<10; i++ )
    clockwiseSpin(ku2, 2, 200 );

  for( i=0; i<5; i++ )
    clockwiseSpin(ku4, 4, 100 );

  for( i=0; i<5; i++ )
    counterclockwiseSpin(ku4, 4, 100 );

  for( i=0; i<5; i++ )
    clockwiseSpin(ku6, 6, 100 );

  for( i=0; i<5; i++ )
    counterclockwiseSpin(ku6, 6, 100 );

  for( i=0; i<5; i++ )
    clockwiseSpin(ku8, 8, 100 );

  for( i=0; i<5; i++ )
    counterclockwiseSpin(ku8, 8, 100 );

  for( i=0; i<5; i++ )
    clockwiseSpin(ku12, 12, 100 );

  for( i=0; i<5; i++ )
    counterclockwiseSpin(ku12, 12, 100 );

  for( i=0; i<5; i++ )
    clockwiseSpin(ku24, 24, 100 );

  for( i=0; i<5; i++ )
    counterclockwiseSpin(ku24, 24, 100 );

  for( i=0; i<10; i++ )
  {
    clockwiseSpin( red8, 8, 100 );
    clockwiseSpin( blue8, 8, 100 );
  }

  for ( int i = 0; i < 5; i++ )
  {
    clockwiseWipe( strip.Color(255, 0, 0), 100 );
    counterclockwiseWipe( strip.Color(0, 0, 255), 100 );
  }
}

void clockwiseWipe(uint32_t c, uint8_t wait)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(strip.numPixels() - (i + 1), c);
    strip.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void counterclockwiseWipe(uint32_t c, uint8_t wait)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void clockwiseSpin( uint32_t colors[], uint8_t colors_size, uint8_t wait )
{
  for ( uint16_t j = 0; j < colors_size; j++ )
  {
    for ( uint16_t i = 0; i < strip.numPixels(); i++ )
    {
      strip.setPixelColor( strip.numPixels() - (i + 1), colors[(j + i) % colors_size] );
    }
    strip.show();
    delay(wait);
  }
}

void counterclockwiseSpin( uint32_t colors[], uint8_t colors_size, uint8_t wait )
{
  for ( uint16_t j = 0; j < colors_size; j++ )
  {
    for ( uint16_t i = 0; i < strip.numPixels(); i++ )
    {
      strip.setPixelColor( i, colors[(j + i) % colors_size] );
    }
    strip.show();
    delay(wait);
  }
}

void simLight()
{
  int potVal = analogRead(A0) >> 1;
  Serial.println(potVal);

  if ( potVal < 256 )
  {
    clockwiseWipe( strip.Color(255, potVal, 0 ), 10 );
  }
  else
  {
    clockwiseWipe( strip.Color(255 - (potVal - 256), 255, 0), 10);
  }
}


