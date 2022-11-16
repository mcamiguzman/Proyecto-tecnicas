#include "proyect.h"


int main()
{
	Pers *p = NULL;
    int n = 3;
    p = ( Pers* )malloc( n*sizeof( Pers ));
    
    Enem *e = NULL;
    int nn = 30;
    e = ( Enem* )malloc( nn*sizeof( Enem ));
/*
    p[0].nombre = "Gigante de Acero";
    p[0].fuerza = 25;
    p[0].dureza = 80;
    p[0].inteligencia = 15;
    // Personaje 2
    p[1].nombre = "Mago Redentor";
    p[1].fuerza = 80;
    p[1].dureza = 35;
    p[1].inteligencia = 100;
            
            
	// Personaje 3
    p[2].nombre = "Bruja Escarlata";
    p[2].fuerza = 90;
    p[2].dureza = 20;
    p[2].inteligencia = 70;
*/	
	FILE* file;
	char buffer[SIZE];
	
	//lABORATORIO
	
	
	                          
    file = fopen( "personajes.txt", "r" );
	//leer todo el buffer
	int banderaP = 1;
	do
	{
		int index = 0;
		while( fgets( buffer, SIZE, file ) != NULL )
		{
			char *token = strtok( buffer, ",");
		
			int index2 = 0;
			while( token != NULL )
			{
				if( index2 == 0 )
				{
					p[index].nombre = malloc( sizeof( char ) );
					strcpy( p[index].nombre , token );
				}
				else if( index2 == 1 )
				{
					p[index].fuerza = atoi( token );
				}
				else if( index2 == 2 )
				{
					p[index].dureza = atoi( token );
				}
				else if( index2 == 3 )
				{
					p[index].inteligencia = atoi( token );
				}
     			printf( " %s\n", token );
      			token = strtok( NULL, "," );
      			index2++;
   			}
   			index++;
		}banderaP = 0;
		system( "cls" );
		menu( p, e );
	}while( banderaP == 1 );
	return 0;
}