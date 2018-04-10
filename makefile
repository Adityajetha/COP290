IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)
GTKFLAG = `pkg-config gtkmm-3.0 --cflags --libs`

ODIR=obj
LDIR =../lib

LIBS=-lm -glut 

_DEPS = main.h myarea.h myarea1.h three2.h two3.h vertex.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = helloworld.o main.o myarea.o myarea1.o three2.o two3.o vertex.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(GTKFLAG) $(LIBS)


hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(GTKFLAG) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

