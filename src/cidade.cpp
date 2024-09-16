#include "../include/cidade.h"
#include "../include/utils.h"
#include <iostream>
#include <cstring>
using namespace std;

void gerarIndicesCidades(Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    for (int i = 0; i < num_cidades; i++) {
        ind_cidade[i].chave = cidades[i].codigo_cidade;
        ind_cidade[i].endereco = i;
    }
    
    // ordenar o índice por código da cidade (chave)
    for (int i = 0; i < num_cidades - 1; i++) {
        for (int j = 0; j < num_cidades - i - 1; j++) {
            if (ind_cidade[j].chave > ind_cidade[j + 1].chave) {
                Indice temp = ind_cidade[j];
                ind_cidade[j] = ind_cidade[j + 1];
                ind_cidade[j + 1] = temp;
            }
        }
    }
}

void lerDadosCidades(Cidade cidades[], Indice ind_cidade[], int& num_cidades) {
    int i = num_cidades;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo da Cidade " << (i+1) << " (0 para sair): ";
        cin >> cidades[i].codigo_cidade;
        if (cidades[i].codigo_cidade > 0) {
            cout << "Nome: ";
            cin.ignore();
            cin.getline(cidades[i].nome, 50);
            cout << "UF: ";
            cin >> cidades[i].UF;
            cidades[i].status = 1; // Cidade ativa
            num_cidades++;
        }
        else saida = 0;
    }
    gerarIndicesCidades(cidades, ind_cidade, num_cidades);
}

void mostrarTodasCidades(Cidade cidades[], Indice ind_cidade[], int num_cidades) {
    cout << "\nDados de todas as Cidades:\n";
    for (int i = 0; i < num_cidades; i++) {
        int pos = ind_cidade[i].endereco;
        if (cidades[pos].status == 1) {
            cout << "Código: " << cidades[pos].codigo_cidade 
                 << ", Nome: " << cidades[pos].nome 
                 << ", UF: " << cidades[pos].UF << endl;
        }
    }
}

bool buscaBinariaCidade(Indice ind_cidade[], Cidade cidades[], int num_cidades, int codigoBusca, Cidade& cidade_encontrada, bool exibir) {
    int inicio = 0, fim = num_cidades - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (codigoBusca == ind_cidade[meio].chave) {
            int posicaoRegistro = ind_cidade[meio].endereco;
            if (cidades[posicaoRegistro].status == 1) {
                cidade_encontrada = cidades[posicaoRegistro];
                if (exibir) {
                    cout << "Cidade encontrada:\n";
                    cout << "Código: " << cidade_encontrada.codigo_cidade 
                         << ", Nome: " << cidade_encontrada.nome 
                         << ", UF: " << cidade_encontrada.UF << endl;
                }
                return true;
            } else {
                cidade_encontrada.codigo_cidade = -1;
                strcpy(cidade_encontrada.nome, "Cidade excluída ou inválida");
                strcpy(cidade_encontrada.UF, "--");
                if (exibir) {
                    cout << "Cidade excluída ou inválida.\n";
                }
                return false;
            }
        } else if (codigoBusca > ind_cidade[meio].chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    cidade_encontrada.codigo_cidade = -1;
    strcpy(cidade_encontrada.nome, "Cidade não encontrada");
    strcpy(cidade_encontrada.UF, "--");
    if (exibir) {
        cout << "Cidade não encontrada.\n";
    }
    return false;
}