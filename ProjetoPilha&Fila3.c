// -------------------------------------------------------------------- //
// ------------------- DESAFIO MESTRE - FASE 3 ------------------------ //
// OBJETIVO:
// -> DEIXAR O CODIGO TODO MODULARIZADO E IDENTADO;
// -> CRIAR AS FUNÇÕES -> PARA FILA & PILHA;
// -> CRIAR AS FUNÇÕES -> AS NOVAS TROCAR PEÇAS;
// -> DEFINIR O TAMANHO FIXO, AS BIBLIOTECAS, PARAMETROS;
// -------------------------------------------------------------------- //

#include <stdio.h> // INCLUI A BIBLIOTECA PADRÃO DE ENTRADA E SAÍDA
#include <stdlib.h> // INCLUI FUNÇÕES GERAIS
#include <string.h> // INCLUI FUNÇÕES DE MANIPULAÇÃO DE STRINGS
#include <time.h> // INCLUI FUNÇÕES RELACIONADAS AO -> Srand()

#define TAM_PILHA 3 // DEFINE O TAMANHO MÁXIMO DA PILHA
#define TAM_FILA 5 // DEFINE O TAMANHO MÁXIMO DA FILA
#define STRING 30 // DEFINE O TAMANHO MÁXIMO DAS STRINGS DAS PEÇAS
#define TAM_MAX TAM_FILA // DEFINE O TAMANHO MÁXIMO PARA PILHA AUXILIAR COMO O TAMANHO DA FILA PARA REVERSÃO

typedef struct { // STRUCT QUE REPRESENTA UMA PEÇA
  char Peca[STRING]; // NOME DA PEÇA
  int Id; // IDENTIFICADOR DA PEÇA
} Elementos;
typedef struct { // STRUCT DA FILA
  Elementos Pecas[TAM_FILA]; // ARRAY DE ELEMENTOS
  int Inicio, Fim, Total; // INDICES DE INÍCIO, FIM E TOTAL DE ELEMENTOS
} Fila;
typedef struct { // STRUCT DA PILHA
  Elementos Pecas[TAM_PILHA]; // ARRAY DE ELEMENTOS
  int Topo; // INDICE DO TOPO DA PILHA (-1 QUANDO VAZIA)
} Pilha;
typedef struct { // STRUCT DA PILHA AUXILIAR
    Elementos Pecas[TAM_MAX]; // ARRAY DE ELEMENTOS
    int Topo; // INDICE DO TOPO DA PILHA AUXILIAR
} PilhaAux;

