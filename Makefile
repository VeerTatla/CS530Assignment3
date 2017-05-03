CC = g++
CFLAGS = -g
LDFLAGS = -lm

parser : main.o Parser.o Grammar.o
	${CC} ${CFLAGS} main.o Parser.o Grammar.o ${LDFLAGS} -o parser

Parser.o : Parser.cpp
	${CC} ${CFLAGS} -c Parser.cpp

Grammar.o : Grammar.cpp 
	${CC} ${CFLAGS} -c Grammar.cpp
	
main.o : main.cpp
	${CC} ${CFLAGS} -c main.cpp

clean: 
	rm -f parser *.o
