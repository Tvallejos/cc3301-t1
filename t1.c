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


/*int main(int argc, char const *argv[])



}*/