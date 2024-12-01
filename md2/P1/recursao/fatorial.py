# 1 - o cálculo de n! utilizando recursividade 

def fatorial(n):
    if n == 0 or n == 1:  # Caso base: fatorial de 0 ou 1 é 1
        return 1
    else:
        return n * fatorial(n - 1)  # Chamada recursiva

numero = int(input("Digite um número: "))
resultado = fatorial(numero)
print(f"O fatorial de {numero} é {resultado}")