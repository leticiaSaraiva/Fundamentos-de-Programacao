#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n, qtdCaracter, i, j;
	scanf("%d", &n);
	char* vet[qtdCaracter];
	
	for(i=0; i<n; i++){
		scanf("%d ", &qtdCaracter);
		vet[i] = (char*) malloc((qtdCaracter + 1) * sizeof(char));
		scanf("%[^\n]", vet[i]);
	}
	//Ordenar
	for(i=0; i<n; i++){
		for(j=1; j<n; j++){
			if(strcmp(vet[j], vet[j-1]) < 0){ // vet[j] < vet[j-1]
				char *aux = vet[j]; // guarda o end da string apontada por vet[j] 
				vet[j] = vet[j-1]; // o end da string apontada por vet[j] guarda o end da string apontada por vet[j-1]
				vet[j-1] = aux; // o end da string apontada por vet[j-1] guarda o end da string apontada aux (vet[j])
			}
		}
	}
	
	for(i = 0; i < n; i++){
		printf("%s\n", vet[i]);
	}   

	return 0;
}
