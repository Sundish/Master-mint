//Esta es la version v2 de mi codigo, le quite toda las features como intro y dibujitos y deje el programa base em si, o sea solo el juego
//Andres estuvo aqui, lo que igual quite es ingresar nombres de usuarios, osea del codebreaker y codemaster
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#include "canica.h"
#include "pista.h"
#include "filaCodigo.h"
#include "fila.h"
#include "tablero.h"
#include "logic.hpp"

//#include "graphfx.hpp"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void impresionsecreta(char letras[4]){
    letras[4]=' ';
    letras[5]=' ';
    letras[6]=' ';
char cal[0];
cal[0]=' ';
cout<<letras[0]<<letras[1]<<letras[2]<<letras[3]<<endl;
strcat(cal,letras);
printf("%s",cal);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {//El juego
    char kas,kbs,kcs,kds;
    char letras[4];
    int meco[4];
    int numeros[4];

	//definimos una semilla para el aleatroio a estilo de mainecraft
	srand (time(NULL));
	system("color B");

	//print_full_table({"abcd","bcfe","abcd"},10);
	tablero t;
	t.jugar(kas,kbs,kcs,kds,letras, numeros);

  impresionsecreta(letras);

	return 0;
}
