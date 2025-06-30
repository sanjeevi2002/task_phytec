CC = gcc
CFLAGS = -Iinc
SRC = src
OBJ = obj
BIN = bin

CLIENT_OBJ = $(OBJ)/client.o $(OBJ)/udp_common.o
SERVER_OBJ = $(OBJ)/server.o $(OBJ)/server_state.o $(OBJ)/udp_common.o

all: dirs client server

dirs:
	mkdir -p $(OBJ) $(BIN)

client: $(CLIENT_OBJ)
	$(CC) -o $(BIN)/client $(CLIENT_OBJ)

server: $(SERVER_OBJ)
	$(CC) -o $(BIN)/server $(SERVER_OBJ)

$(OBJ)/client.o: $(SRC)/client.c inc/udp_common.h
	$(CC) $(CFLAGS) -c $(SRC)/client.c -o $@

$(OBJ)/server.o: $(SRC)/server.c inc/udp_common.h inc/server_state.h
	$(CC) $(CFLAGS) -c $(SRC)/server.c -o $@

$(OBJ)/server_state.o: $(SRC)/server_state.c inc/server_state.h
	$(CC) $(CFLAGS) -c $(SRC)/server_state.c -o $@

$(OBJ)/udp_common.o: $(SRC)/udp_common.c inc/udp_common.h
	$(CC) $(CFLAGS) -c $(SRC)/udp_common.c -o $@

clean:
	rm -rf $(OBJ) $(BIN)
