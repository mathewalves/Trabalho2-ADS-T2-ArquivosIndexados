#include "../include/menu.h"
#include "../include/cidade.h"
#include "../include/curso.h"
#include "../include/instrutor.h"
#include "../include/aluno.h"
#include "../include/turma.h"
#include "../include/matricula.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

void mostrarDados(Cidade cidades[], Indice ind_cidade[], int num_cidades, 
                  Curso cursos[], Indice ind_curso[], int num_cursos, 
                  Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores, 
                  Aluno alunos[], Indice ind_aluno[], int num_alunos,
                  Turma turmas[], Indice ind_turma[], int num_turmas,
                  Matricula matriculas[], Indice ind_matricula[], int num_matriculas) {
    int opcao;
    cout << "\nEscolha o tipo de dado para mostrar:\n";
    cout << "1. Cidades\n";
    cout << "2. Cursos\n";
    cout << "3. Instrutores\n";
    cout << "4. Alunos\n";
    cout << "5. Turmas\n";
    cout << "6. Matrículas\n";
    cout << "Opção: ";
    cin >> opcao;

    limparTela();
    switch (opcao) {
        case 1:
            mostrarTodasCidades(cidades, ind_cidade, num_cidades);
            break;
        case 2:
            mostrarTodosCursos(cursos, ind_curso, num_cursos);
            break;
        case 3:
            mostrarTodosInstrutores(instrutores, num_instrutores, cidades, ind_cidade, num_cidades);
            break;
        case 4:
            mostrarTodosAlunos(alunos, num_alunos, cidades, ind_cidade, num_cidades);
            break;
        case 5:
            mostrarTodasTurmas(turmas, num_turmas, cursos, ind_curso, num_cursos, instrutores, ind_instrutor, num_instrutores);
            break;
        case 6:
            mostrarTodasMatriculas(matriculas, num_matriculas, alunos, ind_aluno, num_alunos, turmas, ind_turma, num_turmas, cursos, ind_curso, num_cursos);
            break;
        default:
            cout << "Opção inválida.\n";
    }
    aguardarEnter();
}

void menuInclusao(Cidade cidades[], Indice ind_cidade[], int& num_cidades, 
                  Curso cursos[], Indice ind_curso[], int& num_cursos, 
                  Instrutor instrutores[], Indice ind_instrutor[], int& num_instrutores, 
                  Aluno alunos[], Indice ind_aluno[], int& num_alunos,
                  Turma turmas[], Indice ind_turma[], int& num_turmas,
                  Matricula matriculas[], Indice ind_matricula[], int& num_matriculas) {
    int opcao;
    do {
        limparTela();
        cout << "\nMenu de Inclusão:\n";
        cout << "1. Incluir Cidade\n";
        cout << "2. Incluir Curso\n";
        cout << "3. Incluir Instrutor\n";
        cout << "4. Incluir Aluno\n";
        cout << "5. Incluir Turma\n";
        cout << "6. Incluir Matrícula\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                limparTela();
                lerDadosCidades(cidades, ind_cidade, num_cidades);
                break;
            case 2:
                limparTela();
                lerDadosCursos(cursos, ind_curso, num_cursos);
                break;
            case 3:
                limparTela();
                lerDadosInstrutor(instrutores, ind_instrutor, num_instrutores);
                break;
            case 4:
                limparTela();
                lerDadosAluno(alunos, ind_aluno, num_alunos);
                break;
            case 5:
                limparTela();
                lerDadosTurma(turmas, ind_turma, num_turmas, cursos, ind_curso, num_cursos, instrutores, ind_instrutor, num_instrutores);
                break;
            case 6:
                limparTela();
                lerDadosMatricula(matriculas, ind_matricula, num_matriculas, alunos, ind_aluno, num_alunos, turmas, ind_turma, num_turmas, cursos, ind_curso, num_cursos);
                break;
            case 0:
                cout << "Voltando ao menu principal.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void menuExclusao(Cidade* cidades, Indice* ind_cidade, int& num_cidades,
                  Curso* cursos, Indice* ind_curso, int& num_cursos,
                  Instrutor* instrutores, Indice* ind_instrutor, int& num_instrutores,
                  Aluno* alunos, Indice* ind_aluno, int& num_alunos,
                  Matricula* matriculas, int num_matriculas,
                  Turma* turmas, int& num_turmas) {
    int opcao;
    do {
        limparTela();
        cout << "\nMenu de Exclusão:\n";
        cout << "1. Excluir Instrutor\n";
        cout << "2. Excluir Aluno\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                limparTela();
                exclusaoInstrutor(ind_instrutor, instrutores, num_instrutores, cidades, ind_cidade, num_cidades, turmas, num_turmas);
                break;
            case 2:
                limparTela();
                exclusaoAluno(ind_aluno, alunos, num_alunos, cidades, ind_cidade, num_cidades, matriculas, num_matriculas);
                break;
            case 0:
                cout << "Voltando ao menu principal.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}