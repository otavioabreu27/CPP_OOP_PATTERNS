# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++14 -Wall -pthread

# Caminho do arquivo de origem
SRC = pagamento.cpp

# Caminho do executável
TARGET = $(BUILD_DIR)/strategy

# Regras de compilação
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
