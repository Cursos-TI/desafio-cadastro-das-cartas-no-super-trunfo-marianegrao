#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países.
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

int main()
{
    typedef struct
    {
        char estado[50];
        char codigo[50];
        char nome[50];
        int populacao;
        float area;
        float pib;
        int qtdPontosTuristicos;
    } Carta;

    int qtdCartas;
    printf("Digite a quantidade de cartas a serem cadastradas: ");
    scanf("%d", &qtdCartas);
    getchar();
    printf("------------------------\n");

    Carta cartas[qtdCartas];

    for (int i = 0; i < qtdCartas; i++)
    {
        strcpy(cartas[i].estado, "NULL");
        strcpy(cartas[i].codigo, "NULL");
        strcpy(cartas[i].nome, "NULL");
        cartas[i].populacao = 0;
        cartas[i].area = 0.0;
        cartas[i].pib = 0.0;
        cartas[i].qtdPontosTuristicos = 0;
    }

    for (int i = 0; i < qtdCartas; i++)
    {
        printf("CADASTRO DA CARTA %d. \n", i + 1);
        printf("Digite o estado: ");
        fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
        cartas[i].estado[strcspn(cartas[i].estado, "\n")] = 0;

        printf("Digite o código: ");
        fgets(cartas[i].codigo, sizeof(cartas[i].codigo), stdin);
        cartas[i].codigo[strcspn(cartas[i].codigo, "\n")] = 0;

        printf("Digite o nome: ");
        fgets(cartas[i].nome, sizeof(cartas[i].nome), stdin);
        cartas[i].nome[strcspn(cartas[i].nome, "\n")] = 0;

        printf("Digite a população: ");
        scanf("%d", &cartas[i].populacao);

        printf("Digite a area (km²): ");
        scanf("%f", &cartas[i].area);

        printf("Digite o PIB: ");
        scanf("%f", &cartas[i].pib);

        printf("Digite a quantidade de pontos turisticos: ");
        scanf("%d", &cartas[i].qtdPontosTuristicos);
        getchar();

        printf("------------------------\n");
    }
    
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("DADOS DA CARTA %d: \n", i + 1);

        printf("Estado: %s\n", cartas[i].estado);
        printf("Código da Carta: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nome);
        printf("População: %d\n", cartas[i].populacao);
        printf("Area: %f km²\n", cartas[i].area);
        printf("PIB: %f\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].qtdPontosTuristicos);

        printf("------------------------\n");
    }
    return 0;
}