// FUNÇÃO PARA LIMPAR O BUFFER DO TECLADO
void Limpar(){
  int a;
  while ((a = getchar()) != '\n' && a != EOF); // DESCARTA TODOS OS CARACTERES ATÉ O ENTER
}
// FUNÇÃO PARA MOSTRAR O MENU PRINCIPAL E RETORNAR A OPÇÃO ESCOLHIDA
int Menu(){
   int Escolha;
   printf("-----------------------------------------\n");
   printf("/////////// \"MENU PRINCIPAL\" ///////////\n");
   printf("-----------------------------------------\n");
   printf("1.JOGAR\n");
   printf("2.RESERVA PEÇAS\n");
   printf("3.USAR PEÇAS\n");
   printf("4.EXBIR PILHA & FILA\n");
   printf("5.TROCAR PEÇA\n");
   printf("6.TROCAR TODAS AS PEÇAS\n");
   printf("0.SAIR\n");
   printf("-----------------------------------------\n");
   printf("Digite Sua Opção: ");
   scanf("%d", &Escolha); // LÊ A OPÇÃO DO USUÁRIO
   Limpar(); // LIMPA O BUFFER PARA EVITAR ERROS
   return Escolha; // RETORNA A OPÇÃO ESCOLHIDA
}
// INICIALIZA FILA VAZIA
void InicializacaoFila(Fila *f){
  f->Fim = 0; // POSIÇÃO FINAL INICIAL
  f->Inicio = 0; // POSIÇÃO INICIAL
  f->Total = 0; // TOTAL DE ELEMENTOS
}
// INICIALIZA PILHA VAZIA
void InicializacaoPilha(Pilha *p){
  p->Topo = -1; // TOPO -1 SIGNIFICA PILHA VAZIA
}
// REMOVE O PRIMEIRO ELEMENTO DA FILA
Elementos Remover(Fila *f) {
    Elementos removido = f->Pecas[0]; // ARMAZENA O PRIMEIRO ELEMENTO
    for (int i = 0; i < f->Total - 1; i++){ // DESLOCA TODOS OS ELEMENTOS PARA A ESQUERDA
        f->Pecas[i] = f->Pecas[i + 1];
    }
    f->Total--; // DECREMENTA O TOTAL
    return removido; // RETORNA O ELEMENTO REMOVIDO
}
// EXIBE O CONTEÚDO DA FILA E DA PILHA
void ExibirFilaPilha(Fila *f, Pilha *p){
    if (f->Total == 0 && p->Topo == -1) return; // SE AMBOS VAZIOS, SAI
    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA FILA\" <-<-<-<-\n\n");
    for (int i = 0, rs = f->Inicio; i < f->Total; i++){
      printf("[%s, %d]\t", f->Pecas[i].Peca, f->Pecas[i].Id); // MOSTRA CADA ELEMENTO DA FILA
    }
    printf("\n----------------------------------------\n");

    if (p->Topo != -1){ // SE PILHA NÃO VAZIA
        printf("  ->->->-> \"PEÇAS DA PILHA\" <-<-<-<-\n\n");
        for (int a = p->Topo; a >= 0; a--){
          printf("[%s, %d]\t", p->Pecas[a].Peca, p->Pecas[a].Id); // MOSTRA PILHA DO TOPO AO FUNDO
        }
        printf("\n----------------------------------------\n");
    }
}
// JOGA UMA PEÇA DA FILA
int Jogar(Fila *f, Elementos *p){
    if (f->Total == 0){
      printf("Fila Vazia, Adicione Uma Nova Peça!\n");
      return 1; // RETORNA ERRO SE FILA VAZIA
    }
    f->Total--; // DECREMENTA TOTAL
    *p = f->Pecas[f->Inicio]; // ARMAZENA ELEMENTO EM 'p'
}
// EXIBE SOMENTE A FILA
void Exibir(Fila *f){
    if (f->Total == 0) return; // SE VAZIA, SAI
    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA FILA\" <-<-<-<-\n\n");
    for (int i = 0; i < f->Total; i++){
      printf("[%s, %d]\t", f->Pecas[i].Peca, f->Pecas[i].Id);
    }
    printf("\n----------------------------------------\n");
}
// ADICIONA ELEMENTO NO FINAL DA FILA
void Adicionar(Fila *f, Elementos e){
    if (f->Total == TAM_FILA) return; // SE FILA CHEIA, NÃO FAZ NADA
    f->Pecas[f->Total++] = e; // ADICIONA ELEMENTO
}
// GERA PEÇAS ALEATÓRIAS PARA A FILA
void GerarPecas(Fila *f){
    char base[] = {'I','O','T','L','|'}; // POSSÍVEIS PEÇAS
    while (f->Total < TAM_FILA){
        Elementos e;
        e.Peca[0] = base[rand() % 5]; // ESCOLHE LETRA ALEATÓRIA
        e.Peca[1] = '\0'; // TERMINADOR DE STRING
        e.Id = rand() % 5; // ID ALEATÓRIO
        Adicionar(f, e); // ADICIONA NA FILA
    }
}
// FUNÇÕES DE PILHA
void Push(Pilha *p, Elementos pes){
  if(p->Topo == TAM_PILHA -1) return; // SE PILHA CHEIA, NÃO FAZ NADA
  p->Pecas[++p->Topo] = pes; // INCREMENTA TOPO E COLOCA ELEMENTO
}
Elementos Pop(Pilha *p){
  Elementos v = {"", -1}; // ELEMENTO VAZIO DEFAULT
  if (p->Topo == -1) return v; // SE PILHA VAZIA, RETORNA ELEMENTO VAZIO
  return p->Pecas[p->Topo--]; // RETORNA ELEMENTO DO TOPO E DECREMENTA
}
void Peek(Pilha *p){
  if (p->Topo == -1) return; // SE VAZIA, SAI
  printf("\n---------\"PEÇAS DA PILHA\"----------\n\n");
  for (int a = p->Topo; a >= 0; a--){
    printf("[%s, %d]\t", p->Pecas[a].Peca, p->Pecas[a].Id); // EXIBE DO TOPO AO FUNDO
  }
  printf("\n--------------------------------------\n");
}
int Free(Pilha *p){
   return p->Topo = -1; // LIMPA PILHA
}
// MOVE UMA PEÇA DA FILA PARA A PILHA
void Mover(Fila *f, Pilha *p){
  if (p->Topo == TAM_PILHA - 1) return; // SE PILHA CHEIA, NÃO FAZ NADA
  if (f->Total == 0) return; // SE FILA VAZIA, NÃO FAZ NADA
  Push(p, Remover(f)); // REMOVE DA FILA E EMPILHA
}
// PILHA AUXILIAR
void InicializacaoPilhaAux(PilhaAux *p){
   p->Topo = -1; 
}
void Puh(PilhaAux *p, Elementos pes){ 
  if(p->Topo == TAM_MAX -1) return; 
  p->Pecas[++p->Topo] = pes; 
}
Elementos Pup(PilhaAux *p){ 
  Elementos v = {"", -1}; 
  if (p->Topo == -1) return v; 
  return p->Pecas[p->Topo--]; 
}
// TROCA UMA PEÇA ENTRE PILHA E FILA
void TrocarONE(Pilha *p, PilhaAux *pilhareversa, Fila *f){
  if (f->Total == 0 || p->Topo == -1){ printf("Fila ou Pilha estão Vazia\n"); return; }
  Elementos a  = Pop(p); // REMOVE DA PILHA
  Elementos b = Remover(f); // REMOVE DA FILA
  Push(p, b); // COLOCA ELEMENTO DA FILA NA PILHA
  Adicionar(f, a); // COLOCA ELEMENTO DA PILHA NA FILA
}
// TROCA TRÊS ELEMENTOS ENTRE PILHA E FILA
void TrocarTudo(Pilha *p, Fila *f){
  if (p->Topo < 2 || f->Total < 3){ 
      printf("Não a Elementos Suficintes pra Realizar a Troca!\n"); 
    return; 
  }

  Elementos pi[3], fi[3];

  for (int i = 0; i < 3; i++){
    pi[i] = Pop(p); // REMOVE 3 DA PILHA
  }

  for (int i = 0; i < 3; i++){
  fi[i] = Remover(f); // REMOVE 3 DA FILA
  }

  for (int i = 2; i >= 0; i--){
  Push(p, fi[i]); // COLOCA ELEMENTOS DA FILA NA PILHA
  }

  for (int i = 0; i < 3; i++){
  Adicionar(f, pi[i]); // COLOCA ELEMENTOS DA PILHA NA FILA
  }
}

