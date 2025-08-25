#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char cidade1[30];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;

    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char cidade2[30];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pib_per_capita2;

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da carta: ");
    scanf(" %3s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf(" %29[^\n]", cidade1);
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
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta: ");
    scanf(" %3s", codigo2);
    printf("Digite o nome da cidade: ");
    scanf(" %29[^\n]", cidade2);
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
        printf("\nAviso: Área da Carta 1 é zero. Densidade Populacional definida como 0.\n");
    }

    if (populacao1 != 0) {
        pib_per_capita1 = (pib1 * 1000000.0f) / (float)populacao1; // PIB per capita = (PIB * 1M) / População
    } else {
        pib_per_capita1 = 0.0f;
        printf("Aviso: População da Carta 1 é zero. PIB per Capita definido como 0.\n");
    }

    // Cálculo da densidade populacional e PIB per capita para a segunda carta
    if (area2 != 0.0f) {
        densidade2 = (float)populacao2 / area2; // Densidade = População / Área
    } else {
        densidade2 = 0.0f;
        printf("\nAviso: Área da Carta 2 é zero. Densidade Populacional definida como 0.\n");
    }

    if (populacao2 != 0) {
        pib_per_capita2 = (pib2 * 1000000.0f) / (float)populacao2; // PIB per capita = (PIB * 1M) / População
    } else {
        pib_per_capita2 = 0.0f;
        printf("Aviso: População da Carta 2 é zero. PIB per Capita definido como 0.\n");
    }

    // Comparação das cartas com base na Densidade Populacional (menor vence)
    printf("\nComparação de cartas (Atributo: Densidade Populacional):\n");
    printf("Carta 1 - %s (%c): %.2f hab/km²\n", cidade1, estado1, densidade1);
    printf("Carta 2 - %s (%c): %.2f hab/km²\n", cidade2, estado2, densidade2);

    // Determinar o vencedor usando if-else, considerando casos especiais para densidade zero
    if (densidade1 == 0.0f && densidade2 == 0.0f) {
        printf("Resultado: Empate! Ambas as cartas têm densidade populacional zero.\n");
    } else if (densidade1 == 0.0f) {
        printf("Resultado: Carta 1 (%s) venceu! (Densidade zero é considerada a menor possível)\n", cidade1);
    } else if (densidade2 == 0.0f) {
        printf("Resultado: Carta 2 (%s) venceu! (Densidade zero é considerada a menor possível)\n", cidade2);
    } else if (densidade1 < densidade2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (densidade2 < densidade1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate! Ambas as cartas têm a mesma densidade populacional.\n");
    }

    return 0;
}