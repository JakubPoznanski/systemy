DIR = `basename $(CURDIR)`

NAME1 = main
NAME2 = producent
NAME3 = konsument
NAME4 = semLib
NAME5 = memoryLib
LIB1 = semLib
LIB2 = memoryLib
PLIK_WE = zasoby
PLIK_WY = skopiowane

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o

LIBS1  = $(LIB1).cpp
LIBS2  = $(LIB2).cpp


CFLAGS = -Wall -O -pthread
LFLAGS = -Wall -O -pthread
LDLIBS = -lrt

CO = g++
LD = $(CO)

AR = ar

ARFLAGS = rsv

%.o: %.cpp %.h
	$(CO) $(CFLAGS) -c $<
%.o: %.cpp
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) 

$(EXEC1): $(OBJS1) $(LIBS1) $(LIBS2)
	$(LD) -o $@ $(CFLAGS) $^ $(LDLIBS)

$(EXEC2): $(OBJS2) $(LIBS1) $(LIBS2)
	$(LD) -o $@ $(CFLAGS) $^ $(LDLIBS)

$(EXEC3): $(OBJS3) $(LIBS1) $(LIBS2)
	$(LD) -o $@ $(CFLAGS) $^ $(LDLIBS)

.PHONY: run7

run7: $(EXEC1) $(EXEC2) $(EXEC3)
	./$(EXEC1) $(EXEC2) $(EXEC3)
	@echo "\n=============================\n"
	@diff -s $(PLIK_WE) $(PLIK_WY)
.PHONY: clean tar

clean:
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )