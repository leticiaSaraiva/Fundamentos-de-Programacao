#include <stdio.h>

int main(){
	char texto[101], palavra[101];
	scanf("\n%100[^\n]", texto);
	scanf("\n%100[^\n]", palavra);
	
	int i, j = 0, cont = 0;
	for(i = 0; texto[i] && palavra[j]; i++){
		if(texto[i] == palavra[j]){
			j++;
			if(palavra[j] == 0){
				cont++;
				j = 0;
			}
		}else{
			j = 0;
		}
	}
	printf("%d", cont);
	return 0;
}
