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
Keypad Teclado = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void dibujarMenu();
void dibujarPlantas();
int points = 0;
char opcion='0';
char regar='0', ctrl='0';
int aumento = 0;
int stt1=0, stt2=0, stt3=0, stt4=0;
bool vistaGeneral=FALSE;
Maceta maceta1(1), maceta2(2), maceta3(3), maceta4(4);

void setup() { 
  TimerOne Timer1;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(Check_up);
  interrupts();  
  tft.initR(INITR_BLACKTAB);
  
}

void loop() {
  
    opcion=Teclado.getKey();
    
  
  
  if(maceta1.vista && maceta2.vista && maceta3.vista && maceta4.vista){ //significa que estamos en MENU
    if(!vistaGeneral){
      dibujarMenu();
      vistaGeneral=TRUE;
      stt1=0;
      stt2=0;
      stt3=0;
      stt4=0;
    }
    dibujarPlantas();
    switch (opcion){
      
      case 'A':
        maceta1.vista=FALSE;
     
      break;
      
      case 'C':
        maceta2.vista=FALSE;
      break;

      case 'B':
       maceta3.vista=FALSE;
      break;

      case 'D':
        maceta4.vista=FALSE;
      break;

      default:
      break;
    }
  }//fin de if menu

    if(!maceta1.vista){
    if(vistaGeneral){
      maceta1.dibujarMax();
      vistaGeneral=FALSE;
    }  
    
    if(maceta1.estado == 0 ){
      do{
        ctrl=Teclado.getKey();
        maceta1.semilla = ctrl - 48;
      }while(!(maceta1.semilla > 0 && maceta1.semilla < 10)&&ctrl!='#');

    if(ctrl!='#')     
      maceta1.sem_init();
    }
      do{
        regar = 0;
        regar = Teclado.getKey();
        aumento = regar - 48;
        maceta1.sem_atributos_avance(aumento);
        maceta1.dibPlantaMax();
      }while(regar != '#'&&ctrl!='#');
    
      maceta1.vista = TRUE;
    }   

    if(!maceta2.vista){
    if(vistaGeneral){
      maceta2.dibujarMax();
      vistaGeneral=FALSE;
    }  
    
    if(maceta2.estado == 0 ){
      do{
        ctrl=Teclado.getKey();
        maceta2.semilla = ctrl - 48;
      }while(!(maceta2.semilla > 0 && maceta2.semilla < 10)&&ctrl!='#');

    if(ctrl!='#')     
      maceta2.sem_init();
    }
      do{
        regar = 0;
        regar = Teclado.getKey();
        aumento = regar - 48;
        maceta2.sem_atributos_avance(aumento);
        maceta2.dibPlantaMax();
      }while(regar != '#'&&ctrl!='#');
    
      maceta2.vista = TRUE;
    }

    if(!maceta3.vista){
    if(vistaGeneral){
      maceta3.dibujarMax();
      vistaGeneral=FALSE;
    }  
    
    if(maceta3.estado == 0 ){
      do{
        ctrl=Teclado.getKey();
        maceta3.semilla = ctrl - 48;
      }while(!(maceta3.semilla > 0 && maceta3.semilla < 10)&&ctrl!='#');

    if(ctrl!='#')     
      maceta3.sem_init();
    }
      do{
        regar = 0;
        regar = Teclado.getKey();
        aumento = regar - 48;
        maceta3.sem_atributos_avance(aumento);
        maceta3.dibPlantaMax();
      }while(regar != '#'&&ctrl!='#');
    
      maceta3.vista = TRUE;
    }

    if(!maceta4.vista){
    if(vistaGeneral){
      maceta4.dibujarMax();
      vistaGeneral=FALSE;
    }  
    
    if(maceta4.estado == 0 ){
      do{
        ctrl=Teclado.getKey();
        maceta4.semilla = ctrl - 48;
      }while(!(maceta4.semilla > 0 && maceta4.semilla < 10)&&ctrl!='#');

    if(ctrl!='#')     
      maceta4.sem_init();
    }
      do{
        regar = 0;
        regar = Teclado.getKey();
        aumento = regar - 48;
        maceta4.sem_atributos_avance(aumento);
        maceta4.dibPlantaMax();
      }while(regar != '#'&&ctrl!='#');
    
      maceta4.vista = TRUE;
    }
    
}

void dibujarMenu(){
  tft.fillScreen(ST77XX_WHITE);
  maceta1.dibujarMini();
  maceta2.dibujarMini();
  maceta3.dibujarMini();
  maceta4.dibujarMini();
}

void dibujarPlantas(){
  if(maceta1.estado!=stt1){
    stt1=maceta1.estado;
    maceta1.dibPlantaMini();
  }
  if(maceta2.estado!=stt2){
    stt2=maceta2.estado;
    maceta2.dibPlantaMini();
  }
  if(maceta3.estado!=stt3){
    stt3=maceta3.estado;
    maceta3.dibPlantaMini();
  }
  if(maceta4.estado!=stt4){
    stt4=maceta4.estado;
    maceta4.dibPlantaMini();
  }
}

void Check_up(){
  if(maceta1.estado != 0){
    maceta1.sem_atributos_retroceso();
    maceta1.sem_estado_retroceso();
    maceta1.sem_estado_avance();
  }
  if(maceta2.estado != 0){
    maceta2.sem_atributos_retroceso();
    maceta2.sem_estado_retroceso();
    maceta2.sem_estado_avance();
  }
  if(maceta3.estado != 0){
    maceta3.sem_atributos_retroceso();
    maceta3.sem_estado_retroceso();
    maceta3.sem_estado_avance();
  }
  if(maceta4.estado != 0){
    maceta4.sem_atributos_retroceso();
    maceta4.sem_estado_retroceso();
    maceta4.sem_estado_avance();
  }
}
