PROJECT  = a.exe

CXX      = g++
CXXFLAGS = -std=c++2a -O2 -Wall -Wextra -Werror -Wshadow -Wpedantic -Wconversion

all: $(PROJECT)

$(PROJECT): main.obj
	$(CXX) $(CXXFLAGS) $^ -o $(PROJECT)

%.obj : %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test: $(PROJECT)
	cat input1.txt | ./$(PROJECT)
	cat input2.txt | ./$(PROJECT)
