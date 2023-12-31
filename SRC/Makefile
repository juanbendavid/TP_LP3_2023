# Definir los archivos fuente
SRCS_C := $(wildcard Cap2/Listing2_1.c Cap2/Listing2_2.c Cap2/Listing2_3.c Cap2/Listing2_4.c Cap2/Listing2_5.c Cap3/*.c Cap4/*.c)
SRCS_CPP := $(wildcard Cap4/*.cpp)

# Definir los archivos ejecutables
EXE_C := $(patsubst %.c,build/%,$(SRCS_C))
EXE_CPP := $(patsubst %.cpp,build/%,$(SRCS_CPP))

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
	rm -rf build

# Regla all para generar todos los archivos ejecutables
all: $(EXE_C) $(EXE_CPP) build/Cap1/reciprocal app Listing2_6 Listing2_9

# Reglas individuales para cada archivo
Listing2_1: build/Cap2/Listing2_1

Listing2_2: build/Cap2/Listing2_2

Listing2_3: build/Cap2/Listing2_3

Listing2_4: build/Cap2/Listing2_4

Listing2_5: build/Cap2/Listing2_5

Listing2_6: build/Cap2/Listing2_6
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

# Regla para compilar Listing2_7.c y Listing2_8.c juntos
app: Listing2_7.o Listing2_8.o libtest.a | dirs2
	gcc -o build/Cap2/app build/Cap2/Listing2_8.o -L build/Cap2/ -ltest
	rm build/Cap2/Listing2_7.o build/Cap2/Listing2_8.o build/Cap2/libtest.a

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

Listing2_9: Cap2/Listing2_9.c
	mkdir -p build/Cap2
	gcc -o build/Cap2/Listing2_9 Cap2/Listing2_9.c -ltiff
	cp ./Cap2/foto.tiff ./build/Cap2/

.PHONY: clean all reciprocal app dirs dirs2 Listing1_% Listing2_% Listing3_% Listing4_%
