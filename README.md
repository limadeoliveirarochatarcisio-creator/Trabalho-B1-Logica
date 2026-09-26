# Trabalho B1 - Lógica de Programação e Algoritmos
## Simulador de Entregas

## Descrição
Sistema desenvolvido em linguagem C para execução em terminal que simula o processamento e cálculo de tarifas de entregas locais. O programa calcula o valor final de cada solicitação com base na distância, peso, modalidade escolhida, serviço de proteção e tentativas adicionais, gerando um resumo estatístico completo ao encerrar a sessão.

## Funcionalidades
- **Validação rigorosa de entradas de domínio:** impede a inserção de distâncias/pesos inválidos ou códigos incorretos através de loops de repetição.
- **Cálculo de tarifas em camadas:** aplica taxas fixas por faixa de distância, taxa variável por quilômetro e adicionais percentuais calculados sobre o subtotal base.
- **Resumo estatístico da sessão:** calcula quantidade total de entregas, valor acumulado, valor médio, contagem por modalidade e identificação do maior e menor valor registrado sem utilizar vetores ou alocação dinâmica.

## Organização da solução
A solução foi modularizada com funções de responsabilidades bem definidas:
- `ler_float_positivo` e `ler_int_intervalo`: garantem a validação contínua das entradas de dados.
- `calcular_subtotal_distancia`: calcula o valor-base da faixa de distância somado à taxa por quilômetro percorrido.
- `calcular_adicional_peso` e `calcular_adicional_modalidade`: aplicam os percentuais adicionais diretamente sobre o subtotal inicial.
- `calcular_valor_entrega`: consolida todas as parcelas numéricas na ordem exigida pela regra de negócio.
- `exibir_resumo`: responsável por formatar e exibir o relatório final ao usuário.

## Compilação
Para compilar o projeto utilizando o GCC, execute no terminal:
```bash
gcc src/main.c -o simulador

Trabalho finalizado e testado.
