# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -pthread

# Caminho do arquivo de origem
SRC = logger.cpp

# Caminho do executável
TARGET = $(BUILD_DIR)/singleton

# Regras de compilação
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET)
