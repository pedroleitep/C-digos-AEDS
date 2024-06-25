#include <iostream>
#include <string>
#include <iomanip> // Para controlar a precis�o do output

#define _MAX 100

using namespace std;

class Candidato {
private:
    string nome;
    double nota;

public:
    // Construtor
    Candidato(const string &nome, double nota) : nome(nome), nota(nota) {}

    // M�todos para definir atributos
    void setNome(const string &nome) {
        this->nome = nome;
    }

    void setNota(double nota) {
        this->nota = nota;
    }

    // M�todos para acessar atributos
    string getNome() const {
        return nome;
    }

    double getNota() const {
        return nota;
    }
};

void lerCandidatos(Candidato* candidatos[], int &numCandidatos) {
    cout << "Digite o n�mero de candidatos (max " << _MAX << "): ";
    cin >> numCandidatos;

    if (numCandidatos > _MAX) {
        cerr << "N�mero de candidatos excede o limite permitido.\n";
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
    cout << "\nCandidatos com nota acima da m�dia (" << fixed << setprecision(2) << media << "):\n";
    for (int i = 0; i < numCandidatos; ++i) {
        if (candidatos[i]->getNota() > media) {
            cout << "Nome: " << candidatos[i]->getNome() << ", Nota: " << fixed << setprecision(2) << candidatos[i]->getNota() << "\n";
        }
    }
}

int main() {
    // Declara um array de ponteiros para objetos Candidato
    Candidato* candidatos[_MAX];

    // N�mero de candidatos
    int numCandidatos = 0;

    // Ler os dados dos candidatos
    lerCandidatos(candidatos, numCandidatos);

    if (numCandidatos > 0) {
        // Calcular a m�dia das notas
        double media = calcularMedia(candidatos, numCandidatos);

        // Listar os candidatos com nota acima da m�dia
        listarCandidatosAcimaDaMedia(candidatos, numCandidatos, media);

        // Liberar a mem�ria alocada para cada candidato
        for (int i = 0; i < numCandidatos; ++i) {
            delete candidatos[i];
        }
    }

    return 0;
}
