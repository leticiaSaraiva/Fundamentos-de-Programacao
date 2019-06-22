#include <stdio.h>

int main(){
	int i, n;
	scanf("%d", &n);
	int vet[n], soma = 0, mult = 1;
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
	
	for(i = n-1; i >= 0; i--){
		soma = (vet[i] * mult) + soma;
		mult *= 10;
	}
	printf("%d", soma);
	
	return 0;
}
