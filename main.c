#include <stdio.h>
#include <stdlib.h>

void deslocamentoEsquerdaDireita(){
    // Deslocamento à esquerda

    int a, b;
    a = 1;      // 0001
    b = a << 1; // 0010 = 2

    printf("a: %d\tb: %d\n", a, b);

    b = a << 2; // 0100 = 4
    printf("a: %d\tb: %d\n", a, b);

    b = a << 3; // 1000 = 8
    printf("a: %d\tb: %d\n", a, b);

    // Deslocamento à esquerda é o mesmo que multiplicar por 2

    // Deslocamento à direita

    a = 10;      // 1010
    b = a >> 1;  // 0101 = 5

    printf("a: %d\tb: %d\n", a, b);

    b = a >> 2; // 0010 = 2
    printf("a: %d\tb: %d\n", a, b);

    b = a >> 3; // 0001 = 1
    printf("a: %d\tb: %d\n", a, b);

    // Deslocamento à direita é o mesmo que dividir por 2

}

void operadorAND(){
    /*
    * Gera sequência de zeros em bash
    * for i in {1..32}; do echo -n 0; done; echo
    * 00000000000000000000000000000000
    *
    * Operador bit a bit E ( & ) and if( () && ())
    *
    * A B A & B
    * 0 0   0
    * 0 1   0
    * 1 0   0
    * 1 1   0
    */

    int a, b, c;
    a = 30;     // 0000.0000.0001.1110
    b = 19;     // 0000.0000.0001.0011
    c = a & b;  // 0000.0000.0001.0010 = 18
    printf("%d & %d = %d\n", a,b,c);
    c = a && b;  // 0000.0000.0000.0001 = 1
    printf("%d && %d = %d\n", a,b,c);

    // Testar se um bit está ligado ou desligado
    a = 73;     //         001001001
    b = a & (1 << 3); //   000001000 ( 1 << 3 ), para testar o bit-3
    printf("a: %d\tb: %d\n", a, b);
    b = a & (1 << 4); //   000010000 ( 1 << 4 ), para testar o bit-4
    printf("a: %d\tb: %d\n", a, b);

    // Verificar se um número é par ou impar
    int n = 97;
    if( n & 1)
        printf("Número impar \n");
    else
        printf("Número par \n");
}

int main() {
    deslocamentoEsquerdaDireita();
    operadorAND();

   return 0;
}
