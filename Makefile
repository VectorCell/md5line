PROGS = md5line

CFLAGS = -std=c99 -O3 -Wall -Werror -lcrypto -lssl -fopenmp

all : $(PROGS)

md5line : md5line.o

$(PROGS) : % : Makefile
	gcc -o $@ $(filter-out Makefile,$^) $(CFLAGS)
	rm *.d *.o

%.o : %.c Makefile
	gcc -c -MD $(CFLAGS) $*.c

test : md5line
	echo "JELLO WORLD\njello world" | ./md5line

clean :
	rm -f *.o
	rm -f $(PROGS)
	rm -f *.d

-include *.d
