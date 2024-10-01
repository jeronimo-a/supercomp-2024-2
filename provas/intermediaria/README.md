# SUPERCOMPUTAÇÃO, 2024-2

## Prova Intermediária - Resolução

Jerônimo de Abreu Afrange

### Questão 1:

#### 1. "Implemente o algoritmo heurístico descrito acima em C++. (entregue o código)"

Implementação em `/questao_1/programa.cpp`

Estrutura arquivo de entrada:

    <QUANTIDADE_NÚMEROS>
    <SOMA_DESEJADA>
    <S_0>
    <S_1>
    <S_2>
    <S_3>
    ...
    <S_N>

Na etapa 2 da heurística descrita, o número em questão (s_i) é incluso na soma se o seu valor somado ao resto já incluso não ultrapassar o valor da soma desejada.

#### 2. "Faça cenários de teste e comprove a corretude da solução."

**Teste 1:** verdadeiro positivo em `questao_1/teste_1.txt`

**Teste 2:** falso negativo em `questao_1/teste_2.txt`