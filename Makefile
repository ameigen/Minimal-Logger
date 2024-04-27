
OBJS = ./src/*.cpp
CC = g++
INCLUDE_PATHS = -I./lib/
OBJ_NAME = "LoggerTest"
COMPILER_FLAGS =  -Wall -std=c++17

make : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(OBJS) $(INCLUDE_PATHS) -o $(OBJ_NAME) -v

	

