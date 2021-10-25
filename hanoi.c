#include <time.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
void torres_hanoi(int n, int pivote_inicial, int pivote_final,int  pivote_aux){
	 if(n==1){
                printf("%i -> %i\n",pivote_inicial,pivote_final);
        }
	else{
		torres_hanoi(n-1,pivote_inicial,pivote_aux,pivote_final);
		printf("%i -> %i\n",pivote_inicial,pivote_final);
		torres_hanoi(n-1,pivote_aux,pivote_final,pivote_inicial);
	}
}

int main(int argc, char **argv){
char *cant;
int c;
while (( c = getopt (argc, argv, "n:")) != -1)
    switch (c)
      {
      case 'n':
        cant = optarg;
        break;
      case '?':
        if (optopt == 'n')
          fprintf (stderr, "Opcion -%d requiere un numero entero.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "argumento desconocido `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "caracteres desconocidos `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
	cant=atoi(cant);
	//printf("%d",cant);	
	clock_t tiempo_inicio,tiempo_final;
	double segundos;
	tiempo_inicio=clock();
	torres_hanoi(cant,1,2,3);
	tiempo_final=clock();
	segundos= (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;
	printf("\n %f\n",segundos);
}
