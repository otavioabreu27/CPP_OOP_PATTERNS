#include <iostream>
#include <memory>

// Classe Base
class Cafe {
public:
    virtual ~Cafe() = default;
    virtual void preparar() const = 0; // Função pura virutal para preparar o cafe
};

// Classe base decoradora
class DecoradorCafe: public Cafe {
protected:
    std::unique_ptr<Cafe> cafe; // Ponteiro pro objeto cafe

public:
    DecoradorCafe(std::unique_ptr<Cafe> c) : cafe(std::move(c)) {} // Inicializa o ponteiro no construtor
};

// Classe decoradora concreta
class Leite: public DecoradorCafe {
public:
    Leite(std::unique_ptr<Cafe> c) : DecoradorCafe(std::move(c)) {} // Chama o construtor da classe base

    void preparar() const override {
        cafe->preparar(); // Chama o metodo da classe base
        std::cout << "Adicionando leite." << std::endl; // Adiciona leite
    }
};

// Classe decoradora concreta
class Chantilly: public DecoradorCafe {
public:
    Chantilly(std::unique_ptr<Cafe> c) : DecoradorCafe(std::move(c)) {} // Chama o construtor da classe base

    void preparar() const override {
        cafe->preparar(); // Chama o metodo da classe base
        std::cout << "Adicionando o chantilly." << std::endl; // Adiciona o chantilly
    }
};

// Classe componente concreta
class CafeSimples: public Cafe {
public:
    void preparar() const override {
        std::cout << "Preparando café simples." << std::endl;
    }
};

int main() {
    std::cout << "-- DEMONSTRAÇÃO DO PADRÃO DECORATOR --" << std::endl;
    std::cout << "Através de abstrações da classe" << std::endl << "'DecoradorCafe' é possivel" << std::endl << "empilhar funcionalidades no" << std::endl << "metodo preparar do café." << std::endl;
    std::cout << "------ INICIANDO A DEMONSTRAÇÃO ------" << std::endl;
    // Cria um cafe simples
    std::unique_ptr<Cafe> cafe = std::make_unique<CafeSimples>();

    std::cout << "> Decorando café com leite" << std::endl;
    // Decora o cafe simples com leite
    std::unique_ptr<Cafe> cafeComLeite = std::make_unique<Leite>(std::move(cafe));

    // Prepara o cafe com leite
    cafeComLeite->preparar();

    std::cout << "> Decorando o café com leite e chantilly" << std::endl;
    // Agora decora o cafe com leite com chantilly
    std::unique_ptr<Cafe> cafeComLeiteEChantilly = std::make_unique<Chantilly>(std::move(cafeComLeite));

    // Prepare o cafe com leite e chantilly
    cafeComLeiteEChantilly->preparar();
    std::cout << "--------------------------------------" << std::endl;

    return 0;
}
