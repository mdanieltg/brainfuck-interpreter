CXX=gcc
RM=rm -f
CPPFLAGS=-Wall -Iinclude
LDFLAGS=

OBJS=files.o brackets.o brackets_check.o main.o
EXE=bfi.exe

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS)

main.o: main.c brackets_check.o files.o
	$(CXX) -c $(CPPFLAGS) main.c

brackets_check.o: source/brackets_check.c include/brackets_check.h brackets.o
	$(CXX) -c $(CPPFLAGS) source/brackets_check.c

brackets.o: source/brackets.c include/brackets.h
	$(CXX) -c $(CPPFLAGS) source/brackets.c

files.o: source/files.c include/files.h
	$(CXX) -c $(CPPFLAGS) source/files.c

clean:
	$(RM) $(OBJS)

clear: clean
	$(RM) $(EXE)
