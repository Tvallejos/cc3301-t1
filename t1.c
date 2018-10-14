#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t1.h"

void bin(int num)
{
    int sup = 8*sizeof(int);
    while(sup >= 0)
    {
        if(num & (((long int)1) << sup))
            printf("1");
        else
            printf("0");
        sup--;
    }
    printf("\n");
}

uint borrar_bits(uint x, uint pat, int len){
	int num = 8*sizeof(int);
	uint mask=(1<<len)-1; // se crea una mascara para obtener solo los len bits de mas a la izq de x
	mask<<=(num-len);
	pat<<=(num-len);       // se empuja el patron hacia la izq
	uint suma=0;		  
	while(num>0+len-1){    // mientras el patron sigue "dentro" del entero lo empujo uno a la derecha
		if((mask&x)==pat){
			suma+=pat;	   // si el patron es encontrado se suma al acumulado
		}
		mask>>=1;
		pat>>=1;
		num--;
	}
	return x-suma;		   // se retorna el int sin los bits del patron
}

char *reemplazo(char *s, char c, char *pal){
	int contador=0; // cuantas veces aparece c
	int lens=0;		// largo de s
	while(*s != '\0'){
		if(*s==c){
					contador++; // se suma 1 cada vez que se ve c
		}
		lens++;
		s++;
	}
	s-=lens;					// se devuelve el puntero al principio del string
	
	int lenpal  = 0;			// contador del largo de la palabra
	while(*pal != '\0'){
		lenpal++;
		pal++;
	}
	pal-=lenpal;				// se devuelve el puntero al principio del string

	char * nueva = malloc(lens+contador*lenpal+1); // se pide memoria
	char * pnueva = & *nueva;						// puntero por si se borran letras
	while(*s != '\0'){
		if (*s == c){
			for (int i = 0; i < lenpal; ++i){		// se copia la palabra si se ve
				* (pnueva+i)= * (pal+i);
			}
			pnueva+=lenpal;
			
		}else{
			*pnueva=*s;								// se copia la misma letra si no 'c'
			pnueva++;
		}
		s++;
	}

	*(++pnueva)='\0';								// se agrega la terminacion del string
	
	return nueva; 
}

/*int main(int argc, char const *argv[])



}*/