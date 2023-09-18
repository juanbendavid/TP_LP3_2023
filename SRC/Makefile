# Definir los archivos fuente
SRCS_C := $(wildcard Cap1/*.c Cap2/*.c Cap3/*.c Cap4/*.c)
SRCS_CPP := $(wildcard Cap1/*.cpp Cap4/*.cpp)

# Definir los archivos ejecutables
EXE_C := $(patsubst %.c,build/%,$(SRCS_C))
EXE_CPP := $(patsubst %.cpp,build/%,$(SRCS_CPP))

# Regla para el objetivo principal
main: $(EXE_C) $(EXE_CPP)
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
all: $(EXE_C) $(EXE_CPP)

# Reglas individuales para cada archivo .c
Listing1_%: build/Cap1/Listing1_%
	mkdir -p $(dir $@)

Listing2_%: build/Cap2/Listing2_%
	mkdir -p $(dir $@)

Listing3_%: build/Cap3/Listing3_%
	mkdir -p $(dir $@)

Listing4_%: build/Cap4/Listing4_%
	mkdir -p $(dir $@)

.PHONY: Listing1_% Listing2_% Listing3_% Listing4_% clean all
