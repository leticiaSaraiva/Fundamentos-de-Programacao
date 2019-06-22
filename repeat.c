#include <stdio.h>

int contaPalavra(char texto[]){
	int i, cont = 0;
	for(i = 0; texto[i]; i++){
		while(texto[i] && (texto[i] != ' ')){
			i++;
		}
		while(texto[i] == ' '){
			i++;
			cont++;
		}
	}
	return cont;
}
int contaPalavraComLetra(char letra, char texto[]){
	int i, cont = 0;
	for(i = 0; texto[i]; i++){
		if(letra == texto[i]){
			cont++;
			while(texto[i] == ' '){
				i++;
			}
		}
	}
	return cont;
}

int main(){
	
}
