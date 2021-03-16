CC = gcc
INCPATH = ./inc/
SRCPATH = ./src/
OBJPATH = ./obj/
FUNCPATH =./func_tests/
UPATH =./unit_tests/
CFLAGS =-std=c99 -I$(INCPATH) -Wall -Werror -pedantic
LFLAGS =--coverage
.PHONY : clean dir release debug func
.NOTPARALLEL: release debug

release: CFLAGS+= -o2
release: $(OBJPATH)release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OBJPATH)debug.lastbuildstate app.exe

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

app.exe: $(OBJPATH)main.o $(OBJPATH)key.o $(OBJPATH)sort.o
	$(CC) $(LFLAGS) -o $@ $^
	
objs =	$(OBJPATH)check_main.o $(OBJPATH)sort.o $(OBJPATH)key.o	
	
unit_tests.exe: $(objs) unit_tests/check_sort.c unit_tests/check_key.c | dir
	$(CC) $(LFLAGS) -I$(INCPATH) -o $@ $(objs) -lcheck

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
	
func: $(OBJPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCPATH) && cmd /C all_test.cmd
	@echo
	gcov -n $(OBJPATH)main.c
	gcov -n $(OBJPATH)sort.c
	gcov -n $(OBJPATH)key.c

dir:
	mkdir -p $(OBJPATH)	

clean :
	rm -fv *.exe
	rm -fv $(OBJPATH)*.o
	rm -fv $(OBJPATH)*.gcno
	rm -fv $(OBJPATH)*.gcda
	touch $(OBJPATH)*.lastbuildstate

