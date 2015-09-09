CC = gcc
CFLAGS = -I. -lpthread
OBJ = getTasking.o  prepareToSendTasking.o  taskmgr.o  utils.o processTasking.o  sendMessage.o queue.o comms.o encrypt.o
DEPS = utils.h queue.h
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

myCamera: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean
clean: 
	rm  myCamera $(OBJ)
