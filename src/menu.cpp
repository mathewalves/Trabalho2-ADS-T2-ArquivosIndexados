#include "../include/menu.h"
#include "../include/cidade.h"
#include "../include/curso.h"
#include "../include/instrutor.h"
#include "../include/aluno.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

void mostrarDados(Cidade cidades[], Indice ind_cidade[], int num_cidades, 
                  Curso cursos[], Indice ind_curso[], int num_cursos, 
                  Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores, 
                  Aluno alunos[], Indice ind_aluno[], int num_alunos) {
    int opcao, subOpcao, codigoBusca;
    cout << "\nEscolha o tipo de dado para mostrar:\n";
    cout << "1. Cidades\n";
    cout << "2. Cursos\n";
    cout << "3. Instrutores\n";
    cout << "4. Alunos\n";
    cout << "Opção: ";
    cin >> opcao;

    limparTela();
    cout << "\nEscolha a ação:\n";
    cout << "1. Mostrar todos os dados\n";
    cout << "2. Pesquisar por um dado\n";
    cout << "Opção: ";
    cin >> subOpcao;

    switch (opcao) {
        case 1:
            if (subOpcao == 1) {
                limparTela();
                mostrarTodasCidades(cidades, ind_cidade, num_cidades);
                aguardarEnter();
            } else if (subOpcao == 2){
                limparTela();
                cout << "Digite o código da Cidade:\n";
                cout << "Opção: ";
                cin >> codigoBusca;
                limparTela();
                Cidade cidade_encontrada;
                buscaBinariaCidade(ind_cidade, cidades, num_cidades, codigoBusca, cidade_encontrada, true);
                aguardarEnter();
            }
            break;
        case 2:
            if (subOpcao == 1) {
                limparTela();
                mostrarTodosCursos(cursos, ind_curso, num_cursos);
                aguardarEnter();
            } else if (subOpcao == 2){
                limparTela();
                cout << "Digite o código do Curso:\n";
                cout << "Opção: ";
                cin >> codigoBusca;
                limparTela();
                buscaBinariaCurso(ind_curso, cursos, num_cursos, codigoBusca);
                aguardarEnter();
            }
            break;
        case 3:
            if (subOpcao == 1) {
                limparTela();
                mostrarTodosInstrutores(instrutores, num_instrutores, cidades, ind_cidade, num_cidades);
                aguardarEnter();
            } else if (subOpcao == 2){
                limparTela();
                cout << "Digite o código do Instrutor:\n";
                cout << "Opção: ";
                cin >> codigoBusca;
                limparTela();
                buscaBinariaInstrutor(ind_instrutor, instrutores, num_instrutores, codigoBusca, cidades, ind_cidade, num_cidades);
                aguardarEnter();
            }
            break;
        case 4:
            if (subOpcao == 1) {
                limparTela();
                mostrarTodosAlunos(alunos, num_alunos, cidades, ind_cidade, num_cidades);
                aguardarEnter();
            } else if (subOpcao == 2){
                limparTela();
                cout << "Digite o código do Aluno:\n";
                cout << "Opção: ";
                cin >> codigoBusca;
                limparTela();
                // buscaBinariaAluno(ind_curso, cursos, num_cursos, codigoBusca);
                aguardarEnter();
            }
            break;
        default:
            cout << "Opção inválida.\n";
    }
}

void menuInclusao(Cidade cidades[], Indice ind_cidade[], int& num_cidades, 
                  Curso cursos[], Indice ind_curso[], int& num_cursos, 
                  Instrutor instrutores[], Indice ind_instrutor[], int& num_instrutores, 
                  Aluno alunos[], Indice ind_aluno[], int& num_alunos) {
    int opcao;
    do {
        limparTela();
        cout << "\nMenu de Inclusão:\n";
        cout << "1. Incluir Cidade\n";
        cout << "2. Incluir Curso\n";
        cout << "3. Incluir Instrutor\n";
        cout << "4. Incluir Aluno\n";
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
                lerDadosAluno(alunos, num_alunos);
                break;
            case 0:
                cout << "Voltando ao menu principal.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}