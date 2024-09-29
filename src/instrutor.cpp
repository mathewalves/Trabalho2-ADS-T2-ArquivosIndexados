#include "../include/instrutor.h"
#include "../include/cidade.h"
#include "../include/utils.h"
#include "../include/turma.h"
#include <iostream>
using namespace std;

bool codigoInstrutorExiste(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigo) {
    int inicio = 0, fim = num_instrutores - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_instrutor[meio].chave == codigo && instrutores[meio].status == 1) {
            return true;
        } else if (ind_instrutor[meio].chave < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false;
}

void gerarIndicesInstrutores(Instrutor instrutores[], Indice ind_instrutor[], int num_instrutores) {
    int j = 0; // contador para índices válidos
    for (int i = 0; i < num_instrutores; i++) {
        if (instrutores[i].status == 1) { 
            ind_instrutor[j].chave = instrutores[i].codigo_instrutor;
            ind_instrutor[j].endereco = i;
            j++;
        }
    }
}

void lerDadosInstrutor(Instrutor instrutores[], Indice ind_instrutor[], int& num_instrutores) {
    int i = num_instrutores;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        int codigo_instrutor;
        do {
            cout << "\n\nCódigo do Instrutor " << (i+1) << " (0 para sair): ";
            cin >> codigo_instrutor;
            
            if (codigo_instrutor == 0) {
                saida = 0;
                break;
            }
            
            if (codigoInstrutorExiste(ind_instrutor, instrutores, num_instrutores, codigo_instrutor)) {
                cout << "Erro: Código de instrutor já existe. Por favor, escolha outro código.\n";
            }
        } while (codigoInstrutorExiste(ind_instrutor, instrutores, num_instrutores, codigo_instrutor));

        if (saida == 0) break;

        instrutores[i].codigo_instrutor = codigo_instrutor;
        cout << "Nome: ";
        cin.ignore();
        cin.getline(instrutores[i].nome, 50);
        cout << "Endereço: ";
        cin.getline(instrutores[i].endereco, 100);
        cout << "Código da Cidade: ";
        cin >> instrutores[i].codigo_cidade;
        instrutores[i].status = 1; // instrutor ativo
        
        num_instrutores++; // incrementa o número de instrutores
        gerarIndicesInstrutores(instrutores, ind_instrutor, num_instrutores);
    }
}

void mostrarTodosInstrutores(Instrutor instrutores[], int num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    cout << "\nDados de todos os Instrutores:\n";
    for (int i = 0; i < num_instrutores; i++) {
        if (instrutores[i].status == 1) { // verifica se o instrutor está ativo
            Cidade cidade_encontrada;
            buscaBinariaCidade(ind_cidade, cidades, num_cidades, instrutores[i].codigo_cidade, cidade_encontrada, false);
            
            cout << "Código: [ " << instrutores[i].codigo_instrutor << " ], Nome: " << instrutores[i].nome 
                 << ", Endereço: " << instrutores[i].endereco 
                 << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;
        }
    }
}

bool buscaBinariaInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigoBusca, Instrutor& instrutor_encontrado) {
    int inicio = 0, fim = num_instrutores - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_instrutor[meio].chave == codigoBusca) {
            instrutor_encontrado = instrutores[ind_instrutor[meio].endereco];
            return true;
        } else if (ind_instrutor[meio].chave < codigoBusca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false;
}

bool instrutorTemTurma(int codigo_instrutor, Turma turmas[], int num_turmas) {
    for (int i = 0; i < num_turmas; i++) {
        if (turmas[i].codigo_instrutor == codigo_instrutor && turmas[i].status == 1) {
            return true;
        }
    }
    return false;
}

// modifique a função exclusaoInstrutor
void exclusaoInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int& num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades, Turma turmas[], int num_turmas) {
    int codigoExclusao;
    cout << "Digite o código para exclusão: ";
    cin >> codigoExclusao;

    for (int i = 0; i < num_instrutores; i++) {
        if (instrutores[i].codigo_instrutor == codigoExclusao && instrutores[i].status == 1) {
            if (instrutorTemTurma(codigoExclusao, turmas, num_turmas)) {
                cout << "Não é possível excluir este instrutor pois ele possui turmas cadastradas.\n";
                aguardarEnter();
                return;
            }

            Cidade cidade_encontrada;
            buscaBinariaCidade(ind_cidade, cidades, num_cidades, instrutores[i].codigo_cidade, cidade_encontrada, false);
            int opcao;

            cout << "Código: [ " << instrutores[i].codigo_instrutor << " ], Nome: " << instrutores[i].nome 
                 << ", Endereço: " << instrutores[i].endereco 
                 << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;

            cout << "Tem certeza que deseja excluir? (Digite '1' para confirmar)" << endl << "Opção: ";
            cin >> opcao;

            if(opcao == 1){
                limparTela();
                instrutores[i].status = 0; // Apenas altera o status
                cout << "Exclusão realizada com sucesso!";
                reorganizacao(ind_instrutor, instrutores, num_instrutores); // Atualiza os índices
            }

            return;
        }
    }

    cout << "Instrutor não encontrado.\n";
}

void reorganizacao(Indice ind_instrutor[], Instrutor instrutores[], int& num_instrutores) {
    Instrutor novosInstrutores[20];
    int j = 0;

    for (int k = 0; k < num_instrutores; k++) {
        if (instrutores[k].status == 1) {
            novosInstrutores[j] = instrutores[k];
            ind_instrutor[j].chave = novosInstrutores[j].codigo_instrutor;
            ind_instrutor[j].endereco = j; // atualiza o índice
            j++;
        }
    }

    num_instrutores = j; // atualiza o número de instrutores ativos
    for (int k = 0; k < num_instrutores; k++) {
        instrutores[k] = novosInstrutores[k]; 
    }
}