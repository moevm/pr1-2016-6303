hello: main.o get_name.o print_str.o
	gcc  main.o get_name.o print_str.o -o hello
main.o: main.c get_name.h print_str.h
	gcc -c -o main.o main.c
get_name.o: get_name.c
	gcc -c -o  get_name.o get_name.c
print_str.o: print_str.c
	gcc  -c -o  print_str.o print_str.c
