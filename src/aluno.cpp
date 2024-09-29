#include "../include/aluno.h"
#include "../include/cidade.h"
#include "../include/utils.h"
#include <iostream>
#include "../include/turma.h"
using namespace std;

bool codigoAlunoExiste(Indice ind_aluno[], Aluno alunos[], int num_alunos, int codigo) {
    int inicio = 0, fim = num_alunos - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_aluno[meio].chave == codigo  && alunos[meio].status == 1) {
            return true;
        } else if (ind_aluno[meio].chave < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false;
}

void gerarIndicesAlunos(Aluno alunos[], Indice ind_aluno[], int num_alunos) {
    int j = 0; // índices válidos
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].status == 1) { // alunos ativos
            ind_aluno[j].chave = alunos[i].codigo_aluno;
            ind_aluno[j].endereco = i;
            j++;
        }
    }
}

void lerDadosAluno(Aluno alunos[], Indice ind_aluno[], int& num_alunos) {
    int i = num_alunos;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        int codigo_aluno;

        do {
            cout << "\n\nCódigo do Aluno " << (i+1) << " (0 para sair): ";
            cin >> codigo_aluno;

            if (codigo_aluno == 0) {
                saida = 0;
                break;
            }

            if (codigoAlunoExiste(ind_aluno, alunos, num_alunos, codigo_aluno)) {
                cout << "Erro: Código de aluno já existe. Por favor, escolha outro código.\n";
            }

        } while (codigoAlunoExiste(ind_aluno, alunos, num_alunos, codigo_aluno));

        if (saida == 0) break;

        alunos[i].codigo_aluno = codigo_aluno;
        cout << "Nome: ";
        cin.ignore();
        cin.getline(alunos[i].nome, 50);
        cout << "Endereço: ";
        cin.getline(alunos[i].endereco, 100);
        cout << "Código da Cidade: ";
        cin >> alunos[i].codigo_cidade;
        alunos[i].status = 1; // Aluno ativo


        num_alunos++;
        gerarIndicesAlunos(alunos, ind_aluno, num_alunos);
    }
}

void mostrarTodosAlunos(Aluno alunos[], int num_alunos, Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    cout << "\nDados de todos os Alunos:\n";
    for (int i = 0; i < num_alunos; i++) {
        Cidade cidade_encontrada;
        buscaBinariaCidade(ind_cidade, cidades, num_cidades, alunos[i].codigo_cidade, cidade_encontrada, false);
        
        if (alunos[i].status == 1){
            cout << "Código: " << alunos[i].codigo_aluno << ", Nome: " << alunos[i].nome 
                << ", Endereço: " << alunos[i].endereco 
                << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;
        }
    }
}

bool buscaBinariaAluno(Indice ind_aluno[], Aluno alunos[], int num_alunos, int codigoBusca, Aluno& aluno_encontrado) {
    int inicio = 0, fim = num_alunos - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_aluno[meio].chave == codigoBusca) {
            aluno_encontrado = alunos[ind_aluno[meio].endereco];
            return true;
        } else if (ind_aluno[meio].chave < codigoBusca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false;
}

bool alunoTemMatricula(int codigo_aluno, Matricula matriculas[], int num_matriculas) {
    for (int i = 0; i < num_matriculas; i++) {
        if (matriculas[i].codigo_aluno == codigo_aluno && matriculas[i].status == 1) {
            return true;
        }
    }
    return false;
}

void exclusaoAluno(Indice ind_aluno[], Aluno alunos[], int& num_alunos, Cidade cidades[], Indice ind_cidade[], int num_cidades, Matricula matriculas[], int num_matriculas) {
    int codigoExclusao;
    cout << "Digite o código para exclusão: ";
    cin >> codigoExclusao;

    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].codigo_aluno == codigoExclusao && alunos[i].status == 1) {
            if (alunoTemMatricula(codigoExclusao, matriculas, num_matriculas)) {
                cout << "Não é possível excluir este aluno pois ele possui matrículas cadastradas.\n";
                aguardarEnter();
                return;
            }

            Cidade cidade_encontrada;
            buscaBinariaCidade(ind_cidade, cidades, num_cidades, alunos[i].codigo_cidade, cidade_encontrada, false);
            int opcao;

            cout << "Código: [ " << alunos[i].codigo_aluno << " ], Nome: " << alunos[i].nome 
                 << ", Endereço: " << alunos[i].endereco 
                 << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;

            cout << "Tem certeza que deseja excluir? (Digite '1' para confirmar)" << endl << "Opção: ";
            cin >> opcao;

            if(opcao == 1){
                limparTela();
                alunos[i].status = 0;
                cout << "Exclusão realizada com sucesso!";
                reorganizacao(ind_aluno, alunos, num_alunos); 
            }

            return;
        }
    }

    cout << "Aluno não encontrado.\n";
}

void reorganizacao(Indice ind_aluno[], Aluno alunos[], int& num_alunos) {
    Aluno novosAlunos[20];
    int j = 0;

    for (int k = 0; k < num_alunos; k++) {
        if (alunos[k].status == 1) { // Apenas alunos ativos
            novosAlunos[j] = alunos[k];
            ind_aluno[j].chave = novosAlunos[j].codigo_aluno;
            ind_aluno[j].endereco = j; 
            j++;
        }
    }

    num_alunos = j; 
    for (int k = 0; k < num_alunos; k++) {
        alunos[k] = novosAlunos[k]; // atualiza o vetor de alunos
    }
}