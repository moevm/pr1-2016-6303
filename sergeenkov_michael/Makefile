
sergeenkov_lr1: main.o print_str.o get_name.o
	gcc  main.o print_str.o get_name.o -o sergeenkov_lr1

main.o: main.c print_str.h get_name.h
	gcc -c main.c

print_str.o: print_str.c
	gcc -c print_str.c

get_name.o: get_name.c
	gcc -c get_name.c

clean:
	rm  *.o sergeenkov_lr1

