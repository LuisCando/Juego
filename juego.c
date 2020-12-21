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
