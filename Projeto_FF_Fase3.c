// =============================================================== //
// ----------------- COD.TORRE DE FUGA -> FASE 3 ----------------- //
// =============================================================== //
// OBJETIVOS: CREATE UM CÓDIGO COM FUNÇÕES DE ORDENAÇÃO DIFERENTES
// -> TIPOS DE ORDENAÇÃO:
// >> BUBBLE SORT
// >> INSERTION SORT 
// >> SELECTION SORT
// =============================================================== //

// BIBLIOTECAS
#include <stdio.h>  // INCLUI FUNÇÕES DE ENTRADA E SAÍDA
#include <string.h> // INCLUI FUNÇÕES DE MANIPULAÇÃO DE STRINGS
#include <stdlib.h> // INCLUI FUNÇÕES GERAIS (MALLOC, FREE, SYSTEM)
#include <time.h>   // INCLUI FUNÇÕES DE TEMPO (CLOCK)

// CONSTANTES
#define TAMANHO 20 // QUANTIDADE MÁXIMA DE ITENS
#define STRING 50  // TAMANHO MÁXIMO DE STRING PARA NOME/TIPO

// STRUCT
typedef struct {
    char Nome[STRING];      // NOME DO ITEM
    char Tipo[STRING];      // TIPO DO ITEM
    int Quantidade;         // QUANTIDADE DO ITEM
    int Prioridade;         // PRIORIDADE DO ITEM
} Torre;

// FUNÇÕES
int MENU(); // FUNÇÃO MENU PRINCIPAL
void INSEÇÃO(Torre *Itens, int *Total); // ADICIONAR ITEM
void REMOÇÃO(Torre *Itens, int *Total); // REMOVER ITEM
void EXIBIR(Torre *Itens, int *Total); // EXIBIR ITENS
void ORDENAÇÃO(); // FUNÇÃO VAZIA, PODE IMPLEMENTAR ORDENAR
int BUSCABINÁRIA(Torre *Itens, int Inicio, int Final, char Buscar[]); // BUSCA BINÁRIA
void Limpar(); // LIMPA BUFFER

// FUNÇÕES DE ORDENAÇÃO
void BUBBLESORT(Torre *Itens, int Total, int *cmp); 
void INSERTIONSORT(Torre *Itens, int Total, int *qtd); 
void SELECTIONSORT(Torre *Itens, int Total, int *temp); 
void SORT(Torre *a, Torre *b); // TROCA ENTRE DOIS ELEMENTOS
int Menu2(); // MENU DE ORDENAÇÃO
int VerificadorLista(Torre *Itens, int Total); // VERIFICA SE LISTA ESTÁ ORDENADA

