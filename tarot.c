#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void abertura() {
    printf("*****************\n");
    printf("* GUIA DE TAROT *\n");
    printf("*****************\n\n");
}

//ARCANOS MAIORES
void nomesMaior() {
    FILE* f = fopen("nomesmenor.txt", "r");
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
            strcpy(nome, linha + 6); 
            nome[strcspn(nome, "\n")] = 0; 

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

//ARCANOS MENORES
void sobre() {
   FILE* f = fopen("sobre.txt", "r");
    if (f == 0) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return;
    }

    char linha[200];
    while (fgets(linha, sizeof(linha), f) != 0) {
        printf("%s", linha); 
    }
    printf("\n");
    fclose(f);
}

void numerologia() {
    FILE* f = fopen("numeros.txt", "r");
    if (f == 0) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return;
    }

    char linha[300];
    while (fgets(linha, sizeof(linha), f) != 0) {
        printf("%s", linha); 
    }
    printf("\n");
    fclose(f);
}

void simbolosMenor() {
    FILE* f = fopen("simbolostd.txt", "r");
    if (f == 0) {
        printf("Erro: Não foi possível abrir o arquivo.\n");
        return;
    }

    int opcao;
    printf("Você quer:\n(1) Buscar uma carta específica\n(2) Listar cartas por naipe\nEscolha: ");
    scanf("%d", &opcao);
    getchar(); // Limpa \n deixado pelo scanf

    char linha[1600];

    if (opcao == 1) {
        // Buscar carta específica
        char nomebusca[1000];
        printf("Digite o nome do Arcano: ");
        fgets(nomebusca, sizeof(nomebusca), stdin);
        nomebusca[strcspn(nomebusca, "\n")] = 0;

        int encontrado = 0;
        while (fgets(linha, sizeof(linha), f)) {
            if (strncmp(linha, "NOME:", 5) == 0) {
                char nome[1000];
                strcpy(nome, linha + 6);
                nome[strcspn(nome, "\n")] = 0;

                if (strcasecmp(nome, nomebusca) == 0) {
                    encontrado = 1;
                    printf("\nCarta: %s\n", nome);

                    while (fgets(linha, sizeof(linha), f)) {
                        if (strncmp(linha, "---", 3) == 0) break;
                        printf("%s", linha);
                    }
                    break;
                }
            }
        }
        if (!encontrado)
            printf("Carta não encontrada! Tente como no exemplo: \"O Louco\".\n");
    } else {
        // Listar cartas por naipe
        int naipe;
        printf("\nEscolha o naipe:\n(1) Todos\n(2) Copas\n(3) Ouros\n(4) Espadas\n(5) Paus\nEscolha: ");
        scanf("%d", &naipe);
        getchar();

        const char* naipes[5] = {"Todos", "Copas", "Ouros", "Espadas", "Paus"};

        printf("\nListando cartas do naipe: %s\n\n", naipes[naipe-1]);

        int imprimir = 0;
        while (fgets(linha, sizeof(linha), f)) {
            if (strncmp(linha, "NOME:", 5) == 0) {
                char nome[1000];
                strcpy(nome, linha + 6);
                nome[strcspn(nome, "\n")] = 0;

                if (naipe == 1 || strstr(linha, naipes[naipe-1])) {
                    imprimir = 1;
                    printf("Carta: %s\n", nome);
                } else {
                    imprimir = 0;
                }
            } else if (imprimir) {
                if (strncmp(linha, "---", 3) == 0) {
                    imprimir = 0;
                    printf("\n");
                } else {
                    printf("%s", linha);
                }
            }
        }
    }
    fclose(f);
}

int menores() {
    int menores;
    printf("O que você quer saber sobre os arcanos maiores?\n");
    printf("\n(1) Sobre os Naipes \n(2) Numerologia \n(3) Símbolos\n\n");
    printf("Escolha: ");
    scanf("%d", &menores);
    printf("\n");

    switch (menores) {
        case 1:
            sobre();
            break;
        case 2:
            numerologia();
            break;
        default:
            simbolosMenor(); 
            break;
    }
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

    int sair = 0;
    while (!sair) {
        int querer;
        printf("\nVocê quer saber sobre:\n");
        printf("(1) Arcanos Maiores\n");
        printf("(2) Arcanos Menores\n");
        printf("(3) Sair\n");
        printf("Escolha: ");
        scanf("%d", &querer);
        getchar();
        
        switch (querer) {
            case 1:
                maiores();
                break;
            case 2:
                menores();
                break;
            case 3:
                sair = 1;
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

        printf("\n"); // Espaço entre menus
    }

    return 0;
}