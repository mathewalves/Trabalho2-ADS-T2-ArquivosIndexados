#ifndef MATRICULA_H
#define MATRICULA_H

#include "structs.h"
#include "aluno.h"
#include "turma.h"
#include "curso.h"

void gerarIndicesMatriculas(Matricula matriculas[], Indice ind_matricula[], int num_matriculas);
void lerDadosMatricula(Matricula matriculas[], Indice ind_matricula[], int& num_matriculas, Aluno alunos[], Indice ind_aluno[], int num_alunos, Turma turmas[], Indice ind_turma[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos);
void mostrarTodasMatriculas(Matricula matriculas[], int num_matriculas, Aluno alunos[], Indice ind_aluno[], int num_alunos, Turma turmas[], Indice ind_turma[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos);

#endif