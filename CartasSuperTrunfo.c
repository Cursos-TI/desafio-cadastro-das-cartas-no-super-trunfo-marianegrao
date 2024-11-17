#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países.
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Nível avancado
// Implementar comparações entre as cartas, utilizando operadores relacionais.
// Haverá a soma entre tipos de dados diferentes (int e float)
// Nesse nível, cada carta terá um super poder.

typedef struct
{
    char estado[50];
    char codigo[50];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int qtdPontosTuristicos;
    float densidadePopulacional; // menor valor ganha
    float pibPerCapita;
    float superPoder;
} Carta;

void listarCartas(Carta cartas[], int qtdCartas)
{
    printf("### CARTAS CADASTRADAS: \n");
    for (int i = 0; i < qtdCartas; i++)
    {
        printf("## DADOS DA CARTA %d: \n", i + 1);

        printf("Estado: %s\n", cartas[i].estado);
        printf("Código da Carta: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nome);
        printf("População: %d\n", cartas[i].populacao);
        printf("Area: %f km²\n", cartas[i].area);
        printf("PIB: %f\n", cartas[i].pib);
        printf("Densidade Populacional: %.2f pessoas/km² \n", cartas[i].densidadePopulacional);
        printf("PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].qtdPontosTuristicos);

        printf("------------------------\n");
    }
}

int main()
{
    /*
        Printar opçoes de jogo.
            - Cadastrar cartas
                - Digitar qtd de cartas a serem cadastradas
            - Comparar cartas
                - Se não tiver cartas, exibir: 'nenhuma carta cadastrada'.
                - Se tiver cartas, listar todas as cartas e pedir para o usuario escolher carta1 e carta2
            - Sair

    */
    int opcao;
    printf("Seja bem vindo ao Super Trunfo - Países!\n");
    printf("Vamos jogar! Digite a opcao desejada: ");
    printf("1 - Cadastrar cartas\n");
    printf("2 - Comparar cartas\n");
    printf("3 - Sair\n");
    scanf("%d", &opcao);
    getchar();

    int qtdCartas = 0;
    Carta cartas[qtdCartas];

    if (opcao == 1)
    {
        printf("Digite a quantidade de cartas a serem cadastradas: ");
        scanf("%d", &qtdCartas);
        getchar();
        printf("------------------------\n");

        cartas = cartas[qtdCartas];

        for (int i = 0; i < qtdCartas; i++)
        {
            strcpy(cartas[i].estado, "NULL");
            strcpy(cartas[i].codigo, "NULL");
            strcpy(cartas[i].nome, "NULL");
            cartas[i].populacao = 0;
            cartas[i].area = 0.0;
            cartas[i].pib = 0.0;
            cartas[i].qtdPontosTuristicos = 0;
            cartas[i].densidadePopulacional = 0.0;
            cartas[i].pibPerCapita = 0.0;
        }

        for (int i = 0; i < qtdCartas; i++)
        {
            printf("## CADASTRO DA CARTA %d. \n", i + 1);
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

            cartas[i].densidadePopulacional = (float)cartas[i].populacao / cartas[i].area;
            cartas[i].pibPerCapita = cartas[i].pib / (float)cartas[i].populacao;

            printf("------------------------\n");
        }

        listarCartas(cartas, qtdCartas);
    }
    else if (opcao == 2)
    {
        listarCartas(cartas, qtdCartas);

        Carta primeiraCarta;
        printf("Escolha a primeira carta: ");
        scanf("%d", &primeiraCarta);
        getchar();

        Carta segundaCarta;
        printf("Escolha a segunda carta: ");
        scanf("%d", &segundaCarta);
        getchar();
        printf("------------------------\n");

        printf("### Dados comparados: \n");
        scanf("%d", &primeiraCarta);
        getchar();
    }
    else if (opcao == 3)
    {
        printf('Saindo do jogo...\n');
        printf('Jogo finalizado. \n');
    }

    return 0;
}
