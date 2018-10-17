#include "Arduino.h"
#include "Maceta.h"

Maceta::Maceta(int temp){ //constructor
  numMaceta=temp;
  switch(numMaceta){
        case 1:
          x=0;
          y=0;
          break;
        case 2:
          x=0;
          y=80;
          break;
        case 3:
          x=64;
          y=0;
          break;
        case 4:
          x=64;
          y=80;
          break;
      }
}

void Maceta::dibujarMini(){ //Maceta en menu
      tft.fillRect(x+20,y+50,24,24,ST77XX_RED);
      tft.fillRect(x+18,y+50,28,8,ST77XX_ORANGE);
      //PRUEBAS

}

void Maceta::dibPlantaMini(){ //Planta en menu
  int triy=0, trix=0, rectx=0, recty=0;

  tft.fillRect(x+18,y+30,30,20,ST77XX_WHITE);
  switch(estado){
    case 0:
    break;

    case 1:
      trix=x+18;
      triy=y+50;
      for(int i=0;i<4;i++){
        tft.fillTriangle(trix,triy-1,trix+3,triy-5,trix+7,triy-1,ST77XX_GREEN);
        trix+=6;
      }
    break;

    case 2:
      rectx=x+29;
      recty=y+38;
      tft.fillRect(rectx, recty, 5, 12, ST77XX_GREEN);
      trix=x+18;
      triy=y+50;
      for(int i=0;i<4;i++){
        tft.fillTriangle(trix,triy-1,trix+3,triy-5,trix+7,triy-1,ST77XX_GREEN);
        trix+=6;
      }
      trix=rectx;
      triy=recty;
      tft.fillTriangle(trix,triy,trix+2,triy-5,trix+4,triy,ST77XX_GREEN);
    break;

    case 3:
      rectx=x+29;
      recty=y+38;
      tft.fillRect(rectx, recty, 5, 12, ST77XX_GREEN);
      trix=x+18;
      triy=y+50;
      for(int i=0;i<4;i++){
        tft.fillTriangle(trix,triy-1,trix+3,triy-5,trix+7,triy-1,ST77XX_GREEN);
        trix+=6;
      }
      trix=rectx;
      triy=recty;
      tft.fillTriangle(trix,triy,trix+2,triy-5,trix+4,triy,ST77XX_GREEN);
      tft.fillTriangle(trix,triy-6,trix+2,triy-1,trix+4,triy-6,ST77XX_GREEN);
      tft.fillRect(rectx+4,recty-8,6,3,ST77XX_GREEN);
      tft.fillTriangle(trix+9,triy-6,trix+11,triy+2,trix+13,triy-6,ST77XX_GREEN);
    break;

    case 4:
      rectx=x+29;
      recty=y+38;
      tft.fillRect(rectx, recty, 5, 12, ST77XX_GREEN);
      trix=x+18;
      triy=y+50;
      for(int i=0;i<4;i++){
        tft.fillTriangle(trix,triy-1,trix+3,triy-5,trix+7,triy-1,ST77XX_GREEN);
        trix+=6;
      }
      trix=rectx;
      triy=recty;
      tft.fillTriangle(trix,triy,trix+2,triy-5,trix+4,triy,ST77XX_GREEN);
      tft.fillTriangle(trix,triy-6,trix+2,triy-1,trix+4,triy-6,ST77XX_GREEN);
      tft.fillRect(rectx+4,recty-8,6,3,ST77XX_GREEN);
      tft.fillTriangle(trix+9,triy-6,trix+11,triy+2,trix+13,triy-6,ST77XX_GREEN);
      tft.fillCircle(trix+11, triy+2, 2, ST77XX_RED);
    break;
  }
}

void Maceta::dibujarMax(){
  tft.fillRect(18,30,30,44,ST77XX_WHITE);
  tft.fillRect(82,30,30,44,ST77XX_WHITE);
  tft.fillRect(18,110,30,44,ST77XX_WHITE);
  tft.fillRect(82,110,30,44,ST77XX_WHITE);
  tft.fillRect(37,70, 54, 54, ST77XX_RED);
  tft.fillRect(34 ,70, 60, 18, ST77XX_ORANGE);
}

