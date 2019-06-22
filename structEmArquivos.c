#include <stdio.h>

typedef struct {
   int matricula;
   char nome[50];
   float media;
} aluno;

void alunos_para_arquivo(aluno turma[], int n){
	FILE *f = fopen("alunos.txt", "w");
	if (f == 0) {
	  printf("Erro: nao foi possivel abrir arquivo!");
	  return;
	}

	int i;
	for (i = 0; i < n; i++){
		fprintf(f, "%d\n%s\n%f\n", turma[i].matricula, turma[i].nome, turma[i].media);
	}
	fclose(f);
}

void imprime_alunos_arquivo(){
	FILE *f = fopen("alunos.txt", "r");
	if (f == 0) {
	  printf("Erro: nao foi possivel abrir arquivo!");
	  return;
	}
	aluno i;
	while (fscanf(f, "%d\n%[^\n]\n%f", &i.matricula, i.nome, &i.media) == 3){
		printf("%s\n", i.nome);
		
	}
	fclose(f);
}

int main(){
   int n, i;
   scanf("%d\n", &n);
   aluno turma[n];

   for (i = 0; i < n; i++) {
      scanf("%d\n", &turma[i].matricula);
      scanf("%[^\n]\n", turma[i].nome);
      scanf("%f\n", &turma[i].media);
   }
   alunos_para_arquivo(turma, n);
   imprime_alunos_arquivo();
  
   return 0;
}