// COD. RAIZ
int main(){

    Torre Torre[TAMANHO]; // ARRAY DE ITENS
    int Tudo = 0;          // TOTAL DE ITENS
    int Opcao;             // OPÇÃO DO MENU
    __clock_t Inicio, Fim; // VARIÁVEL PARA TEMPO DE ORDENAÇÃO
    float Temp;            // TEMPO EM SEGUNDOS

    do {
        Opcao = MENU(); // CHAMA MENU
        system("clear"); // LIMPA TELA

        switch (Opcao){

            case 1: // INSERIR ITEM
                INSEÇÃO(Torre, &Tudo);
                printf("Precione \"Enter\" para Continuar...\n");
                getchar();
                system("clear");
            break;

            case 2: // REMOVER ITEM
                REMOÇÃO(Torre, &Tudo);
                printf("Precione \"Enter\" para Continuar...\n");
                getchar();
                system("clear");
            break;

            case 3: // EXIBIR ITENS
                EXIBIR(Torre, &Tudo);
                printf("Precione \"Enter\" para Continuar...\n");
                getchar();
                system("clear");
            break;

            case 4: // MENU DE ORDENAÇÃO
                int Contador = 0;
                int Escolha;

                do{
                    Escolha = Menu2(); // ESCOLHA DE ORDENACAO

                    switch (Escolha){

                        case 1: // BUBBLE SORT POR NOME
                            Inicio = clock();
                            BUBBLESORT(Torre, Tudo, &Contador);
                            Fim = clock();

                            printf("===========================================================\n");
                            printf("  />-</>-</>-</ MASTER'S BACKPACK -> (%d/20) />-</>-</>-</ \n", Tudo);
                            printf("===========================================================\n");
                            printf("\tNome\t   | \tTipo\t   |  Qtd  | Prioridade\n");
                            printf("===========================================================\n");

                            for (int i = 0; i < Tudo; i++){
                                printf("\t%-10s |\t%-10s | %3d   | %5d\n", 
                                    Torre[i].Nome, 
                                    Torre[i].Tipo, 
                                    Torre[i].Quantidade, 
                                    Torre[i].Prioridade);
                            }

                            Temp = (float)(Fim - Inicio) / CLOCKS_PER_SEC;
                            printf("-----------------------------------------------------------\n");
                            printf("\nTempo de Ordenação da Lista: %f.seg\n", Temp);
                            printf("Total de Comparações: %d\n", Contador);
                            printf("-----------------------------------------------------------\n");
                            printf("Precione \"Enter\" para Continuar...\n");
                            getchar();
                        break;

                        case 2: // INSERTION SORT POR TIPO
                            Inicio = clock();
                            INSERTIONSORT(Torre, Tudo, &Contador);
                            Fim = clock();

                            printf("===========================================================\n");
                            printf("  />-</>-</>-</ MASTER'S BACKPACK -> (%d/20) />-</>-</>-</ \n", Tudo);
                            printf("===========================================================\n");
                            printf("\tNome\t   | \tTipo\t   |  Qtd  | Prioridade\n");
                            printf("===========================================================\n");

                            for (int i = 0; i < Tudo; i++){
                                printf("\t%-10s |\t%-10s | %3d   | %5d\n", 
                                    Torre[i].Nome, 
                                    Torre[i].Tipo, 
                                    Torre[i].Quantidade, 
                                    Torre[i].Prioridade);
                            }

                            Temp = (float)(Fim - Inicio) / CLOCKS_PER_SEC;
                            printf("-----------------------------------------------------------\n");
                            printf("\nTempo de Ordenação da Lista: %.f.seg\n", Temp);
                            printf("Total de Comparações: %d\n", Contador);
                            printf("-----------------------------------------------------------\n");
                            printf("Precione \"Enter\" para Continuar...\n");
                            getchar();
                        break;

                        case 3: // SELECTION SORT POR PRIORIDADE
                            Inicio = clock();
                            SELECTIONSORT(Torre, Tudo, &Contador);
                            Fim = clock();

                            printf("===========================================================\n");
                            printf("  />-</>-</>-</ MASTER'S BACKPACK -> (%d/20) />-</>-</>-</ \n", Tudo);
                            printf("===========================================================\n");
                            printf("\tNome\t   | \tTipo\t   |  Qtd  | Prioridade\n");
                            printf("===========================================================\n");

                            for (int i = 0; i < Tudo; i++){
                                printf("\t%-10s |\t%-10s | %3d   | %5d\n", 
                                    Torre[i].Nome, 
                                    Torre[i].Tipo, 
                                    Torre[i].Quantidade, 
                                    Torre[i].Prioridade);
                            }

                            Temp = (float)(Fim - Inicio) / CLOCKS_PER_SEC;
                            printf("-----------------------------------------------------------\n");
                            printf("\nTempo de Ordenação da Lista: %.2f.seg\n", Temp);
                            printf("Total de Comparações: %d\n", Contador);
                            printf("-----------------------------------------------------------\n");
                            printf("Precione \"Enter\" para Continuar...\n");
                            getchar();
                        break;

                        case 0: // SAIR DO MENU ORDENACAO
                            printf("Retornando para o Menu Principal..\n");
                        break;

                        default:
                            printf("Opção Invalida, Tente Novamente!\n");
                    }

                } while (Escolha != 0);

                printf("Precione \"Enter\" para Continuar...\n");
                getchar();
                system("clear");
            break;

            case 5: // BUSCA BINÁRIA POR NOME
                if(VerificadorLista(Torre, Tudo)){ // VERIFICA SE LISTA ORDENADA
                    char Busca[STRING];

                    printf("---------------------------\n");
                    printf("</></> BUSCA BINARIA </></>\n");
                    printf("---------------------------\n");
                    printf("Digite o Nome(Item) que Deseja ver o Dados: ");
                    fgets(Busca, STRING, stdin);
                    Busca[strcspn(Busca,"\n")] = '\0';
                    system("clear");

                    int A = BUSCABINÁRIA(Torre, 0, Tudo -1, Busca);

                    if(A != -1){
                        printf("---------------------------\n");
                        printf("</></> RESULTADO: </></>\n");
                        printf("---------------------------\n");
                        printf("Nome: \"%s\"\nTipo: \"%s\"\nQtd: \"%d\"\nPrioridade: \"%d\"\n", 
                            Torre[A].Nome,
                            Torre[A].Tipo,
                            Torre[A].Quantidade,
                            Torre[A].Prioridade);
                    } else {
                        printf("Item Não Encontrado na Sua Mochila!\n");
                    }
                } else {
                    printf("Os Itens da Sua Mochila não Estão Ordenados para Realizar a Busca,\nRealize a Ordenação Primeiro Por \"NOME\" na Opção(4)...\n");
                }
                printf("\nPrecione \"Enter\" para Continuar...\n");
                getchar();
                system("clear");
            break;

            case 0: // SAIR
                if (VerificadorLista(Torre, Tudo)){
                    printf("\nTransmissão da Torre Inicia, Helicóptero em Fuga!\n");
                } else {
                    printf("Missão Abandonada!\n");
                    printf("Precione \"Enter\" para Continuar...\n");
                    getchar();
                    system("clear");
                }
            break;

            default:
                printf("Opção Invalida!\n");
                system("clear");
        }

    } while (Opcao != 0);

    return 0;
}

