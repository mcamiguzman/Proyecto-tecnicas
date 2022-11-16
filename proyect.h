#ifndef PROYECT_H
#define PROYECT_H
#define SIZE 255
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Personajes_t
{
	char *nombre;
	int fuerza;
	int dureza;
	int inteligencia;
}Pers;

// lABORATORIO
typedef struct Enemigos_t
{
	char *nombre;
	int vida;
	char *descr;
}Enem;


void menu( Pers *p, Enem *e);
void jugar( Pers *p, Enem *e);
void imprimePers( Pers *p );
void imprimeEnem( Enem *e );

#endif