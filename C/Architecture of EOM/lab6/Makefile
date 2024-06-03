# Імена виконавчих файлів
SERVER = server
CLIENT = client

# Ім'я іменованого каналу
FIFO = myfifo

# Компілятор і прапорці
CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# Цілі за замовчуванням
all: $(SERVER) $(CLIENT)

# Правила для серверного файлу
$(SERVER): server.c
	$(CC) $(CFLAGS) -o $(SERVER) server.c

# Правила для клієнтського файлу
$(CLIENT): client.c
	$(CC) $(CFLAGS) -o $(CLIENT) client.c

# Правило для створення іменованого каналу
$(FIFO):
	mkfifo $(FIFO)

# Очищення згенерованих файлів
clean:
	rm -f $(SERVER) $(CLIENT) $(FIFO)

# Правило для запуску серверу
run-server: $(SERVER) $(FIFO)
	./$(SERVER)

# Правило для запуску клієнту
run-client: $(CLIENT)
	./$(CLIENT)

.PHONY: all clean run-server run-client
