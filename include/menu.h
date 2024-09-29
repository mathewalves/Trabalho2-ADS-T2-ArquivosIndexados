#ifndef MENU_H
#define MENU_H

#include "structs.h"

void mostrarDados(Cidade cidades[], Indice ind_cidade[], int num_cidades, 
                  Curso cursos[], Indice ind_curso[], int num_cursos, 
                  Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores, 
                  Aluno alunos[], Indice ind_aluno[], int num_alunos,
                  Turma turmas[], Indice ind_turma[], int num_turmas,
                  Matricula matriculas[], Indice ind_matricula[], int num_matriculas);

void menuInclusao(Cidade cidades[], Indice ind_cidade[], int& num_cidades, 
                  Curso cursos[], Indice ind_curso[], int& num_cursos, 
                  Instrutor instrutores[], Indice ind_instrutor[], int& num_instrutores, 
                  Aluno alunos[], Indice ind_aluno[], int& num_alunos,
                  Turma turmas[], Indice ind_turma[], int& num_turmas,
                  Matricula matriculas[], Indice ind_matricula[], int& num_matriculas);

void menuExclusao(Cidade* cidades, Indice* ind_cidade, int& num_cidades,
                  Curso* cursos, Indice* ind_curso, int& num_cursos,
                  Instrutor* instrutores, Indice* ind_instrutor, int& num_instrutores,
                  Aluno* alunos, Indice* ind_aluno, int& num_alunos,
                  Matricula* matriculas, int num_matriculas,
                  Turma* turmas, int& num_turmas);

#endif