#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

all: find generate

# old `find` version
# find: find.c helpers.c helpers.h
# 	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm

# generate: generate.c
# 	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c 

find: find.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -I /usr/local/include -L /usr/local/lib -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c -I /usr/local/include -L /usr/local/lib -lcs50

clean:
	rm -f *.o a.out core find generate