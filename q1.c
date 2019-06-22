#include <stdio.h>

int main(){
	int i, n, j, aux = 0;
	scanf("%d", &n);
	
	int vet[n];
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
	
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(vet[j] > vet[i]){
				aux = vet[j];
				vet[j] = vet[i];
				vet[i] = aux;
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}
	
	return 0;
}
