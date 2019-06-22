/*
 *Faça um programa que receba um caractere e informe se ele é letra maiúscula, 
 * letra minúscula ou não é uma letra. Lembre-se que caracteres são representados 
 * internamente por números.  
*/
#include <stdio.h>
char maiuscula(char c){
	return (c >= 'A') && (c <= 'Z');
}
char minuscula(char c){
	return (c >= 'a') && (c <= 'z');
}

int main(){
	char caractere;
	scanf("%c", &caractere);
	
	if(maiuscula(caractere)){
		printf("Letra maiuscula");
		
	}else if(minuscula(caractere)){
		printf("Letra minuscula");
		
	}else if(!maiuscula(caractere) && !minuscula(caractere)){
		printf("Nao é letra");
		
	}
	
	return 0;
}
