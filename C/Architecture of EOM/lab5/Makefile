# Імена виконавчих файлів
SERVER = server
CLIENT = client


FIFO = myfifo


CC = gcc
CFLAGS = -Wall -Wextra -pedantic


all: $(SERVER) $(CLIENT)


$(SERVER): server.c
	$(CC) $(CFLAGS) -o $(SERVER) server.c


$(CLIENT): client.c
	$(CC) $(CFLAGS) -o $(CLIENT) client.c


$(FIFO):
	mkfifo $(FIFO)


clean:
	rm -f $(SERVER) $(CLIENT) $(FIFO)


run-server: $(SERVER) $(FIFO)
	./$(SERVER)


run-client: $(CLIENT)
	./$(CLIENT)

.PHONY: all clean run-server run-client
