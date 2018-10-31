#include "Coordenada.h"
#include <iostream>
using namespace std;

Coordenada::Coordenada(int xx, int yy):x (xx), y (yy){

}

int Coordenada::obtenerX (){
  return x;
}


void Coordenada::cambiarX (int xn){
  x = xn;
}


void Coordenada::cambiarY (int yn){
  y = yn;
}



int Coordenada::obtenerY (){
  return y;
}
