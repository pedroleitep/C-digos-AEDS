#include <iostream>
#include <string>
using namespace std;

const int _MAX = 100; // Número máximo de candidatos

class Candidato {
private:
    string nome;
    double nota;

public:
    Candidato(string _nome, double _nota) : nome(_nome), nota(_nota) {}

    string getNome() const {
        return nome;
    }

    double getNota() const {
        return nota;
    }
};

Candidato* candidatos[_MAX]; // Vetor de ponteiros para objetos Candidato

int lerCandidatos() {
    int numCandidatos;
    cin >> numCandidatos;

    if (numCandidatos > _MAX) {
        return 0;
    }

    for (int i = 0; i < numCandidatos; ++i) {
        string nome;
        double nota;
        cin >> nome >> nota;

        candidatos[i] = new Candidato(nome, nota);
    }

    return numCandidatos;
}

double calcularMedia(int numCandidatos) {
    double soma = 0.0;

    for (int i = 0; i < numCandidatos; ++i) {
        soma += candidatos[i]->getNota();
    }

    return soma / numCandidatos;
}

void listarAcimaDaMedia(int numCandidatos, double media) {
    for (int i = 0; i < numCandidatos; ++i) {
        if (candidatos[i]->getNota() > media) {
            cout << candidatos[i]->getNome() << " " << candidatos[i]->getNota() << endl;
        }
    }
}

int main() {
    int numCandidatos = lerCandidatos();

    if (numCandidatos > 0) {
        double media = calcularMedia(numCandidatos);
        listarAcimaDaMedia(numCandidatos, media);
    }

    // Liberar a memória alocada para os objetos Candidato
    for (int i = 0; i < numCandidatos; ++i) {
        delete candidatos[i];
    }

    return 0;
}
