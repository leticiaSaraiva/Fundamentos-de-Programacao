#include <stdio.h>
int minusculo(char c){
	if(c >= 'a' && c <= 'z'){
		return 1;
	}else{
		return c;
	}
}
int main(){
	int qtdTeste, i, j = 0;
	scanf("%d", &qtdTeste);
	
	while(qtdTeste > 0){
		char texto[101];
		scanf("\n%100[^\n]", texto);
		
		for(i = 0; texto[i]; i++){
			j = i + 1;
			if(minusculo(texto[i])){
				texto[j] = texto[j] - ('a' - 'A');
			}
		}
		qtdTeste--;
		for(i = 0; texto[i]; i++){
			printf("%c", texto[i]);
		}
	}
	
	return 0;
}