void Maceta::dibPlantaMax(){
  int trix=0, triy=0;
  tft.fillRect(34,35,60,35,ST77XX_WHITE);
  switch(estado){
    case 0:
      
    break;

    case 1:
      trix=34;
      triy=70;
      for(int i=0;i<9;i++){
        tft.fillTriangle(trix,triy-1,trix+5,triy-8,trix+10,triy-1,ST77XX_GREEN);
        trix+=6;
      }
    break;

    case 2:
      trix=34;
      triy=70;
      for(int i=0;i<9;i++){
        tft.fillTriangle(trix,triy-1,trix+5,triy-8,trix+10,triy-1,ST77XX_GREEN);
        trix+=6;
      }
      tft.fillRect(60,50,8,18,ST77XX_GREEN);
      tft.fillTriangle(60,50,64,45,67,50,ST77XX_GREEN);
    break;

    case 3:
      trix=34;
      triy=70;
      for(int i=0;i<9;i++){
        tft.fillTriangle(trix,triy-1,trix+5,triy-8,trix+10,triy-1,ST77XX_GREEN);
        trix+=6;
      }
      tft.fillRect(60,50,8,18,ST77XX_GREEN);
      tft.fillTriangle(60,50,64,45,67,50,ST77XX_GREEN);
      tft.fillTriangle(60,40,64,48,67,40,ST77XX_GREEN);
      tft.fillTriangle(60,40,67,35,67,40,ST77XX_GREEN);
      tft.fillRect(67,35,10,5,ST77XX_GREEN);
      tft.fillTriangle(77,40,77,35,84,40,ST77XX_GREEN);
      tft.fillTriangle(77,40,81,48,84,40,ST77XX_GREEN);
    break;

    case 4:
      trix=34;
      triy=70;
      for(int i=0;i<9;i++){
        tft.fillTriangle(trix,triy-1,trix+5,triy-8,trix+10,triy-1,ST77XX_GREEN);
        trix+=6;
      }
      tft.fillRect(60,50,8,18,ST77XX_GREEN);
      tft.fillTriangle(60,50,64,45,67,50,ST77XX_GREEN);
      tft.fillTriangle(60,40,64,48,67,40,ST77XX_GREEN);
      tft.fillTriangle(60,40,67,35,67,40,ST77XX_GREEN);
      tft.fillRect(67,35,10,5,ST77XX_GREEN);
      tft.fillTriangle(77,40,77,35,84,40,ST77XX_GREEN);
      tft.fillTriangle(77,40,81,48,84,40,ST77XX_GREEN);
      dibujarFruta();
    break;
  }
}

void Maceta::dibujarFruta(){
  switch(semilla){
    case 1:
      tft.fillCircle(81, 50, 5, ST77XX_ORANGE);
      tft.fillRect(83,46,5,3,ST77XX_GREEN);
      break;
    case 2:
      tft.fillCircle(81, 50, 5, ST77XX_RED);
      tft.fillRect(83,46,5,3,ST77XX_GREEN);
      
      break;
    case 3:
       tft.fillTriangle(77,48,81,54,84,48,ST77XX_RED); 
       break;
    case 4:
       tft.fillCircle(78,51,2,0x800080);
       tft.fillCircle(84,51,2,0x800080);
       tft.fillCircle(81,55,2,0x800080);
       break;
    case 5:
        tft.fillCircle(81, 52, 4, ST77XX_RED);
      break;   
    case 6:
        tft.fillCircle(81, 52, 4, ST77XX_ORANGE);
      break;
    case 7:
        tft.fillCircle(81, 52, 4, 0x8080);
        break;
    case 8:
        tft.fillCircle(81, 51, 3, 0x0280);
        tft.fillCircle(81, 56, 4, 0x0280);    
      break;  
    case 9:
        tft.fillCircle(78,51,2,ST77XX_RED);
        tft.fillCircle(84,51,2,ST77XX_RED);
        tft.fillCircle(81,55,2,ST77XX_RED);
      break;  
  }
}

