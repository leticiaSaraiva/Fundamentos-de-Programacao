/*
Faça um programa que receba uma frase, calcule e mostre a quantidade de vogais da frase digitada. 
Também deve ser calculado e exibido a quantidade de palavras.
*/
#include <stdio.h>
char vogal(char c){
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}
int main(){
	char frase[101];
	scanf("%100[^\n]", frase);
	
	int i, contVogal = 0, numPalavras = 0, espaco = 0;
	for(i = 0; frase[i]; i++){
		if(vogal(frase[i])){
			contVogal++;
		}
		
		if(frase[i] == ' '){
			espaco++;
		}
	}
	
	numPalavras = espaco + 1;
	
	printf("Vogais: %d\n", contVogal);
	printf("Palavras: %d", numPalavras);
	return 0;
}
