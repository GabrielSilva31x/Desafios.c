// =============================================================== //
// /<->/<->/<->/<->/<->/ COD.FREE FIRE -> FASE 2 /<->/<->/<->/<->/ //
// =============================================================== //
// OBJETIVOS: CREATE UM CÓDIGO COM TIPOS DE LISTAS DIFERENTES
// >> UMA MOCHILA COM O TIPO DE LISTA LINEAR
// >> MOCHILA QUE POSSUI O TIPO DE LISTA ENCADEADA
// >> TODAS COM AS MESMAS FUNÇÕES(BUSCAR, EXIBIR, ADICIONAR, REMOVER) 
// >> OPÇÃO ONDE USUARIO POSSA ESCOLHER O TIPO DE MOCHILA QUEIRA USAR
// =============================================================== //

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define MAX 20       // Número máximo de itens na mochila
#define STRING 50    // Tamanho máximo das strings (Nome/Tipo)

// LISTA LINEAR (ARRAY)
typedef struct {
    char Nome[STRING];
    char Tipo[STRING];
    int Quantidade;
} Mochila1;

// LISTA ENCADEADA (DUPLAMENTE ENCADEADA)
typedef struct Mochila2 {
    char Nome[STRING];
    char Tipo[STRING];
    int Quantidade;
    struct Mochila2 *Proximo;
    struct Mochila2 *Anterior;
} Mochila2;

// Limpa o buffer do teclado
void LimparI() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void LimparII() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int MenuOpcoesI() {

    int opcoes;

    printf("===================================\n");
    printf("/-/-/ MENU DA MOCHILA LINEAR /-/-/\n");
    printf("===================================\n");
    printf("1. Adicionar Itens\n");
    printf("2. Remover Itens\n");
    printf("3. Mostrar Mochila\n");
    printf("4. Buscar Item\n");
    printf("0. Retornar ao Menu Principal\n");
    printf("-------------------------------------\n");
    printf("Digite sua Opção: ");
      scanf("%d", &opcoes);
        LimparI();
          system("clear");

  return opcoes;
}

// Função para adicionar itens na lista linear
void AdicionarItensI(Mochila1 *Inventario, int *TotalTudo){
    int TotalLista = *TotalTudo;

    if (TotalLista >= MAX){
        printf("Espaço insuficiente para mais um item!\n");
        return;
    }

    printf("\n--------- ADICIONAR UM NOVO ITEM ---------\n");

    printf("Digite o Nome do Item: ");
    fgets(Inventario[TotalLista].Nome, STRING, stdin);
    printf("Digite o Tipo do Item: ");
    fgets(Inventario[TotalLista].Tipo, STRING, stdin);

    // Remove '\n' final
    Inventario[TotalLista].Nome[strcspn(Inventario[TotalLista].Nome, "\n")] = '\0';
    Inventario[TotalLista].Tipo[strcspn(Inventario[TotalLista].Tipo, "\n")] = '\0';

    printf("Digite a Quantidade do Item: ");
    scanf("%d", &Inventario[TotalLista].Quantidade);
    getchar();

    (*TotalTudo)++;
    printf("\nItem Adicionado com SUCESSO!\n");
}

// Função para remover item da lista linear
void RemoverItemI(Mochila1 *Inventario, int *TotalTudo){
    int TotalLista = *TotalTudo;
      int pro = -1;
        char Opcao[STRING];

    if (TotalLista == 0){
        printf("Não há itens na mochila!\n");
      return;
    }

    printf("Digite o Nome do Item que deseja REMOVER: ");
    fgets(Opcao, sizeof(Opcao), stdin);
    Opcao[strcspn(Opcao, "\n")] = '\0';

    for (int i = 0; i < TotalLista; i++){
        if (strcmp(Inventario[i].Nome, Opcao) == 0){
            pro = i;
            break;
        }
    }

    if (pro == -1){
        printf("Item não encontrado!\n");
        return;
    }

    for (int i = pro; i < TotalLista - 1; i++){
        Inventario[i] = Inventario[i+1];
    }

    (*TotalTudo)--;
    printf("Item \"%s\" removido com SUCESSO!\n", Opcao);
}

// Exibir itens da lista linear
void ExibirItensI(Mochila1 *Inventario, int *TotalTudo){
    int TotalLista = *TotalTudo;
    if (TotalLista == 0){
        printf("Inventário da mochila está vazio!\n");
      return;
    }

    printf("=================================================\n");
    printf(" /<->/ MOCHILA DO SOBREVIVENTE -> (%d/20) /<->/ \n", TotalLista);
    printf("=================================================\n");
    printf("\tNome\t   | \tTipo\t   |  Qtd\n");
    printf("=================================================\n");

    for (int i = 0; i < TotalLista; i++){
        printf("\t%-10s |\t%-10s |\t%-6d\n",
               Inventario[i].Nome,
               Inventario[i].Tipo,
               Inventario[i].Quantidade);
        printf("-------------------------------------------------\n");
    }
}

