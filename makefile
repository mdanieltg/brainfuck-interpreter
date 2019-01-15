CXX=gcc
RM=rm -f
CPPFLAGS=-Wall -Iinclude
LDFLAGS=

OBJS=files.o keys.o syntax_check.o main.o
EXE=bfi

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS)

main.o: main.c syntax_check.o files.o
	$(CXX) -c $(CPPFLAGS) main.c

syntax_check.o: source/syntax_check.c include/syntax_check.h keys.o
	$(CXX) -c $(CPPFLAGS) source/syntax_check.c

keys.o: source/keys.c include/keys.h
	$(CXX) -c $(CPPFLAGS) source/keys.c

files.o: source/files.c include/files.h
	$(CXX) -c $(CPPFLAGS) source/files.c

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(EXE)
