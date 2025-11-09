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


int total = 0;
conserto  consertos[MAX];

void arquivo() {
    FILE *arq = fopen("consertos.txt", "r");
    if (arq == NULL) {
        return ;
    }
    while (fscanf(arq, "%s %s %s %s", 
    consertos[total].cliente, 
    consertos[total].equipamento,
    consertos[total].problema, 
    consertos[total].progresso) <= MAX); {
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
    if (total > MAX) {
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


int main (void){

return 0;
}
