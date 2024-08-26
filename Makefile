# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++14 -Wall -pthread

# Diretórios de origem e de destino
SRC_DIRS = Singleton Factory Observer Decorator
BUILD_DIR = build

# Alvo padrão, compilar todos os exemplos
all: $(BUILD_DIR) $(SRC_DIRS)

# Cria a pasta de compilação
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regras para compilar os exemplos de cada diretório
$(SRC_DIRS):
	$(MAKE) -C $@ BUILD_DIR=$(abspath $(BUILD_DIR))

# Regra para compilar um exemplo específico
# Variável de substituição automática: $< é o primeiro pré-requisito, $@ é o alvo
$(BUILD_DIR)/%: $(SRC_DIRS)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean $(SRC_DIRS)
