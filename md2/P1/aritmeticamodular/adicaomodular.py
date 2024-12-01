# 7 - Tabela Z_n para adição modular

def tabela_zn_adicao(n):
    # Cabeçalho da tabela
    print(f"\nTabela de adição modular em Z_{n}:\n")
    print("   ", end="")
    for b in range(n):
        print(f"{b:3}", end="")
    print("\n" + "-" * (n * 3 + 3))
    
    # Corpo da tabela
    for a in range(n):
        print(f"{a:2} |", end="")  # Índice da linha
        for b in range(n):
            print(f"{(a + b) % n:3}", end="")
        print()  # Nova linha

n = int(input("Digite o valor de n para Z_n: "))
tabela_zn_adicao(n)
