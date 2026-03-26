#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "clases/ClassJuego.cpp"
#include "clases/ClassMapa.cpp"

using namespace std;

int main() {
    // Limpiar pantalla
    system("cls");

    cout << "\nPresiona una tecla para empezar...";
    cin.ignore();
    cin.get();
    // Crear mapa
    // Crear juego
    Juego juego;
    Mapa m;
    while (juego.Nvidas>0){
        cout << m.mapa;
        juego.iniciarNivel();
        juego.jugarNivel();
        cout << "\nNumero de jugadores: ";
        cin >> juego.numJugadores;

        if(juego.Nvidas <= 0){
            cout << "Perdieron el juego" << endl;
        } else {
            cout << "Ganaron el juego" << endl;
        }

        return 0;
    }
}