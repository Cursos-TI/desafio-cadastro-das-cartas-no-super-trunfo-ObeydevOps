#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char cidade1[30];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;
    
    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char cidade2[30];
    int populacao2;
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
    scanf("%d", &populacao1);
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
    scanf("%d", &populacao2);
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Primeira carta com tratamento de divisão por zero
    if (area1 != 0.0f) {
        densidade1 = (float)populacao1 / area1;
    } else {
        densidade1 = 0.0f;
        printf("\nAviso: Área da Carta 1 é zero. Densidade Populacional definida como 0.\n");
    }

    if (populacao1 != 0) {
        pib_per_capita1 = (pib1 * 1000000) / populacao1;
    } else {
        pib_per_capita1 = 0.0f;
        printf("Aviso: População da Carta 1 é zero. PIB per Capita definido como 0.\n");
    }

    // Segunda carta com tratamento de divisão por zero
    if (area2 != 0.0f) {
        densidade2 = (float)populacao2 / area2;
    } else {
        densidade2 = 0.0f;
        printf("\nAviso: Área da Carta 2 é zero. Densidade Populacional definida como 0.\n");
    }

    if (populacao2 != 0) {
        pib_per_capita2 = (pib2 * 1000000) / populacao2;
    } else {
        pib_per_capita2 = 0.0f;
        printf("Aviso: População da Carta 2 é zero. PIB per Capita definido como 0.\n");
    }

    // Exibir os dados cadastrados
    printf("\nDados das cartas cadastradas:\n");

    printf("\n--- Primeira Carta ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f milhões\n", pib1);
    printf("Pontos turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);

    printf("\n--- Segunda Carta ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f milhões\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);

    return 1;
}