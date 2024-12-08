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
    int populacao;
    float area;
    float pib;
    int qtdPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

void listarCartas(Carta cartas[], int qtdCartas, int index)
{
    if (qtdCartas > index)
    {
        for (int i = 0; i < qtdCartas; i++)
        {

            printf("╭──────────────────────────────────────╮\n");
            printf("│            CARTA N. %d               │\n", i + 1);
            printf("├──────────────────────────────────────┤\n");
            printf("│ Estado: %s                           \n", cartas[i].estado);
            printf("│ Código da Carta: %s                  \n", cartas[i].codigo);
            printf("│ Nome da Cidade: %s                   \n", cartas[i].nome);
            printf("│ População: %d                        \n", cartas[i].populacao);
            printf("│ Area: %f km²                         \n", cartas[i].area);
            printf("│ PIB: %f                              \n", cartas[i].pib);
            printf("│ Densidade Popul.: %.2f pessoas/km²   \n", cartas[i].densidadePopulacional);
            printf("│ PIB per Capita: %.2f                 \n", cartas[i].pibPerCapita);
            printf("│ Número de Pontos Turísticos: %d      \n", cartas[i].qtdPontosTuristicos);
            printf("╰──────────────────────────────────────╯\n");
        }
    }
    else
    {
    }
}

