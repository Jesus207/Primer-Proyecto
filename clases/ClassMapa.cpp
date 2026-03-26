#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
class Mapa{
private:
    static const int COLUMNAS = 11;
    static const int FILAS = 20;
public:
    char mapa[FILAS][COLUMNAS];
    string JP1 = "P1";
    vector<tuple<int,int>> jugador1 = {{0,5}, {0,7}};

    string JP2 = "P2";
    vector<tuple<int,int>> jugador2 = {{10,5}, {10,7}};

    string vidas = "vidas";
    vector<tuple<int,int>> pst_vidas = {{3,4}, {4,4}, {5,4}, {6,4}, {7,4}};

    vector<string> poder = {"Shuriken"};
    vector<tuple<int, int>> pst_shuriken = {{3,4},{4,4},{5,4},{6,4},{7,4}, {8,4},{9,4},{10,4}};
 
    vector<string> puntos = {"Nivel"};
    vector<tuple<int, int>> pst_nivel = {{3,7},{4,7},{5,7},{6,7},{7,7}  };
 
    vector<string> mazo = {"Mazo"};
    vector<tuple<int, int>> pst_mazo = {{9,8},{10,8},{11,8},{12,8},{7,8}};

    void dibujarTexto(string texto, vector<tuple<int,int>> posiciones){
        for (int k = 0; k < texto.size() && k < posiciones.size(); k++){
            int i = get<0>(posiciones[k]);
            int j = get<1>(posiciones[k]);
            mapa[i][j] = texto[k];
        }
    }

    Mapa(){
        // dibujar
        dibujarTexto(JP1, jugador1);
        dibujarTexto(JP2, jugador2);
        dibujarTexto(vidas, pst_vidas);
    }
};
