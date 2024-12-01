# 3 - a impressão recursiva dos números naturais de 1 a n 

def soma_naturais(n):
    if n == 1:  # Caso base: a soma de 1 é 1
        return 1
    else:
        return n + soma_naturais(n - 1)  # Soma o número atual com a soma dos anteriores

numero = int(input("Digite um número: "))
resultado = soma_naturais(numero)
print(f"A soma dos números de 1 até {numero} é {resultado}")
