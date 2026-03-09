// -------------------------------------------------------------------------------- //
// ----------------------- DESAFIO FILAS -> FASE 3 - PARTE 2 ---------------------- //
// OBJETIVOS:
// - JOGAR PEÇAS -> FUNÇÃO(REMOVER) -> FILAS;
// - RESERVAR PEÇAS -> ADICIONAR(PUSH) -> PILHAS;
// - USAR AS PEÇAS RESERVAS -> REMOVER(POP) -> PILHAS;
// - FUNÇÕES EXTRAS -> GERARPEÇAS() & MOVERPEÇAS();
// - MOVERPEÇAS(DA FILA -> PILHA) E GERARPEÇAS(NOVAS PEÇAS NA FILA AUTOMATICAMENTE);
// -------------------------------------------------------------------------------- //

// BIBLIOTECAS
#include <stdio.h> // INCLUI BIBLIOTECA DE ENTRADA E SAÍDA
#include <string.h> // INCLUI FUNÇÕES DE MANIPULAÇÃO DE STRINGS
#include <stdlib.h> // INCLUI FUNÇÕES GERAIS
#include <time.h> // INCLUI FUNÇÕES RELACIONADAS AO SRAND()

// CONSTANTES
#define MAX 5 // TAMANHO MÁXIMO DA FILA
#define STRING 50 // TAMANHO MÁXIMO DA STRING DA PILHA
#define TAM 3 // TAMANHO MÁXIMO DA PILHA

// STRUCT FILA
typedef struct {
    char Peca; // CARACTER REPRESENTANDO A PEÇA
    int Id; // IDENTIFICADOR DA PEÇA
} Elementos;

typedef struct {
    Elementos Itens[MAX]; // ARRAY DE ELEMENTOS NA FILA
    int Inicio; // INDICE DO PRIMEIRO ELEMENTO
    int Fim; // INDICE DO PRÓXIMO ELEMENTO LIVRE
    int Total; // TOTAL DE ELEMENTOS NA FILA
} Fila;

// STRUCT PILHA
typedef struct {
    char parts[STRING]; // STRING REPRESENTANDO A PEÇA
    int Id; // IDENTIFICADOR DA PEÇA
} Pecas;

typedef struct {
    Pecas Dados[TAM]; // ARRAY DE ELEMENTOS NA PILHA
    int Topo; // INDICE DO TOPO DA PILHA
} Pilha;

// FUNÇÕES COMPLEMENTARES
void Limpar(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF ); // LIMPA O BUFFER DO TECLADO
}

void Inicializacao(Pilha *p, Fila *f){
    p->Topo = 0;  // INICIALIZANDO A PILHA

    f->Inicio = 0; // INICIALIZANDO O INÍCIO DA FILA
    f->Fim = 0; // INICIALIZANDO O FIM DA FILA
    f->Total = 0; // INICIALIZANDO O TOTAL DA FILA
}

int Menu(){
    int Escolha;

    printf("-----------------------------------------\n");
    printf("/////////// \"MENU PRINCIPAL\" ///////////\n");
    printf("-----------------------------------------\n");
    printf("1.JOGAR\n");
    printf("2.RESERVA PEÇAS\n");
    printf("3.USAR PEÇAS\n");
    printf("0.Sair\n");
    printf("-----------------------------------------\n");
    printf("Digite Sua Opção: ");
      scanf("%d", &Escolha); // LÊ OPÇÃO DO USUÁRIO
        Limpar(); // LIMPA BUFFER

    return Escolha; // RETORNA A OPÇÃO
}

// FUNÇÕES FILA
int FilaCheia(Fila *f){
    return f->Total >= MAX; // RETORNA 1 SE FILA CHEIA, 0 CASO CONTRÁRIO
}

int FilaVazia(Fila *f){
    return f->Total == 0; // RETORNA 1 SE FILA VAZIA, 0 CASO CONTRÁRIO
}

int Jogar(Fila *f, Elementos *p){
    if (FilaVazia(f)){
        printf("Fila Vazia, Adicione Uma Nova Peça!\n");
        return 1; // RETORNA 1 SE FILA VAZIA
    }

    *p = f->Itens[f->Inicio]; // ARMAZENA O ELEMENTO A SER JOGADO
    f->Inicio = (f->Inicio +1) % MAX; // INCREMENTA O INICIO DA FILA (CIRCULAR)
    f->Total--; // DECREMENTA O TOTAL
}

void Exibir(Fila *f){
    if (FilaVazia(f)) return; // SE FILA VAZIA, SAI

    int c = 0;
    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA FILA\" <-<-<-<-\n");

    for (int i = 0, rs = f->Inicio; i < f->Total; i++, rs = (rs +1) % MAX){
        printf("[%c, %d]\t", f->Itens[rs].Peca, f->Itens[rs].Id = c++); // MOSTRA CADA ELEMENTO
    }

    printf("\n----------------------------------------\n");
}

void Adicionar(Fila *f, Elementos p){
    if (FilaCheia(f)){
      printf("Fila Cheia, Remova Uma peça para Uma Nova Inserção!");
        return; // NÃO ADICIONA SE FILA CHEIA
    }

    f->Itens[f->Fim] = p; // ADICIONA ELEMENTO NO FIM
    f->Fim = (f->Fim +1) % MAX; // INCREMENTA FIM (CIRCULAR)
    f->Total++; // INCREMENTA TOTAL
}

