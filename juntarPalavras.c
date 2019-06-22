#include <stdio.h>

char vogal(char c){
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ;
}
int main(){
	char texto[101];
	scanf("%100[^\n]", texto);
	
	int i;
	for(i = 0; texto[i]; i++){
		if((texto[i] == ' ') && (texto[i-1] == texto[i+1]) && (vogal(texto[i+1]))){
            i++;
		}else{
			printf("%c", texto[i]);
		}
	}
	return 0;
}
