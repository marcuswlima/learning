# Documentação do módulo utilitarios.py

## Objetivo

O módulo fornece funções utilitárias para:

- Validação de números.
- Identificação de números primos.
- Verificação de números inteiros e pares.
- Determinação de maior e menor valor.
- Entrada de dados validada.
- Cálculo de IMC.
- Manipulação e ordenação de dicionários.
- Impressão formatada de títulos e matrizes.

---

# Funções

## is_primo()

### Descrição
Verifica se um número é primo.

### Sintaxe
```python
is_primo(numero: float) -> bool
```

## is_inteiro()

### Descrição
Verifica se um número possui parte decimal.

### Sintaxe
```python
is_inteiro(numero: float) -> bool
```

## is_par()

### Descrição
Verifica se um número é par.

### Sintaxe
```python
is_par(numero: float) -> bool
```

## indicar_menor_numero()

### Descrição
Retorna o menor entre três números.

## indicar_maior_numero()

### Descrição
Retorna o maior entre três números.

## obter_float()

### Descrição
Solicita ao usuário um número decimal.

## obter_float_positivito()

### Descrição
Solicita repetidamente um número positivo.

## obter_int()

### Descrição
Solicita um número inteiro ao usuário.

## obter_int_positivo()

### Descrição
Solicita um inteiro positivo.

## obter_uma_letra()

### Descrição
Solicita ao usuário uma única letra.

## dicio_ordernado_por_valor()

### Descrição
Retorna um novo dicionário ordenado pelos valores.

## imc()

### Descrição
Calcula o Índice de Massa Corporal (IMC).

### Fórmula
```text
IMC = peso / altura²
```

## escrever_linha()

### Descrição
Imprime uma linha decorativa.

## titulo()

### Descrição
Exibe um título formatado.

## int2str()

### Descrição
Converte um inteiro para texto preenchendo espaços à direita até 4 caracteres.

## imprime_matriz()

### Descrição
Exibe uma matriz formatada no console.

---

# Melhorias sugeridas

1. Adicionar `from operator import itemgetter` para a função `dicio_ordernado_por_valor()`.
2. Alterar o parâmetro de `is_primo()` para `int`.
3. Corrigir o nome da função `obter_float_positivito()` para `obter_float_positivo()`.
4. Utilizar `min()` e `max()` nas funções de comparação.
5. Adicionar tratamento de exceções nas rotinas de entrada de dados.
