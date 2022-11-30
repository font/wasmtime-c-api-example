CFLAGS=-I.
LDFLAGS=-ldl
WARNING_OPTIONS="-Wimplicit-function-declaration"
DEPS = handler.h
OBJ = main.o wasmtime.o

%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS) $(WARNING_OPTIONS)

cwasi: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(WARNING_OPTIONS) $(LDFLAGS)
