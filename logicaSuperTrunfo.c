#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar uma carta de cidade
struct Carta {
    char estado[3];
    int codigo;
    char nome[50];
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
};

// --- Função para cadastrar os dados de uma carta ---
void cadastrarCarta(struct Carta *carta, int numero_carta) {
    printf("--- Cadastro da Carta %d ---\n", numero_carta);
    printf("Digite o estado (UF): ");
    scanf("%2s", carta->estado);
    printf("Digite o codigo da carta: ");
    scanf("%d", &carta->codigo);
    printf("Digite o nome da cidade: ");
    // Limpar o buffer do teclado antes de ler a string
    while (getchar() != '\n');
    fgets(carta->nome, 50, stdin);
    // Remover o '\n' que o fgets adiciona
    carta->nome[strcspn(carta->nome, "\n")] = 0;

    printf("Digite a populacao: ");
    scanf("%lld", &carta->populacao);
    printf("Digite a area (em km2): ");
    scanf("%lf", &carta->area);
    printf("Digite o PIB: ");
    scanf("%lld", &carta->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// --- Função para exibir os dados de uma carta ---
void exibirCarta(struct Carta carta) {
    printf("----------------------------------------\n");
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %d\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("Populacao: %lld habitantes\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %lld R$\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("----------------------------------------\n");
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    // Cadastra as duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibe as cartas cadastradas
    printf("\n--- Cartas Cadastradas ---\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("\nCarta 2:\n");
    exibirCarta(carta2);

    // --- Lógica de Comparação ---
    // Você pode alterar este valor para comparar outras propriedades
    // 1 = Populacao | 2 = Area | 3 = PIB | 4 = Pontos Turisticos
    printf("\nEscolha a propriedade para comparacao:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    scanf("%d", &opcao);

    int vencedor = 0; // 0 = Empate, 1 = Carta 1, 2 = Carta 2

    // Usando if-else para a lógica de comparação
    if (opcao == 1) {
        printf("\n--- Comparando Populacao ---\n");
        if (carta1.populacao > carta2.populacao) {
            vencedor = 1;
        } else if (carta2.populacao > carta1.populacao) {
            vencedor = 2;
        }
    } else if (opcao == 2) {
        printf("\n--- Comparando Area ---\n");
        if (carta1.area > carta2.area) {
            vencedor = 1;
        } else if (carta2.area > carta1.area) {
            vencedor = 2;
        }
    } else if (opcao == 3) {
        printf("\n--- Comparando PIB ---\n");
        if (carta1.pib > carta2.pib) {
            vencedor = 1;
        } else if (carta2.pib > carta1.pib) {
            vencedor = 2;
        }
    } else if (opcao == 4) {
        printf("\n--- Comparando Pontos Turisticos ---\n");
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
            vencedor = 1;
        } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
            vencedor = 2;
        }
    } else {
        printf("\nOpcao invalida. Nenhum vencedor.\n");
        return 1;
    }

    // Exibe o resultado da comparação
    if (vencedor == 1) {
        printf("A Carta 1 (%s) vence!\n", carta1.nome);
    } else if (vencedor == 2) {
        printf("A Carta 2 (%s) vence!\n", carta2.nome);
    } else {
        printf("Houve um empate!\n");
    }

    return 0;
}
