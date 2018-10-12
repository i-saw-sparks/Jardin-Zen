#include "Maceta.h"
#include "Keypad.h"

#define TRUE 1
#define FALSE 0

char hexaKeys[4][4]=
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[4] = {1, 2, 3, 4};
byte colPins[4] = {5, 6, 7, 8};
Keypad Teclado = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);

void dibujarMenu();
void dibujarPlantas();
int points = 0;
char opcion='0';
bool vistaGeneral=FALSE;
Maceta maceta1(1), maceta2(2), maceta3(3), maceta4(4);

void setup() { 
  maceta1.tft.initR(INITR_BLACKTAB);
  maceta1.estado=1;
  maceta2.estado=3;
  maceta3.estado=2;
  maceta4.estado=4;
}

void loop() {
  
  //opcion=Teclado.getKey;

  if(maceta1.vista && maceta2.vista && maceta3.vista && maceta4.vista){ //significa que estamos en MENU
    if(!vistaGeneral){
      dibujarMenu();
      dibujarPlantas();
      vistaGeneral=TRUE;
    }
    switch (opcion){
      
      case 'A':
        maceta1.vista=FALSE;
      break;
      
      case 'B':
      break;

      case 'C':
      break;

      case 'D':
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
    //si estado 0 se escoge semilla
    //si estado !0 regar...
  }

  if(!maceta2.vista){
    if(vistaGeneral){
      maceta2.dibujarMax();
      vistaGeneral=FALSE;
    }  
    //si estado 0 se escoge semilla
    //si estado !0 regar...
  }

  if(!maceta3.vista){
    if(vistaGeneral){
      maceta3.dibujarMax();
      vistaGeneral=FALSE;
    }  
    //si estado 0 se escoge semilla
    //si estado !0 regar...
  }

  if(!maceta4.vista){
    if(vistaGeneral){
      maceta4.dibujarMax();
      vistaGeneral=FALSE;
    }  
    //si estado 0 se escoge semilla
    //si estado !0 regar...
  }
  
}

void dibujarMenu(){
  maceta1.tft.fillScreen(ST77XX_WHITE);
  maceta1.dibujarMini();
  maceta2.dibujarMini();
  maceta3.dibujarMini();
  maceta4.dibujarMini();
}

void dibujarPlantas(){
  maceta1.dibPlantaMini();
  maceta2.dibPlantaMini();
  maceta3.dibPlantaMini();
  maceta4.dibPlantaMini();
}
