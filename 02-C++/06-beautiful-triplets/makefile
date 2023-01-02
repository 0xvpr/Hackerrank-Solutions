PROJECT  = a.exe

CXX      = g++
CXXFLAGS = -std=c++2a -O2 -Wall -Wextra -Werror -Wshadow -Wpedantic -Wconversion

all: $(PROJECT)

test: $(PROJECT)
	bash -c '[[ $$(echo "7 3 1 2 4 5 7 8 10" | ./a.exe) -eq 3 ]]'

$(PROJECT): main.obj
	$(CXX) $(CXXFLAGS) $^ -o $(PROJECT)

%.obj : %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
