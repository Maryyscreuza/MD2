# 6 - Calcular o MMC(a,b) a partir do MDC(a,b)

def mdc(a, b):
    # Algoritmo de Euclides para calcular o MDC
    while b != 0:
        a, b = b, a % b
    return a

def mmc(a, b):
    # Calcula o MMC usando a relação MMC(a, b) = (a * b) / MDC(a, b)
    return abs(a * b) // mdc(a, b)  # Usa divisão inteira para evitar valores decimais

x = int(input("Digite o primeiro número: "))
y = int(input("Digite o segundo número: "))
resultado = mmc(x, y)
print(f"O MMC de {x} e {y} é {resultado}")