#include "Pedazos.h"
#include "Asteroide.h"
#include "Coordenada.h"
#include <cmath>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "gfx.h"

using namespace std;

Pedazos::Pedazos(int np,Coordenada c):veces(0),numero_pedazos(np){
  int numero_p = 10+rand()%50;
  double auxp = 0.0;
  double angulop = 360.0/(double)(numero_pedazos);
  for (int i = 0; i < numero_pedazos; i++) {
    int vertices = rand()%10+5;
    int radio = 5+rand()%10;
    restos.push_back(Asteroide(vertices,radio,c));
    auxp =  rand()%((int)angulop*(i+1)-(int)angulop*i + 1 )+(int)angulop*i;
    auxp = ((auxp)*acos(-1))/180.0;
    restos[i].establecerAngulo(auxp);
  }
}

void Pedazos::explosion(){
  for (int j = 0; j < numero_pedazos; j++) {
      restos[j].pintar();
    }
    for (int j = 0; j < numero_pedazos; j++) {
      restos[j].translacion();
  }
  veces++;
}

int Pedazos::obtenerVeces(){
  return veces;
}
