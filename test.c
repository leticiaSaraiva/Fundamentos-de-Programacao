/*#include <stdio.h>

int main()
{
    int a = 1;
    int *p = &a;
    printf("Endereço de memória de a: %p\n", p);    
    printf("Valor armazenado no local apontado: %d\n", *p);
    *p = 5;
    printf("Valor armazenado no local apontado: %d\n", *p);
    printf("Valor de a: %d\n", a);
    return 0;
}
*/
/*
#include <stdio.h>

void f(int *x)
{
   *x = 2;
}

int main()
{
   int y = 1;
   f(&y); // Aponta para o endereço de memória de y
   printf("%d", y);  // Imprime o valor 2.
   return 0;
}
*/

#include <stdio.h>

typedef struct {
   int x;
   float y;
} tupla;

void f(tupla *p)
{
   (*p).y = 3; // Pegando os dados da estrutura (operador de derreferenciar -> (*t).y), acessa o valor de y e altera
}

int main(
{
   tupla t = {1, 2.0};
   f(&t);
   printf("%d %.1f", t.x, t.y);  // Imprime "1 3.0"
   return 0;
}
