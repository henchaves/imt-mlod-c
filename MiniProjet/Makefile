# the compiler
CC = cc

# compiler flags:
CFLAGS  = `pkg-config --libs --cflags raylib`

# the build target executable:
TARGET = tetris

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(TARGET).c $(CFLAGS) -o $(TARGET) 

clean:
	$(RM) $(TARGET)