#include<stdio.h>
#include<math.h>

int main(){

    // Entradas:
    float a,b,c,x1,x2,discriminante=0;

    printf("\n\t Escribe el valor de a: ");
    scanf("%f",&a);
    
    printf("\n\t Escribe el valor de b: ");
    scanf("%f",&b);
    
    printf("\n\t Escribe el valor de c: ");
    scanf("%f",&c);

    discriminante=pow(b,2)-4*a*c;

    if(discriminante>=0){ // Las raices serán reales.
        // Cálculos (linealizando la formula general)
        x1 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
        x2 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
        printf("\n\t x1 = %f , x2 = %f",x1,x2);
    }else{ // discriminante<0, es decir, las raices serán complejas
        printf("\n\t Las raices del trinomio son complejas.");
    }

    printf("\n\n");
    return 0;
}