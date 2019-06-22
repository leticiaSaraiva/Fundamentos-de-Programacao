#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _CONTROLE_ESTOQUE
#define _CONTROLE_ESTOQUE

//Criacao de uma estrutura
struct produtos{
	int id;
    char nome[60];
    double preco;
    int quantidade;
};
typedef struct produtos produto;

//extern produto *vet_produtos; //Cria um ponteiro global do tipo produto (vetor de estrutura)
//extern int tam_vet_produtos; //Inicializa o tamanho do vetor com valor 0

//Protótipo da função que lê os dados do arquivo de texto
produto* lerArquivo(int *tam_vet_produtos); 

//Protótipo da função que escreve os dados no arquivo de texto
void escreverAquivo(produto *vet_produtos, int *tam_vet_produtos); 

//Protótipo da função que cadastra produtos
produto* cadastroProduto(produto *vet_produtos, int *tam_vet_produtos); 

//Protótipo da função que remove produtos cadastrados
produto* removeProduto(produto *vet_produtos, int *tam_vet_produtos); 

//Protótipo da função que permite fazer a retirada de uma quantidade de um produto
produto* retiradaEstoque(produto *vet_produtos, int *tam_vet_produtos); 

//Protótipo da função que permite realizar uma atualização da quantidade de produtos
produto* compra(produto *vet_produtos, int *tam_vet_produtos); 

//Protótipo da função que imprime todos os produtos que estão com a quantidade igual a zero
void imprimirProdutosEmFalta(produto *vet_produtos, int *tam_vet_produtos); 

//Protótipo da função que imprime todos os produtos cadastrados
void imprimirTodos(produto *vet_produtos, int *tam_vet_produtos); 

#endif

