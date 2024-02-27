CCOPTS := -I/usr/include/lua5.4
CLIBS := -shared -fPIC -llua5.4 ../stringnum.a

all: mylib.so

mylib.so: main.c
	$(CC) $(CCOPTS) -o $@ $^ $(CLIBS)

clean:
	rm -f mylib.so
