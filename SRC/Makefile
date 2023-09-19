# Definir los archivos fuente
SRCS_C := $(filter-out Cap2/Listing2_7.c Cap2/Listing2_8.c Cap2/Listing2_6.c, $(wildcard Cap2/*.c)) $(wildcard Cap3/*.c Cap4/*.c)
SRCS_CPP := $(wildcard Cap4/*.cpp)

# Definir los archivos ejecutables
EXE_C := $(patsubst %.c,build/%,$(SRCS_C))
EXE_CPP := $(patsubst %.cpp,build/%,$(SRCS_CPP))

# Regla para el objetivo principal
main: $(EXE_C) $(EXE_CPP) build/Cap1/reciprocal build/Cap2/app Listing2_6
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
all: $(EXE_C) $(EXE_CPP) build/Cap1/reciprocal build/Cap2/app Listing2_6

# Regla para compilar Listing1_1.c y Listing1_2.cpp juntos
build/Cap1/reciprocal: Cap1/Listing1_1.c Cap1/Listing1_2.cpp Cap1/Listing1_3.hpp | dirs
	g++ $^ -o $@

dirs:
	mkdir -p build/Cap1

# Regla para compilar Listing2_7.c y Listing2_8.c juntos
build/Cap2/app: Cap2/Listing2_8.c | dirs2
	gcc $^ -o $@

dirs2:
	mkdir -p build/Cap2

# Regla para compilar Listing2_6 con el txt
build/Cap2/Listing2_6: Cap2/Listing2_6.c | dirs2
	gcc $^ -o $@

# Reglas individuales para cada archivo 
Listing1_1: build/Cap1/reciprocal

Listing1_2: build/Cap1/reciprocal
	
Listing1_3: build/Cap1/reciprocal

Listing2_1: build/Cap2/Listing2_1

Listing2_2: build/Cap2/Listing2_2

Listing2_3: build/Cap2/Listing2_3

Listing2_4: build/Cap2/Listing2_4

Listing2_5: build/Cap2/Listing2_5

Listing2_6: build/Cap2/Listing2_6
	cp ./Cap2/HolaMundo.txt ./build/Cap2/

Listing2_8: build/Cap2/app

Listing2_7: build/Cap2/app

Listing3_%: build/Cap3/Listing3_%
	mkdir -p $(dir $@)

Listing4_%: build/Cap4/Listing4_%
	mkdir -p $(dir $@)

.PHONY: clean all reciprocal dirs app dirs2 Listing3_% Listing4_% Listing1_% Listing2_% 

