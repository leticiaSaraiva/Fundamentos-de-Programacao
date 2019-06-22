/*
 *Faça um programa que receba palavras separadas por vários espaços em 
 * branco e apresente essas palavras separadas por somente um espaço. 
*/
#include <stdio.h>

void removerEspacos(char str[]){
    int i, j = 1;
    for(i = 1; str[i]; i++){
        if(str[i] != ' ' || (str[i - 1] != ' ')){
           str[j] = str[i];
           j++;
        }
    }
    str[j] = '\0';
}
int main() {
   char frase[101];
   scanf("%100[^\n]", frase);
   
   removerEspacos(frase);
   printf("%s", frase);
   
   return 0;
}

