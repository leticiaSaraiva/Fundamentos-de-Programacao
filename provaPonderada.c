#include <stdio.h>
#include <string.h>

typedef struct{
	double nota;
	int peso;
}prova;

int main(){
	int i, qtdProvas, somaPesos = 0;
	double somaPonderada = 0;
	scanf("%d", &qtdProvas);
	
	prova p[qtdProvas];
	for(i = 0; i < qtdProvas; i++){
		scanf("%lf", &p[i].nota);
	}
	for(i = 0; i < qtdProvas; i++){
		scanf("%d", &p[i].peso);
	}
	for(i = 0; i < qtdProvas; i++){
		somaPesos += p[i].peso;
	}
	for(i = 0; i < qtdProvas; i++){
		somaPonderada += p[i].nota * p[i].peso;
	}
	printf("%.1lf", somaPonderada / somaPesos);
	return 0;
}
