#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void abertura() {
    printf("*****************\n");
    printf("* GUIA DE TAROT *\n");
    printf("*****************\n\n");
}

void nomesMaior() {
    FILE* f = fopen("nomes.txt", "r");
    if (f == 0) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), f) != 0) {
        printf("%s", linha); 
    }
    printf("\n");
    fclose(f);
}

void jornada() {
    FILE* f = fopen("jornada.txt", "r");
    if (f == 0) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return;
    }

    char linha[7500];
    while (fgets(linha, sizeof(linha), f) != 0) {
        printf("%s", linha); 
    }
    printf("\n");
    fclose(f);
}

void simbolosMaior() {
    FILE* f = fopen("simbolos.txt", "r");
    if (f == 0) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return;
    }

    char nomebusca[1000];
    printf("Digite o nome do Arcano: ");
    getchar(); // limpa o \n deixado pelo scanf anterior
    fgets(nomebusca, sizeof(nomebusca), stdin);
    nomebusca[strcspn(nomebusca, "\n")] = 0; // remove o \n do nome digitado

    char linha[1600];
    int encontrado = 0;
    while (fgets(linha, sizeof(linha), f) != 0) {
        if (strncmp(linha, "NOME:", 5) == 0) {
            char nome[1000];
            strcpy(nome, linha + 6); // pega o nome após "NOME: "
            nome[strcspn(nome, "\n")] = 0; // remove o \n

            // Se o nome for igual ao buscado
            if (strcasecmp(nome, nomebusca) == 0) {
                encontrado = 1;
                printf("\nCarta: %s\n", nome);

                while (fgets(linha, sizeof(linha), f) != 0) {
                    if (strncmp(linha, "---", 3) == 0) break; // fim da carta
                    printf("%s", linha);
                }
                break;
            }
        }
    }

    if (!encontrado)
        printf("Carta não encontrada! Tente como no exemplo: \"O Louco\".\n");

    printf("\n");
    fclose(f);
}

int maiores() {
    int maiores;
    printf("O que você quer saber sobre os arcanos maiores?\n");
    printf("\n(1) Nomes dos arcanos \n(2) Símbolos \n(3) Jornada do Louco\n\n");
    printf("Escolha: ");
    scanf("%d", &maiores);
    printf("\n");

    switch (maiores) {
        case 1:
            nomesMaior();
            break;
        case 2:
            simbolosMaior();
            break;
        default:
            jornada(); 
            break;
    }

    return 0;
}

int menores() {
    printf("Função dos Arcanos Menores ainda não implementada.\n");
    return 0;
}

int main () {
    
    abertura();

    int querer;
    printf("Você quer saber sobre:\n");
    printf("\n(1) Arcanos Maiores \n(2) Arcanos Menores\n\n");
    printf("Escolha: ");
    scanf("%d",&querer);

    switch (querer) {
    case 1:
        maiores();
        break; 
    default: 
        menores();
        break;
    }
}  