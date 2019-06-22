#include <stdio.h>
#include <stdlib.h>

struct elem {
   int valor;
   struct elem *anterior;
   struct elem *proximo;
};
typedef struct elem elemento;

/*
Aloca memória para um novo elemento, grava 'valor' neste novo elemento, e coloca
depois do elemento 'e'. Para isso os ponteiros 'anterior' e 'proximo' dos 
elementos envolvidos devem ser atualizados, como mostra a figura abaixo:

             +----+                              +----+
   ANTES     |    |+---------------------------->|    |
             |    |<----------------------------+|    |
             +----+                              +----+
               e                               e->proximo


             +----+            +----+            +----+
   DEPOIS    |    |+---------->|    |+---------->|    |
             |    |<----------+|    |<----------+|    |
             +----+            +----+            +----+
               e                novo           e->proximo

Pseudocódigo:
   aloque memória para o novo elemento 
   grave 'valor' (recebido como parâmetro) no campo valor do novo elemento
   faça o campo anterior do novo elemento apontar para o elemento 'e'
   faça o campo próximo do novo elemento apontar para o próximo de 'e'
   se 'e' tem próximo (campo não nulo)
      faça o campo anterior do próximo de 'e' apontar para o novo elemento  e->proximo->anterior = novo
   faça o campo próximo de 'e' apontar para o novo elemento

Obs. 1: O novo elemento deve ser alocado dinamicamente.
        Se usar variável local, ela será descartada ao encerrar a função.
Obs. 2: Lembre do operador -> (mais simples que (*p).campo).
*/
void lista_insere_apos(elemento *e, int valor){
	elemento *novo = (elemento*) malloc(sizeof(elemento));
	novo->valor = valor;
	novo->anterior = e;
	novo->proximo = e->proximo;
	if(e->proximo != 0){
		e->proximo->anterior = novo;
	}
	e->proximo = novo;
}

/*
Remove o elemento 'e' da lista, atualizando os ponteiros do elemento anterior e
posterior, e em seguida liberando a memória de 'e'.
A atualização de ponteiros é ilustrada na figura abaixo:

             +----+            +----+            +----+
   ANTES     |    |+---------->|    |+---------->|    |
             |    |<----------+|    |<----------+|    |
             +----+            +----+            +----+
           e->anterior           e             e->proximo

             +----+                              +----+
   DEPOIS    |    |+---------------------------->|    |
             |    |<----------------------------+|    |
             +----+                              +----+
           e->anterior                         e->proximo

Pseudocódigo:
   se 'e' é nulo, retorne
   se anterior de 'e' não é nulo
      faça o campo 'proximo' do anterior de 'e' apontar para o próximo de 'e'
   se próximo de 'e' não é nulo
      faça o campo 'anterior' do próximo de 'e' apontar para o anterior de 'e'
   libere a memória alocada para o elemento 'e'
*/
void lista_remove(elemento *e){
	if(e == 0){
		return;
	}
	if(e->anterior != 0){
		e->anterior->proximo = e->proximo;
	}
	if(e->proximo != 0){
		e->proximo->anterior = e->anterior;
	}
	free(e);
}

/*
Retorna endereço do primeiro elemento contendo 'valor' na lista. 
Retorna 0 se nenhum elemento for encontrado.

O elemento 'cabeca' é um elemento especial que não é utilizado para armazenar 
valores. Ele serve apenas para indicar o início da lista, como ilustra a figura:

  +----+            +----+            +----+                             +----+
  |    |+---------->|    |+---------->|    |+----------> ... +---------->|    |---> 0
  |    |<----------+|    |<----------+|    |<----------+ ... <----------+|    |
  +----+            +----+            +----+                             +----+
  cabeca           primeiro           segundo                            último

Como saber que a lista terminou?
Quando o elemento 'cabeca' é criado, o campo 'proximo' é inicializado com zero.
Assim, as funções de 'lista_insere_apos' e 'lista_remove' garantem que o
ponteiro 'proximo' do último elemento será zero.
Então, o último elemento será o único cujo campo 'proximo' vale zero.
*/
elemento *lista_busca(elemento *cabeca, int valor){
	elemento *e = cabeca->proximo;
	while(e != 0){
		if(e->valor == valor){
			return e;
		}
		e = e->proximo;
	}
	return 0;
}

/*
Imprime todos os valores armazenados na lista (um por linha).
*/
void lista_imprime(elemento *cabeca){
	elemento *e = cabeca->proximo;
	while(e != 0){
		printf("%d\n", e->valor);
		e = e->proximo;
	}
}

int main()
{
   int num_oper, i, valor;
   scanf("%d\n", &num_oper);

   elemento cabeca;
   cabeca.anterior = cabeca.proximo = 0;

   char oper;
   for (i = 0; i < num_oper; i++) {
      scanf("%c\n", &oper);
      scanf("%d\n", &valor);
      switch (oper) {
         case 'i': lista_insere_apos(&cabeca, valor);
                   break;
         case 'r': lista_remove(lista_busca(&cabeca, valor));
      }
   }

   lista_imprime(&cabeca);
   
   return 0;
}
