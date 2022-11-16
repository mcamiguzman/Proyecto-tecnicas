#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Caminar.h"
#include "Guardar.h"


Enemigo EnemigosNormales[11] = {{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13},{"Flecha",13}};
Enemigo EnemigosEspeciales[11] = {{"Flecha",13},{},{},{},{},{},{},{},{},{}};
Enemigo EnemigosJefes[11] = {{"Flecha",13},{},{},{},{},{},{},{},{},{}};
Carta CartaTienda[15]= {{},{},{} /* ...*/};
Carta CartasPersonaje1[6]= {{"NN","HH",1,2},{"NN","HH",1,2},{"NN","HH",1,1},{"NN","HH",1,2},{"NN","HH",1,2}};
Carta CartasPersonaje2[6]= {};
Carta CartasPersonaje3[6]= {};


void tienda(){
  int seguir;
  while(seguir==1){
    for(int i = 1; i<7;i++){
      printf("%d-- Nombre: %s - Tipo: %s - Gastos de vidas: %d\n",i,CartaTienda[i].nombreCarta,CartaTienda[i].tipo,CartaTienda[i].gastopoder);
    }
  int comprar;
  scanf("%d",&comprar);
  printf("Digite el numero de la carta que desee comprar");
  recibirGuardar(CartaTienda[comprar].gastopoder);
  printf("Digite 1 para seguir comprando");
  scanf("%d",&seguir);
  }
  if(seguir!=1){/* */}
}

void batalla(int vidasJugador, int dureza, int vidasEnemigo, char*NombreEnemigo){
  int manas;
  int elegir;
  
  srand(time(NULL)); 
  int AtaqueEnemigo = rand() % 10 /* Promedio de todas las vidas*/;

  
  while(vidasEnemigo>0||vidasJugador>0){
    manas = 5;
    printf("Nombre Enemigo: %s\n",NombreEnemigo);
    printf("Tus vidas: %d\n",vidasJugador);
    printf("Vidas enemigo: %d\n" ,vidasEnemigo);
    printf("Gastos de poder: %d\n",manas);
    printf("\n");
    printf("Tu turno\n");
    while(manas>0){
      //Elegir que arreglo usar
      if(dureza==1){
        for(int i = 1; i<5;i++){
          printf("%d--  %s | %s | %d| %d \n",i,CartasPersonaje1[i].nombreCarta,CartasPersonaje1[i].tipo,CartasPersonaje1[i].gastopoder,CartasPersonaje1[i].efecto);
        }
        printf("Digite el numero de la carta que desea usar\n");
        scanf("%d",&elegir);
        if(CartasPersonaje1[elegir].gastopoder  >manas){
          printf("Ups no tienes suficientes gatos de poder");}
        else{
          manas = manas - CartasPersonaje1[elegir].gastopoder;
          vidasEnemigo = vidasEnemigo - CartasPersonaje1[elegir].efecto;
          printf("Nombre Enemigo: %s\n",NombreEnemigo);
          printf("Tus vidas: %d\n",vidasJugador);
          printf("Vidas enemigo: %d\n" ,vidasEnemigo);
          printf("Gastos de poder: %d\n",manas);
         }
      }
        
      if(dureza==2){
        for(int i = 1; i<5;i++){
          printf("%d--  %s | %s | %d| %d \n",i,CartasPersonaje2[i].nombreCarta,CartasPersonaje2[i].tipo,CartasPersonaje2[i].gastopoder,CartasPersonaje2[i].efecto);
        }
        printf("Digite el numero de la carta que desea usar\n");
        scanf("%d",&elegir);
        if(CartasPersonaje2[elegir].gastopoder  >manas){
          printf("Ups no tienes suficientes gatos de poder");}
        else{
            manas = manas - CartasPersonaje2[elegir].gastopoder;
            vidasEnemigo = vidasEnemigo - CartasPersonaje2[elegir].efecto;}
        printf("Nombre Enemigo: %s\n",NombreEnemigo);
        printf("Tus vidas: %d\n",vidasJugador);
        printf("Vidas enemigo: %d\n" ,vidasEnemigo);
        printf("Gastos de poder: %d\n",manas);
      }
      
      if(dureza==3){
        for(int i = 1; i<5;i++){
          printf("%d--  %s | %s | %d| %d \n",i,CartasPersonaje3[i].nombreCarta,CartasPersonaje3[i].tipo,CartasPersonaje3[i].gastopoder,CartasPersonaje3[i].efecto);
        } 
        printf("Digite el numero de la carta que desea usar\n");
        scanf("%d",&elegir);
        if(CartasPersonaje2[elegir].gastopoder  >manas){
          printf("Ups no tienes suficientes gatos de poder");}
        else{
          manas = manas - CartasPersonaje2[elegir].gastopoder;
          vidasEnemigo = vidasEnemigo - CartasPersonaje2[elegir].efecto;}
        printf("Nombre Enemigo: %s\n",NombreEnemigo);
        printf("Tus vidas: %d\n",vidasJugador);
        printf("Vidas enemigo: %d\n" ,vidasEnemigo);
        printf("Gastos de poder: %d\n",manas);
      }
    }
  printf("Turno enemigo\n");
  printf("El enemigo eligio quitarte %d\n",AtaqueEnemigo);
  vidasJugador = vidasJugador - AtaqueEnemigo;
    
  printf("Nombre Enemigo: %s\n",NombreEnemigo);
  printf("Tus vidas: %d\n",vidasJugador);
  printf("Vidas enemigo: %d\n" ,vidasEnemigo);
  printf("Gastos de poder: %d\n",manas);
  }
  
  if(vidasEnemigo<0){
    printf("Ganaste");
      for(int i = 1; i<6;i++){
        printf("%d-- Nombre: %s - Tipo: %s - Gastos de vidas: %d\n",i,CartaTienda[i].nombreCarta,CartaTienda[i].tipo,CartaTienda[i].gastopoder);
      }
    int comprar;
    printf("Digite el numero de la carta que desee ");
    scanf("%d",&comprar);
    recibirGuardar(CartaTienda[comprar].gastopoder);
    recibirGuardarEnemigo(NombreEnemigo);
    //llama a menu principal
    
    
  }else{
    printf("Termino");
    }
}  


