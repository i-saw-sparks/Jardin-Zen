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
  
  
  switch(estado){
    case 0:
    break;

    case 1:
      trix=x+18;
      triy=y+50;
      for(int i=0;i<4;i++){
        tft.fillTriangle(trix,triy,trix+3,triy-5,trix+7,triy,ST77XX_GREEN);
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
        tft.fillTriangle(trix,triy,trix+3,triy-5,trix+7,triy,ST77XX_GREEN);
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
        tft.fillTriangle(trix,triy,trix+3,triy-5,trix+7,triy,ST77XX_GREEN);
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
        tft.fillTriangle(trix,triy,trix+3,triy-5,trix+7,triy,ST77XX_GREEN);
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
  //Maceta
  //dibPLantaMax();
}

void Maceta::dibPlantaMax(){
  switch(estado){
    case 0:
    break;

    case 1:
    //germinado
    break;

    case 2:
    //joven
    break;

    case 3:
    //maduro
    break;

    case 4:
    //fruta
    //dibFruta();
    break;
  }
}
