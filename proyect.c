#include "proyect.h"
#include "Caminar.h"
#include "Guardar.h"
// FALTAN CARTAS

void menu( Pers *p, Enem *e )
{
  int opc;
  do
  {
    printf( "Bienvenido"
            "\nSeleccione una opcion:\n"
            "1. Juego Nuevo\t2. Salir\n ");
    scanf( "%d", &opc );
    switch( opc )
      {
        case 1:
              system( "cls" );
              jugar( p, e );
        break;
        case 2:
              system( "cls" );
              printf("Vuelve pronto\n");
        break;
        default:
              printf( "opcion invalida\n");
        break;
      }
  }while( opc != 3 );
}


void imprimePers( Pers *p )
{
	int i = 0;
    int n = 3;
	
	if( p != NULL)
    {
        system("cls");
        printf( "\tPERSONAJES\n\n" );
        for( i=0; i<n; i++ )
        {
            printf( "Personaje %d\n", i+1 );
            printf( "Nombre: %s\n", p[i].nombre );
            printf( "Fuerza: %d\n", p[i].fuerza );
            printf( "Dureza: %d\n", p[i].dureza );
            printf( "Inteligencia: %d\n\n", p[i].inteligencia );
    	}
	}	
}
// LABORATORIO
void imprimeEnem( Enem *e )
{
	//LABORATORIO
    FILE *file;      	  		
	file = fopen( "enemigos.txt", "r" );
	//leer todo el buffer
				
	int banderaE = 1;
	do
	{
		char bufferE[SIZE];
		int indexEnem = 0;
		while( fgets( bufferE, SIZE, file ) != NULL )
		{
			char *tokenEnem = strtok( bufferE, ",");
			int indexEnem2 = 0;
			while( tokenEnem != NULL )
			{
				if( indexEnem2 == 0 )
				{
					e[indexEnem].nombre = malloc( sizeof( char ) );
					strcpy( e[indexEnem].nombre , tokenEnem );
				}
				else if( indexEnem2 == 1 )
				{
					e[indexEnem].vida = atoi( tokenEnem );
				}
				else if( indexEnem2 == 2 )
				{
					e[indexEnem].descr = malloc( sizeof( char ) );
					strcpy( e[indexEnem].descr , tokenEnem );
				}
     			printf( " %s\n", tokenEnem );
      			tokenEnem = strtok( NULL, "," );
      			indexEnem2++;
   			}indexEnem++;
				
		}banderaE = 0;
		if( e != NULL)
    	{
    		int i = 0;
    		int n = 3;
        	printf( "\tENEMIGOS\n\n" );
        	for( i=0; i<n; i++ )
       		{
            	printf( "Enemigo %d\n", i+1 );
            	printf( "Nombre: %s\n", e[i].nombre );
            	printf( "Vida: %d\n", e[i].vida );
            	printf( "Descripcion: %s\n", e[i].descr );
    		}
		}					
	}while( banderaE == 1);      	  	
              	//system( "cls" );	
}
                   // LABORATORIO
void jugar( Pers *p, Enem *e )
{
  
  int opcPer;
  	
  imprimePers( p );
  do
  {
  	printf( "Por favor seleccione el numero de personaje que desea [1-3]:\t" );
    scanf( "%d", &opcPer );
    if( opcPer >= 1 && opcPer <= 3 )
    {
  	  printf( "Acabas de seleccionar %s", p[opcPer-1].nombre );
	}
  }while( opcPer <= 0 && opcPer > 3 );
  
  
  
  
  
  int opc1;
  do
    {  
      printf( "\n\tMenu\n" );
      printf( "Por favor seleccione una opcion:\n");
      printf( "1. Caminar\n2. Deck\n3. Bestiario\n 4. Guardar\n 5. Salir al menu principal\n " );
      printf( "Ingrese la opcion:\t");
      scanf( "%d", &opc1 );
      switch( opc1 )
      
        {
          case 1: 
              system( "cls" );
	      Caminar(/* llama a dureza del personaje que selecciono el jugador*/);
          break;

          case 2:
              system( "cls" );
              printf( "Este es tu deck\n" );
              
          break;

          case 3:
          	  imprimeEnem( e ); //No creo que sea asi
          break;

          case 4:
              system( "cls" );
              printf( "Guardar\n" );//No creo
	      Guardar();
          break;

          case 5:
              system( "cls" );
              printf( "Salir al menu inicial\n" );  
          break;
    
          default:
              printf( "Acabas de ingresar una opcion invalida\n" );
          break;
          
        }
    }while( opc1 != 5);
  printf( "\n\nEstas siendo redireccionado al menu principal\n\n" ); //Como vuelves a llamar al menu?
}
