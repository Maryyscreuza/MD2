#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Questão 10 - Desenvolver um código que calcule a criptografia RSA, no qual o usuário irá definir os primos (p e q) , número E e o tamanho do bloco. 
// Definir um pré-código com o alfabeto iniciando em A = 11.

// Calculo do mdc
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mod_inverso(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (mdc(a, m) != 1)
        return -1;
    
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    return (x1 < 0) ? x1 + m0 : x1;
}

// Função para calcular potência modular (base^exp % mod)
long long potencia_modular(long long base, long long exp, long long mod) {
    long long resultado = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            resultado = (resultado * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return resultado;
}

// Função para codificar a mensagem em números
void codificar_mensagem(char *mensagem, int *codigos, int tamanho_bloco) {
    int i = 0, bloco_idx = 0;
    while (mensagem[i] != '\0') {
        codigos[bloco_idx] = (mensagem[i] - 'A' + 11); // A = 11, B = 12, ..., Z = 36
        i++;
        bloco_idx++;
        
        // Quando o tamanho do bloco for atingido, move para o próximo
        if (bloco_idx == tamanho_bloco) {
            bloco_idx = 0;
        }
    }
}

// Função para cifrar a mensagem usando RSA
void cifrar(int *mensagem_codificada, int tamanho, int e, int n, int *mensagem_cifrada) {
    for (int i = 0; i < tamanho; i++) {
        mensagem_cifrada[i] = potencia_modular(mensagem_codificada[i], e, n);
    }
}

int main() {
    int p, q, e, d, n, phi;
    int tamanho_bloco;
    char mensagem[100];
    
    printf("Digite os primos p e q: \n");
    scanf("%d %d", &p, &q);
    
    printf("Digite o expoente público E: \n");
    scanf("%d", &e);
    
    printf("Digite o tamanho do bloco: \n");
    scanf("%d", &tamanho_bloco);
    
    // Cálculo de n e phi(n)
    n = p * q;
    phi = (p - 1) * (q - 1);
    
    // Cálculo do inverso modular de E para obter D
    d = mod_inverso(e, phi);
    if (d == -1) {
        printf("Erro: Não foi possível calcular o inverso modular. Escolha outro E.\n");
        return 1;
    }
    
    printf("Digite a mensagem (somente letras maiúsculas A-Z): \n");
    scanf("%s", mensagem);
    
    int mensagem_codificada[100], mensagem_cifrada[100];
    
    codificar_mensagem(mensagem, mensagem_codificada, tamanho_bloco); // Codificar a mensagem
    
    int tamanho_mensagem = 0;
    while (mensagem[tamanho_mensagem] != '\0') tamanho_mensagem++; // Cifrar a mensagem
    
    cifrar(mensagem_codificada, tamanho_mensagem, e, n, mensagem_cifrada);
    
    printf("Mensagem cifrada: ");
    for (int i = 0; i < tamanho_mensagem; i++) {
        printf("%d ", mensagem_cifrada[i]);
    }
    printf("\n");
    
    return 0;
}