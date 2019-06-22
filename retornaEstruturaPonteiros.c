#include <stdio.h>

typedef struct{
	float nota[3];
	float media;
} aluno;

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
void calcula_media(aluno *a){
	int i;
	float soma = 0.0;
	for(i = 0; i < 3; i++){
		soma = soma + (*a).nota[i];
	}
	(*a).media = soma / 3;
}

int main(){
	aluno a;
	int i;
	for (i = 0; i < 3; i++)
		scanf("%f", &a.nota[i]);
   
   // Chame a função 'calcula_media' passando o aluno 'a' por referência.
	calcula_media(&a);
   
	printf("%.1f", a.media);
	return 0;
}
