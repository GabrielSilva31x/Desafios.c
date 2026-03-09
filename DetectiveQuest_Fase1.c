/*
=====================================================
PROGRAMA: DETECTIVE QUEST - FASE 1
LINGUAGEM: C

DESCRICAO:
JOGO DE INVESTIGACAO EM UMA MANSAO ASSOMBRADA.
O JOGADOR VAI PODER EXPLORA CADA COMODO DA MANSÃO.

ESTRUTURAS UTILIZADAS:
- ARVORE BINARIA PARA REPRESENTAR A MANSÃO.
- FUNÇÕES, PONTEIROS, STRUCT E ALOCAÇÃO. 

OBJETIVO:
POSSIBILITAR O PLAYER EXPLORAR A MANSÃO.
=====================================================
*/

// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tamanho padrão para strings
#define TAMANHO 100

    // /-/-/-/-/ ESTRUTURA DA MANSÃO /-/-/-/-/
// Estrutura que representa um cômodo da mansão (nó da árvore binária)
typedef struct Mansao{
    char Nome[TAMANHO];
    struct Mansao* Direita;
    struct Mansao* Esquerda;
} Mansao;

  // /-/-/-/-/ FUNÇÕES DO JOGO /-/-/-/-/
Mansao* Criar_Comodos(char* Valor){
  Mansao* Novo = (Mansao*) malloc(sizeof(Mansao));

    strcpy(Novo->Nome, Valor);
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

    printf("===================================\n");
    printf("   ----- MANSÃO ASSOMBRADA -----\n");
    printf("===================================\n");
    printf(" 1.Explorar Mansão\n");
    printf(" 0.Sair\n");
    printf("-----------------------------------\n");
    printf("Digite sua Opção: ");
      scanf("%d", &opcoes);
        Limpar_Entradas();
          system("clear");

  return opcoes;
}

// Função para explorar a mansão
void* Explorar(Mansao* No){

  Mansao* Atual = No;
    char Escolha[10];

  // Enquanto existir cômodo
  while (Atual != NULL){
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

    printf("Você está: %s\n", Atual->Nome);
      printf("ir para Esquerda (e), Direita (d) ou Sair (s): ");
        fgets(Escolha, 10, stdin);
          Escolha[strcspn(Escolha, "\n")] = '\0';

  if (strcmp(Escolha, "s") == 0){ // Comparando o valor de entrada.
      break;

      } else if (strcmp(Escolha, "d") == 0 && Atual->Direita != NULL){
          Atual = Atual->Direita;

      } else if (strcmp(Escolha, "e") == 0 && Atual->Esquerda != NULL){
          Atual = Atual->Esquerda;

      } else {
          printf("Opção Invalida!\n");
    }    
  }
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

// Monta o mapa inicial e dá início à exploração
int main(){

  // Inicializando
    Mansao* Raiz = NULL;

  // Criando os Comodos Dinâmicamente!
    Raiz = Criar_Comodos("Hall");
    Raiz->Esquerda = Criar_Comodos("Sala");
    Raiz->Esquerda->Esquerda = Criar_Comodos("Quartos");
    Raiz->Esquerda->Direita = Criar_Comodos("Banheiro");

    Raiz->Direita = Criar_Comodos("Cozinha");
    Raiz->Direita->Direita = Criar_Comodos("Área de Serviço");
    Raiz->Direita->Esquerda = Criar_Comodos("Sala de Estar");

  // Chamando a função com a Introdução do Jogo para deixar o jogador estigado!
   MensagemInicial(); 

    int Opcoes;

    do {
       Opcoes = Menu_Iterativo();

       switch(Opcoes){

        case 1:
          Explorar(Raiz);
            
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
  
      Liberar_Memoria(Raiz);
    printf("\nMemória Liberada com Sucesso!\n");   
  return 0;
}