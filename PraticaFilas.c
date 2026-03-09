// ASSUNTO 1:
// PRATICAS -> (FILAS) - PARTE 1:
/*

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// CONSTANTE
#define TAM 10

// STRUCT(s)
typedef struct {
   char Nomes[50];
   int idade;
} Ativos;

typedef struct {
  Ativos Pecas[TAM];
  int Inicio;
  int Final;
  int Total;
} Fila;

// FUNÇÕES
void Adicionar(Fila *f, Ativos a);
void Remover(Fila *f, Ativos *a);
void Visualizar(Fila *f);
int VerificacaoONE(Fila *f);
int VerificacaoTWO(Fila *f);
void Inicializacao(Fila *f);

// INPUT CODIGO
int main(){

   Fila Fila;

Inicializacao(&Fila);

Ativos p1 = {"Gabriel", 21};
  Ativos p2 = {"Ariadina", 19};
    Ativos p3 = {"Lucas", 20};

  Ativos Removido;

Adicionar(&Fila, p1);
  Adicionar(&Fila, p2);
    Adicionar(&Fila, p3);

      Visualizar(&Fila);

    Remover(&Fila, &Removido);
      printf("\n\nRemovido da Fila: Nome: %s, Idade: %d\n", Removido.Nomes,Removido.idade);

  Visualizar(&Fila);

return 0;
}

void Visualizar(Fila *f){
   if(VerificacaoONE(f)){
    printf("Mochila Está Vazia!\n");
      return;
   }
   printf("\n\"PESSOAS DA FILA\"\n");
    for (int i = 0, rs = f->Inicio; i < f->Total; i++, rs = (rs + 1) % TAM){
      printf("\n Nome: %s\n Idade: %d\n", f->Dados[rs].Nomes, f->Dados[rs].idade);
   }
}
void Remover(Fila *f, Ativos *a){
   if (VerificacaoONE(f)){
    printf("Mochila Está Vazia!\n");
      return;
    }

   *a = f->Dados[f->Inicio];
    f->Inicio = (f->Inicio +1) % TAM;
    f->Total--;
}
void Adicionar(Fila *f, Ativos a){

   if (VerificacaoTWO(f)){
     printf("Mochila Está Cheia!\n");
      return;
   }
    f->Dados[f->Final] = a;
    f->Final = (f->Final + 1) % TAM;
    f->Total++;
}
void Inicializacao(Fila *f){
    f->Inicio = 0;
    f->Final = 0;
    f->Total = 0;
}
int VerificacaoTWO(Fila *f){
   
  return f->Total >= TAM;
}
int VerificacaoONE(Fila *f){
   return f->Total == 0;
}


// ----------------------- DESAFIO FILAS -> FASE 1 ------------------------------
// OBJETIVOS:
// - Criar um array do Tipo caracteres com letras maiusculas para representar as peças;
// - Informações das peças será [Nome, Id] -> (Deixa Peças Salvas Automaticas);
// - Funções Será [visualizar, Remover e Adicionar];
// - Menu com as 3 opcoes -> inseção/remocao e sair;
// - Função Visualizar Interna apos as outras funções;
// - Funções internas (Verificações);

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTE
#define TAM 5
#define STRING 50

// STRUCTS
typedef struct {
  char Pecas[STRING];
    int Id; 
} Elementos;

typedef struct {
  Elementos Elementos[TAM];
  int Inicio;
  int Fim;
  int Total;
} Fila;

// FUNÇÕES
void Limpar(){
      int c;
     while ((c = getchar()) != '\n' && c != EOF ); 
   }
int Verificar1(Fila *f){

    return f->Total >= TAM;
  }
int Verificar2(Fila *f){
  
  return f->Total == 0;
     
  }
void Inicializacao(Fila* f){
 f->Inicio = 0;
 f->Fim = 0;
 f->Total = 0;
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
    scanf("%d", &Escolha);
      Limpar();

        return Escolha;
  }
void Adicionar(Fila* f, Elementos p){
      if (Verificar1(f)){
          printf("Fila Cheia, Remova Uma peça para Uma Nova Inserção!");
        return;
      }

    f->Itens[f->Fim] = p;
    f->Fim = (f->Fim +1) % TAM;
    f->Total++;

  }
int Remover(Fila* f, Elementos *p){
    if (Verificar2(f)){
      printf("Fila Vazia, Adicione Uma Nova Peça!\n");
        return 1;
      }

    *p = f->Itens[f->Inicio];
     f->Inicio = (f->Inicio +1) % TAM;
     f->Total--;
  }
void Exibir(Fila *f){
    if (Verificar2(f)){
      return;
    }
    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA FILA\" <-<-<-<-\n");
    for (int i = 0, rs = f->Inicio; i < f->Total; i++, rs = (rs +1) % TAM){
      printf("[%s, %d]\t", f->Itens[rs].Pecas, f->Itens[rs].Id);
    }
    printf("\n----------------------------------------\n");

  }

int main(){
  
  Fila Fila;

    Inicializacao(&Fila);
  
  Elementos Removida;
    Elementos Existente0 = {'I', Existente0.Id = 0};
      Elementos Existente1 = {'T', Existente1.Id = 1};
        Elementos Existente2 = {'X', Existente2.Id = 2};
    Elementos Existente3 = {'L', Existente3.Id = 3};
  Elementos Nova;

  Adicionar(&Fila, Existente0);
    Adicionar(&Fila, Existente1);
  Adicionar(&Fila, Existente2);
    Adicionar(&Fila, Existente3);

    int Opcao;

  do{

    Opcao = Menu();
      system("clear");

    switch(Opcao){

    case 1:

    if (Verificar1(&Fila)){
        printf("Fila Cheia, Remova uma Peça para Adicionar uma Nova!\n");

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
          getchar();
            system("clear");
      break;
    }

      printf("\n----------------------------------------\n");
       printf("----\"Adicione Peças a Fila\"----");
      printf("\n----------------------------------------\n");
      printf("Qual Peça você quer Adicionar? ");
        fgets(Nova.Pecas, STRING, stdin);

      Nova.Pecas[strcspn(Nova.Pecas,"\n")] = '\0';

      printf("Digite uma Número de Identificação para a Peça: ");
        scanf("%d", &Nova.Id);
          Limpar();

        printf("----------------------------------------\n");
            system("clear");
          
        Adicionar(&Fila, Nova);
        printf("Peça Adicionada a Fila: [%s, %d]\n", Nova.Pecas, Nova.Id);

          Exibir(&Fila);

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
          getchar();
            system("clear");
            
    break;

    case 2:
       int a = Remover(&Fila, &Removida);

        if (a != 1){
          printf("Peça Removida da Fila: [%s, %d]\n", Removida.Pecas, Removida.Id);
        
          Exibir(&Fila);
        }

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
          getchar();
            system("clear");

    break;

    case 0:
        printf("\nSaindo do Sistema...\n\n");
    break;

      default:
        printf("Opção Invalida, Tente Novamente!\n");

    }
  } while (Opcao != 0);

  return 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------ //
// ASSUNTO 2:
// PRATICAS -> (PILHA) - PARTE 1:

// BIBLIOTECAS;
#include <string.h>
#include <stdlib.h>  
#include <stdio.h>

// CONSTANTES;
#define MAX 5
#define STRING 50

// STRUCT 1
typedef struct {
   char Nome[STRING];
   int Idade;
} Info;

// STRUCT 2;
typedef struct {
  Info Dados[MAX];
    int Topo;
} Pilha;

// FUNÇÕES:
// IMPLEMENTAÇÃO;
void Push(Pilha *p, Info Novo){
  if (Pilhacheia(p)){
     printf("Pilha Já atingiu sua Capacidade Maxima!\n");
    return;
  }
  p->Dados[p->Topo] = Novo;
  p->Topo++;
}
void Pop(Pilha *p, Info *Removido){
  if (PilhaVazia(p)){
    printf("Pilha Vazia, Faça um Push para Adicinar um \"Novo\" Item a Pilha!\n");
      return;
   }
  *Removido = p->Dados[p->Topo];
   p->Topo--;
}
void Peek(Pilha *p, Info *Visualizar){
  if (PilhaVazia(p)){
    printf("Pilha Vazia, Faça um Push para Adicinar um \"Novo\" Item a Pilha!\n");
      return;
  }
   *Visualizar = p->Dados[p->Topo];
}
void View(Pilha *p){
   if (PilhaVazia(p)){
    printf("Pilha Vazia, Faça um Push para Adicinar um \"Novo\" Item a Pilha!\n");
      return;
   }

  printf("\n<///> \"Itens da Pilha\" <///>\n");
   for (int i = p->Topo; i >= 0;i--){
    printf("[%s, %d]\t", p->Dados[i].Nome, p->Dados[i].Idade);
   }
  printf("\n");
}
void Free(Pilha *p){
  p->Topo = -1;
}

// COMPLEMENTARES;
int Inicializacao(Pilha *p){
  return p->Topo = -1;
}
int Pilhacheia(Pilha *p){
  return p->Topo <= MAX -1;
}
int PilhaVazia(Pilha *p){
  return p->Topo == -1;
}
int Menu(){
  
  int Escolha;

  printf("-----------------------------------------\n");
  printf("/////////// \"MENU PRINCIPAL\" ///////////\n");
  printf("-----------------------------------------\n");
  printf("1.Visualizar(View) os Itens da Pilha\n");
  printf("2.Adicinar(Push) Um Novo Item a Pilha\n");
  printf("3.Remover(Pop) Um Item da Pilha\n");
  printf("4.Consultar(Peek) Qual o Ultimo Item da Pilha\n");
  printf("0.Sair\n");
  printf("-----------------------------------------\n");
  printf("Digite Sua Opção: ");
    scanf("%d", &Escolha);
      Limpar();

        return Escolha;
}
void Limpar(){
      int c;
     while ((c = getchar()) != '\n' && c != EOF ); 
   }

   // BLOCO DE CODIGO
  int main(){
   
    Pilha Itens[MAX];

  int Opcao;

  Info Item1 = {"Gabriel", Item1.Idade = 0};
    Info Item2 = {"Maria", Item2.Idade = 1};
      Info Item3 = {"Lucas", Item3.Idade = 2};

      Push(&Itens, Item1);
    Push(&Itens, Item2);
  Push(&Itens, Item3);

  do {

    Opcao = Menu();

  switch (Opcao){

    case 1:

    View(&Itens);

      printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
        getchar();
          system("clear");
      
      break;
    
        case 2:
        Info Novo;

        Push(&Itens, Novo);
      
          printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
            getchar();
              system("clear");
      
          break;

            case 3:
            Info Removido;

            Pop(&Itens, &Removido);

              printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
                getchar();
                  system("clear");
      
              break;

            case 4:
            Info Visualizar;

            Peek(&Itens, &Visualizar);
      
              printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
                getchar();
                  system("clear");
      
          break;

        case 0:
          free(&Itens);
      break;

    default:
    printf("Opção Invalida, Tente Novamente!\n");

      printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
    getchar();
  system("clear");
  break;

    }
  } 
  while (Opcao != 0);

    printf("\nSaindo do Sistema...\n");

 return 0;
}

// ------------------------------------------------------------------------------------------ //

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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// CONSTANTES
#define MAX 5
#define STRING 50
#define TAM 3

// STRUCT FILA
typedef struct {
  char Peca;
    int Id; 
} Elementos;

typedef struct {
  Elementos Itens[MAX];
  int Inicio;
  int Fim;
  int Total;
} Fila;

// STRUCT PILHA
typedef struct {
   char parts[STRING];
   int Id;
} Pecas;

typedef struct {
  Pecas Dados[TAM];
    int Topo;
} Pilha;

// FUNÇÕES COMPLEMENTARES
void Limpar(){
  int c;
    while ((c = getchar()) != '\n' && c != EOF ); 
}
void Inicializacao(Pilha *p, Fila *f){
  p->Topo = 0;  // INICIALIZANDO A PILHA

  f->Inicio = 0; 
  f->Fim = 0;
  f->Total = 0; // INICIALIZANDO A FILA
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
    scanf("%d", &Escolha);
      Limpar();

        return Escolha;
}

// FUNÇÕES FILA
int FilaCheia(Fila *f){

    return f->Total >= MAX;
  }
int FilaVazia(Fila *f){
  return f->Total == 0;
}
int Jogar(Fila *f, Elementos *p){
    if (FilaVazia(f)){
      printf("Fila Vazia, Adicione Uma Nova Peça!\n");
        return 1;
      }

    *p = f->Itens[f->Inicio];
     f->Inicio = (f->Inicio +1) % MAX;
     f->Total--;
  }
void Exibir(Fila *f){
    if (FilaVazia(f)){
      return;
    }
    int c = 0;
    printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA FILA\" <-<-<-<-\n");
    for (int i = 0, rs = f->Inicio; i < f->Total; i++, rs = (rs +1) % MAX){
      printf("[%c, %d]\t", f->Itens[rs].Peca, f->Itens[rs].Id = c++);
    }
    printf("\n----------------------------------------\n");

}
void Adicionar(Fila *f, Elementos p){
      if (FilaCheia(f)){
          printf("Fila Cheia, Remova Uma peça para Uma Nova Inserção!");
        return;
      }

    f->Itens[f->Fim] = p;
    f->Fim = (f->Fim +1) % MAX;
    f->Total++;

  }
void GerarPecas(Fila *f){
  Elementos p;
  char pecas[] = {'I','O','T','L','|'};

  if (f->Total == MAX){
   return;
  }
  while (f->Total < MAX){
    int a = rand() % 5;

      p.Peca = pecas[a];
    
        Adicionar(f, p);
  }
}

// FUNÇÕES PILHA
int PilhaCheia(Pilha *p){
    return p->Topo >= TAM;
}
int PilhaVazia(Pilha *p){
    return p->Topo == 0;
}
int PushMove(Fila *f, Pilha *p){
  if (PilhaCheia(p)){
      printf("Pilha Cheia, Use Uma das Peças!\n");
        return 1;
    }
  // ARMAZENA A PEÇA INICIAL DA FILA
  Elementos *v = &f->Itens[f->Inicio];
  
  // MOVE A PEÇA DA FILA >> PILHA 
   p->Dados[p->Topo].parts[0] = v->Peca;
   p->Dados[p->Topo].parts[1] = '\0';
   p->Dados[p->Topo].Id = v->Id;
   p->Topo++;
   
  // REMOVE PEÇA MOVIDA PARA A PILHA
   f->Inicio = (f->Inicio +1) % MAX;
   f->Total--;
}
void Pop(Pilha *p){
  if (p->Dados == 0){
    printf("Pilha Vazia, Faça um Push para Adicinar um \"Novo\" Item a Pilha!\n");
      return;
   }
  int a = p->Topo -1;
    printf("Peça Usada da Pilha: [%s, %d]\n", p->Dados[a].parts, p->Dados[a].Id);

   p->Topo--;
}
void Peek(Pilha *p){
  if (PilhaVazia(p)){
    printf("Pilha Vazia!\n");
      return;
  }
  printf("\n----------------------------------------\n");
    printf("  ->->->-> \"PEÇAS DA PILHA\" <-<-<-<-\n\n");
  for (int i = p->Topo -1; i >= 0; i--){
    printf("[%s, %d]\t", p->Dados[i].parts, p->Dados[i].Id);
  }
    printf("\n----------------------------------------\n\n");
}
void Free(Pilha *p){
  p->Topo = -1;
}

  // BLOCO DE CODIGO
  int main(){

    int t = 0;
  // DECLARANDO VARIAVEIS DA FILA
  Fila Fila = {0};
  
    Elementos Auto;
      Elementos Jogado;

  Elementos a = { .Peca = 'I'};
    Elementos b = { .Peca = 'O'};
      Elementos c = { .Peca = 'T'};
    Elementos d = { .Peca = 'L'};
  Elementos e = { .Peca = 'H'};
  
  

  // DECLARANDO VARIAVEIS DA PILHA
  Pilha Pilha = {0};

    Pecas Usado;
      Pecas View;

  
  Inicializacao(&Pilha, &Fila);

  Adicionar(&Fila, a);
    Adicionar(&Fila, b);
      Adicionar(&Fila, c);
    Adicionar(&Fila, d);
  Adicionar(&Fila, e);
  
  
  srand(time(NULL));

  int Opcao;

  do {

    Opcao = Menu();
      system("clear");

  switch (Opcao){

    case 1:
      int a = Jogar(&Fila, &Jogado);

        if (a != 1){
          printf("Peça jogada: [%c, %d]\n", Jogado.Peca, Jogado.Id);
        }

        GerarPecas(&Fila);

        Exibir(&Fila);

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
          getchar();
            system("clear");
      break;
     
        case 2:
          if (PilhaCheia(&Pilha)){
            printf("Pilha Cheia, Use Uma Peça Para Reserva uma Nova!\n");

            Peek(&Pilha);

              printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
                getchar();
                  system("clear");
        break;
      }
        
        PushMove(&Fila, &Pilha);

          Peek(&Pilha);

        printf("\nPrecione \"ENTER\" para Retorna ao Menu...\n");
          getchar();
            system("clear");
          break;

            case 3:
            if (PilhaVazia(&Pilha)){
              printf("Pilha Vazia!\n");
             break;
            }
              Pop(&Pilha);

                Peek(&Pilha);

                printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n");
              getchar();
            system("clear");
              break;

            case 0:
              Free(&Pilha);
          break;

      default:
      printf("Opção Invalida, Tente Novamente!\n");

        printf("\nPrecione \"ENTER\" para Retornar ao Menu...\n");
          getchar();
            system("clear");
    break;
    }
  } 
    while (Opcao != 0);
       
  printf("\nSaindo do Sistema...\n");
        
return 0;
}


// ------------------------------------------------------------------------------------- //

// ASSUNTO 3:
// PRATICAS -> (Fila&Pilha) - PARTE 3:

// BIBLIOTECAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// CONSTANTES
#define MAX 50
#define STRING 50

// STRUCT FILA
typedef struct {
  char Nomes[STRING];
  int Idade;
} Pessoas;

// STRUCT FILA
typedef struct {
  Pessoas Dados[MAX];
  int Fim, Inicio;
} Fila;

// STRUCT PILHA
typedef struct {
  Pessoas Dados[MAX];
  int Topo;
} Pilha;

// FUNÇOES:
// COMPLEMENTARES
void InicializacaoF(Fila *f){
  f->Inicio = 0;
  f->Fim = 0;  // Inicializando a Fila Original
}
void InicializacaoP(Pilha *p){
  p->Topo = -1; // Inicializando a Pilha
}
void Limpar(){
  int a;
   while ((a = getchar()) != '\n', a != EOF);
}

// FILA
void Adicionar(Fila *f, Pessoas pes){
    if(f->Fim < MAX){
      f->Dados[f->Fim++] = pes;
  }
}
Pessoas Remover(Fila *f){
  return f->Dados[f->Inicio++];
}
void Exibir(Fila f){
  for (int i = f.Inicio; i < f.Fim; i++){
    printf("[%s, %d]\t", f.Dados[i].Nomes, f.Dados[i].Idade);
  }
    printf("\n-----------------------------------------\n");
}

// PILHA
int PilhaCheia(Pilha *p){
   return p->Topo >= MAX -1;
}
void Push(Pilha *p, Pessoas pes){
   if(PilhaCheia(p)){
    return;
   }
    p->Dados[++p->Topo] = pes;
   
}
Pessoas Pop(Pilha *p){
  return p->Dados[p->Topo--];
}
void Peek(Pilha *p){
  Pessoas a;
    
    printf("\t-----\"PILHA\"-----\n");
  for ( int a = p->Topo; a >= 0; a--){
  printf("[%s, %d]\t", p->Dados[a].Nomes, p->Dados[a].Idade);
  }
   printf("\n--------------------------------------------\n");
 
}

int main(){

  Fila FilaAntiga;
  // Fila FilaNova;

  Pilha P;

  InicializacaoF(&FilaAntiga);
  // InicializacaoF(&FilaNova);
  InicializacaoP(&P);

  Pessoas pes[] = {{"Gabriel", 21}, {"Lula", 65}, {"Fabio", 32}, {"Helen", 23}, {"Xuxa", 56}};

  for (int a = 0; a < 5; a++){
    Adicionar(&FilaAntiga, pes[a]);
  }
  printf("\t-----\"FILA RAIZ\"-----\n");
  Exibir(FilaAntiga);

  while (FilaAntiga.Inicio < FilaAntiga.Fim){
    Push(&P, Remover(&FilaAntiga));
  }

  Peek(&P);

  while (P.Topo >= 0){
    Adicionar(&FilaAntiga, Pop(&P));
  }

  printf("\t-----\"FILA RAIZ\"-----\n");
    Exibir(FilaAntiga);
      printf("\n");

  return 0;
}*/