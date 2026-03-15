// --------------------------------------------------------------------------------------
// /-/-/-/-/-/-/-/-/-/-/-/-/-/-/ DESAFIO FILAS -> PARTE 1 /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/
// --------------------------------------------------------------------------------------
// OBJETIVOS:
// - CRIAR UM ARRAY DO TIPO CARACTERES COM LETRAS MAIÚSCULAS PARA REPRESENTAR AS PEÇAS;
// - INFORMAÇÕES DAS PEÇAS SERÁ [NOME, ID] -> (DEIXA PEÇAS SALVAS AUTOMÁTICAS);
// - FUNÇÕES SERÃO [VISUALIZAR, REMOVER E ADICIONAR];
// - MENU COM AS 3 OPÇÕES -> INSERÇÃO/REMOÇÃO E SAIR;
// - FUNÇÃO VISUALIZAR INTERNA APÓS AS OUTRAS FUNÇÕES;
// - FUNÇÕES INTERNAS (VERIFICAÇÕES);
// --------------------------------------------------------------------------------------

// BIBLIOTECAS
#include <stdio.h> // INCLUI FUNÇÕES DE ENTRADA E SAÍDA
#include <stdlib.h> // INCLUI FUNÇÕES GERAIS
#include <string.h> // INCLUI FUNÇÕES DE MANIPULAÇÃO DE STRINGS

// CONSTANTE
#define TAM 5 // TAMANHO MÁXIMO DA FILA
#define STRING 50 // TAMANHO MÁXIMO DE UMA STRING DE PEÇA

// STRUCTS
typedef struct {
    char Pecas[STRING]; // STRING REPRESENTANDO O NOME DA PEÇA
    int Id; // IDENTIFICADOR DA PEÇA
} Elementos;

typedef struct {
    Elementos Itens[TAM]; // ARRAY DE ELEMENTOS DA FILA
    int Inicio; // INDICE DO PRIMEIRO ELEMENTO
    int Fim; // INDICE DO PRÓXIMO ELEMENTO LIVRE
    int Total; // TOTAL DE ELEMENTOS NA FILA
} Fila;

// FUNÇÕES
void Limpar(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF ); // LIMPA O BUFFER DO TECLADO
}

int Verificar1(Fila *f){
    return f->Total >= TAM; // RETORNA 1 SE FILA CHEIA
}

int Verificar2(Fila *f){
    return f->Total == 0; // RETORNA 1 SE FILA VAZIA
}

void Inicializacao(Fila* f){
    f->Inicio = 0; // INICIALIZA INICIO
    f->Fim = 0; // INICIALIZA FIM
    f->Total = 0; // INICIALIZA TOTAL
}

int Menu(){
    int Escolha;

    printf("-----------------------------------------\n");
    printf("/////////// \"MENU PRINCIPAL\" ///////////\n");
    printf("-----------------------------------------\n");
    printf("1.Adicionar Uma Nova Peça\n");
    printf("2.Remover Uma Peça da Fila\n");
    printf("0.Sair\n");
    printf("-----------------------------------------\n");
    printf("Digite Sua Opção: ");
      scanf("%d", &Escolha); // LÊ OPÇÃO DO USUÁRIO
        Limpar(); // LIMPA BUFFER

  return Escolha; // RETORNA OPÇÃO ESCOLHIDA
}

void Adicionar(Fila* f, Elementos p){
    if (Verificar1(f)){ // VERIFICA SE FILA CHEIA
        printf("Fila Cheia, Remova Uma peça para Uma Nova Inserção!");
      return;
    }

    f->Itens[f->Fim] = p; // ADICIONA ELEMENTO NO FIM
    f->Fim = (f->Fim +1) % TAM; // INCREMENTA FIM (CIRCULAR)
    f->Total++; // INCREMENTA TOTAL
}

