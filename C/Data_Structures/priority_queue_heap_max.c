#include <stdio.h>

void heapfica(int fila[], int index, int tam){
  int filho_esq, filho_dir, maior, aux;
  maior = index;
  if (2*index + 1 <= tam) {
    // O nó analizado tem filhos para a esquerda e direita
    filho_esq = 2*index;
    filho_dir = 2*index + 1;
    if (fila[filho_esq] >= fila[filho_dir] && fila[filho_esq] > fila[index]){
      maior = filho_esq;
    } else if(fila[filho_dir] >= fila[filho_esq] && fila[filho_dir] > fila[index]){
      maior = filho_dir;
    }
  } else if (2*index <= tam) {
    // O nó analizado tem apenas filho para a esquerda
    filho_esq = 2*index;
    if (fila[filho_esq] > fila[index]) {
      maior = filho_esq;
    }
  }
  if (maior != index) {
    // Se o nó colocado na raiz não for o maior então realiza troca
    aux = fila[index];
    fila[index] = fila[maior];
    fila[maior] = aux;
    /* Continua a verificar a posição até que se chegue ao final da lista
    (era o menor) ou até achar a posição correta */
    heapfica(fila, maior, tam);
  }
}

void insere(int fila[], int index, int num){
  while (index > 1 && fila[index/2] < num) { // Heap Máximo, o pai é maior que os filhos
    if (fila[index/2] < num) { // Se o pai for menor que o filho que seria inserido
      // Copia o pai para a posição do novo elemento e muda o indice para o do pai
      fila[index] = fila[index/2];
      index = index/2;
    }
  }
  fila[index] = num;
}

void remover(int fila[], int tam){
  fila[1] = fila[tam];
  heapfica(fila, 1, tam - 1);
}

int main(void){
  int fila[11];
  int index, tam = 0, num, op;

  do {
    puts("1 - Inserir\n2 - Remover\n3 - Consultar\n0 - Sair");
    scanf("%d", &op);
    printf("\n");
    switch (op) {
      case 1:
        if (tam < 10) {
          printf("Numero: ");
          scanf("%d", &num);
          ++tam;
          index = tam;
          insere(fila, index, num);
          printf("\n");
        } else {
          puts("Fila cheia!");
        }
        break;
      case 2:
        if (tam != 0) {
          remover(fila, tam);
          --tam;
          printf("\n");
        } else {
          puts("Fila vazia!");
        }
        break;
      case 3:
        if (tam != 0) {
          for (int i = 1; i <= tam; i++)
            printf("%d ", fila[i]);
          printf("\n\n");
        } else {
          puts("Fila vazia!");
        }
        break;
    }
  } while(op != 0);
}
