#ifndef INSTRUTOR_H
#define INSTRUTOR_H

#include "structs.h"
#include "turma.h"

void gerarIndicesInstrutores(Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores);
bool codigoInstrutorExiste(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigo);
void lerDadosInstrutor(Instrutor instrutores[], Indice ind_instrutor[], int& num_instrutores);
void mostrarTodosInstrutores(Instrutor instrutores[], int num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades);
bool buscaBinariaInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigoBusca, Instrutor& instrutor_encontrado);
void exclusaoInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int& num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades, Turma turmas[], int num_turmas);
void reorganizacao(Indice ind_instrutor[], Instrutor instrutores[], int& num_instrutores);
bool instrutorTemTurma(int codigo_instrutor, Turma turmas[], int num_turmas);

#endif