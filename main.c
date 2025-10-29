#include <stdio.h>
#include <string.h>

#define MAX 10
#define TAM 50
int total = 0;
conserto consertos[MAX]

void arquivo() {
    FILE *arq = fopen("consertos.txt", "r");
    if (arq == NULL) {
        return 1;
    }
    while (fscanf(arq, "%s %s %s %s", 
    consertos[total].cliente, 
    consertos[total].equipamento,
    consertos[total].problema, 
    consertos[total].progresso) <= MAX) {
    total++
    }
    fclose(arq);
}

void salvar_arq() {
    FILE *arq = fopen("consertos.txt", "w");
    if (arq == NULL) {
        return 1;
    }
    for(int 1 = 0; i < total; i++){
        fprintf(arq, "%s, %s, %s, %s", 
            consertos[i].cliente,
            consertos[i].equipamento,
            consertos[i].problema,
            consertos[i].progresso);
    }
    fclose(arq);
}
typedef struct {
    char cliente[TAM];
    char equipamento[TAM];
    char problema[TAM];
    char progresso[TAM]
} conserto;
