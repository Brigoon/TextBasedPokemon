CC               = g++
FLAGS_COMMON     = -std=c++11
FLAGS_BINDINGS   = $(FLAGS_COMMON) -O3 -Wall -shared -fPIC -undefined dynamic_lookup
SOURCES_COMMON   = monster.cpp battleEngine.cpp rng.cpp types.cpp
SOURCES_CPP      = main.cpp $(SOURCES_COMMON)
SOURCES_BINDINGS = bindings.cpp $(SOURCES_COMMON)
BINDINGS_FILE    = pokebindings.so

PYBIND11_DIR = pybind11

# Get Python's include paths and linker flags automatically
PYTHON_INCLUDES = $(shell python3-config --includes)
PYTHON_LDFLAGS = $(shell python3-config --ldflags)

make: $(SOURCES_CPP)
	$(CC) $(SOURCES_CPP) $(FLAGS_COMMON) -o main

bindings: $(SOURCES_BINDINGS)
	$(CC) $(FLAGS_BINDINGS) $(PYTHON_INCLUDES) -I$(PYBIND11_DIR)/include -o $(BINDINGS_FILE) $(SOURCES_BINDINGS) $(PYTHON_LDFLAGS)
	cp $(BINDINGS_FILE) /Users/tydickinson/

clean:
	rm main

clean_bindings:
	rm $(BINDINGS_FILE)