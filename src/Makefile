AROPTS  := -rv
#CCOPTS  := -Wall -Werror -g -DDEBUG
CCOPTS  := -Wall -Werror -g
CLIBS   := -lm
OBJECTS := mul_int_string.o mul_digit_string.o add_digit_strings.o string_wrap.o
SLIB    := ./stringnum.a
VERSION := 0.0.1

all: stringnum.a libstringnum.so run_test

run_test: test_mul_digit_string test_add_digit_strings test_mul_int_string

test: test_mul_int_string test_add_digit_strings test_mul_digit_string $(SLIB)

test_mul_int_string: test_mul_int_string.c
test_add_digit_strings: test_add_digit_strings.c
test_mul_digit_string: test_mul_digit_string.c

%: %.c
	$(CC) $(CCOPTS) -o $@ $^ $(SLIB) $(CLIBS)

%.o: %.c
	$(CC) -c $(CCOPTS) -o $@ $^

stringnum.a: $(OBJECTS)
	$(AR) $(AROPTS) $@ $^
libstringnum.so.$(VERSION): $(OBJECTS)
	$(CC) $(CCOPTS) -shared -o $@ $^
libstringnum.so:  libstringnum.so.$(VERSION)
	ln -fs $^ $@

clean:
	/bin/rm -f *.o test_add_digit_strings test_mul_digit_string test_mul_int_string stringnum.a libstringnum.so.$(VERSION) libstringnum.so

