CC = gcc
XX = g++
CFLAGS = -Wall -O -g
TARGET = hello

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.cpp
	$(XX) $(CFLAGS) -c $< -o $@

SOURCE = $(wildcard *.c *.cpp)
OBJS = $(patsubst *.c,*.o, $(patsubst *.cpp,*.o,$(SOURCE)))

$(TARGET): $(OBJS)
	$(XX) $(OBJS) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
