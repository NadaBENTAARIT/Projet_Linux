PROG_NAME=interface_acceuil
CC=gcc
CFLAGS=`pkg-config --cflags gtk+-3.0`
LIBS=`pkg-config --libs gtk+-3.0`
${PROG_NAME}: ${PROG_NAME}.c
    ${CC} ${CFLAGS} -o ${PROG_NAME} ${PROG_NAME}.c ${LIBS}

clean:
          rm ${PROG_NAME}
