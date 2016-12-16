main: main.o print_str.o get_name.o
	gcc main.o -o main get_name.o print_str.o 
	rm *.o
main.o: main.c
	gcc -c main.c
get_name.o: get_name.c
	gcc -c get_name.c
print_str.o: print_str.c
	gcc -c print_str.c
clean:
	rm *.o
