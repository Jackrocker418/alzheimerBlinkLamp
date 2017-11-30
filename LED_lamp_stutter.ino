/*
  This is a rewrite to make a 40Hz blinking lamp for alzheimers. I make no claim for research, just making this for a friend.
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 1

#define NUM_LEDS 5

#define BRIGHTNESS 255

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

boolean button_was_pressed = false;
boolean ON = false;

void setup()
{ 
  button_was_pressed = false;
  pinMode(0, OUTPUT); // led serial
  pinMode(1, INPUT); // button input
  button_was_pressed = false;
  strip.begin();
  strip.show();
  //loop();

}

int checkButton() {
  if ( digitalRead(0) == HIGH) {
    ON = true;
    } else {ON = false;}
}

void strobe(int i) {
      i++;
      strip.setPixelColor(0, strip.Color(255,255,255 ) );
      strip.show();
      strip.setPixelColor(1, strip.Color(255,255,255 ) );
      strip.show();
      strip.setPixelColor(2, strip.Color(255,255,255 ) );
      strip.show();
      strip.setPixelColor(3, strip.Color(255,255,255 ) );
      strip.show();
      strip.setPixelColor(4, strip.Color(255,255,255 ) );
      strip.show();
      delayMicroseconds(20);
      strip.setPixelColor(0, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(1, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(2, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(3, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(4, strip.Color(0,0,0 ) );
      strip.show();
      delayMicroseconds(5);
      if (i>20){
      strobe(i);}
}

void loop()
{  
  int i = 0;
  checkButton();
  if (ON == true){
  strobe(i);
  } else {
      strip.setPixelColor(0, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(1, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(2, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(3, strip.Color(0,0,0 ) );
      strip.show();
      strip.setPixelColor(4, strip.Color(0,0,0 ) );
      strip.show();
      }
 }
