CC               = g++
FLAGS_COMMON     = -std=c++11 -Ilib -Wall
FLAGS_DEBUG      = -g -O0
FLAGS_RELEASE    = -O3
FLAGS_BINDINGS   = $(FLAGS_COMMON) -shared -fPIC
SOURCES_COMMON   = src/monster.cpp src/battleEngine.cpp src/rng.cpp src/statuses.cpp src/types.cpp src/experience.cpp
SOURCES_CPP      = src/main.cpp $(SOURCES_COMMON)
SOURCES_BINDINGS = src/bindings.cpp $(SOURCES_COMMON)
CPP_FILE         = pokemon.exe
BINDINGS_FILE    = pokebindings.so

PYBIND11_DIR = pybind11

OS_NAME := $(shell uname -s)
ifeq ($(OS_NAME), Darwin)
	FLAGS_BINDINGS += -undefined dynamic_lookup
endif

# Get Python's include paths and linker flags automatically
PYTHON_INCLUDES = $(shell python3-config --includes)
PYTHON_LDFLAGS = $(shell python3-config --ldflags)

.PHONY: build debug release
.DEFAULT_GOAL := debug

build: $(SOURCES_CPP)
	$(CC) $(SOURCES_CPP) $(FLAGS) -o $(CPP_FILE)

debug: FLAGS = $(FLAGS_COMMON) $(FLAGS_DEBUG)
debug: build

release: FLAGS = $(FLAGS_COMMON) $(FLAGS_RELEASE)
release: build

bindings: $(SOURCES_BINDINGS)
	$(CC) $(FLAGS_BINDINGS) $(PYTHON_INCLUDES) -I$(PYBIND11_DIR)/include -o $(BINDINGS_FILE) $(SOURCES_BINDINGS) $(PYTHON_LDFLAGS)

clean:
	rm -f main $(BINDINGS_FILE)