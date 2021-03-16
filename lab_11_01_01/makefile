CC = gcc
INCPATH = ./inc/
SRCPATH = ./src/
OUTPATH = ./out/
UPATH =./unit_tests/
UCFLAGS =-std=c99 -I$(INCPATH)
CFLAGS =-std=c99 -I$(INCPATH) -Wall -Werror -pedantic
LFLAGS =--coverage
.PHONY : clean dir release debug
.NOTPARALLEL: release debug

release: CFLAGS+= -o2
release: $(OUTPATH)release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OUTPATH)debug.lastbuildstate app.exe

app.exe: $(OUTPATH)main.o $(OUTPATH)my_snprintf.o
	$(CC) $(LFLAGS) -ggdb -o $@ $^

U_INCS = $(UPATH)check_my_snprintf.c
U_OBJS = $(OUTPATH)check_main.o $(OUTPATH)my_snprintf.o
	
unit_tests.exe: $(U_OBJS) $(U_INCS) | dir
	$(CC) $(LFLAGS) -I$(INCPATH) -o $@ $(U_OBJS) -lcheck

$(OUTPATH)%.o: $(UPATH)%.c | dir
	$(CC) $(UCFLAGS) -c $^ -o $@

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

dir:
	mkdir -p $(OUTPATH)	

clean :
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o
	rm -fv $(OUTPATH)*.gcno
	rm -fv $(OUTPATH)*.gcda
	touch $(OUTPATH)*.lastbuildstate

