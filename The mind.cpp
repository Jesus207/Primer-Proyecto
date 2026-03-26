#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "clases/ClassJuego.cpp"
#include "clases/ClassMapa.cpp"
#ifdef _win32
#include "conio.h"
#else
#include <ncurses.h>
#endif

using namespace std; 
int main() {
    cout << "\nPresiona una tecla para empezar...";
    cin.get();
    cin.ignore();
    initscr();      // iniciar pantalla
    noecho();       // no mostrar teclas
    cbreak();
    // Crear mapa
    // Crear juego
    Juego juego;
    Mapa m;
    Jugador juga;
    while(juego.Nvidas > 0 && juego.nivel <= 5){
        m.mostrarmapa();
    /*
        char tecla;
        while(true){
            for (int i = 0; i < m.puesto_c1.size(); i++){
                tecla = getch();
                if(tecla == 'w' && m.mapa[juga.jugador1F-1][juga.jugador1C] == m.puesto_c1[i]) m.mapa[juga.jugador1F-1][juga.jugador1C] = 'C';
                if(tecla == 's'&& m.mapa[juga.jugador1F][juga.jugador1C] == m.puesto_c1[i]) m.mapa[juga.jugador1F+1][juga.jugador1C] = 'C';
                if(tecla == 'q') break;
            }
    */
        juego.iniciarNivel();
        juego.jugarNivel();
    #ifdef _win32
    system("cls");
    #else
    system("clear");
    #endif
    }
    if(juego.Nvidas <= 0){
        cout << "Perdieron el juego" << endl;
    }
    else {
        cout << "Ganaron el juego" << endl;
       }
    endwin();
    return 0;
}