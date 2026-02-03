CC               = g++
FLAGS_COMMON     = -std=c++11 -Ilib
FLAGS_BINDINGS   = $(FLAGS_COMMON) -O3 -Wall -shared -fPIC -undefined dynamic_lookup
SOURCES_COMMON   = src/monster.cpp src/battleEngine.cpp src/rng.cpp src/types.cpp
SOURCES_CPP      = src/main.cpp $(SOURCES_COMMON)
SOURCES_BINDINGS = src/bindings.cpp $(SOURCES_COMMON)
CPP_FILE         = pokemon.exe
BINDINGS_FILE    = pokebindings.so

PYBIND11_DIR = pybind11

# Get Python's include paths and linker flags automatically
PYTHON_INCLUDES = $(shell python3-config --includes)
PYTHON_LDFLAGS = $(shell python3-config --ldflags)

make: $(SOURCES_CPP)
	$(CC) $(SOURCES_CPP) $(FLAGS_COMMON) -o main

bindings: $(SOURCES_BINDINGS)
	$(CC) $(FLAGS_BINDINGS) $(PYTHON_INCLUDES) -I$(PYBIND11_DIR)/include -o $(BINDINGS_FILE) $(SOURCES_BINDINGS) $(PYTHON_LDFLAGS)
	cp $(BINDINGS_FILE) $(HOME)

clean:
	rm -f main $(BINDINGS_FILE)