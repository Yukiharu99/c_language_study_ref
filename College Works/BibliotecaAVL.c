#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct node{
  struct node *dir, *esq;
  int altd, alte, idLivro, idPessoa, retirado;
  char nome[51], autor[51];
};
typedef struct node arvore;

struct Pessoa{
  int id;
  char usuario[21], senha[9]; // Dados de login
  struct Pessoa *prox;
  arvore *retirados[3];
};
typedef struct Pessoa usuarios;

void logar(char nome[], char senha[], usuarios *lista, usuarios **sessaoAtual){
  usuarios *aux = lista;
  int achou = 0;
  while (aux != NULL && achou != 1) {
    if (strcmp(aux->usuario, nome) == 0 && strcmp(aux->senha, senha) == 0){
        achou = 1;
    } else
      aux = aux->prox;
  }
  if (achou == 1) { // Login bem sucedido
    *sessaoAtual = aux; // Endereço de memórioa do usuário logado
  } else { // Nome ou senha errado!
    *sessaoAtual = NULL;
  }
}

usuarios* buscaUsuario(usuarios *lista, int id){
  usuarios *aux = lista;
  while (aux != NULL) {
    if (aux->id == id)
      return aux;
    else
      aux = aux->prox;
  }
}

arvore* rotacaoDireita(arvore *node){
  arvore *aux1, *aux2;
  aux1 = node->esq;
  aux2 = aux1->dir;
  node->esq = aux2;
  aux1->dir = node;
  if (node->esq == NULL) {
    node->alte = 0;
  } else if ((node->esq)->alte > (node->esq)->altd) {
    node->alte = (node->esq)->alte + 1;
  } else {
    node->alte = (node->esq)->altd + 1;
  }
  if ((aux1->dir)->alte > (aux1->dir)->altd) {
    aux1->altd = (aux1->dir)->alte + 1;
  } else {
    aux1->altd = (aux1->dir)->altd + 1;
  }
  return aux1;
}

arvore* rotacaoEsquerda(arvore *node){
  arvore *aux1, *aux2;
  aux1 = node->dir;
  aux2 = aux1->esq;
  node->dir = aux2;
  aux1->esq = node;
  if (node->dir == NULL) {
    node->altd = 0;
  } else if ((node->dir)->alte > (node->dir)->altd) {
    node->altd = (node->dir)->alte + 1;
  } else {
    node->altd = (node->dir)->altd + 1;
  }
  if ((aux1->esq)->alte > (aux1->esq)->altd) {
    aux1->alte = (aux1->esq)->alte + 1;
  } else {
    aux1->alte = (aux1->esq)->altd + 1;
  }
  return aux1;
}

arvore* balancear(arvore *node){
  int d, df;
  d = node->altd - node->alte;
  if (d == 2) {
    df = (node->dir)->altd - (node->dir)->alte;
    if (df >= 0) {
      node = rotacaoEsquerda(node);
    } else {
      node->dir = rotacaoDireita(node->dir);
      node = rotacaoEsquerda(node);
    }
  } else if(d == -2) {
    if (df <= 0) {
      node = rotacaoDireita(node);
    } else {
      node->esq = rotacaoEsquerda(node->esq);
      node = rotacaoDireita(node);
    }
  }
  return node;
}