// FUNÇÃO PRINCIPAL
int main(){

  srand(time(NULL)); // INICIA ALEATORIEDADE

  Fila F; // DECLARA FILA
  Elementos Auto, Jogado; // ELEMENTOS AUXILIARES
  Pilha PilhaOriginal; // PILHA PRINCIPAL
  PilhaAux PilhaReserva; // PILHA AUXILIAR
  Elementos Usado, View; // ELEMENTOS USADOS PARA JOGADAS

  InicializacaoFila(&F); // INICIA FILA
  InicializacaoPilhaAux(&PilhaReserva); // INICIA PILHA AUXILIAR
  InicializacaoPilha(&PilhaOriginal); // INICIA PILHA

  int Opcao;

  do {
    Opcao = Menu(); // MOSTRA MENU
    system("clear"); // LIMPA TELA

    switch (Opcao){

      case 1: // JOGAR
        GerarPecas(&F);

        if (F.Total == 0){ 
          printf("Fila Vazia!\n"); 
          break; 
        }

          Usado = Remover(&F); // REMOVE UMA PEÇA

        printf("Peça jogada: [%s, %d]\n", Usado.Peca, Usado.Id);

        Exibir(&F); // EXIBE FILA

        GerarPecas(&F); // ATUALIZA A FILA GERANDO NOVAS PEÇAS

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
          getchar(); 
            system("clear");
        break;
      
      case 2: // RESERVA PEÇAS
        if (PilhaOriginal.Topo == TAM_PILHA -1){ 
          printf("Pilha Cheia, Use Uma Peça Para Reserva uma Nova!\n"); 

          Peek(&PilhaOriginal); 

          printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
            getchar(); 
              system("clear"); 
          break; 
        }

        Mover(&F, &PilhaOriginal); // MOVE UMA PEÇA

        GerarPecas(&F); // GERA NOVAS PEÇAS

        Peek(&PilhaOriginal); // EXIBE PILHA

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
          getchar(); 
            system("clear");
        break;
      
      case 3: // USAR PEÇAS
        if (PilhaOriginal.Topo == -1){ 
          printf("Pilha Vazia!\n"); 

            printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n"); 
              getchar(); 
                system("clear"); 
          break; 
        }

        Pop(&PilhaOriginal); // REMOVE TOPO

        GerarPecas(&F); // ATUALIZA A FILA GERANDO NOVAS PEÇAS

        if (PilhaOriginal.Topo != -1){ 
          Peek(&PilhaOriginal); } // EXIBE SE NÃO VAZIA

        printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n"); 
          getchar(); 
            system("clear");
        break;

      case 4: // EXIBIR PILHA E FILA
        ExibirFilaPilha(&F, &PilhaOriginal);

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
          getchar(); 
            system("clear");
        break;

      case 5: // TROCAR UMA PEÇA
        TrocarONE(&PilhaOriginal, &PilhaReserva, &F);

        while (F.Total > 0){ 
          Puh(&PilhaReserva, Remover(&F)); // INVERTE FILA PARA PILHA AUX
        } 
        while (PilhaReserva.Topo != -1){
          Adicionar(&F, Pup(&PilhaReserva)); // COLOCA DE VOLTA NA FILA
        } 

        ExibirFilaPilha(&F, &PilhaOriginal);

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
          getchar(); 
            system("clear");
        break;

      case 6: // TROCAR TODAS AS PEÇAS
        TrocarTudo(&PilhaOriginal, &F);

        while (F.Total > 0){ 
          Puh(&PilhaReserva, Remover(&F)); // INVERTE FILA PARA PILHA AUX
        } 
        while (PilhaReserva.Topo != -1){
          Adicionar(&F, Pup(&PilhaReserva)); // COLOCA DE VOLTA NA FILA
        } 

        ExibirFilaPilha(&F, &PilhaOriginal);

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
          getchar(); 
            system("clear");
        break;

      case 0: // SAIR
        Free(&PilhaOriginal);
        break;

      default: // OPÇÃO INVÁLIDA
        printf("Opção Invalida, Tente Novamente!\n");
        printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n");
         getchar();
          system("clear");
        break;
    }
  } while (Opcao != 0);

  printf("\nSaindo do Sistema, Até uma Proxíma...\n\n");
return 0;
}
