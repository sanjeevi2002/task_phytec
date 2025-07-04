# Compiler and Flags
CC = gcc
CFLAGS = -Iinc       # Include path for header files

# Directory Structure
SRC = src            # Source code directory
OBJ = obj            # Compiled object files directory
BIN = bin            # Final binaries directory

# Object Files
CLIENT_OBJ = $(OBJ)/client.o $(OBJ)/udp_common.o
SERVER_OBJ = $(OBJ)/server.o $(OBJ)/server_state.o $(OBJ)/udp_common.o

# Default Target: Build everything
all: dirs client server

# Create output directories if not present
dirs:
	mkdir -p $(OBJ) $(BIN)

#  Build Client Executable
client: $(CLIENT_OBJ)
	$(CC) -o $(BIN)/client $(CLIENT_OBJ)

#  Build Server Executable
server: $(SERVER_OBJ)
	$(CC) -o $(BIN)/server $(SERVER_OBJ)

# Compile Client Source File
$(OBJ)/client.o: $(SRC)/client.c inc/udp_common.h
	$(CC) $(CFLAGS) -c $(SRC)/client.c -o $@

# Compile Server Source File
$(OBJ)/server.o: $(SRC)/server.c inc/udp_common.h inc/server_state.h
	$(CC) $(CFLAGS) -c $(SRC)/server.c -o $@

#  Compile Server State Machine Logic
$(OBJ)/server_state.o: $(SRC)/server_state.c inc/server_state.h
	$(CC) $(CFLAGS) -c $(SRC)/server_state.c -o $@

# Compile UDP Common Networking Functions
$(OBJ)/udp_common.o: $(SRC)/udp_common.c inc/udp_common.h
	$(CC) $(CFLAGS) -c $(SRC)/udp_common.c -o $@

#  Clean All Build Artifacts
clean:
	rm -rf $(OBJ) $(BIN)
