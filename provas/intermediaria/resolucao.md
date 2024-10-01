# SUPERCOMPUTAÇÃO, 2024-2

## Prova Intermediária - Resolução

Jerônimo de Abreu Afrange

### Questão 1

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

#### 3. "Discuta a eficácia da sua heurística. Em que cenários ela pode falhar em encontrar um subconjunto existente que some \( T \)? (entregue sua resposta justificada)"

A heurística implementada não consegue analisar tudo o que vem depois do número que ela está analisando no momento. Para a seguinte entrada, por exemplo

    5   <N>
    30  <T>
    29  <S_0>
    16  <S_1>
    14  <S_2>
    5   <S_3>
    2   <S_4>

o 29 já é incluso de cara na solução, só porque ele cabe. No entanto, o algoritmo não percebe que, se ele não incluir o 29, existe uma outra solução.

### Questão 2

#### 1. "Escreva o código da solução ótima em C++ (você pode usar recursão ou não);"

Implementação em `/questao_2/programa.cpp`

Formato da entrada igual ao da implementação da questão anterior.

#### 2. "Gere a solução para 10 entradas distintas em ordens de grandeza diferentes (algumas entradas pequenas, algumas médias, algumas grandes);"

Gráfico da relação entre o tempo de execução e o tamanho da entrada:

![Tempos de execução](questao_2/tempos_execucao.png)

Se não estiver carregando, ver `/questao_2/tempos_execucao.png`

#### 3. "Compare o tempo de execução deste código nas 10 entradas. O comportamento está alinhado com o esperado? Justifique."

Considerando que o espaço de pesquisa do algoritmo exaustivo dobra a cada incremento do tamanho do conjunto de entrada, espera-se que a complexidade dele seja `O(n²)`. A partir do gráfico do item anterior, percebe-se que o comportamento está sim alinhado com o esperado.