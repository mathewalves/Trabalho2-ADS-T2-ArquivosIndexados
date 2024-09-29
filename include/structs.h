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

struct Turma {
    int codigo_turma;
    int codigo_curso;
    int codigo_instrutor;
    int total_participantes;
    int quant_max_participantes;
    int status;
};

struct Matricula {
    int codigo_matricula;
    int codigo_aluno;
    int codigo_turma;
    int quantidade_aulas;
    float valor_total;
    int status;
};

#endif