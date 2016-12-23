main: main.o print_str.o get_name.o 
	gcc main.o print_str.o get_name.o -o main 
main.o: main.c print_str.h get_name.h 
	gcc -c main.c 
get_name.o: get_name.c get_name.h 
	gcc -c get_name.c 
print_name.o: print_str.c print_str.h
	gcc -c print_name.c
