#include <stdio.h>
#include <string.h>

int main(void){
  FILE *arquivo; // Ponteiro do tipo FILE
  char *texto; // String para escrita

  /* Tenta abrir e armazenar o arquivo "teste.txt" no buffer e atribui seu
  endereço ao ponteiro FILE */
  // "w" define que o arquivo será aberto no modo escrita
  if ((arquivo = fopen("teste.txt","w")) == NULL) {
    perror("O seguinte erro ocorreu"); // Mostra o erro registrado no "errno"
    puts("Falha ao abrir o arquivo!"); // O arquivo não pode ser aberto
  } else {
    puts("Arquivo aberto com sucesso!\n"); // O arquivo pode ser aberto
    printf("Insira o texto para ser salvo: \n\t");
    scanf("%[^\n]", texto);
    /* fwrite(const void * ptr, size_t size, size_t count, FILE * stream)
    escreve uma quantidade "count" de elementos de "size" bytes do array de
    elementos do ponteiro "ptr" no arquivo "stream" */
    fwrite(texto, sizeof(char), strlen(texto), arquivo);
  }
  // Fecha arquivo quando não é mais necessário e esvazia o buffer
  fclose(arquivo);

  return 0;
}
