#include <stdio.h>

// Questão 09 – Desenvolver um código que calcule sistemas de congruência linear de até 4 equações utilizando o teorema chinês do resto

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
    
    if (mdc(a, m) != 1) // Verifica se a e m são coprimos
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

// FUnção teo chines
int teorema_chines_do_resto(int a[], int m[], int n) {
    int M = 1, i, x = 0;
    
    for (i = 0; i < n; i++) {
        if (i > 0 && mdc(m[i], m[i-1]) != 1) { // Verifica se os módulos são coprimos
            printf("Erro: Os módulos devem ser coprimos entre si!\n"); 
            return -1;
        }
        M *= m[i];
    }
    
    for (i = 0; i < n; i++) {
        int Mi = M / m[i];
        int inverso = mod_inverso(Mi, m[i]);
        if (inverso == -1) {
            printf("Erro: Não existe inverso modular para %d mod %d!\n", Mi, m[i]);
            return -1;
        }
        x = (x + a[i] * Mi * inverso) % M;
    }
    
    return (x + M) % M; // Garantir que x seja positivo
}

int main() {
    int n, i;
    printf("Número de equações (máximo 4): \n");
    scanf("%d", &n);
    
    if (n < 1 || n > 4) {
        printf("Número de equações inválido!\n");
        return 1;
    }
    
    int a[n], m[n];
    
    printf("Coeficientes 'a' e os módulos 'm' (a1 m1 a2 m2 ... an mn):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &m[i]);
    }
    
    int resultado = teorema_chines_do_resto(a, m, n);
    if (resultado != -1)
        printf("Solução mínima (menor x possível) x = %d\n", resultado);
    
    return 0;
}