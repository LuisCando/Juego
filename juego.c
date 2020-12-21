#include <assert.h>  
#include <ctype.h>  
#include <stdio.h>   
#include <stdlib.h> 
#include <unistd.h>


#define ERROR_MINA_ENCONTRADA 1  
#define ERROR_ESPACIO_YA_DESCUBIERTO 2
#define ERROR_NINGUNO 3
#define COLUMNAS 5
#define FILAS 5
#define ESPACIO_SIN_DESCUBRIR '.'
#define ESPACIO_DESCUBIERTO ' '
#define MINA '*'
#define CANTIDAD_MINAS \
#define DEBUG 0  
int obtenerMinasCercanas(int fila, int columna, char
tablero[FILAS][COLUMNAS]){
int conteo = 0, finalinicio,filaFin,colunmalinicio,columnaFin;
if (fila<=0){
filalinicio=0;
}else{
filslinicio=fila-1;
}

if(fila + 1>=FILAS){
filaFin = FILAS - 1;
}else{
filaFin = fila + 1;
}

if(columna<=0){
columnalinicio=0;
}else{
columnalinicio = columna - 1;
}
if (columna +1 >=COLUMNAS){
columnaFin = COLUMNAS - 1;
}else{
columnaFin=columna+1;
}
int m;
for (m=filainicio;m<=filaFin;m++){
int l;
for (l= columnainicio;l<=columnaFin;l++){
if (tablero[m][l]MINA){
conteo++;
}
}
}
return conteo;
}
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
