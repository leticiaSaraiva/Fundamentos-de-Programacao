//Dada uma string como entrada determinar a soma do código ascii de seus caracteres.

#include <stdio.h>

int main(){
	char palavra[101];
	scanf("%100[^\n]", palavra);
	
	int i, soma = 0;
	for(i = 0; palavra[i]; i++){
		soma += palavra[i];
	}
	
	printf("%d", soma);
	return 0;
}
