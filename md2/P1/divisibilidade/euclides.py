# 5 - Algoritmo de Euclides para o cálculo do MDC

def mdc(a, b):
    if b == 0:  # Caso base: se b é 0, o MDC é a
        return a
    else:
        return mdc(b, a % b)  # Chamada recursiva com (b, a % b)

x = int(input("Digite o primeiro número: "))
y = int(input("Digite o segundo número: "))
resultado = mdc(x, y)
print(f"O MDC de {x} e {y} é {resultado}")