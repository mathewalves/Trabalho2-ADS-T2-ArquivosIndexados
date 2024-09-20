#include "../include/aluno.h"
#include "../include/cidade.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

bool codigoAlunoExiste(Indice ind_aluno[], int num_alunos, int codigo) {
    int inicio = 0, fim = num_alunos - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_aluno[meio].chave == codigo) {
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
    for (int i = 0; i < num_alunos; i++) {
        ind_aluno[i].chave = alunos[i].codigo_aluno;
        ind_aluno[i].endereco = i;
    }
    
    // ordenar o índice por código do aluno (chave)
    for (int i = 0; i < num_alunos - 1; i++) {
        for (int j = 0; j < num_alunos - i - 1; j++) {
            if (ind_aluno[j].chave > ind_aluno[j + 1].chave) {
                Indice temp = ind_aluno[j];
                ind_aluno[j] = ind_aluno[j + 1];
                ind_aluno[j + 1] = temp;
            }
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

            if (codigoAlunoExiste(ind_aluno, num_alunos, codigo_aluno)) {
                cout << "Erro: Código de aluno já existe. Por favor, escolha outro código.\n";
            }

        } while (codigoAlunoExiste(ind_aluno, num_alunos, codigo_aluno));

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
        
        cout << "Código: " << alunos[i].codigo_aluno << ", Nome: " << alunos[i].nome 
             << ", Endereço: " << alunos[i].endereco 
             << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;
    }
}

void buscaBinariaAluno(Indice ind_aluno[], Aluno alunos[], int num_alunos, int codigoBusca, Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    int inicio = 0, fim = num_alunos - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (codigoBusca == ind_aluno[meio].chave) {
            int posicaoRegistro = ind_aluno[meio].endereco;
            if (alunos[posicaoRegistro].status == 1) {
                
                Cidade cidade_encontrada;
                buscaBinariaCidade(ind_cidade, cidades, num_cidades, alunos[posicaoRegistro].codigo_cidade, cidade_encontrada, false);

                if (cidade_encontrada.status == 1) {
                    cout << "Aluno encontrado:\n";
                    cout << "Código: " << alunos[posicaoRegistro].codigo_aluno 
                        << ", Nome: " << alunos[posicaoRegistro].nome
                        << ", Endereço: " << alunos[posicaoRegistro].endereco
                        << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;
                } else {
                    cout << "Aluno encontrado, mas a cidade associada está inválida ou excluída.\n";
                }

            } else {
                cout << "Aluno excluído ou inválido.\n";
            }
            return;
        } else if (codigoBusca > ind_aluno[meio].chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    cout << "Aluno não encontrado.\n";
}

