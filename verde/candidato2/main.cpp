#include <iostream>
#include <string>
#include <iomanip> // Para controlar a precisão do output

#define _MAX 100

using namespace std;

class Candidato {
private:
    string nome;
    double nota;

public:
    // Construtor
    Candidato(const string &nome, double nota) : nome(nome), nota(nota) {}

    // Métodos para definir atributos
    void setNome(const string &nome) {
        this->nome = nome;
    }

    void setNota(double nota) {
        this->nota = nota;
    }

    // Métodos para acessar atributos
    string getNome() const {
        return nome;
    }

    double getNota() const {
        return nota;
    }
};

void lerCandidatos(Candidato* candidatos[], int &numCandidatos) {
    cout << "Digite o número de candidatos (max " << _MAX << "): ";
    cin >> numCandidatos;

    if (numCandidatos > _MAX) {
        cerr << "Número de candidatos excede o limite permitido.\n";
        return;
    }

    for (int i = 0; i < numCandidatos; ++i) {
        string nome;
        double nota;

        cout << "Digite o nome do candidato " << i + 1 << ": ";
        cin >> nome;
        cout << "Digite a nota do candidato " << i + 1 << ": ";
        cin >> nota;

        // Cria um novo objeto Candidato e adiciona ao array
        candidatos[i] = new Candidato(nome, nota);
    }
}

double calcularMedia(Candidato* candidatos[], int numCandidatos) {
    double soma = 0.0;
    for (int i = 0; i < numCandidatos; ++i) {
        soma += candidatos[i]->getNota();
    }
    return soma / numCandidatos;
}

void listarCandidatosAcimaDaMedia(Candidato* candidatos[], int numCandidatos, double media) {
    cout << "\nCandidatos com nota acima da média (" << fixed << setprecision(2) << media << "):\n";
    for (int i = 0; i < numCandidatos; ++i) {
        if (candidatos[i]->getNota() > media) {
            cout << "Nome: " << candidatos[i]->getNome() << ", Nota: " << fixed << setprecision(2) << candidatos[i]->getNota() << "\n";
        }
    }
}

int main() {
    // Declara um array de ponteiros para objetos Candidato
    Candidato* candidatos[_MAX];

    // Número de candidatos
    int numCandidatos = 0;

    // Ler os dados dos candidatos
    lerCandidatos(candidatos, numCandidatos);

    if (numCandidatos > 0) {
        // Calcular a média das notas
        double media = calcularMedia(candidatos, numCandidatos);

        // Listar os candidatos com nota acima da média
        listarCandidatosAcimaDaMedia(candidatos, numCandidatos, media);

        // Liberar a memória alocada para cada candidato
        for (int i = 0; i < numCandidatos; ++i) {
            delete candidatos[i];
        }
    }

    return 0;
}