// FUNÇÕES
int MENU(){
    int opcoes;

    printf("=====================================\n");
    printf("/-/-/ TORRE DE RADIO <-> \"FUGA\" /-/-/\n");
    printf("=====================================\n");
    printf("1.Adicionar Itens para Torre\n");
    printf("2.Remover Itens Desnecessarios\n");
    printf("3.Verificar os Itens da Mochila\n");
    printf("4.Organiza Mochila -> (Ordenação)\n");
    printf("5.Buscar por Itens Especificos na Mochila\n");
    printf("0.Sair\n");
    printf("-------------------------------------\n");

    printf("Digite sua Opção: ");
    scanf("%d", &opcoes );
    Limpar();
    system("clear");

    return opcoes;
}

void INSEÇÃO(Torre *Itens, int *Total){
    int TotalLista = *Total;

    if (TotalLista >= TAMANHO){
        printf("Espaço Insuficiente para mais um Item!\n");
        return;
    } else {
        printf("\n</></></></></></></></></></></></></></></>\n");
        printf(" ->->->-> \"ADICIONAR UM NOVO ITEM\" <-<-<-<-\n");
        printf("</></></></></></></></></></></></></></></>\n\n");

        printf("Digite o \"Nome\" do Item: ");
        fgets(Itens[TotalLista].Nome, STRING, stdin);

        printf("Digite o \"Tipo\" do Item(Ex: Cabos, Reparador, Hardware): ");
        fgets(Itens[TotalLista].Tipo, STRING, stdin);

        Itens[TotalLista].Nome[strcspn(Itens[TotalLista].Nome,"\n")] = '\0';
        Itens[TotalLista].Tipo[strcspn(Itens[TotalLista].Tipo,"\n")] = '\0';

        printf("Digite a \"Qtd\" do Item: ");
        scanf("%d", &Itens[TotalLista].Quantidade);
        getchar();

        printf("Digite o Nivel de \"Prioridade\" do Item: ");
        scanf("%d", &Itens[TotalLista].Prioridade);
        getchar();

        (*Total)++;
        printf("\nItem Adicionado com \"SUCESSO\"...\n");  
        return;
    }
}

