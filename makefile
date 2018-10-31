main: main.cpp Asteroide.o Pedazos.o gfx.o
	g++ main.cpp Asteroide.o gfx.o Pedazos.o Coordenada.o -o main -lX11 -pthread

Asteroide.o: Asteroide.cpp Coordenada.o Asteroide.h
	g++ Asteroide.cpp -c

Pedazos.o: Pedazos.cpp Coordenada.o Pedazos.h
	g++ Pedazos.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c

gfx.o: gfx.c gfx.h
	gcc gfx.c -c
