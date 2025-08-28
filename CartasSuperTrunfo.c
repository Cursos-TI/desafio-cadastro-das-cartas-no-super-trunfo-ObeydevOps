#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char pais1[30];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;

    // Variáveis para a segunda carta
    char pais2[30];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pib_per_capita2;

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Digite o nome do país: ");
    scanf(" %29[^\n]", pais1);
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    printf("Digite a área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cadastro da segunda carta
    printf("\nCadastro da segunda carta:\n");
    printf("Digite o nome do país: ");
    scanf(" %29[^\n]", pais2);
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculo da densidade populacional e PIB per capita para a primeira carta
    if (area1 != 0.0f) {
        densidade1 = (float)populacao1 / area1; // Densidade = População / Área
    } else {
        densidade1 = 0.0f;
        printf("\nAviso: Área do país %s é zero. Densidade Populacional definida como 0.\n", pais1);
    }

    if (populacao1 != 0) {
        pib_per_capita1 = (pib1 * 1000000.0f) / (float)populacao1; // PIB per capita = (PIB * 1M) / População
    } else {
        pib_per_capita1 = 0.0f;
        printf("Aviso: População do país %s é zero. PIB per Capita definido como 0.\n", pais1);
    }

    // Cálculo da densidade populacional e PIB per capita para a segunda carta
    if (area2 != 0.0f) {
        densidade2 = (float)populacao2 / area2; // Densidade = População / Área
    } else {
        densidade2 = 0.0f;
        printf("\nAviso: Área do país %s é zero. Densidade Populacional definida como 0.\n", pais2);
    }

    if (populacao2 != 0) {
        pib_per_capita2 = (pib2 * 1000000.0f) / (float)populacao2; // PIB per capita = (PIB * 1M) / População
    } else {
        pib_per_capita2 = 0.0f;
        printf("Aviso: População do país %s é zero. PIB per Capita definido como 0.\n", pais2);
    }

    // Menu interativo para escolha do atributo
    int opcao;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &opcao);

    // Comparação com base no atributo escolhido
    printf("\nComparação de cartas (Atributo: ");
    switch (opcao) {
        case 1: // População
            printf("População)\n");
            printf("País 1 - %s: %lu habitantes\n", pais1, populacao1);
            printf("País 2 - %s: %lu habitantes\n", pais2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate! Os dois países têm a mesma população.\n");
            }
            break;

        case 2: // Área
            printf("Área)\n");
            printf("País 1 - %s: %.2f km²\n", pais1, area1);
            printf("País 2 - %s: %.2f km²\n", pais2, area2);
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate! Os dois países têm a mesma área.\n");
            }
            break;

        case 3: // PIB
            printf("PIB)\n");
            printf("País 1 - %s: %.2f milhões\n", pais1, pib1);
            printf("País 2 - %s: %.2f milhões\n", pais2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate! Ambos os países têm o mesmo PIB.\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Número de Pontos Turísticos)\n");
            printf("País 1 - %s: %d pontos\n", pais1, pontos_turisticos1);
            printf("País 2 - %s: %d pontos\n", pais2, pontos_turisticos2);
            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate! os dois países têm o mesmo número de pontos turísticos.\n");
            }
            break;

        case 5: // Densidade Populacional
            printf("Densidade Populacional)\n");
            printf("País 1 - %s: %.2f hab/km²\n", pais1, densidade1);
            printf("País 2 - %s: %.2f hab/km²\n", pais2, densidade2);
            if (densidade1 == 0.0f && densidade2 == 0.0f) {
                printf("Resultado: Empate! Os dois países têm densidade populacional zero.\n");
            } else if (densidade1 == 0.0f) {
                printf("Resultado: %s venceu! (Densidade zero é considerada a menor)\n", pais1);
            } else if (densidade2 == 0.0f) {
                printf("Resultado: %s venceu! (Densidade zero é considerada a menor)\n", pais2);
            } else if (densidade1 < densidade2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate! Os dois países têm a mesma densidade populacional.\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    return 0;
}