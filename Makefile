OBJS = *.cpp
CC = g++
INCLUDE_PATHS = -L.
OBJ_NAME = "LoggerTest"
COMPILER_FLAGS =  -Wall -std=c++17

make : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(OBJS) $(INCLUDE_PATHS) -o $(OBJ_NAME)
	

