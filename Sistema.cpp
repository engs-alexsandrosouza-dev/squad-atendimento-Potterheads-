
#include <iostream>
#include <string>
using namespace std;

// =============================================
// ESTRUTURA BASE - NO
// =============================================

struct No {
    string nome;
    int urgencia;
    No* prox;

    No(const string& n, int u = 0)
        : nome(n), urgencia(u), prox(nullptr) {}
};

// =============================================
// R1 - FILA DE PACIENTES (FIFO)
// =============================================

struct FilaPacientes {
    No* frente = nullptr;
    No* tras = nullptr;

    // TODO 1 - Inserir paciente
    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);

        if (frente == nullptr) {
            frente = novo;
            tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
    }

    // TODO 2 - Remover paciente
    string dequeue() {
        if (frente == nullptr) {
            return "Fila vazia";
        }

        No* removido = frente;
        string nome = removido->nome;

        frente = frente->prox;

        if (frente == nullptr) {
            tras = nullptr;
        }

        delete removido;
        return nome;
    }

    // TODO 3 - Consultar primeiro paciente
    string frente_peek() const {
        if (frente == nullptr) {
            return "Fila vazia";
        }

        return frente->nome;
    }

    bool isEmpty() const {
        return frente == nullptr;
    }

    // BONUS - Contar pacientes
    int tamanho() const {
        int total = 0;
        No* atual = frente;

        while (atual != nullptr) {
            total++;
            atual = atual->prox;
        }

        return total;
    }

    // Liberar memoria
    ~FilaPacientes() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// =============================================
// R2 - PILHA DE HISTORICO (LIFO)
// =============================================

struct PilhaHistorico {
    No* topo = nullptr;

    // TODO 4 - Empilhar atendimento
    void push(const string& nome) {
        No* novo = new No(nome);

        novo->prox = topo;
        topo = novo;
    }

    // TODO 5 - Desempilhar atendimento
    string pop() {
        if (topo == nullptr) {
            return "Historico vazio";
        }

        No* removido = topo;
        string nome = removido->nome;

        topo = topo->prox;

        delete removido;
        return nome;
    }

    // TODO 6 - Consultar topo
    string peek() const {
        if (topo == nullptr) {
            return "Historico vazio";
        }

        return topo->nome;
    }

    bool isEmpty() const {
        return topo == nullptr;
    }

    // Liberar memoria
    ~PilhaHistorico() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// =============================================
// R3 - LISTA DE MEDICOS DISPONIVEIS
// =============================================

struct ListaMedicos {
    No* head = nullptr;

    // TODO 7 - Adicionar medico ao final
    void adicionarMedico(const string& nome) {
        No* novo = new No(nome);

        if (head == nullptr) {
            head = novo;
            return;
        }

        No* atual = head;

        while (atual->prox != nullptr) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }

    // TODO 8 - Chamar primeiro medico
    string chamarMedico() {
        if (head == nullptr) {
            return "Nenhum medico disponivel";
        }

        No* removido = head;
        string nome = removido->nome;

        head = head->prox;

        delete removido;
        return nome;
    }

    // TODO 9 - Mostrar medicos disponiveis
    void percorrer(const string& prefixo = "") const {
        if (!prefixo.empty()) {
            cout << prefixo << ": ";
        }

        if (head == nullptr) {
            cout << "(lista vazia)\n";
            return;
        }

        No* atual = head;

        while (atual != nullptr) {
            cout << atual->nome;

            if (atual->prox != nullptr) {
                cout << " -> ";
            }

            atual = atual->prox;
        }

        cout << "\n";
    }

    bool temMedico() const {
        return head != nullptr;
    }

    // Liberar memoria
    ~ListaMedicos() {
        while (head != nullptr) {
            No* removido = head;
            head = head->prox;
            delete removido;
        }
    }
};

// =============================================
// R4 - RELATORIO DE ATENDIMENTOS
// =============================================

// TODO 10 - Imprimir historico sem destruir
void imprimirHistorico(PilhaHistorico& hist) {
    cout << "\n=== Relatorio de Atendimentos ===\n";

    if (hist.isEmpty()) {
        cout << "(nenhum atendimento registrado)\n";
        return;
    }

    PilhaHistorico auxiliar;

    // Transferir para pilha auxiliar
    while (!hist.isEmpty()) {
        auxiliar.push(hist.pop());
    }

    // Restaurar e imprimir os atendimentos
    while (!auxiliar.isEmpty()) {
        string atendimento = auxiliar.pop();

        hist.push(atendimento);
        cout << atendimento << "\n";
    }
}

// =============================================
// PROGRAMA PRINCIPAL
// =============================================

int main() {

    cout << "========================================\n";
    cout << " SISTEMA DE ATENDIMENTO - SQUAD POTTERHEAD\n";
    cout << "========================================\n\n";

    // Criar estruturas
    FilaPacientes fila;
    PilhaHistorico historico;
    ListaMedicos medicos;

    // =========================================
    // R3 - CADASTRAR MEDICOS
    // =========================================

    medicos.adicionarMedico("Dr. Jean Luís");
    medicos.adicionarMedico("Dra. Luana Rocha");
    medicos.adicionarMedico("Dr. Marlene do Nascimento Ramos");

    medicos.percorrer("Medicos disponiveis");

    // =========================================
    // R1 - CADASTRAR PACIENTES
    // =========================================

    cout << "\nPacientes chegando:\n";

    fila.enqueue("Eduardo (urgencia=3)", 3);
    fila.enqueue("Fernanda (urgencia=1)", 1);
    fila.enqueue("Gabriel (urgencia=2)", 2);
    fila.enqueue("Helena (urgencia=1)", 1);

    cout << "Proximo paciente: "
         << fila.frente_peek() << "\n";

    cout << "Total na fila: "
         << fila.tamanho() << "\n";

    // =========================================
    // SIMULACAO DE ATENDIMENTOS
    // =========================================

    cout << "\n=== Simulacao de Atendimentos ===\n";

    int atend = 1;

    while (!fila.isEmpty() && medicos.temMedico()) {

        // Retirar paciente da fila
        string paciente = fila.dequeue();

        // Chamar medico disponivel
        string medico = medicos.chamarMedico();

        cout << "[" << atend++ << "] "
             << medico << " atende "
             << paciente << "\n";

        // R2 - Registrar atendimento
        historico.push(medico + " -> " + paciente);

        // Medico retorna ao final da lista
        medicos.adicionarMedico(medico);
    }

    // =========================================
    // R2 - CONSULTAR ULTIMO ATENDIMENTO
    // =========================================

    cout << "\nUltimo atendimento registrado: "
         << historico.peek() << "\n";

    // =========================================
    // R4 - IMPRIMIR HISTORICO
    // =========================================

    imprimirHistorico(historico);

    // Mostrar que o historico foi preservado
    cout << "\nHistorico preservado: "
         << historico.peek() << "\n";

    // Mostrar medicos disponiveis
    cout << "\n";
    medicos.percorrer("Medicos disponiveis ao final");

    cout << "\nSistema finalizado com sucesso!\n";

    return 0;
}
