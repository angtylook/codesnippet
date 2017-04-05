DEPS = csapp.h csapp.c
DEPS_SRC = csapp.c
INC = -I.
LIBS = -lpthread
kill : kill.c $(DEPS)
	gcc $(INC) $(LIBS) -o kill kill.c $(DEPS_SRC)
snooze : snooze.c $(DEPS)
	gcc $(INC) $(LIBS) -o $@ snooze.c  $(DEPS_SRC)
statcheck : statcheck.c $(DEPS)
	gcc $(INC) $(LIBS) -o $@ statcheck.c  $(DEPS_SRC)
readdir : readdir.c $(DEPS)
	gcc $(INC) $(LIBS) -o $@ readdir.c  $(DEPS_SRC)
hostinfo : hostinfo.c $(DEPS)
	gcc $(INC) $(LIBS) -o $@ hostinfo.c  $(DEPS_SRC)
#.PHONY
clean:
	rm kill snooze statcheck readdir hostinfo