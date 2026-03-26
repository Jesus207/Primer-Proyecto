#ifndef ClassMazo_H
#define ClassMazo_H
#include <cstdlib>
#include <ctime>
#include "ClassCarta.cpp" 

class Mazo{

public:

    Carta cartas[100];
    int indice;

    Mazo(){

        for(int i = 0; i < 100; i++){
            cartas[i] = Carta(i+1);
        }

        indice = 0;
    }

    void barajar(){

        srand(time(0));

        for(int i = 0; i < 100; i++){

            int r = rand() % 100;

            Carta temp = cartas[i];
            cartas[i] = cartas[r];
            cartas[r] = temp;
        }

    }

    Carta sacarCarta(){

        Carta c = cartas[indice];

        indice++;

        return c;
    }

};
#endif