# Factory
O padrão Factory providencia uma interface para criar objetos mas possibilita que subclasses alterem o tipo de objeto que sera criado.
Neste exemplo de código tem uma parte bastante importante que não necessariamente está ligada ao padrão de projeto mas sim ao polimorfismo em C++.

```c++
virtual ~Forma() = default; // Destrutor virtual para garantir destruição adequada
// Leia mais sobre o destrutor virtual no README.md
```

O pedaço de código acima instancia manualmente o destrutor virtual na classe abstrata 'Forma'. Esse mecanismo serve para que no momento em que uma classe que implementa 'Forma' for deletada esta delete o ponteiro apontando ao objeto correto.

Observe o código abaixo:

```c++
#include <iostream>

class Forma {
public:
    virtual void desenha() const = 0; // Método virtual puro
    virtual ~Forma() { // Destrutor virtual
        std::cout << "Destrutor de Forma chamado." << std::endl;
    }
};

class Circulo : public Forma {
public:
    void desenha() const override {
        std::cout << "Desenhando um circulo." << std::endl;
    }

    ~Circulo() {
        std::cout << "Destrutor de Circulo chamado." << std::endl;
    }
};

int main() {
    Forma* forma = new Circulo();
    delete forma; // Agora chama ambos os destrutores
    return 0;
}
```

Como resultado deve-se obter:

```bash
Desenhando um circulo.
Destrutor de Circulo chamado.
Destrutor de Forma chamado.
```
