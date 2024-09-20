#ifndef ALUNO_H
#define ALUNO_H

#include "structs.h"

void gerarIndicesAlunos(Aluno alunos[], Indice ind_aluno[], int num_alunos);
bool codigoInstrutorExiste(Indice ind_aluno[], int num_alunos, int codigo);
void lerDadosAluno(Aluno alunos[], Indice ind_aluno[], int& num_alunos);
void mostrarTodosAlunos(Aluno alunos[], int num_alunos, Cidade cidades[], Indice ind_cidade[], int num_cidades);
void buscaBinariaAluno(Indice ind_aluno[], Aluno alunos[], int num_alunos, int codigoBusca, Cidade cidades[], Indice ind_cidade[], int num_cidades);


#endif