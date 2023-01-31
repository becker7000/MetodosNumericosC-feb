#include<stdio.h>

// Prototipos:
void llenar(float* salarios,int tam);
void imprimir(float* salarios,int tam);
void ordenarPorBurbuja(float* salarios,int tam);
void intercambiar(float* a, float* b);
void mediaAritmetica(float* salarios,int tam);
void mediana(float* salarios,int tam);

int main(){

    int tam;
    printf("\n\t Cuantos salarios? ");
    scanf("%d",&tam);

    float lista_salarios[tam]; // El tamaño una vez declarado va ser fijo
    llenar(lista_salarios,tam);

    printf("\n\n\t Sin ordenar: ");
    imprimir(lista_salarios,tam);

    ordenarPorBurbuja(lista_salarios,tam);
    
    printf("\n\n\t Ordenada: ");
    imprimir(lista_salarios,tam);
    mediaAritmetica(lista_salarios,tam);
    mediana(lista_salarios,tam);

    printf("\n\n");
    return 0;
}

// Definición:
void llenar(float* salarios,int tam){
    int i;
    printf("\n\t Llena el arreglo: ");
    for(i=0;i<tam;i++){
        printf("\n\t Salario #%d: $",i+1);
        scanf("%f",(salarios+i));
    }
}

void imprimir(float* salarios,int tam){
    int i;
    printf("\n\t Lista de salarios: ");
    for(i=0;i<tam;i++){
        printf(" $%.2f ",*(salarios+i));
    } // * pide el valor contenido dentro de cada dirección
}

// Función de ordenamiento por el método de la burbuja:
void ordenarPorBurbuja(float* salarios,int tam){
    int i,j; // i <- Comparaciones, j <- comparación
    for(i=(tam-1);i>0;i--){ // Cuantas comparaciones?
        for(j=0;j<i;j++){
            if(*(salarios+j)>*(salarios+j+1)){
                intercambiar((salarios+j),(salarios+j+1));
            }
        }
    }
}

void intercambiar(float* a, float* b){
    float aux=*a;
    *a=*b;
    *b=aux;
}

void mediaAritmetica(float* salarios,int tam){
    float promedio=0; // Va a guardar una suma
    int i; // Variable de control
    for(i=0;i<tam;i++){
        promedio+=(*(salarios+i)); // promedio=promedio+*(salarios+i)
    }
    promedio/=tam;
    printf("\n\n\t La mediana aritmetica es: $%.3f",promedio);
}

// 2,5,6,8,9 ->  mediana 6
// 1,2,4,7,8,10 -> mediana (4+7)/2 = 5.5

void mediana(float* salarios,int tam){
    float mediana = 0;
    if(tam%2==1){ // tamaño impar: salarios,salarios+1,salarios+2,salarios+3,salarios+4
        mediana=*(salarios+(tam-1)/2);
    }else{ // tamaño par: salarios,salarios+1,salarios+2,salarios+3,salarios+4,salarios+5
        mediana=(*(salarios+(tam-1)/2)+*(salarios+(tam-1)/2+1))/2;
    }
    printf("\n\n\t La mediana es: $%.3f",mediana);
}


/*
    int lista[]={7,3,8,2,5} posiciones:5 comparaciones:4

    7, 3, 8, 2, 5

    Pasada #0: Com:4
    3, 7, 8, 2, 5
    3, 7, 8, 2, 5
    3, 7, 2, 8, 5
    3, 7, 2, 5, 8

    Pasada #1: Com:3
    3, 7, 2, 5, 8 
    3, 2, 7, 5, 8
    3, 2, 5, 7, 8

    Pasada #2: Comp:2
    2, 3, 5, 7, 8
    2, 3, 5, 7, 8

*/