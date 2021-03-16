CC = gcc
INCPATH = ./inc/
SRCPATH = ./src/
OBJPATH = ./obj/
UPATH = ./unit_tests/
CFLAGS =-std=c99 -I$(INCPATH) -Wall -Werror -pedantic
LFLAGS =--coverage
LIBFLAGS = -shared $^ -Wl,--subsystem,windows
.PHONY : clean dir release debug func
.NOTPARALLEL: release debug

release: CFLAGS+= -o2
release: $(OBJPATH)release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OBJPATH)debug.lastbuildstate app.exe
	
arr.dll: $(OBJPATH)arr.o | dir
	$(CC) $(LIBFLAGS) -o $@

app.exe: arr.dll $(OBJPATH)main.o 
	$(CC) $(OBJPATH)main.o -L. -larr -o app.exe
	
objs = arr.dll $(OBJPATH)check_main.o	
	
unit_tests.exe: $(objs) unit_tests/check_arr.c | dir
	$(CC) $(LFLAGS) -I$(INCPATH) -o $@ $(objs) -lcheck
	
$(OBJPATH)arr.o: $(SRCPATH)arr.c 
	$(CC) $(CFLAGS) -D ARR_EXPORTS -c $< -o $@
	
$(OBJPATH)check_%.o: $(UPATH)check_%.c | dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH)%.o: $(SRCPATH)%.c | dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH)release.lastbuildstate: | dir
	rm -rf *.exe $(OBJPATH)*.o $(OBJPATH)debug.lastbuildstate
	touch $(OBJPATH)release.lastbuildstate

$(OBJPATH)debug.lastbuildstate: | dir
	rm -rf *.exe $(OBJPATH)*.o $(OBJPATH)release.lastbuildstate
	touch $(OBJPATH)debug.lastbuildstate
	
unit: unit_tests.exe
	./unit_tests.exe

dir:
	mkdir -p $(OBJPATH)	
	
python: arr.dll
	python $(SRCPATH)main.py

clean :
	rm -fv *.exe
	rm -fv $(LIBPATH)*.a $(LIBPATH)*.so $(LIBPATH)*.dll 
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	touch $(OBJPATH)*.lastbuildstate

