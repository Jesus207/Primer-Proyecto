#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>

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

class Mapa{
private:
    static const int FILAS = 11;
    static const int COLUMNAS = 20;
public:
    char mapa[FILAS][COLUMNAS];
    vector< tuple<int, int>> pst_cts_p1 = {
    {1,1}, {1,3}, {1,5}, {1,7}, {1,9}
}; 
    vector< tuple<int, int>> pst_cts_p2={{18,1},{18,3},{18,5},{18,7},{18,9}};
    vector<string> vidas = {"vidas"};
    vector< tuple<int, int>> pst_vidas = {{3,4},{4,4},{5,4},{6,4},{7,4}};
    vector<string> poder = {"Shuriken"};
    vector< tuple<int, int>> pst_shuriken = {{3,4},{4,4},{5,4},{6,4},{7,4}, {8,4},{9,4},{10,4}};
    vector<string> puntos = {"Nivel"};
    vector< tuple<string, int>> pst_nivel = {{3,7},{4,7},{5,7},{6,7},{7,7}  };
    vector<string> mazo = {"Mazo"};
    vector< tuple<string, int>> pst_mazo = {{9,8},{10,8},{11,8},{12,8},{7,8}};
   
    Mapa(){
            for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                mapa[i][j] = ' ';
            }
        }
    int contador=0;
    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            for (auto t : pst_vidas){
                if (i == get<0>(t) && j == get<1>(t)){
                    mapa[i][j] = vidas[contador];
                    contador++;
                }
            }
        }
    }
       for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_cts_p1){
                    if (i == get<0>(t) && j == get<1>(t)){
                        mapa[i][j] = 'P1';
                    }
                }
            }
       }
       for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_cts_p2){
                    if (i == get<0>(t) && j == get<1>(t)){
                        mapa[i][j] = 'P2';
                    }
                }
            }
       }
         for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_shuriken){
                    if (i == get<0>(t) && j == get<1>(t)){
                        mapa[i][j] = poder[contador][0];
                        contador++;
                    }
                }
            }
         }
            for (int i = 0; i < FILAS; i++){
                for (int j = 0; j < COLUMNAS; j++){
                    for (auto t : pst_mazo){
                        if (i == get<0>(t) && j == get<1>(t)){
                            mapa[i][j] = mazo[contador][0];
                            contador++;
                        }
                    }
                }
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