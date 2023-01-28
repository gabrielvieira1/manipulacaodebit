#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
    * 1 1   1
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

    /* Complemento de dois, como representar o -2 em binário?   QzwDyaoaqSdC
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

void testCheckPalindroma()
{
    char palavra[10] = "gabriel";
    int diferente = 0;

    for (int i = 0; i < strlen(palavra) / 2; i++)
    {
        if (palavra[i] != palavra[strlen(palavra) - i - 1])
            diferente++;
    }

    if (diferente == 0)
        printf("\nEh palindroma\n");
    else
        printf("\nNão é palindroma\n");
}

void verificaPalavraPalindromaSemPerformace()
{
    char palavra[10];
    int i, tam, diferentes = 0;

    printf("Digite uma palavra: ");
    scanf("%10s", palavra);

    tam = strlen(palavra);
    tam--;
    i = 0;

    while (tam >= i)
    {
        if (palavra[i] != palavra[tam])
            diferentes++;
        i++;
        tam--;
    }

    if (diferentes == 0)
        printf("\nEh palindroma...\n");
    else
        printf("\nNão é palindroma...\n");
}

void verificaPalavraPalindromaPerformace()
{
    char palavra[10];
    int tam, diferente = 0;

    printf("Digite uma palavra: ");
    scanf("%10s", palavra);

    tam = strlen(palavra);
    // osso ou gabriel
    for (int i = 0; i < tam / 2; i++)
    {
        if (palavra[i] != palavra[tam - i - 1])
            diferente++;

        printf("\nfora do if tam / 2:%d\t i: %d\t tam - i -1: %d\n", tam / 2, i, tam - i - 1);
    }

    if (diferente == 0)
        printf("\nEh palindroma...\n");
    else
        printf("\nNão é palindroma...\n");
}

void checkPalindroma()
{
    char palavra[10] = "ada";
    int diferente = 0;

    // Percorre somente até a metade da palavra
    for (int i = 0; i < strlen(palavra) / 2; i++)
    {
        // Check a palavra na posição 0 com a ultima - i - 1
        if (palavra[i] != palavra[strlen(palavra) - i - 1])
            diferente++;
    }

    if (diferente == 0)
        printf("\nEh palindroma\n");
    else
        printf("\nNão é palindroma\n");
}

void checkpa()
{
    char palavra[10] = "gabriel";
    int diferente = 0;

    for (int i = 0; i < strlen(palavra) / 2; i++)
    {
        if (palavra[i] != palavra[strlen(palavra) - i - 1])
            diferente++;
    }

    if (diferente == 0)
        printf("\nEh Palindroma\n");
    else
        printf("\nNão é Palindroma\n");
}

int main() {
    deslocamentoEsquerdaDireita();
    operadorAND();
    operadorNOT();
    operadorOU();
    operadorOUExclusivo();

    /*
    printf("Deslocando bit a esquerda\n");

    int a, b;
    a = 10;
    b = a << 1;
    printf("a: %d\tb: %d\n", a, b);

    printf("Deslocando bit a direita\n");

    a = 10;
    b = a >> 1;

    printf("a: %d\tb: %d\n", a, b);

    printf("Bit a Bit not\n");

    a = 16;
    b = ~a;

    printf("a: %d\t~a: %d\n", a, b);

    // Ativando um bit
    printf("Ativando um bit com Bit a Bit OU\n");

    a = 90;           // 01011010
    b = a | (1 << 2); // 01011110
    printf("a: %d\tb: %d\n", a, b);

    printf("Testar se um bit está ligado com Bit a Bit AND\n");

    a = 84;           //           1010100
    b = a & (1 << 4); // 0010000

    printf("a: %d\tb: %d\n", a, b);

    printf("Limpando um bit com Bit a Bit NOT e AND\n");

    a = 84;            //              1010100
    b = a & ~(1 << 4); // 1000100

    printf("a: %d\tb: %d\n", a, b);

    printf("Invertendo o estado de um bit\n");

    a = 97;           // 1100001
    b = a ^ (1 << 5); // 1000001

    printf("a: %d\tb: %d\n", a, b);

    /*
     A B A & B A | B A ^ B
     0 0   0     0     0
     0 1   0     1     1
     1 0   0     1     1
     1 1   1     1     0
    */
    /*
      a = 95;     //     1011111
      b = a << 1; // 10111110

      printf("a: %d\tb: %d\n", a, b);

      a = 5;      //      101
      b = a >> 1; // 010

      printf("a: %d\tb: %d\n", a, b);

      printf("Ativar um bit a esquerda\n");

      a = 5;            // 101
      b = a | (1 << 1); // 010

      printf("a: %d\tb: %d\n", a, b);

      printf("Ativar um bit a direita\n");

      a = 5;            //            101
      b = a | (7 >> 1); // 111

      printf("a: %d\tb: %d\n", a, b);

      printf("Limpar um bit\n");

      a = 5;             //            101 -> 101
      b = a & ~(1 << 2); // 100 -> 011
                         // 100 -> 001

      printf("a: %d\tb: %d\n", a, b);

      printf("Inverter bit\n");

      a = 5;            // 101
      b = a ^ (1 << 2); // 100

      printf("a: %d\tb: %d\n", a, b);

      printf("Testar valor de um bit\n");

      a = 95;           // 1011111
      b = a & (1 << 4); // 010000 Se for falso ele me retorna 0 sempre

      printf("a: %d\tb: %d\n", a, b);

    */
    // verificaPalavraPalindromaSemPerformace();
    // verificaPalavraPalindromaPerformace();
    // checkPalindroma();

    /*
      A B A | B A & B A ^ B
      0 0   0     0     0
      0 1   1     0     1
      1 0   1     0     1
      1 1   1     1     0
    */

    int a = 5; // 101

    /*
    OU é usado para Ativar um bit porque basta passar um bit 1 na posição desejada
    e ele vai sempre retornar 1 independete se for 0 ou 1
    */
    printf("Ativando um bit com OU\n");
    // int resultado = a | (1 << 1); // 111
    int resultado = a | (1 << 1);
    printf("a: %d\t resultado: %d\n", a, resultado);

    /*
    AND é usado para testar um bit porque batas passar um bit 1 na posição desejada, se
    retornar 0 o bit está desligado se retornar qualquer outro valor o bit está ligado
    */
    printf("Testando valor de um bit com AND\n");
    // resultado = a & (1 << 1);
    resultado = a & (1 << 1);
    printf("a: %d\t resultado: %d\n", a, resultado);

    /*
     AND é usado para Limpar um bit porque basta passar um bit 1 na posição desejava e negar ele
     que o resultado sempre vai ser retornar 0
    */
    printf("Limpando um bit com AND\n");
    // resultado = a & ~(1 << 2);
    resultado = a & ~(1 << 2);
    printf("a: %d\t resultado: %d\n", a, resultado);

    /*
      OU exclusivo é usado para Inverter um bit porque basta passar um bit 1 na posição desejada
      que o resultado vai ser sempre o inverso do bit verificado.
    */
    printf("Inverter um bit com OU exclusivo\n");
    // resultado = a ^ (1 << 0);
    resultado = a ^ (1 << 0);
    printf("a: %d\t resultado: %d\n", a, resultado);

    // checkPalindroma();

    printf("Usando System call\n");
    char buffer[20];

    char comando[10] = "ls -a";
    // char arg[10] = "-a";
    char arg[10];
    printf("Digite um comando\n");
    // scanf("%10[^\n]", arg); // Ler espaço em branco

    // scanf("%10[^\n]", comando); // Ler espaço em branco
    // fgets(comando, sizeof(comando), stdin);

    printf("Comando: %s\t arg: %s\n", comando, arg);

    // snprintf(buffer, sizeof(buffer), "%s %s", comando, arg);

    printf("Comando: %s\t arg: %s buffe: %s\n", comando, arg, buffer);

    // testCheckPalindroma();

    checkpa();

    /*
    A função System é usada para execultar comandos, o problema é que ela recebe uma única sequencia de comando e nessa
    sequencia pode ser passado comandos maliciosos, que façam chamadas indevidas e causem comportamentos inesperados.
    Basta subverter o comando anterior passando um ; e inserindo um comando malicioso.
    */
    // system(buffer);
    // system("grep Content *;id");

    // Na função execl devemos passar 3 parametros (Caminho do comando, comando, argumentos separados por virgual e NUll);
    // execl("/bin/ls", "/bin/ls", "-lh", "/home", NULL);

    // Diferente da função System o execl não permite a subversão do comando passando ; ela é a forma segura de fazer chamadas ao sistema
    // execl("/bin/ls", comando, arg, NULL);

   return 0;
}