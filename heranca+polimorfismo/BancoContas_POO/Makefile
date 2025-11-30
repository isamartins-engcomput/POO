# --- Variáveis de Compilação ---
# Compilador C++
CXX = g++

# Flags de compilação:
# -std=c++17: Padrão do C++
# -Wall -Wextra: Mostra todos os avisos
# -g: Habilita informações de debug
# -Iinclude: Diz ao compilador para procurar headers na pasta 'include'
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I$(HEADER_DIR)

# --- Estrutura do Projeto ---
# Pastas do projeto
SRC_DIR = src
HEADER_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Nome do executável final
TARGET = $(BIN_DIR)/circuito_poo

# --- Descoberta Automática de Arquivos ---
# Encontra todos os .cpp em $(SRC_DIR)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Encontra todos os .hpp em $(HEADER_DIR)
HEADERS = $(wildcard $(HEADER_DIR)/*.hpp)

# Gera a lista de arquivos objeto (.o) que ficarão na pasta 'build'
# Ex: "src/main.cpp" vira "build/main.o"
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Flags de inclusão (apenas para clareza)
INCLUDES = -I$(HEADER_DIR)

# --- Regras do Makefile ---

# Regra padrão (o que 'make' faz)
# Compila o executável principal
.PHONY: all
all: $(TARGET)

# Regra para "linkar" o executável final:
# Ele depende de todos os arquivos objeto (.o)
# O '| $(BIN_DIR)' é uma "dependência de ordem": garante que a pasta exista
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "Linkando executável final: $@"
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Regra para compilar cada .cpp em um .o:
# Um arquivo .o depende do seu .cpp e de TODOS os headers
# Se qualquer .hpp mudar, ele recompila os .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	@echo "Compilando: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# --- Regras de Criação de Pastas ---
# Cria a pasta 'build' se ela não existir
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Cria a pasta 'bin' se ela não existir
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# --- Comandos Utilitários ---

# Limpa todos os arquivos compilados
.PHONY: clean
clean:
	@echo "Limpando pastas 'build' e 'bin'..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Recompila tudo do zero
.PHONY: rebuild
rebuild: clean all

# Executa o programa (compila se necessário)
.PHONY: run
run: $(TARGET)
	@echo "Executando: $(TARGET)..."
	./$(TARGET)

# Mostra informações sobre os arquivos do projeto
.PHONY: info
info:
	@echo "--- Informações do Projeto ---"
	@echo "Fonte(s) (.cpp):"
	@echo "  $(SOURCES)"
	@echo "Header(s) (.hpp):"
	@echo "  $(HEADERS)"
	@echo "Objeto(s) (.o):"
	@echo "  $(OBJECTS)"
	@echo "Executável:"
	@echo "  $(TARGET)"

# Mostra esta ajuda
.PHONY: help
help:
	@echo "--- Comandos do Makefile ---"
	@echo "  make         (ou make all)   Compila o projeto."
	@echo "  make run                     Compila (se necessário) e executa o programa."
	@echo "  make clean                   Remove todos os arquivos compilados."
	@echo "  make rebuild                 Limpa e recompila o projeto do zero."
	@echo "  make info                    Mostra os arquivos que o make encontrou."
	@echo "  make help                    Mostra esta ajuda."