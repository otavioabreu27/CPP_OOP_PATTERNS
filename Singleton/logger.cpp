#include <iostream>
#include <mutex>


class Logger
{
private:
    static Logger* instancia;
    static std::mutex mutex_;

    Logger() {}

public:
    // Deleta copia do construtor e operador de atribuição
    Logger(const  Logger&) = delete;
    Logger& operator = (const Logger&) = delete;
    // --------------------------------------------------

    // Método de acesso global a instância Singleton da classe Logger
    static Logger* pegaInstancia() {
        std::lock_guard<std::mutex> lock(mutex_);

        if (instancia == nullptr) {
            instancia = new Logger();
        }
        return instancia;
    }
    // --------------------------------------------------

    void log(const std::string& message) {
        // Printando o endereço de memoria e a mensagem em questão
        std::cout << "[" << instancia << "] " << message << std::endl;
        // -------------------------------------------------------
    }
};

// Inicializando membros estaticos
Logger* Logger::instancia = nullptr;
std::mutex Logger::mutex_;
// --------------------------------

int main() {
    std::cout << "-- DEMONSTRAÇÃO DO PADRÃO SINGLETON --" << std::endl;
    std::cout << "Repare no endereço de memoria entre "<< std::endl << "'[]', este demonstra que o Logger é" << std::endl << "o mesmo pra ambos logs." << std::endl;
    std::cout << "------ INICIANDO A DEMONSTRACAO ------" << std::endl;

    // Instanciando o logger 1
    Logger* logger1 = Logger::pegaInstancia();

    // Instanciando o logger 2
    Logger* logger2 = Logger::pegaInstancia();

    logger1->log("Mensagem do logger1");
    logger2->log("Mensagem do logger2");

    std::cout << "--------------------------------------" << std::endl;
    return 0;
}
