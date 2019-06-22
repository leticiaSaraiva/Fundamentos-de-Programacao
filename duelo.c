#include <stdio.h>
#include <string.h>

typedef struct{
	int vida;
	int ataque;	
}personagem;

void duelo(int vida1, int vida2){
	if(vida1 <= 0 && vida2 <= 0){
		printf("Empate");
	}else if(vida1 > 0){
		printf("Personagem 1");
	}else{
		printf("Personagem 2");	
	}
}
int main(){
	personagem p1;
	personagem p2;
	
	scanf("%d%d", &p1.vida, &p1.ataque);
	scanf("%d%d", &p2.vida, &p2.ataque);
	
	while(p1.vida > 0 && p2.vida > 0){
		p1.vida -= p2.ataque;
		p2.vida -= p1.ataque;
	}
	
	duelo(p1.vida, p2.vida);
	return 0;
}
