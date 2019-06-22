//Grava os números de 1 a 10 no arquivo teste.txt

#include <stdio.h>

int main()
{
   FILE *f = fopen("teste.txt", "w");
   if (f == 0) {
      printf("Erro: nao foi possivel abrir arquivo!");
      return 1;
   }
   
   int i;
   for (i = 1; i <= 10; i++)
      fprintf(f, "%d\n", i);
   
   fclose(f);
	return 0;
}
