# Trabalho 2 ADS - T2 - Gerenciamento de Empresa de Treinamentos

**Data de entrega: 03/10/2024**

## Descrição

Este programa simula arquivos indexados para uma aplicação de gerenciamento de uma empresa de Treinamentos. Ele inclui as seguintes estruturas:

- Cidades: código_cidade, nome, UF
- Cursos: código_curso, descrição, valor_por_aula
- Instrutores: código_instrutor, nome, endereço, codigo_cidade
- Alunos: código_aluno, nome, endereço, codigo_cidade
- Turmas: código_turma, código_curso, código_instrutor, total_participantes, quant_max_participantes
  - Índices: código_turma e código_curso
- Matrículas: código_matrícula, código_aluno, código_turma, quantidade_aulas, valor_total
  - Índices: código_matrícula e código_aluno

## Tarefas

- [x] 1. Funções para leitura dos dados das estruturas: Cidades e Cursos.
- [ ] 2. Função para inclusão de novos registros na tabela de Instrutores.
  - [ ] 2.1. Garantir que o código do instrutor não existe.
  - [ ] 2.2. Buscar e exibir nome da cidade e UF ao digitar o código da cidade.
- [ ] 3. Função para inclusão de novos registros na tabela de Alunos.
  - [ ] 3.1. Garantir que o código do aluno não existe.
  - [ ] 3.2. Buscar e exibir nome da cidade e UF ao digitar o código da cidade.
- [ ] 4. Função para exclusão de registros na tabela de Instrutores.
  - [ ] 4.1. Não permitir exclusão de instrutores com turmas cadastradas.
- [ ] 5. Função para exclusão de registros na tabela de Alunos.
  - [ ] 5.1. Não permitir exclusão de alunos com matrículas cadastradas.
- [ ] 6. Função para inclusão de novos registros na tabela de Turmas.
  - [ ] 6.1. Buscar e exibir descrição e valor por aula do curso.
  - [ ] 6.2. Buscar e exibir nome do instrutor e sua cidade.
  - [ ] 6.3. Atualizar áreas de índices automaticamente.
- [ ] 7. Função para inclusão de novos registros na tabela de Matrículas.
  - [ ] 7.1. Buscar e exibir nome do aluno e sua cidade.
  - [ ] 7.2. Buscar e exibir descrição do curso, nome do instrutor e valor por aula.
  - [ ] 7.3. Calcular e mostrar valor total a ser pago.
  - [ ] 7.4. Atualizar total_participantes.
  - [ ] 7.5. Calcular, exibir e gravar valor total a ser pago.
  - [ ] 7.6. Atualizar áreas de índices automaticamente.
- [ ] 8. Função para consultar dados de determinada turma.
- [ ] 9. Função para exibir Turmas completas.
- [ ] 10. Função para exibir todos os registros da tabela Matrículas.
- [ ] 11. Função para reorganização da tabela de Alunos.

## Observações

- Todas as funções devem ser chamadas através de um menu de opções na função main().
- Não utilizar variáveis globais.