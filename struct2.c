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
	if(a1.nota > a2.nota){
		printf("%s , %.1f", a1.nome, a1.nota);
	}else if(a2.nota > a1.nota){
		printf("%s , %.1f", a2.nome, a2.nota);
	}else{
		printf("%s e %s , %.1f", a1.nome, a2.nome, a2.nota);
	}
	return 0;
}
