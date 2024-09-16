#ifndef CIDADE_H
#define CIDADE_H

#include "structs.h"
#include <iostream>

void gerarIndicesCidades(Cidade cidades[], Indice ind_cidade[], int num_cidades);
void lerDadosCidades(Cidade cidades[], Indice ind_cidade[], int& num_cidades);
void mostrarTodasCidades(Cidade cidades[], Indice ind_cidade[], int num_cidades);
bool buscaBinariaCidade(Indice ind_cidade[], Cidade cidades[], int num_cidades, int codigoBusca, Cidade& cidade_encontrada, bool exibir = false);

#endif