// Busca binária na lista linear (precisa estar ordenada)
int BuscadorI(Mochila1 *Inventario, int Inicio, int Fim, const char Buscar[]){
    if (Inicio > Fim) return -1;

    int meio = Inicio + (Fim - Inicio) / 2;

    int cmp = strcmp(Inventario[meio].Nome, Buscar);

    if (cmp == 0) return meio;

    else if (cmp < 0) {
      return BuscadorI(Inventario, meio+1, Fim, Buscar);

    } else {
        return BuscadorI(Inventario, Inicio, meio-1, Buscar);
  }
}

// Função usada pelo qsort para ordenar por nome
int sort(const void *A, const void *Z){

  const Mochila1 *x = A;
    const Mochila1 *y = Z;

    return strcmp(x->Nome, y->Nome);
}

// ======================================================== //
// =================== LISTA LINEAR ======================= //
int MochilaLinear(){
    Mochila1 Item[MAX];
    int opcoes;
    int TotalLista = 0;

    do {
        opcoes = MenuOpcoesI();
        system("clear");

        switch (opcoes){
            case 1:
              AdicionarItensI(Item, &TotalLista);

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 2:
                RemoverItemI(Item, &TotalLista);

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 3:
                qsort(Item, TotalLista, sizeof(Mochila1), sort);
                ExibirItensI(Item, &TotalLista);

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 4: 
                char Procura[STRING];

                printf("Digite o Nome que Procura: ");
                fgets(Procura, sizeof(Procura), stdin);
                Procura[strcspn(Procura, "\n")] = '\0';

                qsort(Item, TotalLista, sizeof(Mochila1), sort);

                int Busca = BuscadorI(Item, 0, TotalLista-1, Procura);

                if (Busca != -1){
                    printf("\nItem encontrado:\nNome: %s\nTipo: %s\nQuantidade: %d\n",
                      Item[Busca].Nome,
                        Item[Busca].Tipo,
                          Item[Busca].Quantidade);
                } else {
                  printf("Item não encontrado\n");
                }

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
              break;
            

            case 0:
              printf("Retornando ao menu principal...\n");
                break;

            default:
              printf("Opção inválida!\n");
                getchar(); 
                  system("clear");
        }
    } while (opcoes != 0);

  return 0;
}

// ======================================================= //
// ================= LISTA ENCADEADA ===================== //
int MenuOpcoesII() {
    int opcoes;
    printf("================================\n");
    printf("/-/-/ MENU DA MOCHILA ENCADEADA /-/-/\n");
    printf("================================\n");
    printf("1. Adicionar Itens\n2. Remover Itens\n3. Mostrar Mochila\n4. Buscar Item\n0. Retornar ao Menu\n");
    printf("--------------------------------\n");
    printf("Digite sua Opção: ");
    scanf("%d", &opcoes);
    LimparII();
    system("clear");
    return opcoes;
}

// Adicionar item no início da lista encadeada
void AdicionarItensII(Mochila2 **Inicio, int *Total){
    if (*Total >= MAX){
        printf("Espaço insuficiente!\n");
      return;
    }

    Mochila2 *Novo = malloc(sizeof(Mochila2));

    printf("Digite o Nome do Item: ");
    fgets(Novo->Nome, STRING, stdin);
    printf("Digite o Tipo do Item: ");
    fgets(Novo->Tipo, STRING, stdin);
    Novo->Nome[strcspn(Novo->Nome, "\n")] = '\0';
    Novo->Tipo[strcspn(Novo->Tipo, "\n")] = '\0';
    printf("Digite a Quantidade do Item: ");
    scanf("%d", &Novo->Quantidade);
    LimparII();

    Novo->Proximo = *Inicio;
    Novo->Anterior = NULL;
    if (*Inicio != NULL) (*Inicio)->Anterior = Novo;
    *Inicio = Novo;

    (*Total)++;
    printf("\nItem adicionado com SUCESSO!\n");
}

