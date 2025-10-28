#include <stdio.h>
#include <string.h>

#define MAX 10
#define TAM 50

void registro(){
    char nomes[MAX][TAM];
    char equipamentos[MAX][TAM];
    int total = 0;

    while (total < MAX){
        printf("Digite o nome da pessoa %d:  ", total + 1);
        scanf("%[^\n]", nomes[total]);

        printf("Digite o nome do equipamento da pessoa %d", total + 1);
        scanf("%[^\n]", equipamentos[total]);

        total++;

    }
}

int main (void) {

    registro();


    return 0;
}