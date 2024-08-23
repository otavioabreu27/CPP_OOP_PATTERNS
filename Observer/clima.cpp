#include <algorithm>
#include <iostream>
#include <vector>

// Classe base abstrata para observadores
class Observer
{
public:
    virtual void atualizar(float temperatura, float humidade) = 0; // Método virtual puro
    virtual ~Observer() = default; // Destrutor virtual
};

// Classe sujeito dos observadores
class EstacaoClima
{
    // Recebe um vetor ponteiros de observadores
    std::vector<Observer *> observadores;

    float temperatura;
    float humidade;

public:
    void registrarObservador(Observer* observador) {
        // Adiciona um ponteiro de observador a propriedade privada observadores
        observadores.push_back(observador);
    }

    void removerObservador(Observer* observador) {
        // Apaga um observador no conjunto de observadores
        observadores.erase(
            std::remove(
                observadores.begin(),
                observadores.end(),
                observador
            ),

            observadores.end()
        );
    }

    void notificarObservadores() {
        // Atualiza todos os observadores registrados
        for (auto& observador: observadores) {
            observador->atualizar(temperatura, humidade);
        }
    }

    void alterarMedidas(float n_temperatura, float n_humidade) {
        // Altera as medidas e notifica os observadores internos dos novos valores
        temperatura = n_temperatura;
        humidade = n_humidade;
        notificarObservadores();
    }
};

// Implementação da classe observador
class VisualizadorClimaAtual : public Observer {
public:
    void atualizar(float temperatura, float humidade) override {
        std::cout << "Condicoes atuais: " << temperatura << "C graus e humidade em " << humidade << "%." << std::endl;
    }
};


int main() {
    std::cout << "-- DEMONSTRAÇÃO DO PADRÃO OBSERVER --" << std::endl;
    std::cout << "Através da classe 'EstacaoClima'" << std::endl << "os valores de todos seus observadores" << std::endl << "são alterados." << std::endl;
    std::cout << "------ INICIANDO A DEMONSTRAÇÃO -----" << std::endl;
    // Criando objetos das classes estacaoClima e visualizadorClimaAtual
    EstacaoClima estacaoClima;
    VisualizadorClimaAtual visualizadorClimaAtual;

    // Registrando o observador
    estacaoClima.registrarObservador(&visualizadorClimaAtual);
    estacaoClima.alterarMedidas(31.75, 40);
    estacaoClima.alterarMedidas(29.55, 38);
    std::cout << "-------------------------------------" << std::endl;

    return 0;
}
