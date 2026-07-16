CC = g++
CFLAGS = -Wall -O2
TARGET = PhysicsEngine
OBJS = Vetor2D.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

Vetor2D.o: Vetor2D.cpp Vetor2D.h
	$(CC) $(CFLAGS) -c Vetor2D.cpp

main.o: main.cpp Vetor2D.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(TARGET)