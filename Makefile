# IMS project
# @author Juraj Holub <xholub40@stud.fit.vutbr.cz>
# @date 2019

CC = g++
CFLAGS = -I -g -O2 -lsimlib -lm
OBJ = main.o \
	  statistics.o \
	  year_cycle.o \
	  argument_parser.o \
	  daily_process.o \
	  mean_intensity_of_sunlight_brno.o \
	  monthly_process.o \
	  sunlight_brno.o \
	  teoretical_incident_sunlight_brno.o

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

run:
	./$(EXECUTABLE) -years 1 -tank 200 -area 6 -degree 30
