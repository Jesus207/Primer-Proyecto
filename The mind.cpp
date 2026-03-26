#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "clases/ClassJuego.cpp"
using namespace std;
    
int main(){

    Juego juego;

    cout << "Numero de jugadores: ";
    cin >> juego.numJugadores;

    for(int i = 0; i < juego.numJugadores; i++){

        string nombre;

        cout << "Nombre del jugador: ";
        cin >> nombre;

        juego.jugadores[i] = Jugador(nombre);

    }

    while(juego.vidas > 0 && juego.nivel <= 5){

        juego.iniciarNivel();

        juego.jugarNivel();

    }

    if(juego.vidas <= 0){
        cout << "Perdieron el juego" << endl;
    }
    else{
        cout << "Ganaron el juego" << endl;
    }

    return 0;
}