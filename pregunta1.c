#include <stdio.h>

int main () {
    unsigned int registro;
    
    unsigned char n = 0; 

    int opciones = 0;
    
    int contador = 0;
    printf("Escriba un numero\n");
    
    scanf("%u", &registro);
    getchar();

    for(;;){

        do{
            printf("Escriba una posicion (0 a 31)\n");
            n = getchar();
            getchar();
        } while(n < 0   && n > 31 );

        do {
        printf("1.- Encender el bit %c \n", n);
        printf("2.- Apagar el bit %c \n", n);
        printf("3.- Alternar el bit %c \n", n);
        printf("4.- Consultar si el bit %c esta encendido\n", n);
        printf("5.- Imprimir registro en binario, hexadecimal y decimal sin signo %c \n", n);
        printf("6.- Contar bits encendidos %c \n", n);
        printf("7.- Invertir todos los bits del registro %c \n", n);
        printf("0.- Salir\n");
        scanf("%u", &opciones);
            getchar();
        } while(opciones < 0 && opciones > 7);
        
        if (opciones == 0)
        {
            break;
        }
        unsigned int auxiliar = registro;

        switch(opciones) {
            case 1: 
                auxiliar = ( registro | ( 1U << (n - '0') ) ); break;
            case 2:
                auxiliar = ( auxiliar & ~( 1U << (n - '0') ) ); break;
            case 3: 
                if ( ( (auxiliar >> (n - '0')) & 1U )== 1) //bit prendido;
                {
                    auxiliar = ( auxiliar & ~( 1U << (n - '0') ) ); 
                } else{

                    auxiliar = ( auxiliar | ( 1U << (n - '0') ) ); break;
                }
            case 4:
                if ( (auxiliar >> (n - '0') & 1U ) != 0 ) //bit prendido;
                {
                    printf("Bit prendido \n");
                } else{

                    printf("Bit no encendido \n");
                }
            case 5:
            case 6:
                for (int i = 0; i<31; i++) {
                    int bit = auxiliar >> i;

                    if (bit == 1){
                        contador++;
                    }
                }
                printf("Bits encendidos: %d \n", contador);
            case 7:                                 break;
            }
        printf("Nuevo resultado: %u \n", auxiliar);
    }

    return 0;
}