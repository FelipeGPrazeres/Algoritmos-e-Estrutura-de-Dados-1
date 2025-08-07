#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 41
#define NUM_NOTAS 3
#define MAX_ALUNOS 50

typedef struct {
    char nome[MAX_NOME];
    float notas[NUM_NOTAS];
    float media;
} Aluno;

void limparBuffer()
{
    char ch;
    while (((ch = getchar()) != '\n') && ch != EOF);
}

void listarUsuarios(const Aluno alunos[], int contador)
{
    if (contador == 0)
    {
        printf("Não há alunos para mostrar!\n");
        return;
    }

    int i;
    for (i = 0; i < contador; i++)
    {
        printf("Nome: %s; Média: %.2f\n", alunos[i].nome,
                                          alunos[i].media);
    }
}

void adicionarAlunos(int contador, Aluno alunos[])
{
    if (contador < MAX_ALUNOS)
    {
        printf("Digite o nome do aluno: ");
        fgets(alunos[contador].nome, MAX_NOME, stdin);
        printf("Digite as notas do aluno (separadas por espaço): ");
        for (int i = 0; i < NUM_NOTAS; i++) {
            scanf("%f", &alunos[contador].notas[i]);
        }
        for (int i = 0; i < NUM_NOTAS; i++) {
            alunos[contador].media += alunos[contador].notas[i];
        }
        alunos[contador].media /= NUM_NOTAS;
        limparBuffer();
    }

}

void maiorMedia(const Aluno alunos[], int contador)
{
    if (contador == 0)
    {
        printf("Não há alunos para calcular a média!\n");
        return;
    }

    float maiorMedia = alunos[0].media;
    int indiceMaior = 0;

    for (int i = 1; i < contador; i++)
    {
        if (alunos[i].media > maiorMedia)
        {
            maiorMedia = alunos[i].media;
            indiceMaior = i;
        }
    }

    printf("Aluno com maior média: %s\n",alunos[indiceMaior].nome);
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("Nota %d: %.2f\n", i + 1, alunos[indiceMaior].notas[i]);
    }
    printf("Média: %.2f\n", alunos[indiceMaior].media);

}


void main()
{
    // array (vetor de alunos)
    Aluno alunos[MAX_ALUNOS];
    int contador = 0;

    // para ler a opção do menu
    int opcao;

    do {
        printf("---- MENU ----\n");
        printf("1. Add usuário\n");
        printf("2. Listar usuários\n");
        printf("3. Mostrar usuário com maior média\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();
        switch (opcao) {
            case 1:
                // add usuario
                adicionarAlunos(contador, alunos);
                contador++;
                break;
            case 2:
                // listar usuarios
                listarUsuarios(alunos, contador);
                break;
            case 3:
                // mostrar maior média
                maiorMedia(alunos, contador);
                break;
            case 0:
                printf("Fim do programa!\n");
                break;
            default:
                printf("Opção inválida!!\n");
                break;
        }
    } while (opcao != 0);

}

