/*
=========================================================
PROGRAMA: DETECTIVE QUEST - FASE 3
LINGUAGEM: C

DESCRICAO:
JOGO DE INVESTIGACAO EM UMA MANSAO ASSOMBRADA.
O JOGADOR EXPLORA COMODOS, ENCONTRA PISTAS E
NO FINAL ACUSA UM SUSPEITO.

ESTRUTURAS UTILIZADAS:
- ARVORE BINARIA PARA REPRESENTAR A MANSAO
- ARVORE BST PARA ARMAZENAR PISTAS COLETADAS
- TABELA HASH PARA RELACIONAR PISTAS A SUSPEITOS

OBJETIVO:
COLETAR PISTAS SUFICIENTES PARA IDENTIFICAR
O CULPADO DO CRIME.
========================================================
*/

// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tamanho padrão para strings
#define TAMANHO 100
// Tamanho máximo da tabela hash
#define MAX_HASH 10

// /-/-/-/-/ ESTRUTURA DA MANSÃO /-/-/-/-/
// Estrutura que representa um cômodo da mansão (nó da árvore binária)
typedef struct Mansao{
    char Nome[TAMANHO]; // Nome do cômodo
    char Pista[TAMANHO]; // Pista que pode existir no cômodo
    struct Mansao *Direita; // Ponteiro para o cômodo à direita
    struct Mansao *Esquerda; // Ponteiro para o cômodo à esquerda
} Mansao;

// /-/-/-/-/ ÁRVORE DAS PISTAS COLETADAS /-/-/-/-/
// Estrutura que representa uma árvore binária de busca (BST)
// usada para armazenar as pistas encontradas
typedef struct PistasCaso{
    char descricao[TAMANHO]; // Descrição da pista
    struct PistasCaso *Direita; // Ponteiro para subárvore direita
    struct PistasCaso *Esquerda; // Ponteiro para subárvore esquerda
} PistasCaso;

// /-/-/-/-/ ESTRUTURA DA TABELA HASH /-/-/-/-/
// Estrutura de lista encadeada usada em cada posição da tabela hash
typedef struct Hash{

    // Nome da pista armazenada na hash
    char Pistahash[TAMANHO];

    // Nome do suspeito associado à pista
    char suspeito[50];

    // Ponteiro para o próximo elemento (tratamento de colisão)
    struct Hash *proximo;

} Hash;

// /-/-/-/-/ FUNÇÕES HASH /-/-/-/-/
// Função hash simples baseada na soma dos caracteres da string
int calcularIndix(char *str) {

    int soma = 0;

    // Percorre todos os caracteres da string
    for (int i = 0; str[i] != '\0'; i++)
        soma += str[i];   // soma o valor ASCII

    // Retorna o índice da tabela
    return soma % MAX_HASH;
}
// AdicionarNaHash: Associa uma pista a um suspeito na tabela
void AdicionarNaHash(Hash *tabela[], char *pista, char *suspeito) {

    // Calcula o índice da hash
    int indice = calcularIndix(pista);

    // Aloca memória para um novo nó
    Hash *novo = (Hash*)malloc(sizeof(Hash));

    // Copia os dados
    strcpy(novo->Pistahash, pista);
    strcpy(novo->suspeito, suspeito);

    // Inserção no início da lista (tratamento de colisão)
    novo->proximo = tabela[indice];
    tabela[indice] = novo;
}
// Procura qual suspeito está associado a determinada pista
char* encontrarSuspeito(Hash *tabela[], char *pista) {

    // Calcula o índice da hash
    int indice = calcularIndix(pista);

    // Ponteiro para percorrer a lista
    Hash *atual = tabela[indice];

    // Percorre a lista encadeada
    while (atual != NULL) {

        // Se encontrou a pista
        if (strcmp(atual->Pistahash, pista) == 0)
            return atual->suspeito;
        atual = atual->proximo;
    }

    // Caso não encontre
    return "Desconhecido";
}

