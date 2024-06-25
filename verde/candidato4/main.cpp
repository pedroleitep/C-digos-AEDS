#include <iostream>
#include <string>
#include <iomanip> // Para setprecision
using namespace std;

const int _MAX = 100; // N�mero m�ximo de candidatos

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

    // Verifica��o de limites
    if (numCandidatos > _MAX) {
        cerr << "N�mero de candidatos excede o limite m�ximo permitido (" << _MAX << ")." << endl;
        return -1;
    }
    if (numCandidatos <= 0) {
        cerr << "N�mero de candidatos deve ser maior que zero." << endl;
        return -1;
    }

    for (int i = 0; i < numCandidatos; ++i) {
        string nome;
        double nota;

        cin >> nome >> nota;

        // Verifica se a entrada de nota � v�lida
        if(cin.fail() || nota < 0) {
            cerr << "Entrada inv�lida para a nota do candidato." << endl;
            // Liberar a mem�ria alocada anteriormente
            for (int j = 0; j < i; ++j) {
                delete candidatos[j];
            }
            return -1;
        }

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
            cout << candidatos[i]->getNome() << " " << fixed << setprecision(2) << candidatos[i]->getNota() << endl;
        }
    }
}

int main() {
    int numCandidatos = lerCandidatos();

    if (numCandidatos > 0) {
        double media = calcularMedia(numCandidatos);
        listarAcimaDaMedia(numCandidatos, media);
    }

    // Liberar a mem�ria alocada para os objetos Candidato
    for (int i = 0; i < numCandidatos; ++i) {
        delete candidatos[i];
    }

    return 0;
}
