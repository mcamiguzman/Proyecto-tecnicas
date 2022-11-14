#include <stdio.h>
#include <stdlib.h>
#include "Guardar.h"
#include "Caminar.h"

Enemigo TotalEnemigos[30] = {};
Carta TodasCartas[15]={};
Enemigo EnemigosAGuardar[50]={};
Carta CartasAGuardar[50]={};


void recibirGuardar(int datoespecifico){
  Carta Elegida;
  for(int i;i<30;i++){
    if(TodasCartas[i].gastopoder==datoespecifico){
      Elegida = TodasCartas[i];
      for(int i;i<50;i++){
        CartasAGuardar[i]=Elegida;
      }
    }
  }
}

void recibirGuardarEnemigo(char*Nombre){
  Enemigo Elegido;
  for(int i;i<30;i++){
    if(TotalEnemigos[i].nombre==Nombre){
      Elegido = TotalEnemigos[i];
      for(int i;i<50;i++){
        EnemigosAGuardar[i]=Elegido;
      }
    }
  }
}

void Guardar(){
  
}