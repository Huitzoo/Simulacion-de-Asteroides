#ifndef PEDAZOS_H_
#define PEDAZOS_H_
#include "Coordenada.h"
#include "Asteroide.h"
#include <vector>
using namespace std;


class Pedazos{

    private:
        vector<Asteroide> restos;
        int veces;
        vector <int> angulos;
        int numero_pedazos;

    public:   
        Pedazos(int,Coordenada);
        int obtenerVeces();
        void explosion();
};

#endif