#ifndef CLASJUGADOR_H
#define CLASJUGADOR_H
#include "ClassCarta.cpp"
#include "ClassMapa.cpp"
#include "ClassJuego.cpp"
using namespace std;
class Jugador{
public:
    int jugador1F = 1, jugador1C = 1;
    int jugador2F = 18, jugador2C = 1;
    string nombre;
    Carta mano[100];
    int cantidadCartas;

    Jugador(){
        cantidadCartas = 0;
    }

    Jugador(string n){
        nombre = n;
        cantidadCartas = 0;
    }

    void recibirCarta(Carta c){

        mano[cantidadCartas] = c;
        cantidadCartas++;

    }

    void mostrarMano(){

        cout << nombre << " tiene: ";

        for(int i = 0; i < cantidadCartas; i++){
            cout << mano[i].valor << " ";
        }

        cout << endl;

    }

    int jugarCarta(){

        int cartaElegida;

        cout << nombre << " escribe la carta que vas a jugar: ";
        cin >> cartaElegida;

        for(int i = 0; i < cantidadCartas; i++){

            if(mano[i].valor == cartaElegida){

                for(int j = i; j < cantidadCartas-1; j++){
                    mano[j] = mano[j+1];
                }

                cantidadCartas--;

                return cartaElegida;
            }

        }

        cout << "No tienes esa carta. Se juega la primera." << endl;

        int valor = mano[0].valor;

        for(int j = 0; j < cantidadCartas-1; j++){
            mano[j] = mano[j+1];
        }

        cantidadCartas--;

        return valor;

    }

};
#endif