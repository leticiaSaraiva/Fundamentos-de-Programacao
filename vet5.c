/*Faça um programa que receba um vetor A de 10 elementos e construa um vetor
 *B que possui os mesmos números de A, sendo que na ordem invertida.
*/

#include <stdio.h>
int main(){
	int A[10], i, B[10], j = 0;
	for(i = 0; i < 10; i++){
		scanf("%d", &A[i]);
	}
	for(i = 10 - 1; i >= 0; i--){
		B[j] = A[i];
		j++;
	}
	for(i = 0; i < 10; i++){
		printf("%d ", B[i]);
	}
	return 0;
}