int listarMenu(int opcao)
{
    printf("Escolha uma opção abaixo: \n");
    printf("╭────────────────────────────────────╮\n");
    printf("│            MENU PRINCIPAL          │\n");
    printf("├────────────────────────────────────┤\n");
    printf("│ 1 - Cadastrar cartas               │\n");
    printf("│ 2 - Listar cartas                  │\n");
    printf("│ 3 - Comparar cartas                │\n");
    printf("│ 4 - Sair                           │\n");
    printf("╰────────────────────────────────────╯\n");
    printf("Sua ação: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int main()
{
    /*
       TO DO:
       - [X] Funcao de listar menu: adaptar para uso do ponteiro
       - [X] Implementar a comparação entre as cartas
       - [] Corrigir o calculo da densidade populacional e pib per capita
       - [] Corrigir o nome da cidade
       - [] Implementar o calculo do super poder
       - [] Implementar validação p quando primeiraCartaIndex ou segundaCartaIndex for invalido (menor ou maior que a quantidade de cartas cadastradas)
       - [] Testar os outros att de comparacao
    */
    int opcao;
    printf("╔════════════════════════════════════╗\n");
    printf("║          🃏 SUPER TRUNFO 🃏        ║\n");
    printf("╚════════════════════════════════════╝\n");

    printf("Bem-vindo ao jogo Super Trunfo! ");

    int qtdCartas = 0;
    Carta cartas[qtdCartas];
    opcao = listarMenu(opcao);
    int codigoExit = -1;

    while (opcao != codigoExit)
    {
        if (opcao == 1)
        {
            printf("╭────────────────────────────────────╮\n");
            printf("│         CADASTRO DE CARTAS         │\n");
            printf("╰────────────────────────────────────╯\n");
            printf("Digite a quantidade de cartas a serem cadastradas: ");
            scanf("%d", &qtdCartas);
            getchar();

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

            printf("Voltando para o menu... \n");
            opcao = listarMenu(opcao);
        }
        else if (opcao == 2)
        {
            if (qtdCartas == 0)
            {
                printf("Nenhuma carta cadastrada! \n");
                printf("Voltando para o menu... \n");
                opcao = listarMenu(opcao);
            }
            else
            {
                printf("╭────────────────────────────────────╮\n");
                printf("│         LISTAGEM DE CARTAS         │\n");
                printf("╰────────────────────────────────────╯\n");
                listarCartas(cartas, qtdCartas, 0);
                printf("Voltando para o menu... \n");
                opcao = listarMenu(opcao);
            }
        }
        else if (opcao == 3)
        {
            if (qtdCartas == 0)
            {
                printf("Nenhuma carta cadastrada! \n");
                printf("Voltando para o menu... \n");
                opcao = listarMenu(opcao);
            }
            else if (qtdCartas == 1)
            {
                printf("Necessário mais de uma carta cadastrada! \n");
                printf("Voltando para o menu... \n");
                opcao = listarMenu(opcao);
            }
            printf("╭──────────────────────────────────────╮\n");
            printf("│          COMPARAÇÃO DE CARTAS        │\n");
            printf("╰──────────────────────────────────────╯\n");

            const char *atributos[] = {"populacao", "area", "pib", "qtdPontosTuristicos", "densidadePopulacional", "pibPerCapita", "superPoder"};
            int atributoIndex = 0;
            printf("╭──────────────────────────────────────────╮\n");
            printf("│ Selecione o atributo que sera comparado: │ \n");
            printf("│ 1 - População                            │\n");
            printf("│ 2 - Área                                 │\n");
            printf("│ 3 - PIB                                  │\n");
            printf("│ 4 - Pontos turísticos                    │\n");
            printf("│ 5 - Densidade Populacional               │\n");
            printf("│ 6 - PIB per Capita                       │\n");
            printf("│ 7 - SuperPoder                           │\n");
            printf("╰──────────────────────────────────────────╯\n");
            printf("Seu atributo: ");
            scanf("%d", &atributoIndex);
            const char *atributo = atributos[atributoIndex - 1];
            printf("test-Seu atributo: %s ", atributo);

            printf("Selecione o número das cartas que deseja comparar \n");

            int primeiraCartaIndex = 0;
            int segundaCartaIndex = 0;

            printf("Carta A - N. : ");

            scanf("%d", &primeiraCartaIndex);
            getchar();
            Carta *primeiraCarta = &cartas[primeiraCartaIndex - 1];
            // primeiraCarta.superPoder = primeiraCarta.populacao + primeiraCarta.pib + primeiraCarta.densidadePopulacional + primeiraCarta.area + primeiraCarta.qtdPontosTuristicos;

            printf("╭──────────────────────────────────────╮\n");
            printf("│            CARTA N. %d               │\n", primeiraCartaIndex);
            printf("├──────────────────────────────────────┤\n");
            printf("│ Estado: %s                           \n", primeiraCarta->estado);
            printf("│ Código da Carta: %s                  \n", primeiraCarta->codigo);
            printf("│ Nome da Cidade: %s                   \n", primeiraCarta->nome);
            printf("│ População: %d                        \n", primeiraCarta->populacao);
            printf("│ Area: %f km²                         \n", primeiraCarta->area);
            printf("│ PIB: %f                              \n", primeiraCarta->pib);
            printf("│ Densidade Popul.: %.2f pessoas/km²   \n", primeiraCarta->densidadePopulacional);
            printf("│ PIB per Capita: %.2f                 \n", primeiraCarta->pibPerCapita);
            printf("│ Número de Pontos Turísticos: %d      \n", primeiraCarta->qtdPontosTuristicos);
            printf("╰──────────────────────────────────────╯\n");

            printf("Carta B - N. : ");
            scanf("%d", &segundaCartaIndex);
            getchar();
            Carta *segundaCarta = &cartas[segundaCartaIndex - 1];
            // segundaCarta.superPoder = segundaCarta.populacao + segundaCarta.pib + segundaCarta.densidadePopulacional + segundaCarta.area + segundaCarta.qtdPontosTuristicos;

            printf("╭──────────────────────────────────────╮\n");
            printf("│            CARTA N. %d               │\n", segundaCartaIndex);
            printf("├──────────────────────────────────────┤\n");
            printf("│ Estado: %s                           \n", segundaCarta->estado);
            printf("│ Código da Carta: %s                  \n", segundaCarta->codigo);
            printf("│ Nome da Cidade: %s                   \n", segundaCarta->nome);
            printf("│ População: %d                        \n", segundaCarta->populacao);
            printf("│ Area: %f km²                         \n", segundaCarta->area);
            printf("│ PIB: %f                              \n", segundaCarta->pib);
            printf("│ Densidade Popul.: %.2f pessoas/km²   \n", segundaCarta->densidadePopulacional);
            printf("│ PIB per Capita: %.2f                 \n", segundaCarta->pibPerCapita);
            printf("│ Número de Pontos Turísticos: %d      \n", segundaCarta->qtdPontosTuristicos);
            printf("╰──────────────────────────────────────╯\n");

            Carta *vencedora = primeiraCarta;
            char *tipoVencedora = "A";

            if ((atributo == "populacao" &&
                 segundaCarta->populacao > primeiraCarta->populacao) ||
                (atributo == "area" &&
                 segundaCarta->area > primeiraCarta->area) ||
                (atributo == "pib" &&
                 segundaCarta->pib > primeiraCarta->pib) ||
                (atributo == "qtdPontosTuristicos" &&
                 segundaCarta->qtdPontosTuristicos > primeiraCarta->qtdPontosTuristicos) ||
                (atributo == "densidadePopulacional" &&
                 segundaCarta->densidadePopulacional < primeiraCarta->densidadePopulacional) ||
                (atributo == "pibPerCapita" &&
                 segundaCarta->pibPerCapita > primeiraCarta->pibPerCapita) ||
                (atributo == "superPoder" &&
                 segundaCarta->superPoder > primeiraCarta->superPoder))
            {
                vencedora = segundaCarta;
                tipoVencedora = "B";
            }

            printf("╭──────────────────────────────────────╮\n");
            printf("│       RESULTADO DA COMPARAÇÃO        │\n");
            printf("╰──────────────────────────────────────╯\n");

            printf("🏆 **Carta Vencedora**: %s \n", tipoVencedora);

            printf("╭──────────────────────────────────────╮\n");
            printf("│            CARTA %s               │\n", tipoVencedora);
            printf("├──────────────────────────────────────┤\n");
            printf("│ Estado: %s                           \n", vencedora->estado);
            printf("│ Código da Carta: %s                  \n", vencedora->codigo);
            printf("│ Nome da Cidade: %s                   \n", vencedora->nome);
            printf("│ População: %d                        \n", vencedora->populacao);
            printf("│ Area: %f km²                         \n", vencedora->area);
            printf("│ PIB: %f                              \n", vencedora->pib);
            printf("│ Densidade Popul.: %.2f pessoas/km²   \n", vencedora->densidadePopulacional);
            printf("│ PIB per Capita: %.2f                 \n", vencedora->pibPerCapita);
            printf("│ Número de Pontos Turísticos: %d      \n", vencedora->qtdPontosTuristicos);
            printf("╰──────────────────────────────────────╯\n");
            printf("Voltando para o menu... \n");
            opcao = listarMenu(opcao);
        }
        else if (opcao == 4)
        {
            printf("Jogo finalizado!");
            opcao = codigoExit;
            return 0;
        }
        else
        {
            printf("Opção inválida! \n");
            printf("Voltando para o menu... \n");
            opcao = listarMenu(opcao);
        }
    };

    return 0;
}
