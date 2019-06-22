#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Tema: Controle de estoque.
* Equipe: Carlos Henrique, Letícia Saraiva
- Menu para (1) cadastrar produto,(2) remover produto, (3) informar retirada de estoque,
 (4) informar compra, (5) imprimir produtos em falta, (6) imprimir todos os produtos.
- Armazenar produtos em vetor de estruturas.
*/

//Criacao de uma estrutura
typedef struct{
	int id;
    char nome[60];
    double preco;
    int quantidade;
}produto;

produto *vet_produtos; //Cria um ponteiro global do tipo produto (vetor de estrutura)
int tam_vet_produtos = 1; //Inicializa o tamanho do vetor com valor 1

int main(){
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
    
    
    free(vet_produtos);
    return 0;
}
//Funcao que requisita outras funcoes, dependendo da escolha do usuario
void chamar_Funcao(int numero){
    void cadastroProduto();
    void removeProduto();
    void retiradaEstoque();
    void compra();
    void imprimirProdutosEmFalta();
    void imprimirTodos();
    switch(numero){
        case 1:
            cadastroProduto();
            break;
        case 2:
            removeProduto();
            break;
        case 3:
            retiradaEstoque();
            break;
        case 4:
            compra();
            break;
       case 5:
            imprimirProdutosEmFalta();
            break;
      case 6:
            imprimirTodos();
            break;
    }
}
//Funcao que permite cadastrar produtos
void cadastroProduto(){
	int id, quantidade, i;
	char nome[60];
	double preco;
    system("clear");
    printf("Digite o ID do produto: "); 
    scanf("%d", &id);
    printf("Digite o nome do produto: ");
    scanf(" %59[^\n]", nome);
    printf("Digite a quantidade do produto: "); 
    scanf("%d", &quantidade);
    printf("Digite o preco do produto: "); 
    scanf("%lf", &preco);
    
    //Percorre todo o vetor dos produtos ja cadastrados e confere se nao existe nenhum outro produto com nome igual ao digitado
    //confere também se não existe nenhum outro ID igual ao digitado
    for(i=0; i<tam_vet_produtos-1; i++){
		if(strcmp(vet_produtos[i].nome, nome) == 0){
			system("clear");
			printf("Produto ja existe!\n\n\n");
			return;
		}
		if(id == vet_produtos[i].id){
			system("clear");
			printf("ID do produto ja existe!\n\n\n");
			return;
		}
	}
    
    //Realiza a alocacao
    if(tam_vet_produtos == 1){
        vet_produtos = (produto*) malloc(sizeof(produto));
        tam_vet_produtos++;
    }else{
        vet_produtos = (produto*) realloc(vet_produtos, sizeof(produto) * (tam_vet_produtos));
        tam_vet_produtos++;
    }
    //Verifica se foi possivel alocar memoria
    if(vet_produtos == 0){
        printf("Erro ao alocar memoria");
        return;
    }
    
    //Passa as informacoes obtidas para o vetor de struct
    vet_produtos[tam_vet_produtos - 2].id = id;
    strcpy(vet_produtos[tam_vet_produtos - 2].nome, nome);
    vet_produtos[tam_vet_produtos - 2].quantidade = quantidade;
    vet_produtos[tam_vet_produtos - 2].preco = preco;
    
    system("clear");
    printf("Sucesso ao cadastrar o produto %s!\n", vet_produtos[tam_vet_produtos - 2].nome);
    printf("-----------------------------------\n\n\n");
}
//Funcao que permite remover produtos
void removeProduto(){
	system("clear");
	char nome[60];
	int i;
	printf("Nome do produto que deseja remover: ");
    scanf(" %59[^\n]", nome);
    
    //Percorre o vetor de struct e procura um nome igual ao nome digitado e remove todas as informações referentes a ele
    for(i=0; i<tam_vet_produtos-1; i++){
		if(strcmp(nome, vet_produtos[i].nome) == 0){
			//Pega o ultimo elemento do vetor e copia para a posicao na qual está o produto que será removido
			vet_produtos[i].id = vet_produtos[tam_vet_produtos-2].id;
			strcpy(vet_produtos[i].nome, vet_produtos[tam_vet_produtos-2].nome);
			vet_produtos[i].quantidade = vet_produtos[tam_vet_produtos-2].quantidade;
			vet_produtos[i].preco = vet_produtos[tam_vet_produtos-2].preco;
			
			//Realoca o vetor, diminuindo seu tamanho
			vet_produtos = (produto*) realloc(vet_produtos, sizeof(produto) * (tam_vet_produtos-1));
			//Verifica se foi possivel realocar memoria
			if(vet_produtos == 0){
				printf("Erro ao realocar memoria");
				return;
			}
			tam_vet_produtos--;
			printf("Sucesso ao remover o produto!\n");
			printf("-----------------------------------\n\n\n");
			return;
		}
	}
	printf("Produto nao encontrado!\n");
	printf("-----------------------------------\n\n\n");
	
}

void retiradaEstoque(){
    
    
}

void compra(){
    

}

void imprimirProdutosEmFalta(){
    
    
}
//Funcao que imprime todos os produtos
void imprimirTodos(){
	system("clear");
	int i;
	//Se o vetor estiver vazio imprime a mensagem abaixo
	if(tam_vet_produtos == 1){
		printf("Nenhum produto cadastrado!\n");
	}
	//Percorre o vetor de strutc e exibe todo o conteúdo existente nele
	for(i=0; i<tam_vet_produtos-1; i++){
		printf("ID: %d\n", vet_produtos[i].id);
		printf("Nome: %s\n", vet_produtos[i].nome);
		printf("Quantidade: %d\n", vet_produtos[i].quantidade);
		printf("Preco: %.2f\n", vet_produtos[i].preco);
		printf("\n\n");
	}
	printf("-----------------------------------\n\n\n");	
}
