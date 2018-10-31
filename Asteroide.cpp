#include "Asteroide.h"
#include "gfx.h"
#include <iostream>
#include <stdlib.h> 
#include <cmath>
#include <time.h>       
#include <vector>
using namespace std;

Asteroide::Asteroide(int verticesT,int r,Coordenada c):numero_vertices(verticesT),habilitado(1),radio(r),centro(c){
  centro = c;
  angulo = ((double)(1000+rand()%3600)/10)*acos(-1)/180.0;
  double aux = 0.0;
  double angulo_vertice = 360.0/(double)numero_vertices;
  for(int i = 0 ; i < numero_vertices;i++){  
    aux = rand()%((int)angulo_vertice*(i+1)-(int)angulo_vertice*i + 1 )+(int)angulo_vertice*i; //Me regresa un angulo nuevo para dibujar mi vertice
    aux = ((aux)*acos(-1))/180.0; //calculo el valor del anglo en radianes
    int x = ceil(radio*sin(aux));
    int y = ceil(radio*cos(aux));
    x = x + centro.obtenerX();
    y = y + centro.obtenerY();
    vertices.push_back(Coordenada(x,y));
  }
}

void Asteroide::pintar(){
  Coordenada c1;
  Coordenada c;
  if(habilitado == 1){
    for(int i = 0 ; i < numero_vertices ; i++ ){
        c = vertices[i];
        if(i+1 == numero_vertices ){
          c1 = vertices[0];  
        }else{
          c1 = vertices[i+1];
        }
        gfx_line(c.obtenerX(),c.obtenerY(),c1.obtenerX(),c1.obtenerY());
    }
  }
}

void Asteroide::translacion(){
  int moverx = 100*sin(angulo)*3/radio;
  int movery = 100*cos(angulo)*3/radio;
  centro.cambiarX(centro.obtenerX()+moverx);
  centro.cambiarY(centro.obtenerY()+movery);
  for(int i = 0;i < numero_vertices; i++){
    vertices[i].cambiarX(vertices[i].obtenerX()+moverx);
    vertices[i].cambiarY(vertices[i].obtenerY()+movery);
  }
}

void Asteroide::rotacion(){
  double rotar = 5+rand()%10;
  rotar = ((rotar)*acos(-1))/180.0;
  Coordenada vectorTraslacion(-centro.obtenerX(),-centro.obtenerY());
  for(int i = 0 ; i< numero_vertices ; i++){
    int xp = vertices[i].obtenerX() + vectorTraslacion.obtenerX();
    int yp = vertices[i].obtenerY() + vectorTraslacion.obtenerY();
    int xp_aux = xp;
    xp = ceil(xp*cos(rotar)-yp*sin(rotar));
    yp = ceil(xp_aux*sin(rotar)+yp*cos(rotar));
    xp = xp - vectorTraslacion.obtenerX();
    yp = yp - vectorTraslacion.obtenerY();
    vertices[i].cambiarX(xp);
    vertices[i].cambiarY(yp);
  }
}

void Asteroide::deshabilitar(){
  habilitado = 0;
}

int comparar(Asteroide &a, Asteroide &b){
  int radios = a.obtenerRadio()+b.obtenerRadio()-10;
  int distancia = sqrt(pow(a.centro.obtenerX()-b.centro.obtenerX(),2) + pow(a.centro.obtenerY()-b.centro.obtenerY(),2));
  if(distancia < radios){
    return 1;
  }
  return 0;
}

void Asteroide::establecerAngulo(double angulop){
  angulo = angulop;
}

int Asteroide::obtenerHabilitado(){
  return habilitado;
}

double Asteroide::obtenerAngulo(){
  return angulo;
}

int Asteroide::obtenerRadio(){
  return radio;
}

Coordenada Asteroide::obtenerCentro(){
  return centro;
}

