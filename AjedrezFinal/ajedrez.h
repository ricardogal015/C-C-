#ifndef _ajedrez_H_
#define _ajedrez_H_

void dibujar(char tablero[8][8]);
void inicializar(char tablero[8][8]);
int tomarCoordenadas(int coordenadas[2][2],int jug, char tablero[8][8]);//Para ver si sigue pidiendo las coordenadas
void hacerMovimiento(int coordenadas[2][2],char tablero[8][8]);//Simple lo Hace
int comprobar(char tablero[8][8]);//Comprueba si estan los dos Reyes!
int verificaMov(int coordenadas[2][2],char tablero[8][8]);
//----------
int hayPieza(char tablero[8][8],int i,int j);
int checarRecorridoV(int i,int j,int k,int l,char tablero[8][8]);
int checarRecorridoH(int i,int j,int k,int l,char tablero[8][8]);
//++++++++++++
int movCaballo(int coordenadas[2][2],char tablero[8][8]);
int movKing(int coordenadas[2][2],char tablero[8][8]);
int movPeon1(int coordenas[2][2],char tablero[8][8]);
int movPeon0(int coordenas[2][2],char tablero[8][8]);
int movQueen(int coordenadas[2][2],char tablero[8][8]);
int movAlfil(int coordenadas[2][2],char tablero[8][8]);
int movTorre(int coordenadas[2][2],char tablero[8][8]);
//+++++++++++++

