PROJECT  = a.exe

CXX      = g++
CXXFLAGS = -std=c++2a -O2 -Wall -Wextra -Werror -Wshadow -Wpedantic -Wconversion

all: $(PROJECT)

$(PROJECT): main.obj
	$(CXX) $(CXXFLAGS) $^ -o $(PROJECT)

%.obj : %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
