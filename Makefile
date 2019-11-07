# IMS project
# @author Juraj Holub <xholub40@stud.fit.vutbr.cz>
# @date 2019

CC = g++
CFLAGS = -I -g -O2 -lsimlib -lm
OBJ = main.o \
	  monthly_energy_flow.o \
	  solar_energy_source.o \
	  statistics.o \
	  year_cycle.o \
	  argument_parser.o
EXECUTABLE = ims-project

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp %.h
	$(CC) -c $< $(CFLAGS)

.PHONY: pack clean
pack:
	cp doc/manual.pdf . && tar -czvf xholub40.tar *.cpp *.h Makefile README manual.pdf

clean:
	rm -rf *.o *.out $(EXECUTABLE)
