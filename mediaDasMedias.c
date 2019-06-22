#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[16];
    double notas[3];
    double media1;
    double soma1;
    double soma2;
    double media2;
    int i;
}registro_aluno;
registro_aluno leAluno(){
	registro_aluno pessoa;
	pessoa.i = 0;
	scanf(" %15[^\n]", pessoa.nome);
	for(pessoa.i = 0; pessoa.i < 3; pessoa.i++){
		scanf("%lf", &pessoa.notas[pessoa.i]);
	}
	return pessoa;
}
int main(){
	int i;
	registro_aluno a1 = leAluno();
	registro_aluno a2 = leAluno();
	
	for(i = 0; i < 3; i++){
		a1.soma1 += a1.notas[i];
		a2.soma2 += a2.notas[i];
	}
	a1.media1 = a1.soma1/3;
	a2.media2 = a2.soma2/3;
	
	printf("%.1f\n", (a1.media1 + a2.media2)/2);
	
	return 0;
}
