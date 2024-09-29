#ifndef TURMA_H
#define TURMA_H

#include "structs.h"
#include "curso.h"
#include "instrutor.h"

void gerarIndicesTurmas(Turma turmas[], Indice ind_turma[], int num_turmas);
void lerDadosTurma(Turma turmas[], Indice ind_turma[], int& num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos, Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores);
void mostrarTodasTurmas(Turma turmas[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos, Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores);
void consultarTurma(Turma turmas[], Indice ind_turma[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos, Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores);
void mostrarTurmasCompletas(Turma turmas[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos);
bool buscaBinariaTurma(Indice ind_turma[], Turma turmas[], int num_turmas, int codigoBusca, Turma& turma_encontrada);

#endif
