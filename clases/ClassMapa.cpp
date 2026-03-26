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
    vector<tuple<int,int>> puesto_c1= {{1,1},{1,3},{1,5},{1,7},{1,9}};

    string JP2 = "P2";
    vector<tuple<int,int>> jugador2 = {{10,5}, {10,7}};
    vector<tuple<int,int>> puesto_c2= {{18,1},{18,3},{18,5},{18,7},{18,9}};

    string vidas = "vidas";
    vector<tuple<int,int>> pst_vidas = {{3,4}, {4,4}, {5,4}, {6,4}, {7,4}};

    string poder = "Shuriken";
    vector<tuple<int, int>> pst_shuriken = {{3,4},{4,4},{5,4},{6,4},{7,4}, {8,4},{9,4},{10,4}};
 
    string nivel = "Nivel";
    vector<tuple<int, int>> pst_nivel = {{3,7},{4,7},{5,7},{6,7},{7,7}  };
 
    string mazo = "Mazo";
    vector<tuple<int, int>> pst_mazo = {{9,8},{10,8},{11,8},{12,8},{7,8}};

    void dibujarTexto(string texto, vector<tuple<int,int>> posiciones){
        for (int k = 0; k < texto.size() && k < posiciones.size(); k++){
            int i = get<0>(posiciones[k]);
            int j = get<1>(posiciones[k]);
            mapa[i][j] = texto[k];
        }
    }
    void mostrarmapa(){
        char copia[FILAS][COLUMNAS];
        for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                copia[i][j] = mapa[i][j];
            }
        }
        for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                cout << copia[i][j] << " ";
            }
            cout << endl;
        }
    }
    Mapa(){
        // dibujar
        mostrarmapa();
        dibujarTexto(JP1, jugador1);
        dibujarTexto(JP2, jugador2);
        dibujarTexto(vidas, pst_vidas);
        dibujarTexto(mazo, pst_mazo);
        dibujarTexto(poder, pst_shuriken);
        dibujarTexto(nivel, pst_nivel);
    }
};
