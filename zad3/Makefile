# Jakub Poznanski
# make: all, clean, tar  
#
#=========================================================================
DIR = `basename $(CURDIR)`
#------------------------
NAME1 = zad3_a
NAME2 = zad3_b
NAME3 = zad3_c
NAME4 = sub_c
#----------------------
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
#----------------------
EXEC2 = $(NAME2)
OBJS2 = $(NAME2).o
#----------------------
EXEC3 = $(NAME3)
OBJS3 = $(NAME3).o
#----------------------
EXEC4 = $(NAME4)
OBJS4 = $(NAME4).o
#----------------------
#############################
COFLAGS = -Wall -O
LDFLAGS = -Wall -O
CO = g++
LD = $(CO)
#############################
%.o: %.cpp
	$(CO) $(COFLAGS) -c $<
#############################
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)
#############################
$(EXEC1): $(OBJS1)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC2): $(OBJS2)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC3): $(OBJS3)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
$(EXEC4): $(OBJS4)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
# uruchamianie plików 
.PHONY: a b c 
a: $(EXEC1)
	./$(EXEC1)
b: $(EXEC2)
	./$(EXEC2)
c: $(EXEC3)
	./$(EXEC3)
d: $(EXEC4)

.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)
clean:                                                     
	rm -f *.o  *~ $(EXECS)
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================