void caminos (int vidasJugador, int dureza){
  int continuar;
  printf("Para continuar digite 1 ");
  scanf("%d",&continuar);
  while(continuar ==1){
    printf("--------camino 1--------Batalla con Normal\n");
    printf("--------camino 2--------Batalla con Jefe\n");
    printf("--------camino 3--------Batalla con Enemigos Especial \n");
    printf("--------camino 4--------Descanso \n");
    printf("--------camino 5--------Tienda\n");
  
    srand(time(NULL)); 
    int RandEnemigo = rand() % 9;
    
    int ECamino;
    printf("Digite el numero de camino que desee ");
    scanf("%d",&ECamino);
    
    if(ECamino==1){
      if(vidasJugador==0){printf("Intenta otro camino como Descanso\n");}
      else{batalla(vidasJugador,dureza,EnemigosNormales[RandEnemigo].vidasEnemigo,EnemigosNormales[RandEnemigo].nombre);}
    }
    if(ECamino==2){
      if(vidasJugador==0){printf("Intenta otro camino como Descanso\n");}
      else{batalla(vidasJugador,dureza,EnemigosJefes[RandEnemigo].vidasEnemigo,EnemigosJefes[RandEnemigo].nombre);}
    }
    if(ECamino==3){
        if(vidasJugador==0){printf("Intenta otro camino como Descanso\n");}
        else{batalla(vidasJugador,dureza,EnemigosEspeciales[RandEnemigo].vidasEnemigo,EnemigosEspeciales[RandEnemigo].nombre);}
    }
    if(ECamino==4){
        vidasJugador+=10; //Cambiar
    }
    if(ECamino){
        tienda();
    }
    if(continuar!=1){printf("Vuelves a menu principal");}
  }
}

void caminar(int durezaPersonaje){
  int vidasJugador=0;
  caminos (vidasJugador, durezaPersonaje );

}

/*
int main(void) {
  caminar(1);
  return 0;
}
*/