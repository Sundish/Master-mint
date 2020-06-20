//Esta es la version v2 de mi codigo, le quite toda las features como intro y dibujitos y deje el programa base em si, o sea solo el juego
//Andres estuvo aqui, lo que igual quite es ingresar nombres de usuarios, osea del codebreaker y codemaster
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
using namespace std;
#include "canica.h"
#include "pista.h"
#include "filaCodigo.h"
#include "fila.h"
#include "tablero.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
int main() {//El juego
	//definimos una semilla para el aleatroio a estilo de mainecraft
	srand (time(NULL));
	system("color B");
	tablero t;
	t.jugar();

	return 0;
}
