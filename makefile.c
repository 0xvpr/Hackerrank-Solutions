PROJECT  = a.exe

CXX      = gcc
CXXFLAGS = -std=c99 -O2 -Wall -Wextra -Werror -Wshadow -Wpedantic -Wconversion

all: $(PROJECT)

$(PROJECT): main.o
	$(CXX) $(CXXFLAGS) $^ -o $(PROJECT)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@
