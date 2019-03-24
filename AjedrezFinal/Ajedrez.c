#include <stdio.h>
#include <cstdlib>
#include <ctype.h>
#include "ajedrez.h"

int main(){
    char tablero[8][8];//juego
    int coordenadas[2][2];//
    int ganar=0,jug=0,contador=0,verifica=0;//ganar:si falta unRey  contador:Numero de vuelta (Par e Impar)
    inicializar(tablero);
    //Para compra
    do{
    //system("cls");
    dibujar(tablero);
	    //Para movimiento Valido
	    do{
	        //Para tomar buenas coordenadas
	        do{
	            printf("\nJugador %d",(contador%2)+1);
	            printf("\nDame las coordenadas de tu pieza: ");
	            scanf("%d,%d",&coordenadas[0][0],&coordenadas[0][1]);
	            printf("\nDame las coordenadas hacia donde moverla: ");
	            scanf("%d,%d",&coordenadas[1][0],&coordenadas[1][1]);
	            jug=contador%2;
	            verifica=tomarCoordenadas(coordenadas,jug,tablero);
	        }while(verifica==0);
	        
	        verifica=verificaMov(coordenadas,tablero);
	        
	        if(verifica==1)
	            hacerMovimiento(coordenadas,tablero);
	        else
	            printf("\nMovimiento Invalido");
	    }while(verifica==0);
	//turno del otro wuey  
    contador=contador+1;
    //Reviza si hay dos 'K'
    ganar=comprobar(tablero);
    }while(ganar==1);
    dibujar(tablero);
    printf("\nGana jugador %d",jug+1);
    //system("pause");
    return 0;
}