// Remover item da lista encadeada
void RemoverItemII(Mochila2 **Inicio, int *Total){
    if (*Total == 0){
        printf("Não há itens!\n");
      return;
    }

    char Opcao[STRING];
    printf("Digite o Nome do Item que deseja REMOVER: ");

    fgets(Opcao, sizeof(Opcao), stdin);
    Opcao[strcspn(Opcao, "\n")] = '\0';

    Mochila2 *Atual = *Inicio;
    while (Atual != NULL){
        if (strcmp(Atual->Nome, Opcao) == 0){

            if (Atual->Anterior != NULL) {
            Atual->Anterior->Proximo = Atual->Proximo;
            } else {
            *Inicio = Atual->Proximo;
          }
            if (Atual->Proximo != NULL) {
           Atual->Proximo->Anterior = Atual->Anterior;
          }

            free(Atual);
             (*Total)--;

            printf("Item \"%s\" removido com SUCESSO!\n", Opcao);
          return;
        }
      Atual = Atual->Proximo;
    }
    printf("Item não encontrado!\n");
}

// Exibir itens da lista encadeada
void ExibirItensII(Mochila2 *Inicio, int *Total){
    if (*Total == 0){
        printf("Mochila está vazia!\n");
      return;
    }

    printf("=================================================\n");
    printf(" /<->/ MOCHILA DO SOBREVIVENTE -> (%d/20) /<->/ \n", Total);
    printf("=================================================\n");
    printf("\tNome\t   | \tTipo\t   |  Qtd\n");
    printf("=================================================\n");

    Mochila2 *Percorre = Inicio;
    while (Percorre != NULL){
        printf("\t%-10s |\t%-10s |\t%8d\n",
               Percorre->Nome, Percorre->Tipo, Percorre->Quantidade);
                printf("-------------------------------------------------\n");

        Percorre = Percorre->Proximo;
    }
}

// Buscar item na lista encadeada
Mochila2 *BuscadorII(Mochila2 *Inicio, char Buscar[], int *Total){
    Mochila2 *Atual = Inicio;
    while (Atual != NULL){
      if (strcmp(Atual->Nome, Buscar) == 0) return Atual;
        Atual = Atual->Proximo;
    }
  return NULL;
}

// Liberar memória da lista encadeada
void LiberaMemoriasII(Mochila2 *Inicio){
  Mochila2 *Memoria;
    while (Inicio != NULL){
        Memoria = Inicio;
        Inicio = Inicio->Proximo;
      free(Memoria);
    }
  printf("Memória liberada com sucesso!\n");
}

// Função principal da lista encadeada
int MochilaEncadeada(){
  Mochila2 *Inicio = NULL;
    int TotalGeral = 0;
      int opcoes;

    do {
        opcoes = MenuOpcoesII();
        system("clear");

        switch (opcoes){
            case 1:
              AdicionarItensII(&Inicio, &TotalGeral);

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 2:
                RemoverItemII(&Inicio, &TotalGeral);

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 3:
                ExibirItensII(Inicio, &TotalGeral);

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 4: 
                char Procura[STRING];

                printf("Digite o Nome que Procura: ");
                fgets(Procura, sizeof(Procura), stdin);
                Procura[strcspn(Procura, "\n")] = '\0';

                Mochila2 *Resultado = BuscadorII(Inicio, Procura, &TotalGeral);

                if (Resultado != NULL){
                    printf("\nItem encontrado:\nNome: %s\nTipo: %s\nQuantidade: %d\n",
                        Resultado->Nome,
                          Resultado->Tipo,
                            Resultado->Quantidade);

                } else {
                  printf("Item não encontrado\n");
                }

                printf("\nPressione ENTER para continuar...\n");
                  getchar();
                    system("clear");
                break;
            
            case 0:
                LiberaMemoriasII(Inicio);

              printf("Retornando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
                  getchar(); 
                    system("clear");
        }
    } while (opcoes != 0);

  return 0;
}

// ======================================================== //
// ================== MENU PRINCIPAL ====================== //

void ClearScanf(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){
    int Escolha;

    do {
        printf("--------------------------------------\n");
        printf(" /-/-/-/-/ MENU PRINCIPAL /-/-/-/-/ \n");
        printf("--------------------------------------\n");
        printf("1. Mochila Linear\n2. Mochila Encadeada\n0. Sair\n");
        printf("--------------------------------------\n");
        printf("Digite sua opção: ");
          scanf("%d", &Escolha);
            ClearScanf();
              system("clear");

        switch (Escolha){
            case 1:
                printf("Bem-vindo à Mochila Linear!\n");
                  MochilaLinear();
                break;

            case 2:
                printf("Bem-vindo à Mochila Encadeada!\n");
                  MochilaEncadeada();
                break;

            case 0:
                printf("Saindo do Sistema...\nAté a próxima!\n");
                break;

            default:
                printf("Opção inválida!\n"); getchar(); system("clear");
        }
    } while (Escolha != 0);

  return 0;
}
