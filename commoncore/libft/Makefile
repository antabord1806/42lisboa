# Definindo o compilador
CC = gcc

# Definindo as flags de compilação
CFLAGS = -Wall

# Definindo os arquivos objeto
OBJ = main.o isalpha.o isdigit.o isalnum.o

# Nome do executável final
EXEC = programa

# Regra principal para compilar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Regra para compilar o arquivo main.c
main.o: main.c libft.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar o arquivo isalpha.c
isalpha.o: isalpha.c libft.h
	$(CC) $(CFLAGS) -c isalpha.c

# Regra para compilar o arquivo isdigit.c
isdigit.o: isdigit.c libft.h
	$(CC) $(CFLAGS) -c isdigit.c

# Regra para compilar o arquivo isalnum_custom.c
isalnum.o: isalnum.c libft.h
	$(CC) $(CFLAGS) -c isalnum.c

# Limpeza dos arquivos objeto e executáveis
clean:
	rm -f *.o $(EXEC)
