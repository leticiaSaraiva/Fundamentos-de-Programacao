//Imprime os números armazenados no arquivo 

#include <stdio.h>

int main()
{
   FILE *f = fopen("teste.txt", "r");
   if (f == 0) {
      printf("Erro: nao foi possivel abrir arquivo!");
      return 1;
   }
   
   int i;
   while (fscanf(f, "%d", &i) == 1)
      printf("%d\n", i);
   
   fclose(f);
   return 0;
}