arvore* insere(arvore *node, int id, char nome[], char autor[]){
  if (node == NULL) { // nova folha
    arvore *novo = (arvore*)malloc(sizeof(arvore));
    novo->esq = novo->dir = NULL;
    novo->alte = novo->altd = 0;
    novo->idLivro = id;
    strcpy(novo->nome, nome);
    strcpy(novo->autor, autor);
    novo->idPessoa = -1; // ID da pessoa que fez o empréstimo
    novo->retirado = 0; // Disponível para empréstimo
    node = novo;
  } else if (id < node->idLivro) {
    node->esq = insere(node->esq, id, nome, autor);
    if ((node->esq)->alte < (node->esq)->altd) {
      /* Se a altura esquerda do filho esquerdo for menor que a do lado
      direito, então a altura esquerda do pai é a altura direita do filho
      esquerdo + 1*/
      node->alte = (node->esq)->altd + 1;
    } else {
      /* Se a altura esquerda do filho esquerdo for maior que a do lado
      esquerdo, então a altura esquerda do pai é a altura esquerda do filho
      esquerdo + 1*/
      node->alte = (node->esq)->alte + 1;
    }
    node = balancear(node);
  } else {
    node->dir = insere(node->dir, id, nome, autor);
    if ((node->dir)->alte < (node->dir)->altd) {
      /* Se a altura esquerda do filho direito for menor que a do lado
      direito, então a altura direita do pai é a altura direita do filho
      direito + 1*/
      node->altd = (node->dir)->altd + 1;
    } else {
      /* Se a altura esquerda do filho direito for maior que a do lado
      direito, então a altura direita do pai é a altura esquerda do filho
      direito + 1*/
      node->altd = (node->dir)->alte + 1;
    }
    node = balancear(node);
  }
  return node;
}

arvore* procuraMenor(arvore* atual){
  arvore *aux1 = atual, *aux2 = atual->esq;
  while (aux2 != NULL) {
    aux1 = aux2;
    aux2 = aux2->esq;
  }
  return aux1;
}

void attAlturasRemocao(arvore** node){
  arvore *dir, *esq;
  dir = (*node)->dir;
  esq = (*node)->esq;
  if (dir == NULL) {
    (*node)->altd = 0;
  } else if (dir->alte < dir->altd) {
    (*node)->altd = dir->altd + 1;
  } else {
    (*node)->altd = dir->alte + 1;
  }
  if (esq == NULL) {
    (*node)->alte = 0;
  } else if (esq->alte < esq->altd) {
    (*node)->alte = esq->altd + 1;
  } else {
    (*node)->alte = esq->alte + 1;
  }
}

int removeAVL(arvore** node, int alvo){
  if (*node == NULL) { // Valor não existe
    printf("Valor inexistente!\n");
    return 0;
  }
  int retorno;
  if (alvo < (*node)->idLivro) {
    if ((retorno = removeAVL(&(*node)->esq, alvo)) == 1) {
      attAlturasRemocao(node);
      *node = balancear(*node);
    }
  } else if (alvo > (*node)->idLivro) {
    if ((retorno = removeAVL(&(*node)->dir, alvo)) == 1) {
      attAlturasRemocao(node);
      *node = balancear(*node);
    }
  } else {
    arvore *aux;
    if ((*node)->esq == NULL || (*node)->dir == NULL) {
      aux = *node;
      if ((*node)->esq != NULL) {
        *node = (*node)->esq;
      } else {
        *node = (*node)->dir;
      }
      free(aux);
    } else { // O nó possui dois filhos
      aux = procuraMenor((*node)->dir); // Procurar o menor valor da sub arvore direita
      (*node)->idLivro = aux->idLivro;
      (*node)->idPessoa = aux->idPessoa;
      (*node)->retirado = aux->retirado;
      strcpy((*node)->nome, aux->nome);
      strcpy((*node)->autor, aux->autor);
      removeAVL(&(*node)->dir, (*node)->idLivro);
      attAlturasRemocao(node);
      *node = balancear(*node);
    }
    return 1;
  }
  return retorno; // Retorna 1 caso a remoção foi concluída com êxito e 0 caso não
}

int verifEstado(arvore *node, int id, int retirado) {
  if (node != NULL && retirado == 0) {
    if (node->idLivro == id) {
      if (node->retirado == 1)
        retirado = 1;
      else
        return 0;
    } else if (node->idLivro < id)
      retirado = verifEstado(node->dir, id, retirado);
    else
      retirado = verifEstado(node->esq, id, retirado);
  }
  return retirado;
}

void consultarTodos(arvore* node){
  if(node != NULL){
    consultarTodos(node->esq);
    printf("ID: %d\nNome: %s\nAutor: %s\n", node->idLivro, node->nome, node->autor);
    if (node->retirado == 1)
      printf("Estado: retirado pelo usuario %d\n\n", node->idPessoa);
    else
      printf("Estado: disponivel\n\n");
    consultarTodos(node->dir);
  }
}

