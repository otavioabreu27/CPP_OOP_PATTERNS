#include <iostream>
#include <memory>

// Classe base abstrata para formas
class Forma {
public:
    virtual void desenha() const = 0; // Método virtual puro
    virtual ~Forma() = default; // Destrutor virtual para garantir destruição adequada
    // Leia mais sobre o destrutor virtual no README.md
};

// Subclasse para Circulo
class Circulo : public Forma {
public:
    void desenha() const override {
        std::cout << "Desenhando um circulo." << std::endl;
    }

    ~Circulo() {
        std::cout << "Destrutor de Circulo chamado." << std::endl;
    }
};

// Subclasse para Quadrado
class Quadrado : public Forma {
public:
    void desenha() const override {
        std::cout << "Desenhando um quadrado." << std::endl;
    }

    ~Quadrado() {
        std::cout << "Destrutor de Quadrado chamado." << std::endl;
    }
};

// Enum para representar os tipos de formas disponíveis
enum class FormasDisponiveis {
    CIRCULO,
    QUADRADO
};

// Classe de fábrica para criar objetos Forma
class FormaFactory {
public:
    static std::unique_ptr<Forma> criaForma(const FormasDisponiveis& tipo) {
        switch (tipo) {
            case FormasDisponiveis::CIRCULO:
                return std::make_unique<Circulo>();
            case FormasDisponiveis::QUADRADO:
                return std::make_unique<Quadrado>();
            default:
                return nullptr; // Retorno seguro para casos não cobertos
        }
    }
};

int main() {
    std::cout << "-- DEMONSTRAÇÃO DO PADRÃO FACTORY --" << std::endl;
    std::cout << "A partir da classe 'FormaFactory'" << std::endl << "se faz possivel criar abstrações" << std::endl <<"da classe Forma." << std::endl;
    std::cout <<"------ INICIANDO A DEMONSTRAÇÃO -----" << std::endl;

    // Cria um círculo usando a fábrica
    auto circulo = FormaFactory::criaForma(FormasDisponiveis::CIRCULO);
    circulo->desenha();

    // Cria um quadrado usando a fábrica
    auto quadrado = FormaFactory::criaForma(FormasDisponiveis::QUADRADO);
    quadrado->desenha();

    std::cout << "--------------------------------------" << std::endl;
    return 0;
}
