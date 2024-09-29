#ifndef CURSO_H
#define CURSO_H

#include "structs.h"

void gerarIndicesCursos(Curso cursos[], Indice ind_curso[], int num_cursos);
void lerDadosCursos(Curso cursos[], Indice ind_curso[], int& num_cursos);
void mostrarTodosCursos(Curso cursos[], Indice ind_curso[], int num_cursos);
bool buscaBinariaCurso(Indice ind_curso[], Curso cursos[], int num_cursos, int codigoBusca, Curso& curso_encontrado);

#endif