// /-/-/-/-/ FUNÇÕES DO JULGAMENTO  /-/-/-/-/
// Insere uma pista na árvore BST das pistas coletadas
PistasCaso* inserirPista(PistasCaso *raiz, char *pista) {

    // Caso base: cria novo nó
    if (raiz == NULL) {

        PistasCaso *novo = (PistasCaso*) malloc(sizeof(PistasCaso));

      strcpy(novo->descricao, pista);
        novo->Esquerda = novo->Direita = NULL;
          return novo;
    }

    // Inserção na subárvore esquerda
    if (strcmp(pista, raiz->descricao) < 0)
        raiz->Esquerda = inserirPista(raiz->Esquerda, pista);

    // Inserção na subárvore direita
    else if (strcmp(pista, raiz->descricao) > 0)
        raiz->Direita = inserirPista(raiz->Direita, pista);

    return raiz;
}
// Conta quantas pistas apontam para um suspeito específico
int contarEvidencias(PistasCaso *raizPistas, Hash *tabela[], char *acusado) {

    // Caso base
    if (raizPistas == NULL) return 0;

    int conta = 0;

    // Descobre qual suspeito está vinculado à pista
    char *suspeitoVinculado = encontrarSuspeito(tabela, raizPistas->descricao);

    // Se a pista aponta para o acusado
    if (strcmp(suspeitoVinculado, acusado) == 0)
        conta = 1;

    // Soma recursivamente as evidências
    return conta +
           contarEvidencias(raizPistas->Esquerda, tabela, acusado) +
           contarEvidencias(raizPistas->Direita, tabela, acusado);
}
// Lista todas as pistas em ordem (percorrendo a BST)
void listarPistas(PistasCaso *raiz) {
    if (raiz != NULL) {
      listarPistas(raiz->Esquerda);
        printf("- %s\n", raiz->descricao);
      listarPistas(raiz->Direita);
    }
}
// Função que realiza a fase final do julgamento
void verificarSuspeito(PistasCaso *raizPistas, Hash *tabela[]) {

  char acusado[50];

    printf("\n/-/-/ FASE DO VEREDITO FINAL /-/-/\n");
    printf("----------------------------------------------\n");
    printf("Pistas coletadas na Mansão [Organizadas!]:\n");

    // Mostra as pistas coletadas
    listarPistas(raizPistas);
    printf("----------------------------------------------\n");

    // Pergunta quem o jogador acusa
    printf("Quem você acha que é o Vilão da Mansão? (Jardineira -/- Cozinheiro -/- Mordomo): ");

      fgets(acusado, 50, stdin);

        acusado[strcspn(acusado, "\n")] = '\0';

    // Conta quantas pistas apontam para ele
    int evidencias = contarEvidencias(raizPistas, tabela, acusado);

    printf("\nAnalisando evidencias contra %s...\n", acusado);

    printf("Total de pistas encontradas que apontam para ele(a): %d\n", evidencias);

    // Veredito final
    if (evidencias >= 2) {
      printf("SUCESSO! Você apresentou provas suficientes e o culpado foi preso, Parabens!\n");

    } else {
      printf("FRACASSO! Provas insuficientes. O culpado escapou ou você acusou um inocente.[-_-]\n");
  }
}

