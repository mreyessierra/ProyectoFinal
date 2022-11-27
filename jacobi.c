#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//arreglo para la matriz de coeficientes
float A[10][10];
//arreglos para solucion de inicio y solucion 
//calculada en cada iteracion
float x0[10],x[10];

//funcion para imprimir la matriz ingresada por el usuario
void imprime(int n) {
	printf("\nLa matriz es: ");
	int i,j;
    printf("\n");
    for (i=0;i<n;i++){
		printf("\n");
       	for (j=0;j<n+1;j++){
        	printf(" %2.2f",A[i][j]);
        }
    }
    printf("\n");
}

//funcion principal
int main()
{
    int var=0,N=0;
    printf("\nIntroduzca el numero de variables: ");
    scanf("%d",&var);

    //se solicitan los coeficientes del sistema
    for(int i=0;i<var;i++)
        for(int j=0;j<var+1;j++){
            printf("Introduzca a%d%d:",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    
    //se imprime la matriz de coeficientes
    imprime(var);

    //el metodo de Jacobi requiere numero de iteraciones
    printf("\nIntroduzca el numero de iteraciones: ");
    scanf("%d",&N);

    int i,j,k,l;

    //inicializa vector de inicio y final en ceros
    for(i=0;i<var;i++){
        x0[i]=0.0;
        x[i]=0.0;
    }
    
    //impresion de vector de inicio
    printf("x0: ");
    for (i=0;i<var;i++)
        printf("%1.4f  ",x[i]);    
    printf("\n");

    //inicia ciclo de iteraciones
    for(k=1;k<=N;k++){
        //para cada variable
        for(i=0;i<var;i++){
            x[i]=0.0;
            //se calcula el valor de esta iteracion 
            //mostrada en el algoritmo (en el documento)
            for(j=0; j<var;j++){
                if(j!=i){
                    x[i] = x[i]+ A[i][j] * x0[j];
                }
            }
            x[i] = x[i]*(-1.0);
            x[i] = x[i] + A[i][var];
            x[i] = x[i] / A[i][i];
        }
        //se imprime la solucion de esta iteracion
        printf("x%d: ",k);
        for (i=0;i<var;i++)
            printf("%1.4f  ",x[i]);    
        printf("\n");

        //se reemplaza la solucion previa para proceder
        //a la siguiente iteracion
        for (i=0;i<var;i++)
            x0[i]=x[i];
    }
  return 0;
}
