#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Controle_de_Estoque V4.h" //Inclui o arquivo que contém os protótipos das funções

produto *vet_produtos; //Cria um ponteiro global do tipo produto (vetor de estrutura)
int tam_vet_produtos = 0; //Inicializa o tamanho do vetor com valor 0

int main(){
	//Chama a funcao que lê o arquivo
	vet_produtos = lerArquivo(&tam_vet_produtos);
	
    int numero = 0;
    //Exibe o menu enquanto a escolha do numero for diferente de 7 (Exibe pelo menos uma vez)
    do{
        printf("Digite:\n (1) cadastrar produto\n (2) remover produto\n (3) "
        "informar retirada de estoque\n (4) informar compra\n (5) imprimir produtos em falta\n "
        "(6) imprimir todos os produtos\n (7) para sair\n");
        
        printf("Digite sua escolha: ");
        scanf("%d", &numero);
        if(numero != 7){
            void chamar_Funcao(int numero);
            chamar_Funcao(numero);
        }
    }while(numero != 7);
    
    //Chama a funcao que salva/escreve todos os dados da memória no arquivo de texto
	escreverAquivo(vet_produtos, &tam_vet_produtos);
    
    free(vet_produtos);
    return 0;
}
//Funcao que requisita outras funcoes, dependendo da escolha do usuario
void chamar_Funcao(int numero){
    switch(numero){
        case 1:
			//Chama a função que cadastra um produto passando os parametros que serão utilizados
            vet_produtos = cadastroProduto(vet_produtos, &tam_vet_produtos);
            //Chama a funcao que salva/escreve todos os dados da memória no arquivo de texto
			escreverAquivo(vet_produtos, &tam_vet_produtos);
            break;
        case 2:
			//Chama a funcao que remove um produto
            vet_produtos = removeProduto(vet_produtos, &tam_vet_produtos);
            //Chama a funcao que salva/escreve todos os dados da memória no arquivo de texto
			escreverAquivo(vet_produtos, &tam_vet_produtos);
            break;
        case 3:
			//Chama a funcao que permite retirar uma quantidade do estoque de um produto 
            vet_produtos = retiradaEstoque(vet_produtos, &tam_vet_produtos);
            //Chama a funcao que salva/escreve todos os dados da memória no arquivo de texto
			escreverAquivo(vet_produtos, &tam_vet_produtos);
            break;
        case 4:
			//Chama a funcao que permite realizar a atualização da quantidade de um produto
            vet_produtos = compra(vet_produtos, &tam_vet_produtos);
            //Chama a funcao que salva/escreve todos os dados da memória no arquivo de texto
			escreverAquivo(vet_produtos, &tam_vet_produtos);
            break;
        case 5:
			//Chama a funcao que imprime produtos em falta
            imprimirProdutosEmFalta(vet_produtos, &tam_vet_produtos);
            break;
        case 6:
			//Chama a funcao que imprime todos os produtos cadastrados
            imprimirTodos(vet_produtos, &tam_vet_produtos);
            break;
        default:
			//Caso seja digitado uma opcao diferente das existentes no menu, exibe a mensagem abaixo
			printf("\nOpcao invalida! \n\n");
			break;
    }
}

