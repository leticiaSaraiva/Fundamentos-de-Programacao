#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[16];
    int matricula;
    double nota;
    char disciplina[21];
}registro_aluno;
int main(){
	registro_aluno pessoa;
	scanf(" %15[^\n]", pessoa.nome);
	scanf("%d", &pessoa.matricula);
	scanf(" %20[^\n]", pessoa.disciplina);
	scanf("%lf", &pessoa.nota);
	
	if(pessoa.nota >= 7){
		printf("%s aprovado(a) em %s\n", pessoa.nome, pessoa.disciplina);
	}else{
		printf("%s reprovado(a) em %s\n", pessoa.nome, pessoa.disciplina);
	}
	
	return 0;
}
