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

int points = 0, aumento = 0, solt=0, aguat=0;
int stt[4]= {0, 0, 0, 0};
int sttx[4]= {0, 0, 0, 0};

char regar='0', ctrl='0', opcion='0';

bool vistaGeneral=FALSE, ctrlp=FALSE;

Keypad Teclado = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Maceta maceta[4]={1,2,3,4};

void dibujarPlantas();
void Check_up();
void dibujarMenu();
void dibujarMenuS();
void borrarMenuS();

void setup() { 
  TimerOne Timer1;
  Timer1.initialize(3000000);
  Timer1.attachInterrupt(Check_up);
  interrupts();  
  tft.initR(INITR_BLACKTAB);
  
}

void loop() {
    tft.setCursor(1,1);
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(1);
    tft.print("score: ");
    tft.print(points);
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
        dibujarMenuS();
      }while(!(maceta[i].semilla > 0 && maceta[i].semilla < 10)&&ctrl!='#');
        borrarMenuS();
    if(ctrl!='#')     
      maceta[i].sem_init();
    }
      do{
        ctrlp=FALSE;
        regar = 0;
        regar = Teclado.getKey();
        aumento = regar - 48;
        maceta[i].sem_atributos_avance(aumento);
        if(sttx[i]!=maceta[i].estado){
         sttx[i]=maceta[i].estado; 
         maceta[i].dibPlantaMax();
        }
        if(solt!=maceta[i].sol){
          solt=maceta[i].sol;
          maceta[i].dibujarBarraS();
        }
        if(aguat!=maceta[i].agua){
          aguat=maceta[i].agua;
          maceta[i].dibujarBarraA();
        }
        if(maceta[i].estado==4){
          if(aumento==3){
            points++;
            ctrlp=TRUE;
            maceta[i].estado=0;
          }
        }
      }while(regar != '#'&&ctrl!='#'&&maceta[i].estado!=0&&!ctrlp);
    
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

void dibujarMenuS(){
    
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(1);
    for(int c=0; c<2; c++){
      for(int i=10; i<=40; i+=10){
          if(c==0){
          tft.setCursor(5,i);
          switch(i){
          case 10:
            tft.print("1-Naranja ");       
            break;
          case 20:
            tft.print("2-Manzana ");
            break;
          case 30:
            tft.print("3-Fresa");
            break;
          case 40:
            tft.print("4-Uvas");
            break;      
          }
        }
          if(c==1){
          tft.setCursor(65,i);
          switch(i){
          case 10:
            tft.print("5-Cereza ");       
            break;
          case 20:
            tft.print("6-Durazno");
            break;
          case 30:
            tft.print("7-Kiwi");
            break;
          case 40:
            tft.print("8-Pera");
            break;      
          }
        }
    }
    tft.setCursor(25,50);
    tft.print("9-Frambuesa");
}
}

void borrarMenuS(){
  tft.fillRect(5,10,123,50,ST77XX_WHITE);
}
