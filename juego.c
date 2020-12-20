#include <assert.h>  
#include <ctype.h>  
#include <stdio.h>   
#include <stdlib.h> 
#include <unistd.h> 
int aleatorioEnRango(int minimo, int maximo){
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void iniciarTablero(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNA; m++) {
      tablero[l][m] = ESPACIO_SIN_DESCUBRIR;
    }
  }
}

void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  tablero[fila][columna] = MINA;
}

void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNA]) {
  int l;
  for (l = 0; l < CANTIDAD_MINAS; l++) {
    int fila = aleatorioEnRango(0, FILAS - 1);
    int columna = aleatorioEnRango(0, COLUMNA - 1);
    colocarMina(fila, columna, tablero);
  }
}
