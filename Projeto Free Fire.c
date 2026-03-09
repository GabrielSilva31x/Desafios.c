// =====================================================================
// ------------------ DESAFIO FREE FIRE -> FASE 1 ----------------------
// =====================================================================
// OBJETIVO: CRIAR UM INVENTARIO/MOCHILA PARA MEU JOGO - FREE FIRE
// >> USO DE STRUCT
// >> LISTA LINEAR (ARRAYS)
// >> FUNÇÕES / LOOP / ESTRUTURAS
// >> ARRAY / PONTEIROS / PASSAGEM POR REFERÊNCIA
// >> CÓDIGO MODULARIZADO
// =====================================================================

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define MAX 20       // Número máximo de itens
#define STRING 50    // Tamanho máximo de nomes e tipos

// =================== STRUCT MOCHILA =================== //
typedef struct {
    char Nome[MAX][STRING];       // Array de nomes
    char Tipo[MAX][STRING];       // Array de tipos
    int Quantidade[MAX];          // Array de quantidades
    int Total;                    // Total de itens armazenados
} Mochila;

// =================== PROTÓTIPOS ======================== //
void AdicionarItens(Mochila *Inventario);
void RemoverItem(Mochila *Inventario);
void ExibirItens(Mochila *Inventario);
void LiberaMemorias(Mochila* Memoria);
int MenuOpcoes();

// =================== FUNÇÕES =========================== //

// Função do menu principal
int MenuOpcoes(){

    int opcoes;
    printf("================================\n");
    printf("/-/-/ MENU DO SOBREVIVENTE /-/-/\n");
    printf("================================\n");
    printf("1.Adicionar Itens\n");
    printf("2.Remover Itens\n");
    printf("3.Mostrar Mochila\n");
    printf("0.Sair\n");
    printf("--------------------------------\n");
    printf("Digite sua Opção: ");
      scanf("%d", &opcoes);
        getchar();  // Limpa buffer do teclado
          system("clear");

    return opcoes;
}

// Adicionar itens à mochila
void AdicionarItens(Mochila *Inventario){
    int Itens = Inventario->Total;

    if (Itens >= MAX){
        printf("Espaço Insuficiente para mais um Item!\n");
    return;
    }
    
     printf("----------------------------------------\n");
    printf("\n<<<<>>>> ADICIONAR UM NOVO ITEM <<<<>>>>\n\n");
     printf("----------------------------------------\n");


    printf("Digite o Nome do Item: ");
    fgets(Inventario->Nome[Itens], STRING, stdin);

    printf("Digite o Tipo do Item (Ex: Ofensivo, Cura, Proteção): ");
    fgets(Inventario->Tipo[Itens], STRING, stdin);

    // Remove '\n' final
    Inventario->Nome[Itens][strcspn(Inventario->Nome[Itens], "\n")] = '\0';
    Inventario->Tipo[Itens][strcspn(Inventario->Tipo[Itens], "\n")] = '\0';

    printf("Digite a Quantidade do Item: ");
    scanf("%d", &Inventario->Quantidade[Itens]);
    getchar();

    Inventario->Total++;
    printf("\nItem Adicionado com SUCESSO!\n");
}

// Remover item da mochila
void RemoverItem(Mochila *Inventario){
    if (Inventario->Total == 0){
        printf("Não há itens na mochila!\n");
    return;
    }

    char Opcao[STRING];

    printf("Digite o Nome do Item que deseja REMOVER: ");
    fgets(Opcao, sizeof(Opcao), stdin);
    Opcao[strcspn(Opcao, "\n")] = '\0';

    int pro = -1;
    for (int i = 0; i < Inventario->Total; i++){
        if (strcmp(Inventario->Nome[i], Opcao) == 0){
            pro = i;
        break;
        }
    }

    if (pro == -1){
        printf("\nItem não encontrado na mochila!\n");
    return;
    }

    // Move todos os itens seguintes uma posição para trás
    for (int i = pro; i < Inventario->Total - 1; i++){
        strcpy(Inventario->Nome[i], Inventario->Nome[i+1]);
        strcpy(Inventario->Tipo[i], Inventario->Tipo[i+1]);
        Inventario->Quantidade[i] = Inventario->Quantidade[i+1];
    }

    Inventario->Total--;
    printf("Item \"%s\" removido com SUCESSO!\n", Opcao);
}

// Exibir itens da mochila
void ExibirItens(Mochila *Inventario){
    if (Inventario->Total == 0){
        printf("Inventário da mochila está vazio!\n");
    return;
    }

    printf("=================================================\n");
    printf(" /<->/ MOCHILA DO SOBREVIVENTE -> (%d/%d) /<->/ \n", Inventario->Total, MAX);
    printf("=================================================\n");
    printf("\tNome\t   | \tTipo\t   |  Qtd\n");
    printf("=================================================\n");

    for (int i = 0; i < Inventario->Total; i++){
        printf("\t%-10s |\t%-10s |\t%-6d\n",
            Inventario->Nome[i],
            Inventario->Tipo[i],
            Inventario->Quantidade[i]);
    printf("-------------------------------------------------\n");

    }
}

// Liberar memória
void LiberaMemorias(Mochila* Memoria){
    free(Memoria);
      Memoria = NULL;
    printf("Memória liberada com SUCESSO!\n");
}

// =================== BLOCO PRINCIPAL =================== //
  int main(){
    
    // Aloca memória para a mochila
    Mochila *slots = (Mochila*) malloc(sizeof(Mochila));
    slots->Total = 0;  // Inicializa contagem de itens

       int opcoes;
    do {
        opcoes = MenuOpcoes();

        switch (opcoes){
            case 1:
                AdicionarItens(slots);

                printf("\nPressione \"ENTER\" para continuar...\n");
                  getchar();
                    system("clear");
                break;

            case 2:
                RemoverItem(slots);

                  printf("\nPressione \"ENTER\" para continuar...\n");
                    getchar();
                      system("clear");
                break;

            case 3:
                ExibirItens(slots);

                printf("\nPressione \"ENTER\" para continuar...\n");
                  getchar();
                    system("clear");
              break;

            case 0:
                LiberaMemorias(slots);

                  printf("\nSaindo do Sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
                  getchar();
                    system("clear");
                break;
        }

    } while (opcoes != 0);

  return 0;
}
