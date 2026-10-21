Desafio Squad PotterHeads — Sistema de Atendimento
Sistema em C++17 que implementa manualmente uma fila FIFO de pacientes, uma pilha LIFO de atendimentos e uma lista encadeada de médicos.

Compilação
g++ -std=c++17 -Wall -Wextra -pedantic -o atendimento atendimento.cpp

Execução
Windows (PowerShell): ./atendimento.exe

Funcionalidades
R1: enqueue, dequeue, frente_peek, tamanho.
R2: push, pop, peek.
R3: adicionarMedico, chamarMedico, percorrer.
R4: imprimirHistorico mostra do mais recente ao mais antigo, usando uma pilha auxiliar e restaurando o histórico.
A fila atende por ordem de chegada (FIFO). A urgência é armazenada, mas não define prioridade.

Como compilar:
1-Abra uma pasta no terminal clicando com o botão direito na pasta e indo na opção abrir no terminal
2-Copie o código do repositório no Github
3-Digite no terminal (git clone https://github.com/engs-alexsandrosouza-dev/squad-atendimento-Potterheads-.git)
4-Após clonar o repositório é só digitar no terminal(code .)

Exemplo de saída:
<img width="976" height="486" alt="image" src="https://github.com/user-attachments/assets/2c3143be-5892-4f30-9edc-da492c36e1f9" />


Exemplo de saída
=== Sistema de Atendimento - Squad ===

Medicos disponiveis: Dra. Ana Lima -> Dr. Bruno Costa -> Dra. Carla Ramos

Pacientes chegando:
Proximo a ser atendido: Eduardo (urgencia=3)
Total na fila: 4

Simulacao de atendimentos:
  [1] Dra. Ana Lima atende Eduardo (urgencia=3)
  [2] Dr. Bruno Costa atende Fernanda (urgencia=1)
  [3] Dra. Carla Ramos atende Gabriel (urgencia=2)
  [4] Dra. Ana Lima atende Helena (urgencia=1)

Ultimo atendimento registrado (peek): Dra. Ana Lima -> Helena (urgencia=1)

=== Relatorio de Atendimentos ===
Dra. Ana Lima -> Helena (urgencia=1)
Dra. Carla Ramos -> Gabriel (urgencia=2)
Dr. Bruno Costa -> Fernanda (urgencia=1)
Dra. Ana Lima -> Eduardo (urgencia=3)
Historico preservado (peek): Dra. Ana Lima -> Helena (urgencia=1)
