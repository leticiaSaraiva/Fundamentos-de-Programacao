#include <stdio.h>
void InvertePalavras(char str[]){
    char qtdePalavras = 1, i, j, k = 0, l, aux;

    for(l = 0; str[l] != '\0'; l++){
        if(str[l] == ' '){
            qtdePalavras += 1;
        }else{
            qtdePalavras += 0;
        }
        //qtdePalavras += (str[l] == ' ') ? 1 : 0;
    }
    do{
        if(qtdePalavras == 1){
            l--;
            for(j = k; l > j; j++){
                aux = str[j];
                str[j] = str[l];
                str[l] = aux;
                l--;
            }
        }else{
            for(j = i = k; str[i] != ' '; i++){

            }
            k = i + 1;
            for(--i; j < i; i--, j++){
                aux = str[j];
                str[j] = str[i];
                str[i] = aux;
            }
        }
    }while(--qtdePalavras);

    for(i = 0; str[i]; i++){
        printf("%c", str[i]);
    }
}
int main(){
    char texto[101];
    scanf("%100[^\n]", texto);
    InvertePalavras(texto);

    return 0;
}
