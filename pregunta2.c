#include <stdio.h>
#include <math.h>
#define INVALIDO 0
#define NO_FORMAN 1
#define EQUILATERO 2
#define ISOSCELES 3
#define ESCALENO 4
    
int main(){
    int lado_a,lado_b,lado_c;
    int tipo;
    scanf("%d %d %d",&lado_a,&lado_b,&lado_c);
    
    
    if(lado_a>0 && lado_b>0 && lado_c>0){
        if(lado_a+lado_b>lado_c && lado_a+lado_c>lado_b && lado_b+lado_c>lado_a){
            if(lado_a==lado_b && lado_b==lado_c) {
                tipo=EQUILATERO;}
            else if (lado_a==lado_b||lado_a==lado_c||lado_b==lado_c) {
                tipo=ISOSCELES;
            } else {
                tipo=ESCALENO;}
        } else {
            tipo=NO_FORMAN;}
    } else {
        tipo=INVALIDO;
    }
    
    printf("Lados \t\t:%d %d %d\n",lado_a,lado_b,lado_c);
    printf("Tipo \t\t:");
    switch (tipo) {
        case 0: printf("Invalido\n"); break;
        case 1: printf("No existe el triangulo\n"); break;
        case 2: printf("Equilatero\n"); break;
        case 3: printf("Isosceles\n"); break;
        case 4: printf("Escaleno\n"); break;
    }
    
    //Extension
    
    if (tipo!=0 && tipo!=1) {
        printf("Rectangulo \t:");
        long long hip;
        long long cat1,cat2;
        
        int temp=0;
        if (lado_a>lado_b) {
            temp=lado_a;
            lado_a=lado_b;
            lado_a=temp;
        } else if (lado_b>lado_c) {
            temp=lado_b;
            lado_b=lado_c;
            lado_c=temp;
        }
        
        hip=lado_c;
        cat1=lado_a, cat2=lado_b;
        
        if (hip*hip==cat1*cat1 + cat2*cat2) {
            printf("Si\n");
        } else {printf("No\n");}
        
        float s;
        s=(lado_a+lado_b+lado_c)/2.0;
        float area;
        area=sqrt(s*(s-lado_a)*(s-lado_b)*(s-lado_c));
        printf("Area \t\t:%f",area);
    }
    
    return 0;
}