# 2 - a sequência de Fibonacci

def fibonacci(n):
    if n == 0:  # Caso base 1: Fibonacci(0) = 0
        return 0
    elif n == 1:  # Caso base 2: Fibonacci(1) = 1
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2) 

numero = int(input("Digite um número: "))
resultado = fibonacci(numero)
print(f"O {numero}-ésimo número de Fibonacci é {resultado}")
2