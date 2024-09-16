#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

struct Cidade {
    int codigo_cidade;
    char nome[50];
    char UF[2];
    int status;
};

struct Curso {
    int codigo_curso;
    char descricao[100];
    float valor_por_aula;
    int status;
};

struct Instrutor {
    int codigo_instrutor;
    char nome[50];
    char endereco[100];
    int codigo_cidade;
    int status;
};

struct Aluno {
    int codigo_aluno;
    char nome[50];
    char endereco[100];
    int codigo_cidade;
    int status;
};

struct Indice {
    int chave;
    int endereco;
};

#endif