#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char nome[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, const char *nome_carta) {
    printf("Cadastro da carta %s:\n", nome_carta);
    printf("Digite o nome do país: ");
    scanf(" %29[^\n]", carta->nome);
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculo da densidade populacional
    carta->densidade = (carta->area != 0.0f) ? (float)carta->populacao / carta->area : 0.0f;
    if (carta->area == 0.0f) {
        printf("Aviso: Área do país %s é zero. Densidade definida como 0.\n", carta->nome);
    }

    // Cálculo do PIB per capita
    carta->pib_per_capita = (carta->populacao != 0) ? (carta->pib * 1000000.0f) / (float)carta->populacao : 0.0f;
    if (carta->populacao == 0) {
        printf("Aviso: População do país %s é zero. PIB per capita definido como 0.\n", carta->nome);
    }
}

// Função para exibir o menu de atributos
void exibirMenuAtributos(int excluir_opcao) {
    printf("Escolha o atributo:\n");
    if (excluir_opcao != 1) printf("1. População\n");
    if (excluir_opcao != 2) printf("2. Área\n");
    if (excluir_opcao != 3) printf("3. PIB\n");
    if (excluir_opcao != 4) printf("4. Número de Pontos Turísticos\n");
    if (excluir_opcao != 5) printf("5. Densidade Populacional\n");
    printf("Digite sua escolha: ");
}

// Função para obter o valor de um atributo
float obterValorAtributo(Carta *carta, int opcao) {
    switch (opcao) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return (float)carta->pontos_turisticos;
        case 5: return carta->densidade;
        default: return 0.0f;
    }
}

// Função para obter o nome do atributo
const char* obterNomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de Pontos Turísticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

// Função para comparar atributos
int compararAtributo(Carta *carta1, Carta *carta2, int opcao) {
    float valor1 = obterValorAtributo(carta1, opcao);
    float valor2 = obterValorAtributo(carta2, opcao);

    // Exceção para Densidade Populacional: menor valor vence
    if (opcao == 5) {
        if (valor1 == 0.0f && valor2 == 0.0f) return 0; // Empate
        if (valor1 == 0.0f) return 1; // Carta 1 vence
        if (valor2 == 0.0f) return 2; // Carta 2 vence
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    }

    // Regra geral: maior valor vence
    return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
}

int main() {
    Carta carta1, carta2;
    int opcao1, opcao2;

    // Cadastro das cartas
    cadastrarCarta(&carta1, "primeira");
    printf("\n");
    cadastrarCarta(&carta2, "segunda");
    printf("\n");

    // Escolha do primeiro atributo
    do {
        exibirMenuAtributos(0);
        scanf("%d", &opcao1);
        if (opcao1 < 1 || opcao1 > 5) {
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
        }
    } while (opcao1 < 1 || opcao1 > 5);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        exibirMenuAtributos(opcao1);
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) {
            printf("Erro: O segundo atributo deve ser diferente do primeiro!\n");
        } else if (opcao2 < 1 || opcao2 > 5) {
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
        }
    } while (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5);

    // Comparação dos atributos
    printf("\nResultado da comparação:\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n\n", carta2.nome);

    // Comparação do primeiro atributo
    printf("Comparação do atributo %s:\n", obterNomeAtributo(opcao1));
    printf("%s: %.2f\n", carta1.nome, obterValorAtributo(&carta1, opcao1));
    printf("%s: %.2f\n", carta2.nome, obterValorAtributo(&carta2, opcao1));
    int resultado1 = compararAtributo(&carta1, &carta2, opcao1);
    printf("Vencedor: %s\n\n", resultado1 == 1 ? carta1.nome : resultado1 == 2 ? carta2.nome : "Empate");

    // Comparação do segundo atributo
    printf("Comparação do atributo %s:\n", obterNomeAtributo(opcao2));
    printf("%s: %.2f\n", carta1.nome, obterValorAtributo(&carta1, opcao2));
    printf("%s: %.2f\n", carta2.nome, obterValorAtributo(&carta2, opcao2));
    int resultado2 = compararAtributo(&carta1, &carta2, opcao2);
    printf("Vencedor: %s\n\n", resultado2 == 1 ? carta1.nome : resultado2 == 2 ? carta2.nome : "Empate");

    // Cálculo da soma dos atributos
    float soma1 = obterValorAtributo(&carta1, opcao1) + obterValorAtributo(&carta1, opcao2);
    float soma2 = obterValorAtributo(&carta2, opcao1) + obterValorAtributo(&carta2, opcao2);

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    // Determinação do vencedor final
    printf("\nResultado final: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}