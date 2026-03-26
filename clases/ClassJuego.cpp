#include <iostream>
#include "ClassJugador.cpp"
#include "ClassMazo.cpp"
using namespace std;
class Juego{

public:

    Jugador jugadores[4];
    int numJugadores;

    Mazo mazo;

    int vidas;
    int nivel;

    int ultimaCarta;

    Juego(){

        vidas = 3;
        nivel = 1;
        ultimaCarta = 0;

    }

    void iniciarNivel(){

        cout << endl;
        cout << "Nivel " << nivel << endl;

        mazo = Mazo();
        mazo.barajar();

        for(int i = 0; i < numJugadores; i++){

            jugadores[i].cantidadCartas = 0;

            for(int j = 0; j < nivel; j++){

                Carta c = mazo.sacarCarta();

                jugadores[i].recibirCarta(c);

            }

            jugadores[i].mostrarMano();

        }

        ultimaCarta = 0;

    }

    void jugarNivel(){

        int totalCartas = nivel * numJugadores;
        int cartasJugadas = 0;

        while(cartasJugadas < totalCartas && vidas > 0){

            for(int i = 0; i < numJugadores; i++){

                int carta = jugadores[i].jugarCarta();

                cout << jugadores[i].nombre << " jugo " << carta << endl;

                if(carta < ultimaCarta){

                    cout << "Error! carta menor que la anterior" << endl;

                    vidas--;

                    cout << "Vidas: " << vidas << endl;

                }

                ultimaCarta = carta;

                cartasJugadas++;

                if(cartasJugadas >= totalCartas || vidas <= 0){
                    break;
                }

            }

        }

        if(vidas > 0){
            cout << "Nivel superado" << endl;
            nivel++;
        }

    }

};
