//Leia um vetor de inteiros e imprima o menor valor.
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int i, vet[n], menor = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
	menor = vet[0];
	for(i = 1; i < n; i++){
		if(menor > vet[i]){
			menor = vet[i];
		}
	}
	
	printf("%d", menor);
	
	return 0;
}
