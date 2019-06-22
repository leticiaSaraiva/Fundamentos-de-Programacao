//Crie uma função que receba a quantidade n de termos e imprima os n termos da sequência de fibonacci.
#include <stdio.h>
int main(){
    int n, q = 0, i, p = 0, result;
     
    printf("Valor: ");
    scanf("%d", &n);
     
    for(i = 0; i < n; i++){
        result = p + q;
        if(result == 0){
            q = 1;
        }
        printf("%d ", result);
        p = q;
        q = result;
    }
    return 0;
}
