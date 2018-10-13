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
	uint mask=(1<<len)-1;
	mask<<=(32-len);
	pat<<=(32-len);
	uint suma=0;
	int num = 8*sizeof(int);
	while(num>0+len-1){
		//bin(mask);
		//bin(pat);
		if((mask&x)==pat){
			suma+=pat;
		}
		mask>>=1;
		pat>>=1;
		num--;
	}
	printf("resultado %u\n",x-suma );
	return x-suma;
}


/*int main(int argc, char const *argv[])
{

	uint x = 137;
	uint y = 473;
	uint z = 2;
	uint k = 5;
	uint t = 1;
	int prueba= 2 == z;
	borrar_bits(x,t,1);
	//borrar_bits(y,z,2);
	//borrar_bitss(y,k,3);
	
	return 0;
}*/