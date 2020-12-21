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
  for (l=0;l<FILAS;l++) {
    int m;
    for (m=0;m<COLUMNA;m++) {
      tablero[l][m] = ESPACIO_SIN_DESCUBRIR;
    }
  }
}

void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  tablero[fila][columna] = MINA;
}

void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNA]) {
  int l;
  for (l=0;l<CANTIDAD_MINAS;l++) {
    int fila = aleatorioEnRango(0, FILAS - 1);
    int columna = aleatorioEnRango(0, COLUMNA - 1);
    colocarMina(fila, columna, tablero);
  }
}

void imprimirSeparadorEncabezado() {
  int m;
  for (m=0;m<=COLUMNAS;m++) {
    printf("----");
    if (m+2==COLUMNAS){
      printf("-");
    }
  }
  printf("\n");
}

void imprimirSeparadorFilas() {
  int m;
  for (m=0;m<=COLUMNAS;m++) {
    printf("+---");
    if (m == COLUMNAS){
      printf("+");
    }
  }
  printf("\n");
}

void imprimirEncabezado(){
  imprimirSeparadorEncabezado();
  printf("|   ");
  int l;
  for(l=0;l<COLUMNAS;l++) {
    printf("| %d ", l + 1);
    if (l + 1 == COLUMNAS) {
      printf("|");
    }
  }
  printf("\n");
}

char enteroACaracter(int numero) {
  return numero + '0';
}

void imprimirTablero(char tablero[FILAS][COLUMNAS], int deberiaMostrarMinas) {
  imprimirEncabezado();
  imprimirSeparadorEncabezado();
  char letra = 'A';
  int l;
  for (l=0;l<FILAS;l++) {
    int m;
    
  printf("| %c ", letra);
    letra++;
    for(m= 0;m<COLUMNAS; m++) {
      char verdaderaLetra = ESPACIO_SIN_DESCUBRIR;
      char letraActual = tablero[l][m];
      if (letraActual == MINA) {
        verdaderaLetra = ESPACIO_SIN_DESCUBRIR;
      }else if(letraActual == ESPACIO_DESCUBIERTO){
        int minasCercanas = obtenerMinasCercanas(l, m, tablero);
        verdaderaLetra = enteroACaracter(minasCercanas);
      }
