#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
#include "Coordenada.h"
#include <vector>
using namespace std;


class Asteroide{
  
    friend int comparar(Asteroide&, Asteroide&);
  
    private:
        int numero_vertices;
        double angulo;
        int radio;
        bool habilitado;
        vector<Coordenada> vertices;
        Coordenada centro;

    public: 
        Asteroide(int,int,Coordenada);
        void pintar();
        void deshabilitar();
        void translacion();
        void rotacion();
        int obtenerHabilitado();
        int obtenerRadio();
        int obtenerNumeroVertices();
        void establecerAngulo(double);
        double obtenerAngulo();
        //Coordenada obtenerVertices();
        Coordenada obtenerCentro();
};

#endif