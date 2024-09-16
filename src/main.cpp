#include <iostream>
#include <string>
#include <cstring>
#include <locale>
#include "../include/structs.h"
#include "../include/cidade.h"
#include "../include/curso.h"
#include "../include/instrutor.h"
#include "../include/aluno.h"
#include "../include/menu.h"
#include "../include/utils.h"

using namespace std;

int main() {    
    configurarLocale();
    Indice ind_cidade[20], ind_curso[20], ind_instrutor[20], ind_aluno[20];
    
    Cidade cidades[20]; Curso cursos[20]; Instrutor instrutores[20]; Aluno alunos[20];

    int num_cidades = 0, num_cursos = 0, num_instrutores = 0, num_alunos = 0;

    int opcao;
    do {
        limparTela();
        cout << "\nMenu Principal:\n";
        cout << "1. Incluir Dados\n";
        cout << "2. Mostrar Dados\n";
        cout << "3. Excluir Dados\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                menuInclusao(cidades, ind_cidade, num_cidades, cursos, ind_curso, num_cursos, instrutores, ind_instrutor, num_instrutores, alunos, ind_aluno, num_alunos);
                break;
            case 2:
                limparTela();
                mostrarDados(cidades, ind_cidade, num_cidades, cursos, ind_curso, num_cursos, instrutores, ind_instrutor, num_instrutores, alunos, ind_aluno, num_alunos);
                break;
            case 0:
                limparTela();
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}