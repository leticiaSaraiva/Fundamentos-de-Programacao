#include <stdio.h>
#include <string.h>

int main(){
	char texto[101], anterior[101];
	anterior[0] = 0;
	while(scanf("%100s", texto) == 1){
		if(strcmp(anterior, texto) > 0){
			printf("nao");
			return 0;
		}else{
			strcpy(anterior, texto);
		}
	}
	printf("sim");
	return 0;
}
