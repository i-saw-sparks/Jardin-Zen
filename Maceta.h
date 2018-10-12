#ifndef Maceta_h
#define Maceta_h
#include "Arduino.h"
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Adafruit_GFX.h> 

#define TRUE 1
#define FALSE 0
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

class Maceta{
  public: 
    void init(void);
    void dibujarMini(void);
    void dibujarMax(void);
    void dibujarFruta(void);
    void dibPlantaMini(void);
    void dibPlantaMax(void);
    
    int semilla=0, numMaceta=0, x=0, y=0, estado=0;
    bool vista=TRUE;
    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
    
    Maceta(int temp);
};


#endif
