// Dados como entrada um vetor de números L e um número x, determinar utilizando busca linear se x está ou não presente em L.

#include <stdio.h>
int main(){
	int n, p = 0;
	scanf("%d", &n);
	int L[n], i, x;
	for(i = 0; i < n; i++){
		scanf("%d", &L[i]);
	}
	scanf("%d", &x);
	
	for(i = 0; i < n; i++){
		if(L[i] == x){
			p = 1;
			break;
		}
	}
	if(p == 1){
		printf("sim");
	}else{
		printf("nao");
	}
	return 0;
}
