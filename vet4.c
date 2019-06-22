/*
 *Faça um programa que leia 15 números inteiros e os armazene em um vetor A. 
 * Determine então qual o maior e o menor destes números e quantas vezes este 
 * maior e este menor ocorrem no vetor. No final, apresente esses valores 
*/

#include <stdio.h>
int main(){
	int A[15], i, maior = 0, menor = 0, contMaior = 0, contMenor = 0;
	for(i = 0; i < 15; i++){
		scanf("%d", &A[i]);
	}
	
	menor = A[0];
	maior = A[0];
	for(i = 0; i < 15; i++){
		if(A[i] < menor){
			menor = A[i];
		}
		
		if(A[i] > maior){
			maior = A[i];
		}
	}
	for(i = 0; i < 15; i++){
		if(A[i] == menor){
			contMenor++;
		}
		if(A[i] == maior){
			contMaior++;
		}
	}
	printf("Menor: %d \n", menor);
	printf("Apareceu %dX \n", contMenor);
	printf("Maior: %d \n", maior);
	printf("Apareceu %dX \n", contMaior);
	return 0;
}
