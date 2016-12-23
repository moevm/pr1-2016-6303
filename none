EXECUTABLE_NAME=lab1_kulikov

all: program clean_obj

program_clean: program clean_obj

program: main.o get_name.o print_str.o
	gcc main.o get_name.o print_str.o -o $(EXECUTABLE_NAME)

main.o: main.c
	gcc -c main.c

get_name.o: get_name.c
	gcc -c get_name.c

print_str.o: print_str.c
	gcc -c print_str.c

clean_obj:
	rm -rf *.o

clean:
	rm -rf *.o $(EXECUTABLE_NAME)
