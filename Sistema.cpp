#include <iostream>
#include <string>
using namespace std;

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
string frente_peek() const {
    if (frente == nullptr) {
        return "Fila vazia";
    }

    return frente->nome;
}
int tamanho() const {
    int total = 0;
    No* atual = frente;

    while (atual != nullptr) {
        total++;
        atual = atual->prox;
    }

    return total;
}

string peek()const {
    if(topo == nullptr){
        return "Historico vazio";
    }
    return topo -> nome;
}
