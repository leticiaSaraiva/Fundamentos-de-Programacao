#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[16];
    double notas[3];
    double media;
    double soma;
}registro_aluno;
int main(){
	int i;
	registro_aluno pessoa;
	scanf(" %15[^\n]", pessoa.nome);
	for(i = 0; i < 3; i++){
		scanf("%lf", &pessoa.notas[i]);
	}
	for(i = 0; i < 3; i++){
		pessoa.soma += pessoa.notas[i];
	}
	pessoa.media = pessoa.soma/3;
	
	printf("%.1f\n", pessoa.media);
	
	return 0;
}
