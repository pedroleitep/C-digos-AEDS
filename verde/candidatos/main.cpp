#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Para controlar a precisão do output

#define _MAX 100

class Candidato {
private:
    std::string nome;
    double nota;

public:
    // Construtor
    Candidato(const std::string &nome, double nota) : nome(nome), nota(nota) {}

    // Métodos para definir atributos
    void setNome(const std::string &nome) {
        this->nome = nome;
    }

    void setNota(double nota) {
        this->nota = nota;
    }

    // Métodos para acessar atributos
    std::string getNome() const {
        return nome;
    }

    double getNota() const {
        return nota;
    }
};

void lerCandidatos(std::vector<Candidato*> &candidatos, int &numCandidatos) {
    std::cout << "Digite o número de candidatos (max " << _MAX << "): ";
    std::cin >> numCandidatos;

    if (numCandidatos > _MAX) {
        std::cerr << "Número de candidatos excede o limite permitido.\n";
        return;
    }

    for (int i = 0; i < numCandidatos; ++i) {
        std::string nome;
        double nota;

        std::cout << "Digite o nome do candidato " << i + 1 << ": ";
        std::cin >> nome;
        std::cout << "Digite a nota do candidato " << i + 1 << ": ";
        std::cin >> nota;

        // Cria um novo objeto Candidato e adiciona ao vetor
        Candidato *candidato = new Candidato(nome, nota);
        candidatos.push_back(candidato);
    }
}

double calcularMedia(const std::vector<Candidato*> &candidatos) {
    double soma = 0.0;
    for (Candidato* candidato : candidatos) {
        soma += candidato->getNota();
    }
    return soma / candidatos.size();
}

void listarCandidatosAcimaDaMedia(const std::vector<Candidato*> &candidatos, double media) {
    std::cout << "\nCandidatos com nota acima da média (" << std::fixed << std::setprecision(2) << media << "):\n";
    for (Candidato* candidato : candidatos) {
        if (candidato->getNota() > media) {
            std::cout << "Nome: " << candidato->getNome() << ", Nota: " << std::fixed << std::setprecision(2) << candidato->getNota() << "\n";
        }
    }
}

int main() {
    // Declara um vetor de ponteiros para objetos Candidato
    std::vector<Candidato*> candidatos;

    // Número de candidatos
    int numCandidatos = 0;

    // Ler os dados dos candidatos
    lerCandidatos(candidatos, numCandidatos);

    if (numCandidatos > 0) {
        // Calcular a média das notas
        double media = calcularMedia(candidatos);

        // Listar os candidatos com nota acima da média
        listarCandidatosAcimaDaMedia(candidatos, media);

        // Liberar a memória alocada para cada candidato
        for (Candidato* candidato : candidatos) {
            delete candidato;
        }
    }

    return 0;
}