int movCaballo(int coordenadas[2][2],char tablero[8][8])
{
if(tablero[coordenadas[0][0]][coordenadas[0][1]]=='C'||tablero[coordenadas[0][0]][coordenadas[0][1]]=='c'){
    
    if((coordenadas[0][0]-coordenadas[1][0])==1&&(coordenadas[0][1]-coordenadas[1][1]==-2)){
        return 1;
    }else{
        if((coordenadas[0][0]-coordenadas[1][0])==1&&(coordenadas[0][1]-coordenadas[1][1]==2)){
            return 1;
        }else{
            if((coordenadas[0][0]-coordenadas[1][0])==-1&&(coordenadas[0][1]-coordenadas[1][1]==2)){
                return 1;
            }else{
                if((coordenadas[0][0]-coordenadas[1][0])==-1&&(coordenadas[0][1]-coordenadas[1][1]==2)){
                    return 1;
                }else{
                    if((coordenadas[0][0]-coordenadas[1][0])==2&&(coordenadas[0][1]-coordenadas[1][1]==1)){
                        return 1;
                    }else{
                        if((coordenadas[0][0]-coordenadas[1][0])==2&&(coordenadas[0][1]-coordenadas[1][1]==-1)){
                            return 1;
                        }else{
                           if((coordenadas[0][0]-coordenadas[1][0])==-2&&(coordenadas[0][1]-coordenadas[1][1]==-1)){
                                return 1;
                           }else{
                                if((coordenadas[0][0]-coordenadas[1][0])==-2&&(coordenadas[0][1]-coordenadas[1][1]==1)){
                                    return 1;
                                }
                           }
                        }
                    }
                }
            }
        }
    }
    return 0;	
}
}
void dibujar(char tablero[8][8]){
    printf( "\n\t    0  1  2  3  4  5  6  7  \n");
	printf( "\n\t0  %c |%c |%c |%c |%c |%c |%c |%c ", tablero[0][0],tablero[0][1],tablero[0][2],tablero[0][3],tablero[0][4],tablero[0][5],tablero[0][6],tablero[0][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t1  %c |%c |%c |%c |%c |%c |%c |%c ", tablero[1][0],tablero[1][1],tablero[1][2],tablero[1][3],tablero[1][4],tablero[1][5],tablero[1][6],tablero[1][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t2  %c |%c |%c |%c |%c |%c |%c |%c", tablero[2][0],tablero[2][1],tablero[2][2],tablero[2][3],tablero[2][4],tablero[2][5],tablero[2][6],tablero[2][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t3  %c |%c |%c |%c |%c |%c |%c |%c", tablero[3][0],tablero[3][1],tablero[3][2],tablero[3][3],tablero[3][4],tablero[3][5],tablero[3][6],tablero[3][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t4  %c |%c |%c |%c |%c |%c |%c |%c", tablero[4][0],tablero[4][1],tablero[4][2],tablero[4][3],tablero[4][4],tablero[4][5],tablero[4][6],tablero[4][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t5  %c |%c |%c |%c |%c |%c |%c |%c", tablero[5][0],tablero[5][1],tablero[5][2],tablero[5][3],tablero[5][4],tablero[5][5],tablero[5][6],tablero[5][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t6  %c |%c |%c |%c |%c |%c |%c |%c", tablero[6][0],tablero[6][1],tablero[6][2],tablero[6][3],tablero[6][4],tablero[6][5],tablero[6][6],tablero[6][7]);
	printf( "\n\t   --+--+--+--+--+--+--+--");
	printf( "\n\t7  %c |%c |%c |%c |%c |%c |%c |%c", tablero[7][0],tablero[7][1],tablero[7][2],tablero[7][3],tablero[7][4],tablero[7][5],tablero[7][6],tablero[7][7]);
    printf("\n");
}

void inicializar(char tablero[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            tablero[i][j]=32;
        }
    }
    for(int i=0;i<8;i++){
        tablero[1][i]='P';
    }
    for(int i=0;i<8;i++){
        tablero[6][i]='p';
    }
    tablero[0][0]='T';
    tablero[0][7]='T';
    tablero[0][1]='C';
    tablero[0][6]='C';
    tablero[0][2]='A';
    tablero[0][5]='A';
    tablero[0][3]='Q';
    tablero[0][4]='K';
    tablero[7][0]='t';
    tablero[7][7]='t';
    tablero[7][1]='c';
    tablero[7][6]='c';
    tablero[7][2]='a';
    tablero[7][5]='a';
    tablero[7][3]='k';
    tablero[7][4]='q';
   
}


int tomarCoordenadas(int coordenadas[2][2],int jug, char tablero[8][8]){
    int verifica=1;
        if(jug==0){
            if(tablero[coordenadas[0][0]][coordenadas[0][1]]=='\n'){
                return verifica=0;
            }else{
                if(isupper(tablero[coordenadas[1][0]][coordenadas[1][1]])==1){
                    return verifica=0;
                }else{
                    if(isupper(tablero[coordenadas[0][0]][coordenadas[0][1]])==0){
                        return verifica=0;
                    }else{
                        if(coordenadas[0][0]<0||coordenadas[0][0]>7||coordenadas[0][1]<0||coordenadas[0][1]>7||coordenadas[1][1]<0||coordenadas[1][1]>7||coordenadas[1][0]<0||coordenadas[1][0]>7){
                            return verifica=0;
                        }else{
                            if(coordenadas[0][0]==coordenadas[1][0]&&coordenadas[0][1]==coordenadas[1][1]){
                                return verifica=0;
                            }
                        }
                    }
                }
            }
        }
        else{
            if(jug==1){
            if(tablero[coordenadas[0][0]][coordenadas[0][1]]=='\n'){
                return verifica=0;
            }else{
            	//Aqui modifque a 1
                if(islower(tablero[coordenadas[1][0]][coordenadas[1][1]])==1){
                    return verifica=0;
                }else{
                    if(islower(tablero[coordenadas[0][0]][coordenadas[0][1]])==0){
                        return verifica=0;
                    }else{
                        if(coordenadas[0][0]<0||coordenadas[0][0]>7||coordenadas[0][1]<0||coordenadas[0][1]>7||coordenadas[1][1]<0||coordenadas[1][1]>7||coordenadas[1][0]<0||coordenadas[1][0]>7){
                            return verifica=0;
                        }else{
                            if(coordenadas[0][0]==coordenadas[1][0]&&coordenadas[0][1]==coordenadas[1][1]){
                                return verifica=0;
                            }
                        }
                    }
                }
            }
            }
        }
    return verifica;
}

void hacerMovimiento(int coordenadas[2][2],char tablero[8][8]){
    tablero[coordenadas[1][0]][coordenadas[1][1]]=tablero[coordenadas[0][0]][coordenadas[0][1]];
    tablero[coordenadas[0][0]][coordenadas[0][1]]=32;
}

int comprobar(char tablero[8][8]){
    int ganar=1;
    int checar=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(tablero[i][j]=='k')
                checar=checar+5;
            else{
                if(tablero[i][j]=='K')
                checar=checar+5;
            }
        }
    }
    if(checar!=10){
        ganar=0;
    }
    return ganar;

}

