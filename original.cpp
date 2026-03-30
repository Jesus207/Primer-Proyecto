#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Carta{

public:

    int valor;

    Carta(){
        valor = 0;
    }

    Carta(int v){
        valor = v;
    }

};


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


class Jugador{

public:

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