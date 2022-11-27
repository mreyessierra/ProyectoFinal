#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

//arreglo para la matriz (tamanio maximo 10)
float A[10][10];

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

//operacion elemental de intercambiar matrices
//recibe renglones a intercambiar y numero de variables
void intercambiar(int r1,int r2,int v){
	int j=0;
	float C=0.0;		
	for (j=0;j<v+1;j++){
		C = A[r1][j];
		A[r1][j]= A[r2][j];
		A[r2][j]= C;
	}
}

//operacion elemental de sumar un multiplo de una fila a otra
//recibe renglones, multiplo y numero de variables
void op(int r1,float n,int r2,int v){
    int j;   
	for (j=0;j<v+1;j++){
        A[r1][j] = A[r1][j] + (A[r2][j]*n);
    }
}   

//funcion principal
void main(){
    int v=0;
    printf("Introduzca el numero de variables:");
    scanf("%d",&v);

    //solicita al usuario coeficientes del sistema
    for(int i=0;i<v;i++)
        for(int j=0;j<v+1;j++){
            printf("Introduzca a%d%d:",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    
    //imprime la matriz ingresada
    imprime(v);
    
    int p,j,i;
    float m,x[v],E,R;

    //inicia eliminacion gaussiana
    //para cada columna
    for (i=0;i<v-1;i++){
        //se busca el pivote
        for (j=i;j<v;j++){
            if (A[j][i]!=0){
                p=j;
    		    break;
 	        }
        }
        //si no es el elemento en la diagonal,
        //se intercambia para que lo sea
	    if (p!=i){ 
  		    intercambiar(p,i,v);
        }
        //se hacen cero los elementos inferiores
        //la operacion se aplica a todo el renglon
        for (j=i+1;j<v;j++){
    	    m = -A[j][i]/A[i][i];
    	    op(j,m,i,v);
        } 
    }
    //termina eliminacion gaussiana

    //si el ultimo renglon es de ceros, no hay solucion
    if (A[v-1][v-1]==0){
	    printf("\n No tiene solucion\n");
        return;
    }

    //se calcula la ultima variable
    x[v-1]= A[v-1][v]/A[v-1][v-1];
    
    //se calcula el resto de las variables, en orden 
    //hacia atras, sustituyendo las variables ya calculadas
    for (i=v-2;i>=0;i--){
    	R=0;
		for(j=1;(i+j)<=v-1;j++){
			E = A[i][i+j]*x[i+j];
			R = R - E;
        }
        x[i] = ( A[i][v] + R ) /A[i][i];
	}

    //se imprime la solucion
    printf("\nSolucion: ");
    for(i=0;i<v;i++)
        printf("x%d: %f ",i+1,x[i]);
    printf("\n");

}





