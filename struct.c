#include <stdio.h>
#include <string.h>

struct aluno
{
   int matricula;
   char nome[15];
   double nota;
   int faltas;
};

int main()
{
   struct aluno joao;  

   joao.matricula = 1234;
   strcpy(joao.nome, "Joao da Silva");
   joao.nota = 8.0;
   joao.faltas = 5;
    
   printf("%d, %s, %f, %d\n", joao.matricula, joao.nome, joao.nota, joao.faltas);
   
   return 0;
}
