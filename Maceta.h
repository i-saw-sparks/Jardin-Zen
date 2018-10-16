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

    //FUNCIONES Y VARIABLES RELACIONADAS CON LA MACETAS
    void init(void);
    void dibujarMini(void);
    void dibujarMax(void);
    void dibujarFruta(void);
    void dibPlantaMini(void);
    void dibPlantaMax(void);

    int semilla=0, numMaceta=0, x=0, y=0, estado=0;
    bool vista = TRUE;
    Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

    Maceta(int temp);


    //FUNCIONES Y VARIABLES RELACIONADAS CON LAS SEMILLAS
        int agua = 0, sol = 0;
        bool ctrl_critico = false;
        int a_avance = 0, s_avance = 0;
        int a_aceptable = 0, s_aceptable = 0;
        int a_retroceso = 0, s_retroceso = 0;
        int cont = 0, cont2 = 0;

        void sem_init();
        void sem_estado_avance();
        void sem_estado_retroceso();
        void sem_atributos_avance(int entrada);
        void sem_atributos_retroceso();
        void dibujarBarras(); //relacion a agua y sol como 100

};


#endif
