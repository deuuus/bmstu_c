CC = gcc
INCPATH = ./inc/
SRCPATH = ./src/
OBJPATH = ./obj/
FUNCPATH =./func_tests/
UPATH =./unit_tests/
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

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

libarr.a: $(OBJPATH)stat_arr.o | dir
	ar cr $@ $^
	
arr.dll: $(OBJPATH)dyn_arr.o | dir
	$(CC) $(LIBFLAGS) -o $@

static_build: $(OBJPATH)stat_main.o libarr.a
	$(CC) $(LFLAGS) -o app.exe $^
	
dyn_load_build: arr.dll $(OBJPATH)dyn_load_main.o
	$(CC) -o app.exe $^
	
dyn_compose_build: arr.dll $(OBJPATH)dyn_compose_main.o 
	$(CC) $(OBJPATH)dyn_compose_main.o -L. -larr -o app.exe

app.exe: $(OBJPATH)stat_main.o $(OBJPATH)stat_arr.o
	$(CC) $(LFLAGS) -o $@ $^
	
objs =	$(OBJPATH)check_main.o $(OBJPATH)stat_arr.o
	
unit_tests.exe: $(objs) unit_tests/check_arr.c | dir
	$(CC) $(LFLAGS) -I$(INCPATH) -o $@ $(objs) -lcheck
	
$(OBJPATH)dyn_arr.o: $(SRCPATH)dyn_arr.c 
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
	rm -fv $(OBJPATH)*.o
	./unit_tests.exe
	
func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCPATH) && cmd /C all_test.cmd
	@echo
	gcov -n $(OBJPATH)stat_main.c
	gcov -n $(OBJPATH)stat_arr.c

dir:
	mkdir -p $(OBJPATH)	
	

clean :
	rm -fv *.exe
	rm -fv $(LIBPATH)*.a $(LIBPATH)*.so $(LIBPATH)*.dll 
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	touch $(OBJPATH)*.lastbuildstate

