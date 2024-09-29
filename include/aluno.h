#ifndef ALUNO_H
#define ALUNO_H

#include "structs.h"
#include "turma.h"

void gerarIndicesAlunos(Aluno alunos[], Indice ind_aluno[], int num_alunos);
bool codigoAlunoExiste(Indice ind_aluno[], Aluno alunos[], int num_alunos, int codigo);
void lerDadosAluno(Aluno alunos[], Indice ind_aluno[], int& num_alunos);
void mostrarTodosAlunos(Aluno alunos[], int num_alunos, Cidade cidades[], Indice ind_cidade[], int num_cidades);
bool buscaBinariaAluno(Indice ind_aluno[], Aluno alunos[], int num_alunos, int codigoBusca, Aluno& aluno_encontrado);
void exclusaoAluno(Indice ind_aluno[], Aluno alunos[], int& num_alunos, Cidade cidades[], Indice ind_cidade[], int num_cidades, Matricula matriculas[], int num_matriculas);
void reorganizacao(Indice ind_aluno[], Aluno alunos[], int& num_alunos);
bool alunoTemMatricula(int codigo_aluno, Matricula matriculas[], int num_matriculas);

#endif