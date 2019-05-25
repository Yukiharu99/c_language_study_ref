#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  FILE *arquivo; // Ponteiro do tipo FILE
  long txt_size; // Tamanho do texto
  char* buffer; // String para armazenar o texto
  unsigned int readed_txt_size; // Número de elementos lidos do arquivo

  /* Tenta abrir e armazenar o arquivo "teste.txt" no buffer e atribui seu
  endereço ao ponteiro FILE */
  /* "r" define que o arquivo será aberto no modo leitura apenas e "b" define
  o modo de leitura como binário */
  if ((arquivo = fopen("teste.txt","rb")) == NULL) {
    perror("O seguinte erro ocorreu"); // Mostra o erro registrado no "errno"
    puts("Falha ao abrir o arquivo!"); // O arquivo não pode ser aberto
  } else {
    puts("Arquivo aberto com sucesso!\n"); // O arquivo pode ser aberto

  // Obtendo o tamanho do arquivo de texto
    fseek(arquivo, 0, SEEK_END); // EOF == End-Of-File
    /* int fseek ( FILE * stream, long int offset, int origin );
    Posiciona o ponteiro FILE "stream" na posição de uma distancia "offset" da
    direita para a esquerda em relação a posição "origin". Caso a operação seja
    bem sucedida retorna 0 senão retorna um valor não nulo */
    txt_size = ftell(arquivo);
    /* long int ftell ( FILE * stream );
    Retorna a atual posição do ponteiro FILE "stream" caso a operação seja bem
    sucedida, caso não seja retorna um valor long negativo */
    rewind(arquivo);
    /* void rewind ( FILE * stream );
    Retorna o ponteiro FILE "stream" para o início do arquivo */

  // Alocação de memória para armazenar o arquivo inteiro
    buffer = (char*)malloc(sizeof(char)*txt_size); // Alocação dinâmica
    if(buffer == NULL){ // Caso não consiga alocar
      // Retorna o erro e finaliza o programa com o código de erro 2;
      fputs("Erro de memoria", stderr);
      exit(2);
    }

  // Copiar o arquivo para o buffer
      readed_txt_size = fread(buffer, 1, txt_size, arquivo);
      printf("readed_txt_size = %d\ntxt_size = %d\n", readed_txt_size, txt_size);
      if (readed_txt_size != txt_size) {
        fputs("Erro de leitura", stderr);
        exit(3);
      }

  // Imprime o texto
    puts(buffer);
  }
  // Fecha arquivo quando não é mais necessário e o buffer é esvaziado
  fclose(arquivo);

  return 0;
}
