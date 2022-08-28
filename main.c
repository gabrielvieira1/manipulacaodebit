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

void operadorNOT(){
    // Operador bit a bit NOT ( ~ )

    //  1 = 0001            2 = 00000010        3 = 0011        9 = 111...1001
    // ~1 = 1110 (-2)      ~2 = 11111101 (-3)  ~3 = 1100 (-4)  ~9 = 000...0110 (-10)

    int a, b;
    a = 9;
    b = ~a;

    printf("a: %d\t~a: %d\n", a, b);

    /* Complemento de dois, como representar o -2 em binário?
     * 2 - em decimal
     * 0011 - dois em binário
     * 1100
     *    1
     * 1101 -> -3
     * */
}

void operadorOU(){
    /*
   * Operador bit a bit OU ( | ) OR || if( () || ())
   *
   * A B A | B
   * 0 0   0
   * 0 1   1
   * 1 0   1
   * 1 1   1
   */

    int a, b, c;
    a = 30;     // 0000.0000.0001.1110
    b = 19;     // 0000.0000.0001.0011
    c = a | b;  // 0000.0000.0001.1111 = 31
    printf("%d | %d = %d\n", a,b,c);
    a = 0;
    c = a || b;  // 0000.0000.0000.0001 = 1
    printf("%d || %d = %d\n", a,b,c);

    // Como ativar um bit (colocar um bit em 1)

    a = 1;        //   0000.0001
    c = (1 << 1); //   0000.0010
    b = a | c;    //   0000.0011 = 3
    printf("a: %d\tb: %d\n", a, b);

    a = 1;         //   0000.0001
    c = (1 << 2);  //   0000.0100
    b = a | c;     //   0000.0101 = 5
    printf("a: %d\tb: %d\n", a, b);

    a = 1;        //   0000.0001
    c = (1 << 3); //   0000.1000
    b = a | c;    //   0000.1001 = 9
    printf("a: %d\tb: %d\n", a, b);
}

void operadorOUExclusivo(){
    /*
    * Operador bit a bit OU Exclusivo ( ^ )
    *
    * A B A ^ B
    * 0 0   0
    * 0 1   1
    * 1 0   1
    * 1 1   0
    *
    * Esta operação é útil quando precisamos inverter o estado de um bit.
    * xxxx.xxXx
    * 0000.0010
    * xxxx.xx0x
    */

    int a, b, c;
    a = 73;        // 0100.1001
    c = (1 << 3);  // 0000.1000 ( 1 << 3 ), para inverter o bit 3
    b = a ^ c;     // 0100.0001 = 65
    printf("a:%d\tb: %d\n", a,b);

    a = b;         // 0100.0001 = 65
    c = (1 << 3);  // 0000.1000 ( 1 << 3 ), para inverter o bit 3
    b = b ^ c;     // 0100.1001 = 73
    printf("a:%d\tb: %d\n", a,b);
}

int main() {
    deslocamentoEsquerdaDireita();
    operadorAND();
    operadorNOT();
    operadorOU();
    operadorOUExclusivo();

   return 0;
}
