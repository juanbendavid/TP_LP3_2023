# Definir los archivos fuente
SRCS_C := $(wildcard Cap2/*.c Cap3/*.c Cap4/*.c)
SRCS_CPP := $(wildcard Cap4/*.cpp)

# Definir los archivos ejecutables
EXE_C := $(patsubst %.c,build/%,$(SRCS_C))
EXE_CPP := $(patsubst %.cpp,build/%,$(SRCS_CPP))

# Regla para el objetivo principal
main: $(EXE_C) $(EXE_CPP) build/Cap1/reciprocal
	g++ $^ -o $@

# Regla para los archivos ejecutables .c
build/%: %.c | build
	mkdir -p $(dir $@)
	gcc $< -o $@

# Regla para los archivos ejecutables .cpp
build/%: %.cpp | build
	mkdir -p $(dir $@)
	g++ $< -o $@

# Regla para crear el directorio build
build:
	mkdir -p $@

# Regla para limpiar los archivos generados
clean:
	rm -rf build main

# Regla all para generar todos los archivos ejecutables
all: $(EXE_C) $(EXE_CPP) build/Cap1/reciprocal

# Reglas individuales para cada archivo .c
Listing2_%: build/Cap2/Listing2_%
	mkdir -p $(dir $@)

Listing3_%: build/Cap3/Listing3_%
	mkdir -p $(dir $@)

Listing4_%: build/Cap4/Listing4_%
	mkdir -p $(dir $@)

# Regla para compilar Listing1_1.c y Listing1_2.cpp juntos
build/Cap1/reciprocal: Cap1/Listing1_1.c Cap1/Listing1_2.cpp Cap1/Listing1_3.hpp | dirs
	g++ $^ -o $@

dirs:
	mkdir -p build/Cap1

# Reglas de dependencia para Listing1_1, Listing1_2 y Listing1_3
Listing1_1: build/Cap1/reciprocal

Listing1_2: build/Cap1/reciprocal

Listing1_3: build/Cap1/reciprocal

.PHONY: Listing2_% Listing3_% Listing4_% clean all reciprocal Listing1_1 Listing1_2 Listing1_3 dirs