int Remover(Fila* f, Elementos *p){
    if (Verificar2(f)){ // VERIFICA SE FILA VAZIA
        printf("Fila Vazia, Adicione Uma Nova Peça!\n");
      return 1;
    }

    *p = f->Itens[f->Inicio]; // ARMAZENA ELEMENTO REMOVIDO
    f->Inicio = (f->Inicio +1) % TAM; // INCREMENTA INICIO (CIRCULAR)
    f->Total--; // DECREMENTA TOTAL
}

void Exibir(Fila *f){
    if (Verificar2(f)) return; // SE FILA VAZIA, SAI

    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA FILA\" <-<-<-<-\n");
    
    for (int i = 0, rs = f->Inicio; i < f->Total; i++, rs = (rs +1) % TAM){
        printf("[%s, %d]\t", f->Itens[rs].Pecas, f->Itens[rs].Id); // EXIBE CADA ELEMENTO
    }

    printf("\n----------------------------------------\n");
}

int main(){
    Fila Fila; // DECLARA FILA
    Inicializacao(&Fila); // INICIALIZA FILA

    Elementos Removida; // ELEMENTO REMOVIDO
    Elementos Existente0 = {'I', Existente0.Id = 0}; // ELEMENTO FIXO 0
    Elementos Existente1 = {'O', Existente1.Id = 1}; // ELEMENTO FIXO 1
    Elementos Existente2 = {'T', Existente2.Id = 2}; // ELEMENTO FIXO 2
    Elementos Existente3 = {'L', Existente3.Id = 3}; // ELEMENTO FIXO 3
    Elementos Nova; // ELEMENTO NOVO ADICIONADO PELO USUÁRIO

    // ADICIONA ELEMENTOS INICIAIS NA FILA
    Adicionar(&Fila, Existente0);
    Adicionar(&Fila, Existente1);
    Adicionar(&Fila, Existente2);
    Adicionar(&Fila, Existente3);

    int Opcao; // OPÇÃO DO MENU

    do{
        Opcao = Menu(); // MOSTRA MENU
        system("clear"); // LIMPA TELA

        switch(Opcao){
            case 1: // ADICIONAR NOVA PEÇA
                if (Verificar1(&Fila)){
                  printf("Fila Cheia, Remova uma Peça para Adicionar uma Nova!\n");

                  printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
                    getchar();
                      system("clear");
                  break;
                }

                printf("\n----------------------------------------\n");
                printf("----\"Adicione Peças a Fila\"----\n");
                printf("----------------------------------------\n");

                printf("Qual Peça você quer Adicionar? ");
                fgets(Nova.Pecas, STRING, stdin); // LÊ NOME DA PEÇA

                Nova.Pecas[strcspn(Nova.Pecas,"\n")] = '\0'; // REMOVE '\n' DO FIM

                printf("Digite uma Número de Identificação para a Peça: ");
                  scanf("%d", &Nova.Id); // LÊ ID
                    Limpar(); // LIMPA BUFFER

                printf("----------------------------------------\n");
                  system("clear");

                Adicionar(&Fila, Nova); // ADICIONA NA FILA
                printf("Peça Adicionada a Fila: [%s, %d]\n", Nova.Pecas, Nova.Id);

                Exibir(&Fila); // EXIBE FILA

                printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
                  getchar();
                    system("clear");
                break;

              case 2: // REMOVER PEÇA
                int a = Remover(&Fila, &Removida); // REMOVE ELEMENTO

                if (a != 1){ // SE REMOÇÃO FOI REALIZADA
                    printf("Peça Removida da Fila: [%s, %d]\n", Removida.Pecas, Removida.Id);
                  Exibir(&Fila); // EXIBE FILA
                }

                printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
                  getchar();
                    system("clear");
                break;

              case 0: // SAIR
                printf("\nSaindo do Sistema, Bay...\n\n");
              break;

            default: // OPÇÃO INVÁLIDA
                printf("Opção Invalida, Tente Novamente!\n");
              break;
        }
    } while (Opcao != 0); // REPETE ENQUANTO NÃO SAIR

  return 0;
}
