main: main.o get_name.o print_str.o
	gcc main.o get_name.o print_str.o -o main
main.o: main.c get_name.h print_str.h
	gcc -c main.c
get_name.o: get_name.c
	gcc -c get_name.c
print_str.o: print_str.c
	gcc -c print_str.c
clear:
	rm *.o
