#include "Pedazos.h"
#include "gfx.h"
#include <unistd.h>
#include "Asteroide.h"
#include <iostream>
#include <time.h> 
#include <thread> 

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
	gfx_open(1000, 1000, "Asteroides");
	gfx_color(17,200,82);
    gfx_thread();
    int numero_v = atoi(argv[1]);
    int vertices = 0;
    int radio = 0;
    int numero_pedazos = 0;
    vector<Asteroide> a;
    vector<Pedazos> p;
    for(int i = 0 ; i < numero_v ; i ++){
        vertices = rand()%5+6;
        radio = 5+rand()%100;
        a.push_back(Asteroide(vertices,radio,Coordenada(1+rand()%800,1+rand()%800)));
    }
	while(1){
        gfx_clear();

        for(int i = 0 ; i < a.size() ; i ++){
            a[i].pintar();
        }
        for(int i = 0 ; i < a.size() ; i ++){
            a[i].translacion();
            a[i].rotacion();
        }
        for(int i = 0 ; i < a.size() ; i ++){
            for(int j = 0 ;j < a.size() ; j++){
                if(j != i){
                    if(a[i].obtenerHabilitado() == 1){    
                        if(a[j].obtenerHabilitado()==1){        
                            if(comparar(a[i],a[j])==1){
                                a[i].deshabilitar();
                                a[j].deshabilitar();
                                //Esto es para que se crean los asteroides cada vez que se destruye uno.
                                /*for(int k = 0 ; k < 2 ; k ++){
                                    vertices = rand()%10+5;
                                    radio = 10+rand()%70;
                                    a.push_back(Asteroide(vertices,radio,Coordenada(1+rand()%800,1+rand()%800)));
                                }*/
                                Coordenada c = a[i].obtenerCentro();
                                numero_pedazos = 10+rand()%20;
                                p.push_back(Pedazos(numero_pedazos,c));
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0;i < p.size();i++){
            if(p[i].obtenerVeces() !=30){
                p[i].explosion();
            }
        }
        gfx_flush();
        usleep(100000); //24 por segundo  
	}
 return 0;
}