int movKing(int coordenadas[2][2],char tablero[8][8])
{
	if(tablero[coordenadas[0][0]][coordenadas[0][1]]=='k'||tablero[coordenadas[0][0]][coordenadas[0][1]]=='K'){
	    if((coordenadas[0][0]-coordenadas[1][0])==1&&(coordenadas[0][1]-coordenadas[1][1]==0)){
	        return 1;
	    }else{
	        if((coordenadas[0][0]-coordenadas[1][0])==-1&&(coordenadas[0][1]-coordenadas[1][1]==0)){
	            return 1;
	        }else{
	            if((coordenadas[0][0]-coordenadas[1][0])==0&&(coordenadas[0][1]-coordenadas[1][1]==-1)){
	                return 1;
	            }else{
	                if((coordenadas[0][0]-coordenadas[1][0])==0&&(coordenadas[0][1]-coordenadas[1][1]==1)){
	                    return 1;
	                }else{
	                    if((coordenadas[0][0]-coordenadas[1][0])==1&&(coordenadas[0][1]-coordenadas[1][1]==-1)){
	                        return 1;
	                    }else{
	                        if((coordenadas[0][0]-coordenadas[1][0])==1&&(coordenadas[0][1]-coordenadas[1][1]==1)){
	                            return 1;
	                        }else{
	                           if((coordenadas[0][0]-coordenadas[1][0])==-1&&(coordenadas[0][1]-coordenadas[1][1]==-1)){
	                                return 1;
	                           }else{
	                                if((coordenadas[0][0]-coordenadas[1][0])==-1&&(coordenadas[0][1]-coordenadas[1][1]==1)){
	                                    return 1;
	                                }
	                           }
	                        }
	                    }
	                }
	            }
	        }
	    }
	    return 0;
	}
}

int movPeon1(int coordenadas[2][2],char tablero[8][8])
{
	if(tablero[coordenadas[0][0]][coordenadas[0][1]]=='p'){
	    if((coordenadas[1][0]-coordenadas[0][0])==-1&&(coordenadas[1][1]-coordenadas[0][1])==0)
	        return 1;
	    else{
	        if((coordenadas[1][0]-coordenadas[0][0])==-1&&(coordenadas[1][1]-coordenadas[0][1])==1&&tablero[coordenadas[1][0]][coordenadas[1][1]]!=32){
	            return 1;
	        }else{
	            if((coordenadas[1][0]-coordenadas[0][0])==-1&&(coordenadas[1][1]-coordenadas[0][1])==-1&&tablero[coordenadas[1][0]][coordenadas[1][1]]!=32){
	                return 1;
	            }
	        }
	    }
	    return 0;
	}
}

int movPeon0(int coordenadas[2][2],char tablero[8][8])
{
	if(tablero[coordenadas[0][0]][coordenadas[0][1]]=='P'){
	    if((coordenadas[1][0]-coordenadas[0][0])==1&&(coordenadas[1][1]-coordenadas[0][1])==0)
	        return 1;
	    else{
	        if((coordenadas[1][0]-coordenadas[0][0])==1&&(coordenadas[1][1]-coordenadas[0][1])==1&&tablero[coordenadas[1][0]][coordenadas[1][1]]!=32){
	            return 1;
	        }else{
	            if((coordenadas[1][0]-coordenadas[0][0])==1&&(coordenadas[1][1]-coordenadas[0][1])==-1&&tablero[coordenadas[1][0]][coordenadas[1][1]]!=32){
	                return 1;
	            }
	        }
	    }
	    return 0;
	}
}


int verificaMov(int coordenadas[2][2],char tablero[8][8]){
  char tmp='\0';
  int i=coordenadas[0][0]; 
  int j=coordenadas[0][1]; 
  tmp=tablero[i][j];
  int decision=0;
  switch(tmp)
  {
  		case 'k':
  		case 'K':
  				decision=movKing(coordenadas,tablero);
  				break;
  		case 'q':
  		case 'Q':
  				decision=movQueen(coordenadas,tablero);
  				break;
  		case 't':
  		case 'T':
  				decision=movTorre(coordenadas,tablero);
  				break;
  		case 'a':
  		case 'A':
  				decision=movAlfil(coordenadas,tablero);
  				break;
  		case 'c':
  		case 'C':
  				decision=movCaballo(coordenadas,tablero);
  				break;
  		//minuscula Peon1
  		case 'p':
  				decision=movPeon1(coordenadas,tablero);
  				break;
  		//mayuscula Peon0
  		case 'P':
  				decision=movPeon0(coordenadas,tablero);
  				break;
  }
  return decision;
}

