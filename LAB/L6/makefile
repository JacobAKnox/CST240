CC = gcc

TARGET = pthreads

FLAGS = -fsanitize=leak -g

$(TARGET): pthreads.c ll.h
	$(CC) $(FLAGS) -o $(TARGET) pthreads.c ll.h -lpthread

clean:
	$(RM) $(TARGET)