// /-/-/-/-/ FUNÇÕES MANSÃO /-/-/-/-/
// Cria um novo cômodo da mansão
Mansao* Criar_Comodos(char* Valor){

  // Alocação de memória
  Mansao* Novo = (Mansao*) malloc(sizeof(Mansao));

    // Copia o nome do cômodo
    strcpy(Novo->Nome, Valor);

      // Inicializa ponteiros
      Novo->Direita = NULL;
      Novo->Esquerda = NULL;

  return Novo;
}
// Libera toda a memória da árvore da mansão
void Liberar_Memoria(Mansao* No){

    if (No != NULL){
      Liberar_Memoria(No->Esquerda);
      Liberar_Memoria(No->Direita);
        free(No);
    }
} 
// Limpa o buffer de entrada do teclado
void Limpar_Entradas(){
    int c;
      while ((c = getchar()) != '\n' && c != EOF);
}
// Menu principal do jogo
int Menu_Iterativo(){

    int opcoes;

    printf("====================================\n");
    printf("   $-$-$ MANSÃO ASSOMBRADA $-$-$\n");
    printf("====================================\n");
    printf(" 1.Explorar Mansão\n");
    printf(" 0.Sair\n");
    printf("------------------------------------\n");
    printf("Digite sua Opção: ");
      scanf("%d", &opcoes);
        Limpar_Entradas();
          system("clear");

  return opcoes;
}
// Função responsável pela exploração da mansão
void Explorar(Mansao* No, Hash* tabela[]){

  // Começa pela raiz
  Mansao* Atual = No;

  // Lista de pistas coletadas
  PistasCaso *Lista = NULL; 

  char Escolha[10];
      
      printf("Comodo:[%s] - ", Atual->Nome);

  // Enquanto existir cômodo
  while (Atual != NULL){

     // Se existir pista no cômodo
     if (strlen(Atual->Pista) != 0){
          printf("Comodo:[%s] - [!] Pista:[%s]\n", Atual->Nome, Atual->Pista);

            // Insere pista na árvore de pistas
            Lista = inserirPista(Lista, Atual->Pista);
            // Remove pista do cômodo
            strcpy(Atual->Pista, "");
        }
        
      // Mostra caminhos disponíveis
      if (Atual->Esquerda != NULL || Atual->Direita != NULL){

        printf("Caminhos: ");
        if (Atual->Esquerda){
          printf("%s [e] | ", Atual->Esquerda->Nome);
        }

        if (Atual->Direita){
          printf("%s [d]\n", Atual->Direita->Nome);
        }
      }

      printf("\nEscolha ir para Esquerda [e], Direita [d] ou Sair [s]: ");
        fgets(Escolha, 10, stdin);
          Escolha[strcspn(Escolha, "\n")] = '\0';
            system("clear");


  if (strcmp(Escolha, "s") == 0){
        break;

      } else if (strcmp(Escolha, "d") == 0 && Atual->Direita != NULL){
          Atual = Atual->Direita;

      } else if (strcmp(Escolha, "e") == 0 && Atual->Esquerda != NULL){
          Atual = Atual->Esquerda;

      } else {
          printf("Opção Invalida!\n");
    }    
  }

  // Ao terminar exploração inicia julgamento
  verificarSuspeito(Lista, tabela);
}

// /-/-/-/-/ INTRODUÇÃO DO JOGO /-/-/-/-/
// Mostra a história inicial do jogo
void MensagemInicial(){

char Mensagem[10]; 
  int valido;

printf("Olá, Jogador!\n");
printf("Você está pronto para embarcar em uma investigação... diferente de tudo que já viu?\n");

// Validação do nome do jogador
do{
  valido = 1;
  printf("Antes de começarmos, diga-me... como devo chamá-lo? ");
    fgets(Mensagem, 10, stdin);
      Mensagem[strcspn(Mensagem, "\n")] = '\0';
        system("clear");

    // Verifica se existe número no nome
    for(int i = 0; Mensagem[i] != '\0'; i++) {
      if(isdigit(Mensagem[i])) {   // se for número!
        valido = 0;
          break;
        }
      }

    // Verifica se está vazio
    if(strlen(Mensagem) == 0){ // se estiver vazia!
      printf("Entrada invalida! Digite um nome.\n\n");
        valido = 0;
    }

} while(!valido);

    // Mensagens narrativas
    printf("\n----------------------------------------------------------------------\n");
  
  printf("A noite está silenciosa demais...\nAlgo naquela mansão parece observar cada passo seu.\n\"%s\", hoje você não é apenas um visitante... você é o detetive.", Mensagem);
    printf("\n----------------------------------------------------------------------\n");
      printf("To continue...");getchar();system("clear");

    printf("\n--------------------------------------------------------------------------------\n");

  printf("Portas antigas rangem enquanto o vento atravessa os corredores. \nMistérios esquecidos aguardam alguém corajoso o suficiente para revelá-los. \nTalvez apenas você consiga descobrir o que realmente aconteceu aqui, \"%s\".", Mensagem);
    printf("\n--------------------------------------------------------------------------------\n");
      printf("To continue...");getchar();system("clear");

  printf("\nRespire fundo, detetive... a investigação começa agora.");
    printf("\n--------------------------------------------------------\n");
      printf("To continue...");getchar();system("clear");

}

