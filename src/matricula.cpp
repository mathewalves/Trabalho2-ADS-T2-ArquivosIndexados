#include "../include/matricula.h"
#include "../include/utils.h"
#include "../include/aluno.h"
#include "../include/turma.h"
#include "../include/curso.h"
#include <iostream>
using namespace std;

void gerarIndicesMatriculas(Matricula matriculas[], Indice ind_matricula[], int num_matriculas) {
    int j = 0;
    for (int i = 0; i < num_matriculas; i++) {
        if (matriculas[i].status == 1) {
            ind_matricula[j].chave = matriculas[i].codigo_matricula;
            ind_matricula[j].endereco = i;
            j++;
        }
    }
    // ordenar índices
    for (int i = 0; i < j - 1; i++) {
        for (int k = 0; k < j - i - 1; k++) {
            if (ind_matricula[k].chave > ind_matricula[k + 1].chave) {
                Indice temp = ind_matricula[k];
                ind_matricula[k] = ind_matricula[k + 1];
                ind_matricula[k + 1] = temp;
            }
        }
    }
}

void lerDadosMatricula(Matricula matriculas[], Indice ind_matricula[], int& num_matriculas, Aluno alunos[], Indice ind_aluno[], int num_alunos, Turma turmas[], Indice ind_turma[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos) {
    int i = num_matriculas;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo da Matrícula " << (i+1) << " (0 para sair): ";
        cin >> matriculas[i].codigo_matricula;
        if (matriculas[i].codigo_matricula == 0) {
            saida = 0;
            break;
        }

        cout << "Código do Aluno: ";
        cin >> matriculas[i].codigo_aluno;
        Aluno aluno_encontrado;
        if (buscaBinariaAluno(ind_aluno, alunos, num_alunos, matriculas[i].codigo_aluno, aluno_encontrado)) {
            cout << "Aluno: " << aluno_encontrado.nome << endl;
        } else {
            cout << "Aluno não encontrado. Operação cancelada." << endl;
            continue;
        }

        cout << "Código da Turma: ";
        cin >> matriculas[i].codigo_turma;
        Turma turma_encontrada;
        if (buscaBinariaTurma(ind_turma, turmas, num_turmas, matriculas[i].codigo_turma, turma_encontrada)) {
            if (turma_encontrada.total_participantes >= turma_encontrada.quant_max_participantes) {
                cout << "Turma está cheia. Operação cancelada." << endl;
                continue;
            }
            Curso curso_encontrado;
            if (buscaBinariaCurso(ind_curso, cursos, num_cursos, turma_encontrada.codigo_curso, curso_encontrado)) {
                cout << "Curso: " << curso_encontrado.descricao << ", Valor por aula: R$" << curso_encontrado.valor_por_aula << endl;
            } else {
                cout << "Curso não encontrado. Operação cancelada." << endl;
                continue;
            }
        } else {
            cout << "Turma não encontrada. Operação cancelada." << endl;
            continue;
        }

        cout << "Quantidade de aulas: ";
        cin >> matriculas[i].quantidade_aulas;
        
        Curso curso_da_turma;
        if (buscaBinariaCurso(ind_curso, cursos, num_cursos, turma_encontrada.codigo_curso, curso_da_turma)) {
            matriculas[i].valor_total = matriculas[i].quantidade_aulas * curso_da_turma.valor_por_aula;
            cout << "Valor total a ser pago: R$" << matriculas[i].valor_total << endl;
        } else {
            cout << "Erro ao calcular o valor total. Operação cancelada." << endl;
            continue;
        }
        
        matriculas[i].status = 1;
        
        for (int j = 0; j < num_turmas; j++) {
            if (turmas[j].codigo_turma == matriculas[i].codigo_turma) {
                turmas[j].total_participantes++;
                break;
            }
        }
        
        num_matriculas++;
        gerarIndicesMatriculas(matriculas, ind_matricula, num_matriculas);
    }
}

void mostrarTodasMatriculas(Matricula matriculas[], int num_matriculas, Aluno alunos[], Indice ind_aluno[], int num_alunos, Turma turmas[], Indice ind_turma[], int num_turmas, Curso cursos[], Indice ind_curso[], int num_cursos) {
    cout << "\nDados de todas as Matrículas:\n";
    for (int i = 0; i < num_matriculas; i++) {
        if (matriculas[i].status == 1) {
            Aluno aluno_encontrado;
            Turma turma_encontrada;
            Curso curso_encontrado;
            if (buscaBinariaAluno(ind_aluno, alunos, num_alunos, matriculas[i].codigo_aluno, aluno_encontrado) &&
                buscaBinariaTurma(ind_turma, turmas, num_turmas, matriculas[i].codigo_turma, turma_encontrada) &&
                buscaBinariaCurso(ind_curso, cursos, num_cursos, turma_encontrada.codigo_curso, curso_encontrado)) {
                
                cout << "Código: " << matriculas[i].codigo_matricula 
                     << ", Aluno: " << aluno_encontrado.nome
                     << ", Curso: " << curso_encontrado.descricao
                     << ", Aulas: " << matriculas[i].quantidade_aulas
                     << ", Valor Total: R$" << matriculas[i].valor_total << endl;
            }
        }
    }
}