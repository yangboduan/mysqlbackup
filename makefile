CC       = g++
OBJ      = mysqlbackup.o 
LINKOBJ  = mysqlbackup.o
BIN      = mysqlback
RM       = rm -f



$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) 
clean: 
	${RM} $(OBJ) $(BIN)


