# Makefile genérico para projeto de herança
# Compila automaticamente todos os arquivos .cpp encontrados
# Uso: make DIR=pasta run

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Diretório padrão (pode ser sobrescrito com DIR=pasta)
DEFAULT_DIR = heranca
DIR ?= $(DEFAULT_DIR)

# Diretórios
SRC_DIR = $(DIR)/Sources
HEADER_DIR = $(DIR)/Headers
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

# Nome do executável
TARGET = $(BIN_DIR)/main

# Encontra automaticamente todos os arquivos .cpp
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Encontra automaticamente todos os arquivos .h
HEADERS = $(wildcard $(HEADER_DIR)/*.h)

# Gera os nomes dos arquivos objeto
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Flags para incluir diretórios de headers
INCLUDES = -I$(HEADER_DIR)

# Regra padrão
all: $(TARGET)

# Regra especial para permitir make pasta run
%: 
	@if [ -d "$*/Sources" ] && [ -d "$*/Headers" ]; then \
		$(MAKE) DIR=$* run; \
	else \
		echo "Erro: Pasta '$*' não encontrada ou não contém diretórios Sources/Headers"; \
		echo "Pastas disponíveis:"; \
		ls -d */Sources 2>/dev/null | sed 's|/Sources||' | sed 's/^/  /' || echo "  Nenhuma pasta com Sources/Headers encontrada"; \
		exit 1; \
	fi

# Regra para criar o executável
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@
	@echo "Compilação concluída: $@"

# Regra para compilar arquivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Cria diretórios necessários
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpa arquivos compilados
clean:
	rm -rf $(BUILD_DIR)
	@echo "Arquivos de compilação removidos"

# Recompila tudo do zero
rebuild: clean all

# Executa o programa
run: $(TARGET)
	./$(TARGET)

# Mostra informações sobre os arquivos encontrados
info:
	@echo "Arquivos fonte encontrados:"
	@echo $(SOURCES)
	@echo "Headers encontrados:"
	@echo $(HEADERS)
	@echo "Objetos a serem criados:"
	@echo $(OBJECTS)

# Ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make                    - Compila o projeto (diretório padrão: heranca)"
	@echo "  make DIR=pasta          - Compila o projeto da pasta especificada"
	@echo "  make DIR=pasta run      - Compila e executa o programa da pasta especificada"
	@echo "  make clean              - Remove arquivos compilados"
	@echo "  make rebuild            - Limpa e recompila tudo"
	@echo "  make run                - Compila e executa o programa (diretório padrão)"
	@echo "  make info               - Mostra arquivos encontrados"
	@echo "  make help               - Mostra esta ajuda"
	@echo ""
	@echo "Exemplos de uso:"
	@echo "  make heranca            - Compila e executa da pasta heranca"
	@echo "  make heranca run        - Compila e executa da pasta heranca"
	@echo "  make DIR=outra_pasta run - Compila e executa da pasta outra_pasta"
	@echo "  make lista\\ 1           - Compila e executa da pasta 'lista 1'"

# Marca como phony (não são arquivos)
.PHONY: all clean rebuild run info help
