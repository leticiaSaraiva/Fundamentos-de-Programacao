#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "Controle_de_Estoque V4.h" //Inclui o arquivo que contém os protótipos das funções

//produto *vet_produtos; //Cria um ponteiro global do tipo produto (vetor de estrutura)
//int tam_vet_produtos = 0; //Inicializa o tamanho do vetor com valor 0

//Funcao que permite ler o arquivo de texto
produto* lerArquivo(int *tam_vet_produtos){
	//Cria um ponteiro para o arquivo de texto
	FILE *arquivo = fopen("controleDeEstoque.txt", "r");
	produto *vet_produtos = NULL;
	//Testa se o arquivo de texto existe, se não existir ele é criado
	if(arquivo == NULL){
		arquivo = fopen("controleDeEstoque.txt", "w");
		fprintf(arquivo, "%d", *tam_vet_produtos);
		fclose(arquivo);
	}
	
	//Lê a quantidade de produtos que está no arquivo de texto(primeira linha do arquivo de texto) e salva no tamanho do ponteiro
	fscanf(arquivo,"%d", tam_vet_produtos);
	
	//Faz alocacao de memória dos produto cadastrados no arquivo de texto
	vet_produtos = (produto*) malloc((*tam_vet_produtos) * sizeof(produto));
	
	//Verifica se foi possivel alocar memoria
	if(!vet_produtos){
		printf("Não foi possível alocar memória!");
		return vet_produtos;
	}
				
	//Lê os dados do arquivo de texto e salva no vetor de produtos
	int i = 0;
	while(i < *tam_vet_produtos){
		fscanf(arquivo, " %d", &vet_produtos[i].id);
		fscanf(arquivo, " %[^\n]", vet_produtos[i].nome);
		fscanf(arquivo, " %d", &vet_produtos[i].quantidade);
		fscanf(arquivo, " %lf", &vet_produtos[i].preco);
		i++;
	}	
	//Fecha o arquivo de texto
	fclose(arquivo);
	return vet_produtos;
}
//Funcao que permite escrever no arquivo de texto
void escreverAquivo(produto *vet_produtos, int *tam_vet_produtos){
    //Abre o arquivo de texto para escrever no arquivo
    FILE *arquivo1 = fopen("controleDeEstoque.txt", "w");
    
    //Testa se foi possível abrir/criar arquivo de texto
    if(arquivo1 == NULL){
		printf("Não foi possível abrir o arquivo!");
		return;
	}
    
    //Salva na primeira linha do arquivo de texto o tamanho do vetor
    fprintf(arquivo1,"%d\n", *tam_vet_produtos);
    
    //Escreve todos os dados do vetor de produtos no arquivo de texto
    int i;
    for(i = 0; i < *tam_vet_produtos; i++){
        fprintf(arquivo1, "%d\n", vet_produtos[i].id);
        fprintf(arquivo1, "%s\n", vet_produtos[i].nome);
        fprintf(arquivo1, "%d\n", vet_produtos[i].quantidade);
        fprintf(arquivo1, "%.2lf\n", vet_produtos[i].preco);
    }
    //Fecha o arquivo de texto
    fclose(arquivo1);
}

