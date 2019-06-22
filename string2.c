/*Escreva um programa que solicita dois números ponto flutuante do usuário e uma 
 * operação (caractere) que ele deseja realizar. O programa deve realizar a operação 
 * selecionada pelo usuário e apresentar na tela. Cuidado com divisões por zero.
 */
#include <stdio.h>

int main(){
	double n1, n2, result = 0;
	char operacao;
	scanf("%lf", &n1);
	scanf("\n%c\n", &operacao);
	scanf("\n%lf", &n2);
	
	switch(operacao){
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			if(n2 == 0){
				printf("Divisor 0!!!");
			}else{
				result = n1 / n2;
			}
			break;
		default:
			break;
	}
	printf("%lf", result);
	return 0;
}
