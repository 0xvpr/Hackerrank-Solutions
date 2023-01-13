PROJECT  = a.exe

CC       = gcc
CFLAGS   = -std=c99 -O2 -Wall -Wextra -Werror -Wshadow -Wpedantic -Wconversion

all: $(PROJECT)

test: $(PROJECT)
	bash -c '[[ $$(echo "20 3 6 85" | ./a.exe) -eq 7 ]]'

$(PROJECT): main.o
	$(CC) $(CFLAGS) $^ -o $(PROJECT)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@
