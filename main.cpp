#include <iostream>
#include <string>
#include <cstring>
#include "utils.h"

using namespace std;

struct Cidade {
    int codigo_cidade;
    char nome[50];
    char UF[2];
};

struct Curso {
    int codigo_curso;
    char descricao[100];
    float valor_por_aula;
};

struct Instrutor {
    int codigo_instrutor;
    char nome[50];
    char endereco[100];
    int codigo_cidade;
};

struct Aluno {
    int codigo_aluno;
    char nome[50];
    char endereco[100];
    int codigo_cidade;
};

struct Turma {
    int codigo_turma;
    int codigo_curso;
    int codigo_instrutor;
    int total_participantes;
    int quant_max_participantes;
};

struct Matricula {
    int codigo_matricula;
    int codigo_aluno;
    int codigo_turma;
    int quantidade_aulas;
    float valor_total;
};

struct Indice {
    int chave;
    int endereco;
};

void lerDadosCidades(Cidade cidades[], int& num_cidades) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo da Cidade " << (i+1) << " (0 para sair): ";
        cin >> cidades[i].codigo_cidade;
        if (cidades[i].codigo_cidade > 0) {
            cout << "Nome: ";
            cin.ignore();
            cin.getline(cidades[i].nome, 50);
            cout << "UF: ";
            cin >> cidades[i].UF;
        }
        else saida = 0;
    }
    num_cidades = i-1;
}

void lerDadosCursos(Curso cursos[], int& num_cursos) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo do Curso " << (i+1) << " (0 para sair): ";
        cin >> cursos[i].codigo_curso;
        if (cursos[i].codigo_curso > 0) {
            cout << "Descrição: ";
            cin.ignore();
            cin.getline(cursos[i].descricao, 100);
            cout << "Valor por aula: ";
            cin >> cursos[i].valor_por_aula;
        }
        else saida = 0;
    }
    num_cursos = i-1;
}

void mostrarTodasCidades(Cidade cidades[], int num_cidades) {
    cout << "\nDados de todas as Cidades:\n";
    for (int i = 0; i < num_cidades; i++) {
        cout << "Código: " << cidades[i].codigo_cidade << ", Nome: " << cidades[i].nome << ", UF: " << cidades[i].UF << endl;
    }
}

void mostrarTodosCursos(Curso cursos[], int num_cursos) {
    cout << "\nDados de todos os Cursos:\n";
    for (int i = 0; i < num_cursos; i++) {
        cout << "Código: " << cursos[i].codigo_curso << ", Descrição: " << cursos[i].descricao 
             << ", Valor por aula: " << cursos[i].valor_por_aula << endl;
    }
}

void mostrarDados(Cidade cidades[], int num_cidades, Curso cursos[], int num_cursos) {
    int opcao;
    cout << "\nEscolha o tipo de dado para mostrar:\n";
    cout << "1. Cidades\n";
    cout << "2. Cursos\n";
    cout << "Opção: ";
    cin >> opcao;

    int subOpcao;
    cout << "\nEscolha a ação:\n";
    cout << "1. Mostrar todos os dados\n";
    cout << "Opção: ";
    cin >> subOpcao;

    switch (opcao) {
        case 1:
            if (subOpcao == 1) {
                limparTela();
                mostrarTodasCidades(cidades, num_cidades);
                aguardarEnter();
            }
            break;
        case 2:
            if (subOpcao == 1) {
                limparTela();
                mostrarTodosCursos(cursos, num_cursos);
                aguardarEnter();
            }
            break;
        default:
            cout << "Opção inválida.\n";
    }
}

int main() {    
    Cidade cidades[20];
    Curso cursos[20];

    int num_cidades = 0, num_cursos = 0;

    // // indices para turmas
    // Indice indice_turma_codigo[20];
    // Indice indice_turma_curso[20];

    // // indices para matrículas
    // Indice indice_matricula_codigo[20];
    // Indice indice_matricula_aluno[20];

    int opcao;
    do {
        limparTela();
        cout << "\nMenu de Opções:\n";
        cout << "1. Mostrar Dados\n";
        cout << "2. Ler dados de Cidades\n";
        cout << "3. Ler dados de Cursos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                limparTela();
                mostrarDados(cidades, num_cidades, cursos, num_cursos);
                break;
            case 2:
                limparTela();
                lerDadosCidades(cidades, num_cidades);
                break;
            case 3:
                limparTela();
                lerDadosCursos(cursos, num_cursos);
                break;
            case 0:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}