int movQueen(int coordenadas[2][2],char tablero[8][8])
{
	int i=coordenadas[0][0];
    int j=coordenadas[0][1];
    int k=coordenadas[1][0];
    int l=coordenadas[1][1];
	int tmp=0;
	int dif1=k-i,dif2=l-j;
	
	if(dif1==-dif2&&dif1<0)
	{
		for(int a=i-1,b=j+1;a>k&&b<l;a--,b++)
		{
			tmp=hayPieza(tablero,a,b);
			if(tmp==1)
				return 0;
		}
		return 1;
	}
	else if(dif1==dif2&&dif1<0)
	{
		for(int a=i-1,b=j-1;a>k&&b>l;a--,b--)
		{
			tmp=hayPieza(tablero,a,b);
			if(tmp==1)
				return 0;
		}
		return 1;	
	}
	else if(-dif1==dif2&&dif1>0)
	{
		for(int a=i+1,b=j-1;a<k&&b>l;a++,b--)
			{
				tmp=hayPieza(tablero,a,b);
				if(tmp==1)
					return 0;
			}
			return 1;
		
	}
	else if(dif1==dif2&&dif1>0)
	{
		for(int a=i+1,b=j+1;a<k&&b<l;a++,b++)
		{
			tmp=hayPieza(tablero,a,b);
			if(tmp==1)
				return 0;
		}
		return 1;
	}	
	//Empieza El de la TOrre!
	    if(i!=k && j==l)//mov vertical
    {
        int tmp=checarRecorridoV(i,j,k,l,tablero);
        if(tmp==1)
            return 1;
        else
            return 0;
    }
    else if(j!=l && i==k)//mov horizontal
    {
        int tmp=checarRecorridoH(i,j,k,l,tablero);
        if(tmp==1)
            return 1;
        else
            return 0;
    }
    else
        return 0;

	
}
//1=Se mueve 0=no se mueve

int movAlfil(int coordenadas[2][2],char tablero[8][8])
{
    int i=coordenadas[0][0];
    int j=coordenadas[0][1];
    int k=coordenadas[1][0];
    int l=coordenadas[1][1];
	int tmp=0;
	int dif1=k-i,dif2=l-j;
	
	if(dif1==-dif2&&dif1<0)
	{
		for(int a=i-1,b=j+1;a>k&&b<l;a--,b++)
		{
			tmp=hayPieza(tablero,a,b);
			if(tmp==1)
				return 0;
		}
		return 1;
	}
	else if(dif1==dif2&&dif1<0)
	{
		for(int a=i-1,b=j-1;a>k&&b>l;a--,b--)
		{
			tmp=hayPieza(tablero,a,b);
			if(tmp==1)
				return 0;
		}
		return 1;	
	}
	else if(-dif1==dif2&&dif1>0)
	{
		for(int a=i+1,b=j-1;a<k&&b>l;a++,b--)
			{
				tmp=hayPieza(tablero,a,b);
				if(tmp==1)
					return 0;
			}
			return 1;
		
	}
	else if(dif1==dif2&&dif1>0)
	{
		for(int a=i+1,b=j+1;a<k&&b<l;a++,b++)
		{
			tmp=hayPieza(tablero,a,b);
			if(tmp==1)
				return 0;
		}
		return 1;
	}	
}
int movTorre(int coordenadas[2][2],char tablero[8][8])
{
    int i=coordenadas[0][0];
    int j=coordenadas[0][1];
    int k=coordenadas[1][0];
    int l=coordenadas[1][1];

    if(i!=k && j==l)//mov vertical
    {
        int tmp=checarRecorridoV(i,j,k,l,tablero);
        if(tmp==1)
            return 1;
        else
            return 0;
    }
    else if(j!=l && i==k)//mov horizontal
    {
        int tmp=checarRecorridoH(i,j,k,l,tablero);
        if(tmp==1)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

//0=Obstaculo 1=Libre
int checarRecorridoV(int i,int j,int k,int l,char tablero[8][8])
{
	int distancia=k-i,tmp=0;
	if(distancia<0)//ParaArriba
	{
		for(int a=i-1;a>k;a--)
		{
			tmp=hayPieza(tablero,a,j);
			if(tmp==1)
				return 0;	
		}
		return 1;
	}
	else if(distancia>0)//Para abajo
	{
		for(int a=i+1;a<k;a++)
		{
			tmp=hayPieza(tablero,a,j);
			if(tmp==1)
				return 0;	
		}
		return 1;
	}
}

//0=Obstaculo 1=Libre
int checarRecorridoH(int i,int j,int k,int l,char tablero[8][8])
{
	int distancia=l-j,tmp=0;
	if(distancia<0)//Izquierda
	{
		for(int a=j-1;a>l;a--)
		{
			tmp=hayPieza(tablero,i,a);
			if(tmp==1)
				return 0;	
		}
		return 1;
	}
	else if(distancia>0)//Derecha
	{
		for(int a=j+1;a<l;a++)
		{
			tmp=hayPieza(tablero,i,a);
			if(tmp==1)
				return 0;	
		}
		return 1;
	}
}
//1=Hay Pza. 0=No hay Pieza
int hayPieza(char tablero[8][8],int i,int j)
{
	if(tablero[i][j]==32)
		return 0;
	else
		return 1;
}
#endif