void consultarTodosRetirados(arvore* node){
  if(node != NULL){
    consultarTodosRetirados(node->esq);
    if (node->retirado == 1) {
      printf("ID: %d\nNome: %s\nAutor: %s\n", node->idLivro, node->nome, node->autor);
      printf("Retirado pelo usuario: %d\n\n", node->idPessoa);
    }
    consultarTodosRetirados(node->dir);
  }
}

void consultarPorID(arvore *node, int id, int achou){
  if (achou == 1) {
    return;
  } else {
    if(node != NULL){
      consultarPorID(node->esq, id, achou);
      if (node->idLivro == id) {
        printf("ID: %d\nNome: %s\nAutor: %s\n", node->idLivro, node->nome, node->autor);
        if (node->retirado == 1)
          printf("Estado: retirado pelo usuario %d\n\n", node->idPessoa);
        else
          printf("Estado: disponivel\n\n");
        achou = 1;
      }
      consultarPorID(node->dir, id, achou);
    }
  }
}

void consultarRetiradosUsuario(usuarios *usuarioAtual) {
  int i;
  for (i = 0; i < 3; i++) {
    if (usuarioAtual->retirados[i] != NULL) {
      printf("ID: %d\nNome: %s\nAutor: %s\n\n", (usuarioAtual->retirados[i])->idLivro, (usuarioAtual->retirados[i])->nome, (usuarioAtual->retirados[i])->autor);
    }
  }
}

void retiraLivro(arvore *node, int id, int achou, usuarios *usuarioAtual){
  if(achou == 1) {
    return;
  } else if (node != NULL) {
    retiraLivro(node->esq, id, achou, usuarioAtual);
    if (node->idLivro == id) {
      achou = 1;
      if (node->retirado == 0){
        int i;
        for (i = 0; i < 3; i++) {
          if (usuarioAtual->retirados[i] == NULL) {
            usuarioAtual->retirados[i] = node;
            node->retirado = 1;
            node->idPessoa = usuarioAtual->id;
            break;
          }
        }
        if (i == 3)
          puts("Limite atingido, (max. 3) devolva um livro antes de retirar este!");
        else
          puts("Retirado com sucesso!");
      }
      return;
    }
    retiraLivro(node->dir, id, achou, usuarioAtual);
  }
}

void devolverLivro(usuarios *usuarioAtual, int id) {
  int i;
  for (i = 0; i < 3; i++) {
    if ((usuarioAtual->retirados[i])->idLivro == id) {
      (usuarioAtual->retirados[i])->retirado = 0;
      (usuarioAtual->retirados[i])->idPessoa = -1;
      usuarioAtual->retirados[i] = NULL;
      return;
    }
  }
}

int verifUsuario(usuarios *listaUsuarios, char usuario[]){
  usuarios *aux = listaUsuarios;
  while (aux != NULL) {
    if (!strcmp(aux->usuario, usuario))
      return 1; // Usuário com o mesmo nome de acesso
    aux = aux->prox;
  }
  return 0; // Não existe outro usuário com o mesmo nome de acesso
}

void cadastraUsuario(usuarios *listaUsuarios, char usuario[], char senha[], int id){
  int i;
  usuarios *novo = (usuarios*)malloc(sizeof(usuarios));
  strcpy(novo->usuario, usuario);
  strcpy(novo->senha, senha);
  for (i = 0; i < 3; i++)
    novo->retirados[i] = NULL;
  novo->prox = NULL;
  novo->id = id;
  usuarios *aux = listaUsuarios;
  while (aux->prox != NULL)
    aux = aux->prox;
  aux->prox = novo;
}

