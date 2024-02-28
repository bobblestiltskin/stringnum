CCOPTS := -I/usr/include/lua5.4
STRINGNUM := ../stringnum.a
CLIBS := -shared -fPIC -llua5.4 ../stringnum.a

all: $(STRINGNUM) mylib.so

$(STRINGNUM):
	make -C .. stringnum.a

mylib.so: main.c
	$(CC) $(CCOPTS) -o $@ $^ $(CLIBS)

clean:
	rm -f mylib.so
