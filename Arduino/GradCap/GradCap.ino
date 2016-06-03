#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define BRIGHTNESS 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(144, 6, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel grid = Adafruit_NeoPixel(64, 5, NEO_GRBW + NEO_KHZ800);

uint8_t strip_iter = 0;
uint8_t grid_iter = 0;

uint8_t word_loop_iter = 0;
uint16_t hi[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
               , 10, 11, 12, 13, 14, 15, 19, 20, 27, 28
               , 32, 33, 34, 35, 36, 37, 38, 39, 40, 41
               , 42, 43, 44, 45, 46, 47, 64, 65, 66, 67
               , 68, 69, 70, 71, 72, 73, 74, 75, 76, 77
               , 78, 79 };

uint16_t mom[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
                , 10, 11, 12, 13, 14, 20, 21, 27, 28, 36
                , 37, 40, 41, 42, 43, 44, 45, 46, 48, 49
                , 50, 51, 52, 53, 54, 55, 74, 75, 76, 77
                , 81, 82, 83, 84, 85, 86, 88, 89, 94, 95
                , 96, 97, 102, 103, 105, 106, 107, 108, 109, 110
                , 114, 115, 116, 117, 136, 137, 138, 139, 140, 141
                , 142, 143, 144, 145, 146, 147, 148, 149, 150, 156
                , 157, 163, 164, 172, 173, 176, 177, 178, 179, 180
                , 181, 182, 184, 185, 186, 187, 188, 189, 190, 191};

uint16_t dad[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
                , 10, 11, 12, 13, 14, 15, 16, 17, 22, 23
                , 24, 25, 26, 29, 30, 31, 33, 34, 35, 36
                , 37, 38, 42, 43, 44, 45, 64, 65, 66, 67
                , 68, 69, 72, 73, 74, 75, 76, 77, 78, 82
                , 83, 86, 87, 90, 91, 94, 95, 96, 97, 98
                , 99, 100, 101, 102, 104, 105, 106, 107, 108, 109
                , 128, 129, 130, 131, 132, 133, 134, 135, 136, 137
                , 138, 139, 140, 141, 142, 143, 144, 145, 150, 151
                , 152, 153, 154, 157, 158, 159, 161, 162, 163, 164
                , 165, 166, 170, 171, 172, 173};

uint16_t eecs[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
                 , 10, 11, 12, 13, 14, 15, 16, 17, 19, 20
                 , 22, 23, 24, 25, 27, 28, 30, 31, 32, 33
                 , 35, 36, 38, 39, 56, 57, 58, 59, 60, 61
                 , 62, 63, 64, 65, 66, 67, 68, 69, 70, 71
                 , 72, 73, 75, 76, 78, 79, 80, 81, 83, 84
                 , 86, 87, 88, 89, 91, 92, 94, 95, 114, 115
                 , 116, 117, 121, 122, 123, 124, 125, 126, 128, 129
                 , 130, 133, 134, 135, 136, 137, 142, 143, 144, 145
                 , 150, 151, 168, 169, 172, 173, 174, 176, 177, 179
                 , 180, 181, 182, 183, 184, 185, 187, 188, 190, 191
                 , 192, 193, 194, 195, 196, 198, 199, 201, 202, 203
                 , 206, 207};

uint16_t year[] = { 1, 2, 3, 6, 7, 8, 9, 10, 11, 12
                 , 14, 15, 16, 17, 19, 20, 22, 23, 24, 25
                 , 27, 28, 29, 30, 31, 32, 33, 36, 37, 38
                 , 57, 58, 59, 60, 61, 62, 64, 65, 66, 67
                 , 68, 69, 70, 71, 72, 73, 78, 79, 80, 81
                 , 86, 87, 88, 89, 90, 91, 92, 93, 94, 95
                 , 97, 98, 99, 100, 101, 102, 120, 121, 126, 127
                 , 128, 129, 130, 131, 132, 133, 134, 135, 136, 137
                 , 138, 139, 140, 141, 142, 143, 144, 145, 169, 170
                 , 171, 172, 173, 174, 176, 177, 178, 179, 180, 181
                 , 182, 183, 184, 185, 187, 188, 190, 191, 192, 193
                 , 195, 196, 198, 199, 200, 201, 202, 203, 204, 206
                 , 207, 209, 210, 211};

/*
 * w[] array form of the word
 * l elements in the array
 * n number of movements before it's over
 */
struct words
{
  uint16_t* w;
  uint8_t l;
  uint8_t n;
} ;

struct words word_loop[6];

void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  words hi_struct;
  hi_struct.w = hi;
  hi_struct.l = 52;
  hi_struct.n = 10;

  words mom_struct;
  mom_struct.w = mom;
  mom_struct.l = 100;
  mom_struct.n = 24;

  words dad_struct;
  dad_struct.w = dad;
  dad_struct.l = 106;
  dad_struct.n = 22;

  words eecs_struct;
  eecs_struct.w = eecs;
  eecs_struct.l = 122;
  eecs_struct.n = 24;

  words year_struct;
  year_struct.w = year;
  year_struct.l = 124;
  year_struct.n = 24;
  
  word_loop[0] = hi_struct;
  word_loop[1] = mom_struct;
  word_loop[2] = hi_struct;
  word_loop[3] = dad_struct;
  word_loop[4] = eecs_struct;
  word_loop[5] = year_struct;
  
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  grid.setBrightness(BRIGHTNESS);
  grid.begin();
  grid.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  wordScroll();
  colorWipe(strip.Color(255, 0, 0), 50); // Red
//  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//  colorWipe(strip.Color(0, 0, 0, 255), 50); // White

  strip.show();
  grid.show();
  delay(50);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  if( strip_iter < strip.numPixels() ) 
  {
    strip.setPixelColor( strip_iter , c);
    strip_iter++;
  }
  else
  {
    strip_iter = 0;
  }
}

/*
 * Scrolls through a given word
 */
void wordScroll()
{
  uint8_t i;
  uint16_t* w = word_loop[word_loop_iter].w;
  uint8_t l = word_loop[word_loop_iter].l;
  uint8_t n = word_loop[word_loop_iter].n;

  for( i = 0; i < 64; i++)
  {
    grid.setPixelColor( i, grid.Color( 0, 0, 0 ) ); //clear grid
  }
  
  for( i = 0; i < l; i++ )
  {
    if( ( w[i] + 64 - (grid_iter*8) >= 0 ) && ( w[i] + 64 - (grid_iter*8) < 64 ) )
    {
      grid.setPixelColor( ( w[i] + 64 - (grid_iter*8) ) , grid.Color( 255, 0, 0 ) );
    }
  }

  if( grid_iter < n+8 )
  {
    grid_iter++;
  }
  else //start new word
  {
    grid_iter = 0;
    word_loop_iter++;

    if( word_loop_iter == 6 )
      word_loop_iter = 0;
  }
}