void Maceta::sem_init(){

    agua = 50;
    sol = 50;
    ctrl_critico = false;

    switch(semilla){
    case 1: //Naranja
        a_avance = 4;
        s_avance = 2;
        a_aceptable = 30;
        s_aceptable = 10;
        a_retroceso = 1;
        s_retroceso = 1;

    break;

    case 2: //Manzana
        a_avance = 3;
        s_avance = 4;
        a_aceptable = 20;
        s_aceptable = 30;
        a_retroceso = 1;
        s_retroceso = 2;

    break;

    case 3: // Fresa
        a_avance = 3;
        s_avance = 3;
        a_aceptable = 20;
        s_aceptable = 20;
        a_retroceso = 1;
        s_retroceso = 1;

    break;

    case 4: //UVAS
        a_avance = 2;
        s_avance = 2;
        a_aceptable = 5;
        s_aceptable = 5;
        a_retroceso = 1;
        s_retroceso = 1;

    break;

    case 5: //CEREZA
        a_avance = 5;
        s_avance = 10;
        a_aceptable = 20;
        s_aceptable = 40;
        a_retroceso = 1;
        s_retroceso = 2;

    break;

    case 6: //DURAZNO
        a_avance = 4;
        s_avance = 2;
        a_aceptable = 30;
        s_aceptable = 10;
        a_retroceso = 1;
        s_retroceso = 1;

    break;

    case 7: // KIWI
        a_avance = 3;
        s_avance = 2;
        a_aceptable = 20;
        s_aceptable = 30;
        a_retroceso = 2;
        s_retroceso = 2;

    break;

    case 8: //PERA
        a_avance = 1;
        s_avance = 2;
        a_aceptable = 0;
        s_aceptable = 40;
        a_retroceso = 1;
        s_retroceso = 2;

    break;

    case 9: //TOMATE
        a_avance = 3;
        s_avance = 2;
        a_aceptable = 20;
        s_aceptable = 30;
        a_retroceso = 2;
        s_retroceso = 2;

    break;

    default:
        a_avance = 0;
        s_avance = 0;
        a_aceptable = 0;
        s_aceptable = 0;
        a_retroceso = 0;
        s_retroceso = 0;



        break;
    }
    estado = 1;
}
void Maceta::sem_estado_avance(){
    if((agua >= a_aceptable) && (sol >= s_aceptable )){
        if(cont >= 5){
            if(estado<4)
              estado++;
            cont = 0;
        }else{
            cont ++;
        }
        ctrl_critico = false;
    }else{
        ctrl_critico = true;
    }
}

void Maceta::sem_estado_retroceso(){
    if(ctrl_critico){
        if(estado>0){
            estado --;
            
        }
    }
}



void Maceta::sem_atributos_avance(int entrada){
    if(!vista){
        if(entrada == 2 && agua < 100)
            agua += a_avance;

        if(entrada == 1 && sol < 100)
            sol += s_avance;
        
    }
}

void Maceta::sem_atributos_retroceso(){
    agua -= a_retroceso;
    sol -= s_retroceso;
}

void Maceta::dibujarBarraA(){
      tft.fillRect(13+a_aceptable,155,2,3,ST77XX_RED);
      tft.fillRect(14, 150, 105, 5, ST77XX_WHITE);
      tft.fillRect(14, 150, agua, 5, ST77XX_BLUE);
} 

void Maceta::dibujarBarraS(){
  tft.fillRect(13+s_aceptable,142,2,3,ST77XX_RED);
  tft.fillRect(14, 145, 105, 5, ST77XX_WHITE);
  tft.fillRect(14, 145, sol, 5, ST77XX_YELLOW);
}
