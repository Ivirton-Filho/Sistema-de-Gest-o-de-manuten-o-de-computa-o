#include <stdio.h>
#include <string.h>

#define MAX 10
#define TAM 50

typedef struct {
    char cliente[TAM];
    char equipamento[TAM];
    char problema[TAM];
    char progresso[TAM];
} conserto;

//variaveis globais
int total = 0;
conserto  consertos[MAX];
int qnt_pecas = 0; //armazena a quantidade de peças que o user deseja cadastrar
char var_auxiliador_pecas[TAM]; //variavel auxiliar para verificar se ja existe peças cadastradas

//struct para pecas
struct pecas{
    int id;
    char nome[TAM];
    int quantidade;
};

//array para peças
struct pecas lista_de_equipamentos[MAX];


void arquivo() {
    FILE *arq = fopen("consertos.txt", "r");
    if (arq == NULL) {
        return ;
    }
    while (fscanf(arq, "%s %s %s %s", 
    consertos[total].cliente, 
    consertos[total].equipamento,
    consertos[total].problema, 
    consertos[total].progresso) <= MAX) {
    total++;
    }
    fclose(arq);
}

void salvar_arq() {
    FILE *arq = fopen("consertos.txt", "w");
    if (arq == NULL) {
        return ;
    }
    for(int i = 0; i < total; i++){
        fprintf(arq, "%s, %s, %s, %s", 
            consertos[i].cliente,
            consertos[i].equipamento,
            consertos[i].problema,
            consertos[i].progresso);
    }
    fclose(arq);
}


void cadastro() {
    if (total >= MAX) {
        printf("Limite de consertos atingindo!\n");
        return;
    }
    else {
        printf("--- CADASTRO DE CLIENTE ---");
        printf("Digite o nome do cliente: ");
        getchar();
        fgets(consertos[total].cliente, TAM, stdin);
        consertos[total].cliente[strcspn(consertos[total].cliente, "\n")] = 0;

        printf("Equipamento: ");
        fgets(consertos[total].equipamento, TAM, stdin);
        consertos[total].equipamento[strcspn(consertos[total].equipamento, "\n")] = 0;

        printf("Problema do equipamento: ");
        fgets(consertos[total].problema, TAM, stdin);
        consertos[total].problema[strcspn(consertos[total].problema, "\n")] = 0;

        strcpy(consertos[total].progresso, "Em análise");
        total++;
        salvar_arq();
    }
}

void status_conserto() {
    int escolha;
    if (total == 0){
        printf("Nenhum equipamento cadastrado.\n");
        return;
    }
    printf("Digite o número do conserto que deseja atualizar: ");
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > total) {
        printf("Opção inválida!\n");
        while (getchar() != '\n'); 
        return;
    }
    escolha--;
    printf("Atualização do status de conserto: ");
    getchar(); 
    fgets(consertos[escolha].progresso, TAM, stdin);
    consertos[escolha].progresso[strcspn(consertos[escolha].progresso, "\n")] = 0;

    salvar_arq();
    printf("Status atualizado com sucesso!\n");
}


void estoque (){
    printf("--- ESTOQUE DE PEÇAS ---\n");
    //verifica se ja existe peças cadastradas e imprime elas na tela do user
    if(var_auxiliador_pecas[0] != NULL){
      printf("Peças cadastradas no estoque:\n");
        for(int i = 0; i < qnt_pecas; i++){
            printf("ID: %d\n", lista_de_equipamentos[i].id);
            printf("Nome: %s\n", lista_de_equipamentos[i].nome);
            printf("Quantidade: %d\n", lista_de_equipamentos[i].quantidade);
            printf("-----------------------\n");
        }
    //add peças ao estoque caso não tenha peças cadastradas 
    }else{
       printf("Nenhuma peça cadastrada no estoque.\n");
       printf("Quantas peças deseja adicionar? Infome o número de 1 a 10: ");
        scanf("%d", &qnt_pecas);

        for (int i = 0; i < qnt_pecas; i++){
        lista_de_equipamentos[i].id = i + 1;
        printf("Nome da peca %d: ", i + 1);
        scanf("%s", lista_de_equipamentos[i].nome);
        printf("\nQuantidade da peça %d: ", i + 1);
        scanf("%d", &lista_de_equipamentos[i].quantidade);
        }
    }
    
    
}

int main (void){
    estoque();
return 0;
}
