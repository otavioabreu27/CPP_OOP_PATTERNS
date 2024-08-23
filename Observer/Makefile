# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++14 -Wall -pthread

# Caminho do arquivo de origem
SRC = clima.cpp

# Caminho do executável
TARGET = $(BUILD_DIR)/observer

# Regras de compilação
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