//Funcao que permite cadastrar produtos
produto* cadastroProduto(produto *vet_produtos, int *tam_vet_produtos){
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
    for(i=0; i < *tam_vet_produtos; i++){
		if(strcmp(vet_produtos[i].nome, nome) == 0){
			system("clear");
			printf("Produto ja existe!\n\n\n");
			return vet_produtos;
		}
		if(id == vet_produtos[i].id){
			system("clear");
			printf("ID do produto ja existe!\n\n\n");
			return vet_produtos;
		}
	}
    
    //Realiza a alocacao
    if(*tam_vet_produtos == 0){
        vet_produtos = (produto*) malloc(sizeof(produto));
        (*tam_vet_produtos)++;
    }else{
        vet_produtos = (produto*) realloc(vet_produtos, sizeof(produto) * (*tam_vet_produtos + 1));
        (*tam_vet_produtos)++;
    }
    //Verifica se foi possivel alocar memoria
    if(vet_produtos == 0){
        printf("Erro ao alocar memoria");
        return vet_produtos;
    }
    
    //Passa as informacoes obtidas para o vetor de struct
    vet_produtos[*tam_vet_produtos - 1].id = id;
    strcpy(vet_produtos[*tam_vet_produtos - 1].nome, nome);
    vet_produtos[*tam_vet_produtos - 1].quantidade = quantidade;
    vet_produtos[*tam_vet_produtos - 1].preco = preco;
    
    system("clear");
    printf("Sucesso ao cadastrar o produto %s!\n\n", vet_produtos[*tam_vet_produtos - 1].nome);
    printf("-----------------------------------\n\n\n");
    return vet_produtos;
}
//Funcao que permite remover produtos
produto* removeProduto(produto *vet_produtos, int *tam_vet_produtos){
	system("clear");
	//Se o vetor estiver vazio imprime a mensagem abaixo
	if(*tam_vet_produtos == 0){
		printf("Nenhum produto cadastrado!\n\n");
		printf("-----------------------------------\n\n\n");
		return vet_produtos;
	}
	char nome[60];
	int i;
	printf("Nome do produto que deseja remover: ");
    scanf(" %59[^\n]", nome);
    
    //Percorre o vetor de struct e procura um nome igual ao nome digitado e remove todas as informações referentes a ele
    for(i=0; i < *tam_vet_produtos; i++){
		if(strcmp(nome, vet_produtos[i].nome) == 0){
			//Pega o ultimo elemento do vetor e copia para a posicao na qual está o produto que será removido
			vet_produtos[i].id = vet_produtos[*tam_vet_produtos-1].id;
			strcpy(vet_produtos[i].nome, vet_produtos[*tam_vet_produtos-1].nome);
			vet_produtos[i].quantidade = vet_produtos[*tam_vet_produtos-1].quantidade;
			vet_produtos[i].preco = vet_produtos[*tam_vet_produtos-1].preco;
			
			//Realoca o vetor, diminuindo seu tamanho
			vet_produtos = (produto*) realloc(vet_produtos, sizeof(produto) * (*tam_vet_produtos-1));
			(*tam_vet_produtos)--;
			printf("Sucesso ao remover o produto!\n\n");
			printf("-----------------------------------\n\n\n");
			return vet_produtos;
		}
	}
	printf("Produto nao encontrado!\n\n");
	printf("-----------------------------------\n\n\n");
	return vet_produtos;
}
//Função que permite informar uma quantidade de retirada de certo produto do estoque
produto* retiradaEstoque(produto *vet_produtos, int *tam_vet_produtos){
	system("clear");
	//Se o vetor estiver vazio imprime a mensagem abaixo
	if(*tam_vet_produtos == 0){
		printf("Nenhum produto cadastrado!\n\n");
		printf("-----------------------------------\n\n\n");
		return vet_produtos;
	}
    char nome[60];
    int quantidadeNova;
    
    printf("Digite o nome do produto para retirar estoque: ");
    scanf(" %59[^\n]", nome);
    printf("Digite a quantidade de produtos para retirar: ");
    scanf(" %d", &quantidadeNova);
    
    //Percorre todo o vetor dos produtos ja cadastrados procurando o nome igual ao digitado e adiciona a quantidade
    // informada na quantidade do produto que já existe
    int i, count = 0;
    for(i=0; i < *tam_vet_produtos; i++){
		if(strcmp(vet_produtos[i].nome, nome) == 0){
			if(vet_produtos[i].quantidade >= quantidadeNova){
				vet_produtos[i].quantidade -= quantidadeNova;
				count++;
			}else{
				system("clear");
				printf("Quantidade no estoque é insuficiente! \n\n");
				printf("Quantidade em estoque: %d \n\n", vet_produtos[i].quantidade);
				printf("-----------------------------------\n\n\n");
				return vet_produtos;
			}
		}
	}
	//Se não entrar nenhuma vez no IF do FOR é porque não existe nenhum produto cadastrado com o nome que foi informado
	if(count == 0){
		system("clear");
		printf("Nenhum produto cadastrado com o nome informado! \n\n");
		printf("-----------------------------------\n\n\n");
		return vet_produtos;
	}
	//Mensagem de sucesso retirar do estoque
    system("clear");
    printf("Sucesso ao retirar produto do estoque!\n\n");
    printf("-----------------------------------\n\n\n");
    return vet_produtos;
}
//Funçao que permite adicionar uma compra de um produto (aumentar a quantidade de certo produto)
produto* compra(produto *vet_produtos, int *tam_vet_produtos){
	system("clear");
	//Se o vetor estiver vazio imprime a mensagem abaixo
	if(*tam_vet_produtos == 0){
		printf("Nenhum produto cadastrado!\n\n");
		printf("-----------------------------------\n\n\n");
		return vet_produtos;
	}
    char nome[60];
    int quantidadeNova;
    
    printf("Digite o nome do produto que foi realizada a compra: ");
    scanf(" %59[^\n]", nome);
    printf("Digite a quantidade de produtos adquiridos na compra: ");
    scanf(" %d", &quantidadeNova);
    
    //Percorre todo o vetor dos produtos ja cadastrados procurando o nome igual ao digitado e adiciona a quantidade
    // informada na quantidade do produto que já existe
    int i, count = 0;
    for(i=0; i < *tam_vet_produtos; i++){
		if(strcmp(vet_produtos[i].nome, nome) == 0){
			vet_produtos[i].quantidade += quantidadeNova;
			count++;
		}
	}
	//Se não entrar nenhuma vez no IF do FOR é porque não existe nenhum produto cadastrado com o nome que foi informado
	if(count == 0){
		system("clear");
		printf("Nenhum produto cadastrado com o nome informado! \n\n");
		printf("-----------------------------------\n\n\n");
		return vet_produtos;
	}
	//Mensagem de sucesso ao adicionar compra
    system("clear");
    printf("Sucesso ao adicionar compra!\n");
    printf("-----------------------------------\n\n\n");
	return vet_produtos;
}
//Função que imprime todos os produtos que estiverem em falta (quantidade == 0)
void imprimirProdutosEmFalta(produto *vet_produtos, int *tam_vet_produtos){
    system("clear");
	
	//Se o vetor estiver vazio imprime a mensagem abaixo
	if(*tam_vet_produtos == 0){
		printf("Nenhum produto cadastrado!\n\n");
		printf("-----------------------------------\n\n\n");
		return;
	}
	//Percorre o vetor de strutc e exibe as informações onde a quantidade for igual a 0
	int i, count = 0;
	for(i=0; i < *tam_vet_produtos; i++){
		if(vet_produtos[i].quantidade == 0){
			printf("Produtos em falta: \n\n");
			printf("ID: %d\n", vet_produtos[i].id);
			printf("Nome: %s\n", vet_produtos[i].nome);
			printf("Quantidade: %d\n", vet_produtos[i].quantidade);
			printf("Preco: %.2f\n", vet_produtos[i].preco);
			printf("\n\n");
			count++;
		}
	}
	//Se não entrar nenhuma vez no IF do FOR é porque não existe nenhum produto em falta, logo, exibe a mensagem abaixo
	if(count == 0){
		printf("Nenhum produto em falta! \n\n");
	}
	printf("-----------------------------------\n\n\n");	
    
}
//Funcao que imprime todos os produtos
void imprimirTodos(produto *vet_produtos, int *tam_vet_produtos){
	system("clear");
	//Se o vetor estiver vazio imprime a mensagem abaixo
	if(*tam_vet_produtos == 0){
		printf("Nenhum produto cadastrado!\n\n");
		printf("-----------------------------------\n\n\n");
		return;
	}
	//Percorre o vetor de strutc e exibe todo o conteúdo existente nele
	int i;
	for(i=0; i < *tam_vet_produtos; i++){
		printf("ID: %d\n", vet_produtos[i].id);
		printf("Nome: %s\n", vet_produtos[i].nome);
		printf("Quantidade: %d\n", vet_produtos[i].quantidade);
		printf("Preco: %.2f\n", vet_produtos[i].preco);
		printf("\n\n");
	}
	printf("-----------------------------------\n\n\n");	
}
