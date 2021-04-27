#include <Adafruit_NeoPixel.h> // Library einbinden
 
#define N_LEDS 32 //Anzahl LEDs
#define PIN     6 //Output Pin für den LED Daten Input
 
//NeoPixels initialisieren 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
int delayval = 1000; //1000 Milli Sekunden
int delayval2 = 100; //100 Milli Sekunden
int start = 0; //Läuft das Skript zum ersten mal?
 
void setup() {
  strip.begin();
}
 
 
void loop() {
 
  if(start == 0){ // Skript läuft das erste mal! Anschalt Sequenz anzeigen.
 
   // Lauflicht Rot      
   for(int i=0;i<N_LEDS;i++){ 
 
      strip.setPixelColor(i, strip.Color(255,0,0));       
      strip.setPixelColor(N_LEDS-i, strip.Color(255,0,0));
      strip.setPixelColor(i-1, strip.Color(5,0,0)); 
      strip.setPixelColor(N_LEDS-i+1, strip.Color(5,0,0)); 
      strip.show();
      delay(delayval2);   
 
    }       
 
    // Blau Blinken
    for(int i=0;i<N_LEDS;i++){
      strip.setPixelColor(i, strip.Color(0,0,255)); // Blau an
      strip.show();   
    }
 
    delay(delayval2);    // warten
 
    for(int i=0;i<N_LEDS;i++){
      strip.setPixelColor(i, strip.Color(0,0,0)); // Blau aus
      strip.show();   
    }              
 
    delay(delayval2);   // warten
 
    for(int i=0;i<N_LEDS;i++){
      strip.setPixelColor(i, strip.Color(0,0,255)); // Blau an
      strip.show();   
    }              
 
    delay(delayval2); // warten
    delay(delayval2); // warten
 
    // Start vorbei, nicht noch mal ausführen
    start=1; 
  }
 
  //Lichter vorne Weiss anschalten
  for(int i=0;i<(N_LEDS/2);i++){
    strip.setPixelColor(i, strip.Color(255,255,255));
    strip.show();   
  }          
 
  // Lichter hinten Rot anschalten
  for(int i=(N_LEDS/2);i<N_LEDS;i++){
    strip.setPixelColor(i, strip.Color(255,0,0));
    strip.show();   
  }
 
  delay(delayval);
 
}
