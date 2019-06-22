#include <stdio.h>
#include <string.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}data;

int main(){
	data d1;
	data d2;
	scanf("%d%d%d", &d1.dia, &d1.mes, &d1.ano);
	scanf("%d%d%d", &d2.dia, &d2.mes, &d2.ano);
	if((d1.dia == d2.dia) && (d1.mes == d2.mes) && (d1.ano == d2.ano)){
		printf("Iguais");
		return 0;
	}else{
		printf("Diferentes");
		return 0;
	}
	return 0;
}
