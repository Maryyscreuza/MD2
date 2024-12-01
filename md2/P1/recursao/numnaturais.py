# 4 - um método recursivo que receba como entrada um número inteiro positivo n e retorne 1 + 2 + 3 + 4 + … + n

def imprimir_naturais(n):
    if n > 0:
        imprimir_naturais(n - 1)  # Chamada recursiva para imprimir os números menores
        print(n)  # Imprime o valor de n após a chamada recursiva

numero = int(input("Digite um número: "))
imprimir_naturais(numero)