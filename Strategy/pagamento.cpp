#include <iostream>
#include <memory>

// Classe abstrata de pagamento
class EstrategiaPagamento {
public:
    virtual ~EstrategiaPagamento() = default; // Destrutor virtual
    virtual void pagar(int preco) = 0;
};

// Classe concreta de pagamento via cartao de credito
class PagamentoCartaoCredito : public EstrategiaPagamento {
public:
    void pagar(int preco) override {
        std::cout << "Pagando: " << preco << "R$ utilizando o cartao de credito." << std::endl;
    }
};

// Classe concreta de pagamento utilizando o mercado pago
class PagamentoMercadoPago : public EstrategiaPagamento {
public:
    void pagar(int preco) override {
        std::cout << "Pagando: " << preco << "R$ utilizando o mercado pago." << std::endl;
    }
};

// Classe concreta que acessa o metodo de pagamento
class CarrinhoCompras {
    std::unique_ptr<EstrategiaPagamento> estrategiaPagamento;
public:
    // Altera a estrategia de pagamento
    void alterarEstrategiaPagamento(std::unique_ptr<EstrategiaPagamento> estrategia) {
        estrategiaPagamento = std::move(estrategia);
    }

    void finalizarCompra(int quantidade) {
        estrategiaPagamento->pagar(quantidade);
    }
};

int main() {
    CarrinhoCompras carrinhoCompras;

    carrinhoCompras.alterarEstrategiaPagamento(std::make_unique<PagamentoCartaoCredito>());
    carrinhoCompras.finalizarCompra(200);

    carrinhoCompras.alterarEstrategiaPagamento(std::make_unique<PagamentoMercadoPago>());
    carrinhoCompras.finalizarCompra(15);

    return 0;
}
