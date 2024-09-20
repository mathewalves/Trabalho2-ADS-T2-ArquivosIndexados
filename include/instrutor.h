#ifndef INSTRUTOR_H
#define INSTRUTOR_H

#include "structs.h"

void gerarIndicesInstrutores(Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores);
bool codigoInstrutorExiste(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigo);
void lerDadosInstrutor(Instrutor instrutores[], Indice ind_instrutor[], int& num_instrutores);
void mostrarTodosInstrutores(Instrutor instrutores[], int num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades);
void buscaBinariaInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigoBusca, Cidade cidades[], Indice ind_cidade[], int num_cidades);
void exclusaoInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int& num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades);

#endif