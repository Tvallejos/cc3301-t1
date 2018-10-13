# Tarea 1 PSS
## 1.- Borrar bits
Programar una funcion
```
typedef unsigned int uint;
uint borrar_bits(uint x, uint pat, int len);
```
que reemplace en un int x todas las apariciones del patrón "pat" de "len" bits por ceros.
### Ejemplo de uso
```
borrar_bits(0b00010001001, 0b1, 1) es 0
borrar_bits(0b111011001, 0b10, 2) es 0b110010001
borrar_bits(0b111011001, 0b101, 3) es 0b110001001
```
## 2.- Reemplazar String
Programar una funcion
```
char *reemplazo(char *s, char c, char *pal);
```
que reemplace en el string "s" todas las ocurrencias del caracter "c" por el string "pal"
utilizando la siguiente 
### Metodología
  * hacer un recorrido por el string s para calcular el largo del string resultante.
  * Luego recorrer los caracteres de s desde el principio de s hacia el final.
  * cuando el caracter visitado sea c copiar "pal" en el string resultante, si no, se debe copiar el caracter visitado.
  * Se debe usar un puntero para recorrer s y otro para recorrer el string resultante.
### Restricciones 
  * no se puede usar el operador de subindicación [ ], ni su equivalente *(p+i).
  * Se debe usar ++ o p+i. No puede usar strlen, strcpy, etc.
  * No puede copiar s en el nuevo string y usar la parte c para resolver esta parte, ya que estaría haciendo una copia
  de más.
### Ejemplo de uso
```
char *res= reemplazo("hola que tal", 'a', "xyz");
// res es "holxyz que txyzl"
```
## 3.- Reemplazar String
Programar una funcion 
```
void reemplazar(char *s, char c, char *pal);
```
que reemplaza en s todas las ocurrencias del caracter c por la palabra pal dejando el resultado en el mismo s.
Suponiendo que la memoria destinada a s es suficiente para almacenar el string resultante.

### Metodologia
  * Hacer un primer recorrido del string s para calcular el largo del string resultante.
  * Si el largo de "pal" es a lo más 1, recorra los caracteres de s desde el principio de s hacia el final.
  De lo contrario recorra s desde el final de s hacia el principio (en orden inverso). 
  Para ambos casos cuando el caracter visitado sea c copie "pal" en la posición que le corresponde en el string resultante, si no copie el caracter visitado.
  * Se debe usar un puntero para recorrer s y otro para recorrer el string resultante.
### Restricciones
  * no se puede usar el operador de subindicación [ ], ni su equivalente *(p+i).
  * Se debe usar ++ -- p+i o p-i.
  * No puede usar malloc o declarar un arreglo para pedir memoria adicional.
### Ejemplo de uso
```
char r[17]="hola que tal";
reemplazar(r, 'a', "opa");
// r es "holopa que topal"
reemplazar(r, 'o', "");
// r es "hlpa que tpal"
```
## Recursos
 al descomprimir t1.zip se obtiene la carpeta T1 que contiene los
archivos 
- `test-t1.c` que prueba si la tarea funciona 
- `t1.h` que incluye los encabezados de las funciones pedidas
- `t1.c.plantilla` muestra los includes que debe contener el archivo t1.c
- `Makefile`.
