#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t1.h"

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
		mask>>=1;	       // se revisa el patron en el siguiente bit
		pat>>=1;
		num--;
	}
	return x-suma;		   // se retorna el int sin los bits del patron
}

char *reemplazo(char *s, char c, char *pal){
	int contador=0; 	   // cuantas veces aparece c
	int lens=0;			   // largo de s
	while(*s != '\0'){
		if(*s==c){
			contador++;    // se suma 1 cada vez que se ve c
		}
		lens++;			   // se suma 1 al largo y se avanza por s
		s++;
	}
	s-=lens;					// se devuelve el puntero al principio del string
	
	int lenpal  = 0;			// contador del largo de la palabra
	while(*pal != '\0'){
		lenpal++;				// se suma 1 al largo y se avanza por pal
		pal++;
	}
	pal-=lenpal;				// se devuelve el puntero al principio del string
	char * nueva = malloc(lens+contador*(lenpal-1)+1); // se pide memoria
	char * pnueva = & *nueva;						   // puntero por si se borran letras
	while(*s != '\0'){
		if (*s == c){								   // si se ve c se reemplaza por pal
			int i = 0;
			while(i<lenpal){
				*pnueva=*pal;
				pnueva++;
				pal++;
				i++;
			}
			pal-=lenpal;
		}else{
			*pnueva=*s;								// se copia la misma letra si no es 'c'
			pnueva++;
		}
		s++;										// se avanza por s
	}
	*(++pnueva)='\0';								// se agrega la terminacion del string
	return nueva; 
}

void reemplazar(char *s, char c, char *pal){
	char * news = & *s;
	int contador=0; 			// cuantas veces aparece c
	int lens=0;					// largo de s
	while(*s != '\0'){
		if(*s==c){
			contador++; 		// se suma 1 cada vez que se ve c
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
	if(lenpal==1){				// se copia la palabra s cambiando las c por pal
		while(*s != '\0'){
			if(*s == c){
				*s = * pal;
			}
			s++;
		}
		s-=lens;
	}else{
		if(lenpal==0){ 			// se copia la palabra s borrando las c 
			while(*s != '\0'){
				if(*s==c){
					s++;
				}
				*(news++)= *(s++);
			}
			*(news)='\0';			
		}else{
			if(lenpal>1){							// de atras hacia adelante copiando pal en cada c
				s+=lens-1;							// se mueve el puntero hacia el final de s
				news+=lens+contador*(lenpal-1);		// se mueve el puntero hacia el final del nuevo string
				*(news--)='\0';						// se agrega la terminacion
				for (int i = 0; i < lens; ++i){		// se copian las letras
					if(*s!=c){						// si es != de c se copia la misma
						*(news--)=*(s--);				
					}else{							// si es c se va copiando pal de atras hacia adelante
						pal+=lenpal-1;
						for(int j=0;j<lenpal;j++){
							*(news--)=*(pal--);
						}
						pal++;
						s--;
					}
				}
			}
		}
	}
}