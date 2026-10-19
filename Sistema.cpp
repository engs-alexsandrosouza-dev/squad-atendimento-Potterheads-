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