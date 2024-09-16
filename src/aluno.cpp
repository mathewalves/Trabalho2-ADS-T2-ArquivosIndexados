#include "../include/aluno.h"
#include "../include/cidade.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

void lerDadosAluno(Aluno alunos[], int& num_alunos) {
    int i = num_alunos;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\n\nCódigo do Aluno " << (i+1) << " (0 para sair): ";
        cin >> alunos[i].codigo_aluno;

        if (alunos[i].codigo_aluno > 0) {
            cout << "Nome: ";
            cin.ignore();
            cin.getline(alunos[i].nome, 50);
            cout << "Endereço: ";
            cin.getline(alunos[i].endereco, 100);
            cout << "Código da Cidade: ";
            cin >> alunos[i].codigo_cidade;
            alunos[i].status = 1; // Cidade ativa
            num_alunos++;
        }
        else saida = 0;
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

