#include "../include/curso.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

void gerarIndicesCursos(Curso cursos[], Indice ind_curso[], int num_cursos) {
    for (int i = 0; i < num_cursos; i++) {
        ind_curso[i].chave = cursos[i].codigo_curso;
        ind_curso[i].endereco = i;
    }
    
    // Ordenar o índice por código do curso (chave)
    for (int i = 0; i < num_cursos - 1; i++) {
        for (int j = 0; j < num_cursos - i - 1; j++) {
            if (ind_curso[j].chave > ind_curso[j + 1].chave) {
                Indice temp = ind_curso[j];
                ind_curso[j] = ind_curso[j + 1];
                ind_curso[j + 1] = temp;
            }
        }
    }
}

void lerDadosCursos(Curso cursos[], Indice ind_curso[], int& num_cursos) {
    int i = num_cursos;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo do Curso " << (i+1) << " (0 para sair): ";
        cin >> cursos[i].codigo_curso;
        if (cursos[i].codigo_curso > 0) {
            cout << "Descrição: ";
            cin.ignore();
            cin.getline(cursos[i].descricao, 100);
            cout << "Valor por aula: ";
            cin >> cursos[i].valor_por_aula;
            cursos[i].status = 1; // Curso ativo
            num_cursos++;
        }
        else saida = 0;
    }
    gerarIndicesCursos(cursos, ind_curso, num_cursos);
}

void mostrarTodosCursos(Curso cursos[], Indice ind_curso[], int num_cursos) {
    cout << "\nDados de todos os Cursos:\n";
    for (int i = 0; i < num_cursos; i++) {
        int pos = ind_curso[i].endereco;
        if (cursos[pos].status == 1) {
            cout << "Código: " << cursos[pos].codigo_curso 
                 << ", Descrição: " << cursos[pos].descricao 
                 << ", Valor por aula: R$" << cursos[pos].valor_por_aula << endl;
        }
    }
}

void buscaBinariaCurso(Indice ind_curso[], Curso cursos[], int num_cursos, int codigoBusca) {
    int inicio = 0, fim = num_cursos - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (codigoBusca == ind_curso[meio].chave) {
            int posicaoRegistro = ind_curso[meio].endereco;
            if (cursos[posicaoRegistro].status == 1) {
                cout << "Curso encontrado:\n";
                cout << "Código: " << cursos[posicaoRegistro].codigo_curso 
                     << ", Descrição: " << cursos[posicaoRegistro].descricao 
                     << ", Valor por aula: R$" << cursos[posicaoRegistro].valor_por_aula << endl;
            } else {
                cout << "Curso excluído ou inválido.\n";
            }
            return;
        } else if (codigoBusca > ind_curso[meio].chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    cout << "Curso não encontrado.\n";
}