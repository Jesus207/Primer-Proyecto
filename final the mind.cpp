#include <iostream>
#include <vector>
using namespace std;

class Mapa{
private:
    static const int FILAS = 11;
    static const int COLUMNAS = 20;
public:
    char mapa[FILAS][COLUMNAS];
    vector<pair<int, int>> pst_cts_p1={{1,1},{1,3},{1,5},{1,7},{1,9}};
    vector<pair<int, int>> pst_cts_p2={{18,1},{18,3},{18,5},{18,7},{18,9}};
