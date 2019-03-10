PROG = main
CC = g++
FLAGS = -Wall -O2
OBJS1 = main.cpp
OBJS2 = main.o

${PROG} : ${OBJS1}
	${CC} -c ${OBJS1}
	${CC} ${FLAGS} -o ${PROG} ${OBJS2}

clean:
	rm -f core ${PROG} ${OBJS2}
