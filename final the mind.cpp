#include <iostream>
#include <vector>
using namespace std;

class Mapa{
private:
    static const int FILAS = 11;
    static const int COLUMNAS = 20;
public:
    char mapa[FILAS][COLUMNAS];
    vector<pair<int, int>> pst_cts_p1={(1,1),(1,3),(1,5),(1,7),(1,9)};
    vector<pair<int, int>> pst_cts_p2={(18,1),(18,3),(18,5),(18,7),(18,9)};
    vector<string> vidas = {"vidas"};
    vector<pair<string, int>> pst_vidas = {(3,4),(4,4),(5,4),(6,4),(7,4)};
    vector<string> poder = {"Shuriken"};
    vector<pair<string, int>> pst_shuriken = {(3,4),(4,4),(5,4),(6,4),(7,4), (8,4),(9,4),(10,4)};
    vector<string> puntos = {"Nivel"};
    vector<pair<string, int>> pst_nivel = {(3,7),(4,7),(5,7),(6,7),(7,7)};
    vector<string> mazo = {"mazo"};
    vector<pair<string, int>> pst_mazo = {(9,8),(10,8),(11,8),(12,8),(7,8)};
   
    Mapa(){
            for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                mapa[i][j] = ' ';
            }
        }
        int contador=0
        for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_vidas){
                    if (i == t.first && j == t.second){
                        mapa[i][j] = vidas[contador];
                        contador++;
                    };
                };
            }; 
       };
       for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_cts_p1){
                    if (i == t.first && j == t.second){
                        mapa[i][j] = P1;
                    };
                };
            }; 
       };
       for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_cts_p2){
                    if (i == t.first && j == t.second){
                        mapa[i][j] = P2;
                    };
                };
            };
       };
         for (int i = 0; i < FILAS; i++){
            for (int j = 0; j < COLUMNAS; j++){
                for (auto t : pst_shuriken){
                    if (i == t.first && j == t.second){
                        mapa[i][j] = poder[contador];
                        contador++;
                    };
                };
            };
         };
            for (int i = 0; i < FILAS; i++){
                for (int j = 0; j < COLUMNAS; j++){
                    for (auto t : pst_mazo){
                        if (i == t.first && j == t.second){
                            mapa[i][j] = mazo[contador];
                            contador++;
                        };
                    };
                };
            };
    };
    };
};

// me falta organizar la sintazis de las clases, pero aqui esta la idea de lo que se mostrara 
// en la terminal, cada zona del mapa se va a ir llenando con los datos correspondientes, como 
// el numero de vidas, el nivel, las cartas del mazo, etc.