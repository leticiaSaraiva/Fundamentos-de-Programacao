#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int vet[n], i, j, cont = 0, aux = 0, valor = 0, contV = 0;
	
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
		for(j = i + 1; j < n; j++){
			if(vet[i] == vet[j]){
				cont++;
			}
			
			if(vet[i] != vet[j]){
				valor = vet[i];
				contV = cont;
				if(contV < cont){
					contV = cont; 
				}
			}
		}
	}
	
	if(contV == 0){
		printf("nao\n");
	}else if(contV > n/2){
		printf("sim\n");
	}else{
		printf("nao\n");
	}
	
	printf("%d", contV);
	return 0;
}
