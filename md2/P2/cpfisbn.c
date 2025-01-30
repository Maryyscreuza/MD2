#include <stdio.h>
#include <stdlib.h>

// Questão 11 - Desenvolver um código que calcule o CPF e o ISBN de um livro, utilizando as regras de congruência.

// Cálculo do primeiro dígito verificador do CPF
int calcular_digito_cpf(int numeros[], int tamanho) {
    int soma = 0;
    int pesos[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};  // Pesos para o primeiro dígito
    
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i] * pesos[i];
    }
    
    int digito = soma % 11;
    if (digito < 2) {
        return 0;
    } else {
        return 11 - digito;
    }
}

// Cálculo do segundo dígito verificador do CPF
int calcular_segundo_digito_cpf(int cpf[]) {
    int soma = 0;
    int pesos[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};  // Pesos para o segundo dígito
    
    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * pesos[i];
    }
    
    int digito = soma % 11;
    if (digito < 2) {
        return 0;
    } else {
        return 11 - digito;
    }
}

// Função para validar e calcular o CPF
void validar_cpf(int cpf[]) {
    int primeiro_digito = calcular_digito_cpf(cpf, 9);
    
    cpf[9] = primeiro_digito;
    
    int segundo_digito = calcular_segundo_digito_cpf(cpf);
    cpf[10] = segundo_digito;
    
    // Imprime o CPF completo
    printf("CPF: ");
    for (int i = 0; i < 11; i++) {
        printf("%d", cpf[i]);
    }
    printf("\n");
}

// Cálculo do dígito verificador do ISBN
char calcular_digito_isbn(int numeros[]) {
    int soma = 0;
    int pesos[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};  // Pesos para o ISBN
    
    for (int i = 0; i < 9; i++) {
        soma += numeros[i] * pesos[i];
    }
    
    // Cálculo do dígito verificador
    int digito = soma % 11;
    
    if (digito == 10) {
        return 'X';
    } else {
        return digito + '0';  
    }
}

// Função para validar e calcular o ISBN
void validar_isbn(int isbn[]) {
    char digito_verificador = calcular_digito_isbn(isbn);
    
    // Imprime o ISBN completo
    printf("ISBN: ");
    for (int i = 0; i < 9; i++) {
        printf("%d", isbn[i]);
    }
    printf("%c\n", digito_verificador);
}

int main() {
    char cpf_input[12];  // Armazena os 11 números do CPF como string
    char isbn_input[10];  // Armazena os 9 números do ISBN como string
    
    // Para armazenar os números
    int cpf[11];
    int isbn[9]; 
    
    // Entrar com os 9 primeiros números do CPF como uma string
    printf("Digite os 9 primeiros números do CPF (sem espaços): \n");
    scanf("%s", cpf_input);
    
    for (int i = 0; i < 9; i++) {
        cpf[i] = cpf_input[i] - '0';  // Converte o caractere para inteiro
    }
    
    validar_cpf(cpf);
    
    // Entrar com os 9 primeiros números do ISBN como uma string
    printf("Digite os 9 primeiros números do ISBN (sem espaços): \n");
    scanf("%s", isbn_input);
    
    for (int i = 0; i < 9; i++) {
        isbn[i] = isbn_input[i] - '0';  // Converte o caractere para inteiro
    }
    
    validar_isbn(isbn);
    
    return 0;
}
