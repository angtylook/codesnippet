DEPS = csapp.h csapp.c
DEPS_SRC = csapp.c
INC = -I.
LIBS = -lpthread
CC = gcc-6
kill : kill.c $(DEPS)
	$(CC) $(INC) $(LIBS) -o kill kill.c $(DEPS_SRC)
snooze : snooze.c $(DEPS)
	$(CC) $(INC) $(LIBS) -o $@ snooze.c  $(DEPS_SRC)
statcheck : statcheck.c $(DEPS)
	$(CC) $(INC) $(LIBS) -o $@ statcheck.c  $(DEPS_SRC)
readdir : readdir.c $(DEPS)
	$(CC) $(INC) $(LIBS) -o $@ readdir.c  $(DEPS_SRC)
hostinfo : hostinfo.c $(DEPS)
	$(CC) $(INC) $(LIBS) -o $@ hostinfo.c  $(DEPS_SRC)
tiny : tiny.c $(DEPS)
	$(CC) $(INC) $(LIBS) -o $@ tiny.c  $(DEPS_SRC)
.PHONY:
clean:
	rm kill snooze statcheck readdir hostinfo tiny