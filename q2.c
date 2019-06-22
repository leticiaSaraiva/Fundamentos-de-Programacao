#include <stdio.h>
char maiuscula(char c){
	if(c >= 'a' && c <= 'z'){
		return c - ('a' - 'A');
	}
	return c;
}
char minuscula(char c){
	if(c >= 'A' && c <= 'Z'){
		return c + ('a' - 'A');
	}
	return c;
}
int main(){
	char texto[101];
	scanf("%100[^\n]", texto);
	
	int i;
	for(i = 0; texto[i]; i++){
		texto[i] = minuscula(texto[i]);
	}
	for(i = 0; texto[i]; i++){
		texto[0] = maiuscula(texto[0]);
		if(texto[i] == ' '){
			texto[i+1] = maiuscula(texto[i+1]);
		}
		printf("%c", texto[i]);
	}
	return 0;
}
