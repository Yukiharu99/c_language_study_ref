#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuração da lista
struct node{
  struct node *prox;
  int value;
};
typedef struct node lista;

// Insere um novo elemento no início da lista
void insere(int num, lista **inicio){
  lista *novo = (lista*)malloc(sizeof(lista));
  novo->value = num;
  novo->prox = *inicio;
  *inicio = novo;
}

// Obtem os valores armazenados no .txt e os insere chamando a função de inserção
void preencher(FILE *fonte, lista **destino){
  char value[11];

  while (fgets(value, sizeof(value), fonte)) {
    insere(atoi(value), destino);
  }
}

// Imprime a lista
void imprime(lista *inicio){
  lista *aux = inicio;
  while (aux != NULL){
    printf("%d ", aux->value);
    aux = aux->prox;
  }
}

int main(int argc, char const *argv[]) {
  FILE *arquivo;
  lista *inicio = (lista*)malloc(sizeof(lista));
  inicio = NULL;

  // Tenta abrir o arquivo .txt no modo binário somente leitura
  arquivo = fopen("lista.txt", "rb");
  if (arquivo == NULL) {
    perror("Falha ao carregar arquivo");
  } else {
    // Chama as funções de leitura e inserção, imprimindo caso bem sucedido
    preencher(arquivo, &inicio);
    imprime(inicio);
  }

  // Limpa o buffer do arquivo carregado
  fclose(arquivo);

  return 0;
}
