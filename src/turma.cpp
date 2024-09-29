#include "../include/turma.h"
#include "../include/utils.h"
#include "../include/curso.h"
#include "../include/instrutor.h"
#include <iostream>
using namespace std;

void gerarIndicesTurmas(Turma turmas[], Indice ind_turma[], int num_turmas) {
    int j = 0;
    for (int i = 0; i < num_turmas; i++) {
        if (turmas[i].status == 1) {
            ind_turma[j].chave = turmas[i].codigo_turma;
            ind_turma[j].endereco = i;
            j++;
        }
    }
    // Ordenar índices
    for (int i = 0; i < j - 1; i++) {
        for (int k = 0; k < j - i - 1; k++) {
            if (ind_turma[k].chave > ind_turma[k + 1].chave) {
                Indice temp = ind_turma[k];
                ind_turma[k] = ind_turma[k + 1];
                ind_turma[k + 1] = temp;
            }
        }
    }
}

void lerDadosTurma(Turma turmas[], Indice ind_turma[], int& num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos, Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores) {
    int i = num_turmas;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo da Turma " << (i+1) << " (0 para sair): ";
        cin >> turmas[i].codigo_turma;
        if (turmas[i].codigo_turma == 0) {
            saida = 0;
            break;
        }

        cout << "Código do Curso: ";
        cin >> turmas[i].codigo_curso;
        Curso curso_encontrado;
        if (buscaBinariaCurso(ind_curso, cursos, num_cursos, turmas[i].codigo_curso, curso_encontrado)) {
            cout << "Curso: " << curso_encontrado.descricao << ", Valor por aula: R$" << curso_encontrado.valor_por_aula << endl;
        } else {
            cout << "Curso não encontrado. Operação cancelada." << endl;
            continue;
        }

        cout << "Código do Instrutor: ";
        cin >> turmas[i].codigo_instrutor;
        Instrutor instrutor_encontrado;
        if (buscaBinariaInstrutor(ind_instrutor, instrutores, num_instrutores, turmas[i].codigo_instrutor, instrutor_encontrado)) {
            cout << "Instrutor: " << instrutor_encontrado.nome << endl;
        } else {
            cout << "Instrutor não encontrado. Operação cancelada." << endl;
            continue;
        }

        cout << "Quantidade máxima de participantes: ";
        cin >> turmas[i].quant_max_participantes;
        
        turmas[i].total_participantes = 0;
        turmas[i].status = 1;
        
        num_turmas++;
        gerarIndicesTurmas(turmas, ind_turma, num_turmas);
    }
}

void mostrarTodasTurmas(Turma turmas[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos, Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores) {
    cout << "\nDados de todas as Turmas:\n";
    for (int i = 0; i < num_turmas; i++) {
        if (turmas[i].status == 1) {
            Curso curso_encontrado;
            Instrutor instrutor_encontrado;
            buscaBinariaCurso(ind_curso, cursos, num_cursos, turmas[i].codigo_curso, curso_encontrado);
            buscaBinariaInstrutor(ind_instrutor, instrutores, num_instrutores, turmas[i].codigo_instrutor, instrutor_encontrado);
            
            cout << "Código: " << turmas[i].codigo_turma 
                 << ", Curso: " << curso_encontrado.descricao
                 << ", Instrutor: " << instrutor_encontrado.nome
                 << ", Participantes: " << turmas[i].total_participantes << "/" << turmas[i].quant_max_participantes << endl;
        }
    }
}

void consultarTurma(Turma turmas[], Indice ind_turma[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos, Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores) {
    int codigo_turma;
    cout << "Digite o código da turma: ";
    cin >> codigo_turma;

    for (int i = 0; i < num_turmas; i++) {
        if (turmas[i].codigo_turma == codigo_turma && turmas[i].status == 1) {
            Curso curso_encontrado;
            Instrutor instrutor_encontrado;
            buscaBinariaCurso(ind_curso, cursos, num_cursos, turmas[i].codigo_curso, curso_encontrado);
            buscaBinariaInstrutor(ind_instrutor, instrutores, num_instrutores, turmas[i].codigo_instrutor, instrutor_encontrado);
            
            cout << "Dados da Turma:\n";
            cout << "Código: " << turmas[i].codigo_turma << endl;
            cout << "Curso: " << curso_encontrado.descricao << endl;
            cout << "Instrutor: " << instrutor_encontrado.nome << endl;
            cout << "Participantes: " << turmas[i].total_participantes << "/" << turmas[i].quant_max_participantes << endl;
            return;
        }
    }
    cout << "Turma não encontrada." << endl;
}

void mostrarTurmasCompletas(Turma turmas[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos) {
    cout << "\nTurmas Completas:\n";
    for (int i = 0; i < num_turmas; i++) {
        if (turmas[i].status == 1 && turmas[i].total_participantes == turmas[i].quant_max_participantes) {
            Curso curso_encontrado;
            buscaBinariaCurso(ind_curso, cursos, num_cursos, turmas[i].codigo_curso, curso_encontrado);
            
            cout << "Código: " << turmas[i].codigo_turma 
                 << ", Curso: " << curso_encontrado.descricao
                 << ", Participantes: " << turmas[i].total_participantes << endl;
        }
    }
}

bool buscaBinariaTurma(Indice ind_turma[], Turma turmas[], int num_turmas, int codigoBusca, Turma& turma_encontrada) {
    int inicio = 0, fim = num_turmas - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_turma[meio].chave == codigoBusca) {
            turma_encontrada = turmas[ind_turma[meio].endereco];
            return true;
        } else if (ind_turma[meio].chave < codigoBusca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false;
}