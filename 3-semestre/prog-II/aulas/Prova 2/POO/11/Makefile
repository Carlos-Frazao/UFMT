CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = biblioteca
OBJS = main.o Livro.o Membro.o Biblioteca.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Biblioteca.h Livro.h Membro.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Livro.o: Livro.cpp Livro.h
	$(CXX) $(CXXFLAGS) -c Livro.cpp

Membro.o: Membro.cpp Membro.h
	$(CXX) $(CXXFLAGS) -c Membro.cpp

Biblioteca.o: Biblioteca.cpp Biblioteca.h Livro.h Membro.h
	$(CXX) $(CXXFLAGS) -c Biblioteca.cpp

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean

