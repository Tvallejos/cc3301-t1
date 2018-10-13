#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t1.h"

typedef unsigned int uint;
uint borrar_bits(uint x, uint pat, int len){
	int suma=0;
	for(int i=0;i<sizeof(int)*8;i+= len){
		suma+=(x&pat)
		pat<<=len
	}
	return suma
}

