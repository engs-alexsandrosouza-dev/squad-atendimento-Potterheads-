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