// /-/-/-/ FUNÇÃO PRINCIPAL /-/-/-/
// Monta o mapa inicial e inicia o jogo
int main(){

  // Inicializando
  Mansao *Raiz = NULL;

  // Tabela hash inicializada com NULL
  Hash *Tabela_Hash[MAX_HASH] = {NULL};

  // MONTAGEM DA ÁRVORE DA MANSÃO
  Raiz = Criar_Comodos("Hall de Entrada"); 
  
  Raiz->Esquerda = Criar_Comodos("Sala"); 
  Raiz->Esquerda->Esquerda = Criar_Comodos("Quartos"); 
  Raiz->Esquerda->Direita = Criar_Comodos("Banheiro"); 

  Raiz->Direita = Criar_Comodos("Cozinha"); 
  Raiz->Direita->Direita = Criar_Comodos("Área de Serviço");
  Raiz->Direita->Esquerda = Criar_Comodos("Sala de Estar"); 


  // INSERINDO PISTAS NOS CÔMODOS
  strcpy(Raiz->Pista, "");
  strcpy(Raiz->Esquerda->Pista, "Câmera desligada");
  strcpy(Raiz->Esquerda->Esquerda->Pista, "Chave mestra");
  strcpy(Raiz->Esquerda->Direita->Pista, "Ferramenta de jardim");

  strcpy(Raiz->Direita->Pista, "Uma faca caída no chão e uma pequena mancha escura perto da pia.");
  strcpy(Raiz->Direita->Direita->Pista, "Pegadas de terra");
  strcpy(Raiz->Direita->Esquerda->Pista, "Frasco de veneno na despensa");


  // ASSOCIANDO PISTAS A SUSPEITOS
  AdicionarNaHash(Tabela_Hash, "Frasco de veneno na despensa", "Cozinheiro");
  AdicionarNaHash(Tabela_Hash, "Uma faca caída no chão e uma pequena mancha escura perto da pia.", "Cozinheiro");
  AdicionarNaHash(Tabela_Hash, "Pegadas de terra", "Jardineira");
  AdicionarNaHash(Tabela_Hash, "Ferramenta de Jardim", "Jardineira");
  AdicionarNaHash(Tabela_Hash, "Chave mestra", "Mordomo");
  AdicionarNaHash(Tabela_Hash, "Câmera desligada", "Mordomo");


  // INÍCIO DO JOGO 

  // Historia para deixa o Jogador ansioso para se aventurar!
  MensagemInicial();

    int Opcoes;
  do {
      Opcoes = Menu_Iterativo();

    switch(Opcoes){

        case 1:

          Explorar(Raiz, Tabela_Hash);

          printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
            getchar();
              system("clear");
        break;


        case 0:
          printf("Até Uma Proxíma...\n");   
          break;


        default:
        printf("Opção Invalida!\n");
          printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
            getchar();
              system("clear");
      }
    } while (Opcoes != 0);

  // Libera memória da árvore da mansão
    Liberar_Memoria(Raiz);
      printf("\nMemória Liberada com Sucesso!\n");   
  return 0;
}
