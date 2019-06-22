//Faça um programa para criptografar uma frase, trocando as consoantes por # e invertendo a frase.

#include <stdio.h>
#include <string.h>

char vogal(char c){
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}
int main(){
	char frase[101];
	scanf("%100[^\n]", frase);
	
	int i;
	for(i = strlen(frase) - 1; i >= 0; i--){
		if(!vogal(frase[i]) && frase[i] != ' '){
			printf("#");
		}else{
			printf("%c", frase[i]);
		}
	}

	return 0;
}