void REMOÇÃO(Torre *Itens, int *Total){
    int TotalLista = *Total;
    char Opcao[STRING];
    int pro = -1;
    int i;

    if (TotalLista == 0){
        printf("Não há Itens na Mochila do Sobrevivente!\n");
        return;
    } else {
        printf("------- MOCHILA DO SOBREVIVENTE -------\n");
        printf("Digite o \"NOME\" do Item que Deseja \"REMOVER\": ");
        fgets(Opcao,sizeof(Opcao),stdin);
        Opcao[strcspn(Opcao,"\n")] = '\0';

        for(i = 0; i < TotalLista; i++){
            if (strcmp(Itens[i].Nome, Opcao) == 0){
                pro = i;   
            }
        }
    }

    if (pro == -1){
        printf("\nItem não Encontrado na Mochila!\n");
        return;
    } else {
        for (i = pro; i < TotalLista -1; i++){
            Itens[i] = Itens[i+1];
        }
        printf("Item: \"%s\" Removido com \"SUCESSO\"\n", Opcao);
    }
    (*Total)--;
    return;
}

void EXIBIR(Torre *Itens, int *Total){
    int TotalLista = *Total;
    int i;

    if (TotalLista == 0 ){
        printf("Inventario da Mochila está Vazia\n");
        return;
    }

    printf("===========================================================\n");
    printf("  />-</>-</>-</ MASTER'S BACKPACK -> (%d/20) />-</>-</>-</ \n", TotalLista);
    printf("===========================================================\n");
    printf("\tNome\t   | \tTipo\t   |  Qtd  | Prioridade\n");
    printf("===========================================================\n");

    for (i = 0; i < TotalLista; i++){
        printf("\t%-10s |\t%-10s | %3d   | %5d\n", 
            Itens[i].Nome, 
            Itens[i].Tipo, 
            Itens[i].Quantidade, 
            Itens[i].Prioridade);
    }
    printf("-----------------------------------------------------------\n\n");
}

int BUSCABINÁRIA(Torre *Itens, int Inicio, int Final, char Buscar[]){
    if ( Inicio > Final ) return -1;

    int meio = Inicio + (Final - Inicio) /2;
    int cmp = strcmp(Itens[meio].Nome, Buscar);

    if (cmp == 0){
        return meio;
    } else if (cmp < 0){
        return BUSCABINÁRIA(Itens, meio +1, Final, Buscar);
    } else {
        return BUSCABINÁRIA(Itens, Inicio, meio -1, Buscar);   
    } 
}

void Limpar(){
    int b;
    while((b = getchar()) != '\n' && b != EOF);
}

// FUNÇÕES DE ORDENAÇÃO
void BUBBLESORT(Torre *Itens, int Total, int *cmp){
    for (int a = 0; a < Total -1; a++){
        for (int b = 0; b < Total -1 -a; b++){
            if(strcmp(Itens[b].Nome, Itens[b+1].Nome) > 0)
                SORT(&Itens[b], &Itens[b+1]);
            (*cmp)++;
        }
    }
}

void INSERTIONSORT(Torre *Itens, int Total, int *qtd){
    for (int i = 1; i < Total; i++){
        Torre chave = Itens[i];
        int f = i -1;

        while(f >= 0 && strcmp(Itens[f].Tipo, chave.Tipo) > 0){
            Itens[f + 1] = Itens[f]; 
            f--;
            (*qtd)++;
        }
        Itens[f+1] = chave;
    }
}

void SELECTIONSORT(Torre *Itens, int Total, int *temp){
    for (int i = 0; i < Total; i++){
        int x = i;
        (*temp)++;
        for (int s = i +1; s < Total; s++){
            if (Itens[s].Prioridade < Itens[x].Prioridade){
                x = s;
            }
        }
        if(x != i){
            SORT(&Itens[i], &Itens[x]);
        }
    }
}

void SORT(Torre *a, Torre *b){
    Torre x = *a;
    *a = *b;
    *b = x;
}

int Menu2(){
    int Escolha;

    printf("\n-----------------------------------\n");
    printf("------- Tipos de Ordenação --------");
    printf("\n-----------------------------------\n");
    printf("1.Ordena por Nome\n");
    printf("2.Ordena por Tipo\n");
    printf("3.Ordena por Prioridade\n");
    printf("0.Sair\n");
    printf("-----------------------------------\n");
    printf("Digite sua Opção: ");
    scanf("%d", &Escolha);
    Limpar();
    system("clear");

    return Escolha;
}

int VerificadorLista(Torre *Itens, int Total) {
    for (int i = 0; i < Total - 1; i++) {
        if (strcmp(Itens[i].Nome, Itens[i + 1].Nome) > 0) {
            return 0; 
        }
    }
    return 1; 
}
