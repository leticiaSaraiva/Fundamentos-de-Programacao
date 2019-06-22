#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[16];
    int matricula;
    double nota;
    char disciplina[21];
}registro_aluno;
registro_aluno leAluno(){
	registro_aluno pessoa;
	scanf(" %15[^\n]", pessoa.nome);
	scanf("%d", &pessoa.matricula);
	scanf(" %20[^\n]", pessoa.disciplina);
	scanf("%lf", &pessoa.nota);
	return pessoa;
}
int main(){
	
	registro_aluno a1 = leAluno();
	registro_aluno a2 = leAluno();
	printf("Média = %f\n", (a1.nota + a2.nota)/2);
	return 0;
}
