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
    float super_poder1;
    
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
    float super_poder2;

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

    // Primeira carta com tratamento de divisão por zero
    if (area1 != 0.0f) {
        densidade1 = (float)populacao1 / area1;
    } else {
        densidade1 = 0.0f;
        printf("\nAviso: Área da Carta 1 é zero. Densidade Populacional definida como 0.\n");
    }

    if (populacao1 != 0) {
        pib_per_capita1 = (pib1 * 1000000.0f) / (float)populacao1;
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
        pib_per_capita2 = (pib2 * 1000000.0f) / (float)populacao2;
    } else {
        pib_per_capita2 = 0.0f;
        printf("Aviso: População da Carta 2 é zero. PIB per Capita definido como 0.\n");
    }

    // Calcular Super Poder para a primeira carta
    super_poder1 = 0.0f;
    super_poder1 += (float)populacao1;  // População
    super_poder1 += area1;              // Área
    super_poder1 += pib1 * 1000000.0f;  // PIB (convertendo para unidade)
    super_poder1 += (float)pontos_turisticos1;  // Pontos turísticos
    super_poder1 += pib_per_capita1;    // PIB per capita
    
    // Adicionar inverso da densidade (quanto menor a densidade, maior o poder)
    if (densidade1 > 0.0f) {
        super_poder1 += 1.0f / densidade1;
    }

    // Calcular Super Poder para a segunda carta
    super_poder2 = 0.0f;
    super_poder2 += (float)populacao2;  // População
    super_poder2 += area2;              // Área
    super_poder2 += pib2 * 1000000.0f;  // PIB (convertendo para unidade)
    super_poder2 += (float)pontos_turisticos2;  // Pontos turísticos
    super_poder2 += pib_per_capita2;    // PIB per capita
    
    // Adicionar inverso da densidade
    if (densidade2 > 0.0f) {
        super_poder2 += 1.0f / densidade2;
    }

    // Exibir os dados cadastrados
    printf("\nDados das cartas cadastradas:\n");

    printf("\n--- Primeira Carta ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f milhões\n", pib1);
    printf("Pontos turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\n--- Segunda Carta ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f milhões\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparação das cartas
    printf("\nComparação de Cartas:\n");
    
    // População (maior vence)
    int pop_vencedor = (populacao1 > populacao2) ? 1 : 0;
    printf("População: Carta %d venceu (%d)\n", pop_vencedor ? 1 : 2, pop_vencedor);
    
    // Área (maior vence)
    int area_vencedor = (area1 > area2) ? 1 : 0;
    printf("Área: Carta %d venceu (%d)\n", area_vencedor ? 1 : 2, area_vencedor);
    
    // PIB (maior vence) - convertendo para mesma unidade
    float pib1_unidade = pib1 * 1000000.0f;
    float pib2_unidade = pib2 * 1000000.0f;
    int pib_vencedor = (pib1_unidade > pib2_unidade) ? 1 : 0;
    printf("PIB: Carta %d venceu (%d)\n", pib_vencedor ? 1 : 2, pib_vencedor);
    
    // Pontos Turísticos (maior vence)
    int pontos_vencedor = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", pontos_vencedor ? 1 : 2, pontos_vencedor);
    
    // Densidade Populacional (MENOR vence)
    int densidade_vencedor;
    if (densidade1 == 0.0f && densidade2 == 0.0f) {
        densidade_vencedor = 0; // Empate, Carta 2 por padrão
    } else if (densidade1 == 0.0f) {
        densidade_vencedor = 1; // Carta 1 vence (densidade zero é a menor possível)
    } else if (densidade2 == 0.0f) {
        densidade_vencedor = 0; // Carta 2 vence
    } else {
        densidade_vencedor = (densidade1 < densidade2) ? 1 : 0;
    }
    printf("Densidade Populacional: Carta %d venceu (%d)\n", densidade_vencedor ? 1 : 2, densidade_vencedor);
    
    // PIB per Capita (maior vence)
    int pib_per_capita_vencedor = (pib_per_capita1 > pib_per_capita2) ? 1 : 0;
    printf("PIB per Capita: Carta %d venceu (%d)\n", pib_per_capita_vencedor ? 1 : 2, pib_per_capita_vencedor);
    
    // Super Poder (maior vence)
    int super_poder_vencedor = (super_poder1 > super_poder2) ? 1 : 0;
    printf("Super Poder: Carta %d venceu (%d)\n", super_poder_vencedor ? 1 : 2, super_poder_vencedor);

    // Sistema de pontuação para determinar a carta vencedora geral
    int pontos_carta1 = 0;
    int pontos_carta2 = 0;
    
    // Contabilizar pontos para cada comparação
    pontos_carta1 += (populacao1 > populacao2) ? 1 : 0;
    pontos_carta2 += (populacao2 > populacao1) ? 1 : 0;
    
    pontos_carta1 += (area1 > area2) ? 1 : 0;
    pontos_carta2 += (area2 > area1) ? 1 : 0;
    
    pontos_carta1 += (pib1_unidade > pib2_unidade) ? 1 : 0;
    pontos_carta2 += (pib2_unidade > pib1_unidade) ? 1 : 0;
    
    pontos_carta1 += (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0;
    pontos_carta2 += (pontos_turisticos2 > pontos_turisticos1) ? 1 : 0;
    
    // Densidade: menor valor vence
    if (densidade1 == 0.0f && densidade2 > 0.0f) {
        pontos_carta1 += 1;
    } else if (densidade2 == 0.0f && densidade1 > 0.0f) {
        pontos_carta2 += 1;
    } else if (densidade1 < densidade2) {
        pontos_carta1 += 1;
    } else if (densidade2 < densidade1) {
        pontos_carta2 += 1;
    }
    // Se ambas forem 0 ou iguais, nenhuma ganha ponto
    
    pontos_carta1 += (pib_per_capita1 > pib_per_capita2) ? 1 : 0;
    pontos_carta2 += (pib_per_capita2 > pib_per_capita1) ? 1 : 0;
    
    pontos_carta1 += (super_poder1 > super_poder2) ? 1 : 0;
    pontos_carta2 += (super_poder2 > super_poder1) ? 1 : 0;
    
    // Determinar a carta vencedora geral
    printf("\n--- Resultado Final ---\n");
    printf("Pontos Carta 1: %d\n", pontos_carta1);
    printf("Pontos Carta 2: %d\n", pontos_carta2);
    
    if (pontos_carta1 > pontos_carta2) {
        printf("Carta Vencedora Geral: Carta 1 - %s\n", cidade1);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("Carta Vencedora Geral: Carta 2 - %s\n", cidade2);
    } else {
        printf("Empate! Ambas as cartas têm %d pontos.\n", pontos_carta1);
    }
    
    printf("Super Poder Carta 1: %.2f\n", super_poder1);
    printf("Super Poder Carta 2: %.2f\n", super_poder2);

    return 0;
}