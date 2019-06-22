#include <stdio.h>

char vogal(char c){
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int tamSeqVogal(int posicao, char texto[]){
	int i, cont = 0;
	for(i = posicao; texto[i]; i++){
		if(vogal(texto[i])){
			cont++;
		} 
		else{
			break;
		} 
	}
	return cont;
}

void imprimeMaiorSequencia(char texto[]){
	int i, pos_maior, maior = -1, tam;
	for(i = 0; texto[i]; i++){
		tam = tamSeqVogal(i, texto);
		if(tam > maior){
			maior = tam;
			pos_maior = i;
		}	
	}
	for(i = pos_maior; texto[i] && vogal(texto[i]); i++){
		printf("%c", texto[i]);
	}
	printf("\n");
}

int main(){
	char texto[101];
	int n, i;
	scanf("%d\n", &n);
	
	for(i = 0; i < n; i++){
		scanf("%100[^\n]\n", texto);
		imprimeMaiorSequencia(texto);
	}
	return 0;
}
