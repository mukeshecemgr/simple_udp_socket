CC= gcc
CFLAGS=-I. -I/usr/local/include

objs: prep main.o client.o server.o

vpath %.o ./obj

OBJ_DIR=/obj

run: $(OBJ_DIR)/*.o
	$(CC) $(CFLAGS) -o $@ $^ 


all: run

prep:
	if [ ! -d ${OBJ_DIR} ] ; then \
	   mkdir ${OBJ_DIR} ;\
	fi 

main.o:main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ_DIR)/$@
client.o:client.c
	$(CC) $(CFLAGS) -c client.c -o $(OBJ_DIR)/$@
server.o:server.c
	$(CC) $(CFLAGS) -c server.c -o $(OBJ_DIR)/$@
	
clean:
	rm -f $(OBJ_DIR)/*.o run