void GerarPecas(Fila *f){
    Elementos p;
    char pecas[] = {'I','O','T','L','|'};

    if (f->Total == MAX) return; // SE FILA CHEIA, SAI

    while (f->Total < MAX){
        int a = rand() % 5; // ESCOLHE UMA PEÇA ALEATÓRIA
        p.Peca = pecas[a]; // ATRIBUI PEÇA
        Adicionar(f, p); // ADICIONA À FILA
    }
}

// FUNÇÕES PILHA
int PilhaCheia(Pilha *p){
    return p->Topo >= TAM; // RETORNA 1 SE PILHA CHEIA
}

int PilhaVazia(Pilha *p){
    return p->Topo == 0; // RETORNA 1 SE PILHA VAZIA
}

int Mover(Fila *f, Pilha *p){
    if (PilhaCheia(p)){
      printf("Pilha Cheia, Use Uma das Peças!\n");
        return 1; // RETORNA 1 SE PILHA CHEIA
    }

    // ARMAZENA A PEÇA INICIAL DA FILA
    Elementos *v = &f->Itens[f->Inicio];

    // MOVE A PEÇA DA FILA PARA PILHA
    p->Dados[p->Topo].parts[0] = v->Peca;
    p->Dados[p->Topo].parts[1] = '\0'; // TERMINADOR DE STRING
    p->Dados[p->Topo].Id = v->Id;
    p->Topo++; // INCREMENTA TOPO

    // REMOVE PEÇA MOVIDA DA FILA
    f->Inicio = (f->Inicio +1) % MAX;
    f->Total--;
}

void Pop(Pilha *p){
    if (p->Dados == 0){
      printf("Pilha Vazia, Faça um Push para Adicinar um \"Novo\" Item a Pilha!\n");
        return; // SE PILHA VAZIA, SAI
    }

  int a = p->Topo -1; // INDICE DO TOPO
    printf("Peça Usada da Pilha: [%s, %d]\n", p->Dados[a].parts, p->Dados[a].Id); // MOSTRA ELEMENTO USADO

  p->Topo--; // DECREMENTA TOPO
}

void Peek(Pilha *p){
    if (PilhaVazia(p)){
        printf("Pilha Vazia!\n");
        return; // SE PILHA VAZIA, SAI
    }

    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA PILHA\" <-<-<-<-\n\n");

    for (int i = p->Topo -1; i >= 0; i--){
        printf("[%s, %d]\t", p->Dados[i].parts, p->Dados[i].Id); // MOSTRA PILHA DO TOPO AO FUNDO
    }

    printf("\n----------------------------------------\n\n");
}

void Free(Pilha *p){
    p->Topo = -1; // LIMPA PILHA
}

// BLOCO DE CÓDIGO PRINCIPAL
int main(){

    // DECLARANDO VARIÁVEIS DA FILA
    Fila Fila;
    Elementos Auto;
    Elementos Jogado;

    // DECLARANDO VARIÁVEIS DA PILHA
    Pilha Pilha;
    Pecas Usado;
    Pecas View;

    Inicializacao(&Pilha, &Fila); // INICIALIZA FILA E PILHA

    Elementos Pes[] = { {'I'}, {'O'}, {'T'}, {'L'}, {'|'} };

    for (int i = 0; i < 5; i++){
        Adicionar(&Fila, Pes[i]); // ADICIONA PEÇAS INICIAIS NA FILA
    }

    srand(time(NULL)); // INICIALIZA ALEATORIEDADE
      int Opcao;

    do {
        Opcao = Menu(); // MOSTRA MENU
        system("clear"); // LIMPA TELA

        switch (Opcao){
            case 1: // JOGAR
                int a = Jogar(&Fila, &Jogado);

                if (a != 1){
                  printf("Peça jogada: [%c, %d]\n", Jogado.Peca, Jogado.Id); // MOSTRA PEÇA JOGADA
                }

                GerarPecas(&Fila); // GERA NOVAS PEÇAS
                Exibir(&Fila); // EXIBE FILA

                printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
                  getchar();
                    system("clear");
              break;

              case 2: // RESERVA PEÇAS
                if (PilhaCheia(&Pilha)){
                    printf("Pilha Cheia, Use Uma Peça Para Reserva uma Nova!\n");

                    Peek(&Pilha);

                    printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
                      getchar();
                        system("clear");
                  break;
                }

                Mover(&Fila, &Pilha); // MOVE PEÇA PARA PILHA
                  Peek(&Pilha); // EXIBE PILHA

                printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n"); 
                  getchar();
                    system("clear");
                break;

            case 3: // USAR PEÇAS
                if (PilhaVazia(&Pilha)){
                    printf("Pilha Vazia!\n");
                  break;
                }
                Pop(&Pilha); // REMOVE PEÇA DO TOPO
                  Peek(&Pilha); // EXIBE PILHA

                printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n"); 
                  getchar();
                    system("clear");
                break;

            case 0: // SAIR
                Free(&Pilha); // LIMPA PILHA
              break;

            default:
                printf("Opção Invalida, Tente Novamente!\n");

                printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n"); 
                  getchar();
                    system("clear");
              break;
        }

    } while (Opcao != 0); // REPETE ENQUANTO NÃO SAIR

    printf("\nSaindo do Sistema, Volte Logo...\n");
  return 0;
}
