#include <stdio.h>

typedef struct
{
   int matricula;
   char nome[50];
   double nota;
   int faltas;
} aluno;

int main()
{
   FILE *f = fopen("alunos.txt", "r");
   if (f == 0) {
      printf("Erro: nao foi possivel abrir arquivo!");
      return 1;
   }
   
   int n = 0;
   aluno turma[30];
   while (fscanf(f, "%d %s %lf %d", &turma[n].matricula, turma[n].nome, &turma[n].nota, &turma[n].faltas) == 4)
      n++;
   
   fclose(f);
   
   int i;
   for (i = 0; i < n; i++)
       printf("%d, %s, %f, %d\n", turma[i].matricula, turma[i].nome, turma[i].nota, turma[i].faltas);
	return 0;
}
