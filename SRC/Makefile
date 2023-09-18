# Definir los archivos fuente
SRCS_C := $(wildcard Cap2/Listing2_1.c Cap2/Listing2_2.c Cap2/Listing2_3.c Cap2/Listing2_4.c Cap2/Listing2_5.c Cap3/*.c Cap4/*.c)
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
all: $(EXE_C) $(EXE_CPP) build/Cap1/reciprocal app Listing2_6

# Reglas individuales para cada archivo .c
Listing2_1: build/Cap2/Listing2_1
	mkdir -p $(dir $@)

Listing2_2: build/Cap2/Listing2_2
	mkdir -p $(dir $@)

Listing2_3: build/Cap2/Listing2_3
	mkdir -p $(dir $@)

Listing2_4: build/Cap2/Listing2_4
	mkdir -p $(dir $@)

Listing2_5: build/Cap2/Listing2_5
	mkdir -p $(dir $@)

Listing2_6: build/Cap2/Listing2_6
	mkdir -p $(dir $@)
	cp ./Cap2/HolaMundo.txt ./build/Cap2/

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

# Regla para compilar Listing2_7.c y Listing2_8.c juntos
app: Listing2_7.o Listing2_8.o libtest.a | dirs2
	gcc -o build/Cap2/app build/Cap2/Listing2_8.o -L build/Cap2/ -ltest

libtest.a: Listing2_7.o
	ar cr build/Cap2/libtest.a build/Cap2/Listing2_7.o --output build/Cap2/

Listing2_7.o: Cap2/Listing2_7.c
	mkdir -p build/Cap2
	gcc -c Cap2/Listing2_7.c -o build/Cap2/Listing2_7.o

Listing2_8.o: Cap2/Listing2_8.c
	mkdir -p build/Cap2
	gcc -c Cap2/Listing2_8.c -o build/Cap2/Listing2_8.o

dirs2:
	mkdir -p build/Cap2

# Reglas de dependencia para Listing2_7 y Listing2_8
Listing2_8: app

Listing2_7: app


