CC = gcc
INCPATH = ./inc/
SRCPATH = ./src/
OUTPATH = ./out/
FUNCPATH =./func_tests/
UPATH =./unit_tests/
CFLAGS =-std=c99 -I$(INCPATH) -Wall -Werror -pedantic
LFLAGS =--coverage
.PHONY : clean dir release debug func
.NOTPARALLEL: release debug

release: CFLAGS+= -o2
release: $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OUTPATH)debug.lastbuildstate app.exe

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

OBJS = $(OUTPATH)node.o $(OUTPATH)list_funcs.o
INCS = $(INCPATH)codes.h

app.exe: $(OUTPATH)main.o $(OBJS)
	$(CC) $(LFLAGS) -ggdb -o $@ $^
	
U_INCS = $(UPATH)check_node.c $(UPATH)check_list_funcs.c
U_OBJS = $(OUTPATH)check_main.o $(OUTPATH)node.o $(OUTPATH)list_funcs.o
	
unit_tests.exe: $(U_OBJS) $(U_INCS) | dir
	$(CC) $(LFLAGS) -I$(INCPATH) -o $@ $(U_OBJS) -lcheck

$(OUTPATH)%.o: $(UPATH)%.c | dir
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUTPATH)%.o: $(SRCPATH)%.c | dir
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUTPATH)release.lastbuildstate: | dir
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)debug.lastbuildstate
	touch $(OUTPATH)release.lastbuildstate

$(OUTPATH)debug.lastbuildstate: | dir
	rm -rf *.exe $(OUTPATH)*.o $(OUTPATH)release.lastbuildstate
	touch $(OUTPATH)debug.lastbuildstate
	
unit: unit_tests.exe | dir
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	touch $(OUTPATH)*.lastbuildstate
	./unit_tests.exe
	
func: $(OUTPATH)debug.lastbuildstate app.exe
	@echo
	cd $(FUNCPATH) && cmd /C all_test.cmd
	@echo
	gcov -n $(OUTPATH)main.c
	gcov -n $(OUTPATH)node.c
	gcov -n $(OUTPATH)list_funcs.c
	

dir:
	mkdir -p $(OUTPATH)	

clean :
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	touch $(OUTPATH)*.lastbuildstate

