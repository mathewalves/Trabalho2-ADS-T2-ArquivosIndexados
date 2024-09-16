#include "../include/instrutor.h"
#include "../include/cidade.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

bool codigoInstrutorExiste(Indice ind_instrutor[], int num_instrutores, int codigo) {
    int inicio = 0, fim = num_instrutores - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (ind_instrutor[meio].chave == codigo) {
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
    for (int i = 0; i < num_instrutores; i++) {
        ind_instrutor[i].chave = instrutores[i].codigo_instrutor;
        ind_instrutor[i].endereco = i;
    }
    
    // ordenar o índice por código do instrutor (chave)
    for (int i = 0; i < num_instrutores - 1; i++) {
        for (int j = 0; j < num_instrutores - i - 1; j++) {
            if (ind_instrutor[j].chave > ind_instrutor[j + 1].chave) {
                Indice temp = ind_instrutor[j];
                ind_instrutor[j] = ind_instrutor[j + 1];
                ind_instrutor[j + 1] = temp;
            }
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
            
            if (codigoInstrutorExiste(ind_instrutor, num_instrutores, codigo_instrutor)) {
                cout << "Erro: Código de instrutor já existe. Por favor, escolha outro código.\n";
            }
        } while (codigoInstrutorExiste(ind_instrutor, num_instrutores, codigo_instrutor));

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
        
        num_instrutores++;
        gerarIndicesInstrutores(instrutores, ind_instrutor, num_instrutores);
    }
}

void mostrarTodosInstrutores(Instrutor instrutores[], int num_instrutores, Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    cout << "\nDados de todos os Instrutores:\n";
    for (int i = 0; i < num_instrutores; i++) {
        Cidade cidade_encontrada;
        buscaBinariaCidade(ind_cidade, cidades, num_cidades, instrutores[i].codigo_cidade, cidade_encontrada, false);
        
        cout << "Código: [ " << instrutores[i].codigo_instrutor << " ], Nome: " << instrutores[i].nome 
             << ", Endereço: " << instrutores[i].endereco 
             << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;
    }
}

void buscaBinariaInstrutor(Indice ind_instrutor[], Instrutor instrutores[], int num_instrutores, int codigoBusca, Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    int inicio = 0, fim = num_instrutores - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (codigoBusca == ind_instrutor[meio].chave) {
            int posicaoRegistro = ind_instrutor[meio].endereco;
            if (instrutores[posicaoRegistro].status == 1) {
                
                Cidade cidade_encontrada;
                buscaBinariaCidade(ind_cidade, cidades, num_cidades, instrutores[posicaoRegistro].codigo_cidade, cidade_encontrada, false);

                if (cidade_encontrada.status == 1) {
                    cout << "Instrutor encontrado:\n";
                    cout << "Código: " << instrutores[posicaoRegistro].codigo_instrutor 
                        << ", Nome: " << instrutores[posicaoRegistro].nome
                        << ", Endereço: " << instrutores[posicaoRegistro].endereco
                        << ", Cidade: " << cidade_encontrada.nome << " (" << cidade_encontrada.UF << ")" << endl;
                } else {
                    cout << "Instrutor encontrado, mas a cidade associada está inválida ou excluída.\n";
                }

            } else {
                cout << "Instrutor excluído ou inválido.\n";
            }
            return;
        } else if (codigoBusca > ind_instrutor[meio].chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    cout << "Instrutor não encontrado.\n";
}