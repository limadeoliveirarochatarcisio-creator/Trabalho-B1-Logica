#include <stdio.h>

#define VALOR_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA 4.00

float ler_float_positivo(char mensagem[]);
int ler_int_intervalo(char mensagem[], int min, int max);
float calcular_subtotal_distancia(float distancia);
float calcular_adicional_peso(float subtotal, float peso);
float calcular_adicional_modalidade(float subtotal, int modalidade);
float calcular_valor_entrega(float distancia, float peso, int modalidade, int protecao, int tentativas);
void exibir_resumo(int total_entregas, float total_valor, int econ, int expr, int prior, float maior, float menor);

int main() {
    int total_entregas = 0;
    float total_valor = 0.0;
    int entregas_econ = 0, entregas_expr = 0, entregas_prior = 0;
    float maior_valor = 0.0, menor_valor = 0.0;
    
    int continuar = 1;

    printf("=== SIMULADOR DE ENTREGAS ===\n\n");

    while (continuar == 1) {
        printf("--- Nova Entrega (%d) ---\n", total_entregas + 1);
        
        float distancia = ler_float_positivo("Informe a distancia (km): ");
        float peso = ler_float_positivo("Informe o peso (kg): ");
        int modalidade = ler_int_intervalo("Informe a modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ", 1, 3);
        int protecao = ler_int_intervalo("Deseja servico de protecao? (1-Sim, 0-Nao): ", 0, 1);
        int tentativas = ler_int_intervalo("Informe a quantidade de tentativas adicionais: ", 0, 999);

        float valor_entrega = calcular_valor_entrega(distancia, peso, modalidade, protecao, tentativas);
        printf("-> Valor final da entrega: R$ %.2f\n\n", valor_entrega);

        total_entregas++;
        total_valor += valor_entrega;

        if (modalidade == 1) entregas_econ++;
        else if (modalidade == 2) entregas_expr++;
        else if (modalidade == 3) entregas_prior++;

        if (total_entregas == 1) {
            maior_valor = valor_entrega;
            menor_valor = valor_entrega;
        } else {
            if (valor_entrega > maior_valor) maior_valor = valor_entrega;
            if (valor_entrega < menor_valor) menor_valor = valor_entrega;
        }


        continuar = ler_int_intervalo("Deseja registrar outra entrega? (1-Sim, 0-Nao): ", 0, 1);
        printf("\n");
    }

    exibir_resumo(total_entregas, total_valor, entregas_econ, entregas_expr, entregas_prior, maior_valor, menor_valor);

    return 0;
}

float ler_float_positivo(char mensagem[]) {
    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor <= 0) {
            printf("[ERRO] O valor deve ser maior que zero. Tente novamente.\n");
        }
    } while (valor <= 0);
    return valor;
}

int ler_int_intervalo(char mensagem[], int min, int max) {
    int valor;
    do {
        printf("%s", mensagem);
        scanf("%d", &valor);
        if (valor < min || valor > max) {
            printf("[ERRO] Opcao invalida. Digite um valor entre %d e %d.\n", min, max);
        }
    } while (valor < min || valor > max);
    return valor;
}

float calcular_subtotal_distancia(float distancia) {
    float base = 0.0;
    if (distancia <= 5.0) base = 8.00;
    else if (distancia <= 15.0) base = 12.00;
    else if (distancia <= 30.0) base = 18.00;
    else base = 25.00;

    return base + (distancia * VALOR_KM);
}

float calcular_adicional_peso(float subtotal, float peso) {
    if (peso <= 2.0) return 0.0;
    if (peso <= 5.0) return subtotal * 0.05;
    if (peso <= 10.0) return subtotal * 0.10;
    return subtotal * 0.20;
}

float calcular_adicional_modalidade(float subtotal, int modalidade) {
    if (modalidade == 2) return subtotal * 0.15; // Expressa
    if (modalidade == 3) return subtotal * 0.30; // Prioritária
    return 0.0; // Econômica
}

float calcular_valor_entrega(float distancia, float peso, int modalidade, int protecao, int tentativas) {
    float subtotal = calcular_subtotal_distancia(distancia);
    float adic_peso = calcular_adicional_peso(subtotal, peso);
    float adic_mod = calcular_adicional_modalidade(subtotal, modalidade);
    float valor_prot = (protecao == 1) ? VALOR_PROTECAO : 0.0;
    float valor_tent = tentativas * VALOR_TENTATIVA;

    return subtotal + adic_peso + adic_mod + valor_prot + valor_tent;
}

void exibir_resumo(int total_entregas, float total_valor, int econ, int expr, int prior, float maior, float menor) {
    printf("========================================\n");
    printf("           RESUMO DA SESSAO             \n");
    printf("========================================\n");
    printf("Total de entregas processadas: %d\n", total_entregas);
    if (total_entregas > 0) {
        printf("Valor total acumulado:        R$ %.2f\n", total_valor);
        printf("Valor medio por entrega:     R$ %.2f\n", total_valor / total_entregas);
        printf("Entregas Economicas:          %d\n", econ);
        printf("Entregas Expressas:           %d\n", expr);
        printf("Entregas Prioritarias:        %d\n", prior);
        printf("Maior valor de entrega:       R$ %.2f\n", maior);
        printf("Menor valor de entrega:       R$ %.2f\n", menor);
    } else {
        printf("Nenhuma entrega foi registrada.\n");
    }
    printf("========================================\n");
}