int main() {
  // Variáveis auxiliares
  int aux, op, qtdUsuarios = 1, qtdLivros = 0;
  usuarios *usuarioAtual = NULL;
  char c, usuario[21], senha[9], nome[51], autor[51];
  // Inicio da lista de usuários e criação do usuário padrão.
  usuarios *listaUsuarios = (usuarios*)malloc(sizeof(usuarios));
  strcpy(listaUsuarios->usuario, "admin");
  strcpy(listaUsuarios->senha, "admin");
  listaUsuarios->id = 0;
  listaUsuarios->prox = NULL;
  listaUsuarios->retirados[0] = listaUsuarios->retirados[1] = listaUsuarios->retirados[2] = NULL;
  // Criação da árvore AVL de livros
  arvore *raizLivros = NULL;

  do { // Login ou cadastro de usuário
    puts("1 - Logar");
    puts("2 - Cadastrar-se");
    puts("0 - Sair");
    do {
      scanf("%d%*c", &op);
      system("cls");
    } while(op < 0 || op > 3);

    switch (op) {
      case 1: // Cadastro de usuário
        printf("Usuario: ");
        scanf(" %20[^\n]", usuario);
        while((c = getchar()) != '\n' && c != EOF); // Limpeza de buffer
        printf("Senha: ");
        scanf(" %9[^\n]", senha);
        while((c = getchar()) != '\n' && c != EOF);
        logar(usuario, senha, listaUsuarios, &usuarioAtual);
        if(usuarioAtual != NULL){
          do {
            puts("1 - Retirar livro OK");
            puts("2 - Consultar todos os livros OK");
            puts("3 - Consultar por ID OK");
            puts("4 - Consultar meus livros retirados OK");
            puts("5 - Consultar todos os livros retirados OK");
            puts("6 - Inserir livro OK");
            puts("7 - Devolver livro");
            puts("8 - Remover livro OK");
            puts("0 - Deslogar");
            do {
              scanf("%d%*c", &op);
            } while(op < 0 || op > 8);
            system("cls");
            switch (op) {
              case 1:
                puts("OBS.: Para voltar insira um valor negativo!");
                puts("OBS.: Uma mensangem de exito aparecera em caso de sucesso!");
                printf("ID do livro a ser retirado: ");
                scanf("%d%*c", &aux);
                if (aux >= 0)
                retiraLivro(raizLivros, aux, 0, usuarioAtual);
                break;
              case 2:
                consultarTodos(raizLivros);
                break;
              case 3:
                puts("OBS.: Para voltar insira um valor negativo!");
                printf("ID do livro a ser procurado: ");
                scanf("%d%*c", &aux);
                if (aux >= 0)
                  consultarPorID(raizLivros, aux, 0);
                break;
              case 4:
                consultarRetiradosUsuario(usuarioAtual);
                break;
              case 5:
                consultarTodosRetirados(raizLivros);
                break;
              case 6:
                printf("Nome do livro: ");
                scanf(" %50[^\n]", nome);
                while((c = getchar()) != '\n' && c != EOF);
                printf("Nome do autor: ");
                scanf(" %50[^\n]", autor);
                while((c = getchar()) != '\n' && c != EOF);
                raizLivros = insere(raizLivros, qtdLivros, nome, autor);
                qtdLivros++;
                break;
              case 7:
                puts("OBS.: Para voltar insira um valor negativo!");
                printf("ID do livro a ser devolvido: ");
                scanf("%d%*c", &aux);
                if (aux >= 0)
                  devolverLivro(usuarioAtual, aux);
                break;
              case 8:
                puts("OBS.: Para voltar insira um valor negativo!");
                printf("ID do livro a ser removido: ");
                scanf("%d%*c", &aux);
                  if (aux >= 0) {
                    if (!verifEstado(raizLivros, aux, 0))
                      removeAVL(&raizLivros, aux);
                    else
                      puts("Este livro nao pode ser removido, pois ainda nao foi devolvido!");
                  }
                break;
            }
          } while(op != 0);
          op = 1;
        } else
          puts("Usuario ou senha incorretos!");
          break;
        case 2:
          do {
            printf("Nome de usuario (max. 20 caracteres): ");
            scanf(" %20[^\n]", usuario);
            while((c = getchar()) != '\n' && c != EOF);
          } while(verifUsuario(listaUsuarios, usuario));
          printf("Senha (max. 8 caracteres): ");
          scanf("%8[^\n]", senha);
          while((c = getchar()) != '\n' && c != EOF);
          cadastraUsuario(listaUsuarios, usuario, senha, qtdUsuarios);
          qtdUsuarios++;
          break;
    }
  } while(op != 0);

  return 0;
}
