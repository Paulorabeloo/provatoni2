#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next, *back;
} no;

struct no *corrente, *inicio, *fim, *auxiliar, *auxiliar2;

void Exibir() {
    if(inicio == NULL) {
        printf("\nLista vazia");
        system("pause");
    } else {
        auxiliar = inicio;
        while(auxiliar != NULL) {
            printf("\nCodigo: %d", auxiliar->codigo);
            printf("\nNome: %s\n", auxiliar->nome);
            auxiliar = auxiliar->next;
        }
        system("pause");
    }
}

void Enterdata() {
    printf("Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("\nInforme o nome: ");
    scanf("%s", corrente->nome);
}

void Classificar() {
    int achou;
    corrente = (no*) malloc(sizeof(no));
    Enterdata();
    auxiliar = inicio;
    achou = 0;

    if(inicio == NULL) {
        fim = corrente;
        inicio = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        printf("\nPrimeiro elemento inserido na lista");
        system("pause");
        achou = 1;
    } else {
        if(strcmp(corrente->nome, auxiliar->nome) < 0) {
            corrente->next = auxiliar;
            inicio = corrente;
            corrente->back = NULL;
            auxiliar->back = corrente;
            printf("\nElemento inserido no início da lista");
            system("pause");
            achou = 1;
        } else {
            auxiliar2 = auxiliar->next;
            while(auxiliar2 != NULL) {
                if(strcmp(corrente->nome, auxiliar->nome) >= 0 && strcmp(corrente->nome, auxiliar2->nome) <= 0) {
                    auxiliar->next = corrente;
                    corrente->back = auxiliar;
                    corrente->next = auxiliar2;
                    auxiliar2->back = corrente;
                    printf("\nElemento inserido no meio da lista");
                    system("pause");
                    achou = 1;
                    break;
                }
                auxiliar2 = auxiliar2->next;
                auxiliar = auxiliar->next;
            }
        }
    }

    if(strcmp(corrente->nome, auxiliar->nome) >= 0 && achou == 0) {
        fim->next = corrente;
        corrente->back = fim;
        fim = corrente;
        corrente->next = NULL;
        printf("\nElemento inserido no final da lista");
        system("pause");
    }
}

void Excluir() {
    char xnome[30];
    int achou = 0;

    if(inicio == NULL) {
        printf("\nLista vazia...");
        system("pause");
    } else {
        auxiliar = inicio;
        printf("\nInforme o nome a ser excluido: ");
        scanf("%s", xnome);

        if(strcmp(xnome, auxiliar->nome) == 0) {
            inicio = inicio->next;
            if(inicio != NULL) {
                inicio->back = NULL;
            }
            free(auxiliar);
            achou = 1;
            printf("\nRegistro excluido com sucesso <<Inicio da lista>>");
            system("pause");
        } else {
            corrente = auxiliar->next;
            while(corrente != NULL) {
                if(strcmp(xnome, auxiliar->nome) == 0) {
                    corrente->back = auxiliar->back;
                    corrente = corrente->back;
                    corrente->next = auxiliar->next;
                    free(auxiliar);
                    printf("\nRegistro excluido com sucesso <<Meio da lista>>");
                    system("pause");
                    achou = 1;
                    break;
                }
                auxiliar = auxiliar->next;
                corrente = corrente->next;
            }
        }

        if(strcmp(xnome, auxiliar->nome) == 0 && achou == 0) {
            fim = fim->back;
            fim->next = NULL;
            free(auxiliar);
            printf("\nRegistro excluido com sucesso <<Fim da lista>>");
            system("pause");
        }

        if(achou == 0) {
            printf("\nO elemento nao esta na lista");
            system("pause");
        }
    }
}

int main() {
    int op;
    do {
        system("cls");
        printf(" [1] Incluir elementos na lista");
        printf("\n [2] Exibir os elementos da lista");
        printf("\n [3] Remover elementos da lista");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                Classificar();
                break;
            case 2:
                Exibir();
                break;
            case 3:
                Excluir();
                break;
            default:
                printf("\nOpcao invalida... Tente novamente");
                system("pause");
        }
    } while(op != 4);
}
