#include <Keypad.h>
#include <TimerOne.h>
#include "Maceta.h"

#define TRUE 1
#define FALSE 0

char hexaKeys[4][4]=
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[4] = {22, 24, 26, 28};
byte colPins[4] = {30, 32, 34, 36};

int points = 0, aumento = 0;
int stt[4]= {0, 0, 0, 0};
int sttx[4]= {0, 0, 0, 0};

char regar='0', ctrl='0', opcion='0';

bool vistaGeneral=FALSE;

Keypad Teclado = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Maceta maceta[4]={1,2,3,4};

void dibujarPlantas();
void Check_up();
void dibujarMenu();

void setup() { 
  TimerOne Timer1;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(Check_up);
  interrupts();  
  tft.initR(INITR_BLACKTAB);
  
}

void loop() {
  
  opcion=Teclado.getKey();
    
  if(maceta[0].vista && maceta[1].vista && maceta[2].vista && maceta[3].vista){ //significa que estamos en MENU
    if(!vistaGeneral){
      dibujarMenu();
      vistaGeneral=TRUE;
      
      for(int i=0; i<=3; i++){
        stt[i]=5;
        sttx[i]=5;
      }
    }
    dibujarPlantas();
    
    switch (opcion){
      
      case 'A':
        maceta[0].vista=FALSE;
      break;
      
      case 'C':
        maceta[1].vista=FALSE;
      break;

      case 'B':
       maceta[2].vista=FALSE;
      break;

      case 'D':
        maceta[3].vista=FALSE;
      break;

      default:
      break;
    }
  }//fin de if menu

  for(int i=0; i<=3; i++){
    if(!maceta[i].vista){
    if(vistaGeneral){
      maceta[i].dibujarMax();
      vistaGeneral=FALSE;
    }  
    
    if(maceta[i].estado == 0 ){
      do{
        ctrl=Teclado.getKey();
        maceta[i].semilla = ctrl - 48;
      }while(!(maceta[i].semilla > 0 && maceta[i].semilla < 10)&&ctrl!='#');

    if(ctrl!='#')     
      maceta[i].sem_init();
    }
      do{
        regar = 0;
        regar = Teclado.getKey();
        aumento = regar - 48;
        maceta[i].sem_atributos_avance(aumento);
        if(sttx[i]!=maceta[i].estado){
         sttx[i]=maceta[i].estado; 
         maceta[i].dibPlantaMax();
        }
      }while(regar != '#'&&ctrl!='#');
    
      maceta[i].vista = TRUE;
    }   
  }
  }

void dibujarMenu(){
  tft.fillScreen(ST77XX_WHITE);
  for(int i=0; i<=3; i++)
    maceta[i].dibujarMini();
}

void Check_up(){
    for(int i=0; i<=3; i++){
      if(maceta[i].estado != 0){
        maceta[i].sem_atributos_retroceso();
        maceta[i].sem_estado_retroceso();
        maceta[i].sem_estado_avance();
      }
    }
}

void dibujarPlantas(){
    for(int i=0; i<=3; i++){
      if(maceta[i].estado!=stt[i]){
        stt[i]=maceta[i].estado;
        maceta[i].dibPlantaMini();
      }
    }
}
