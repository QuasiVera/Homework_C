# если в clean не срабатывает del попробовать: rm -rf *.o prog

all: sens_prog

sens_prog: sens_main.o sens_func.o
	gcc -o sens_prog sens_main.o sens_func.o

sense_main.o: sens_main.c sens_func.h
	gcc -c -o sens_main.o sens_main.c -I./sens_func.h

sens_func.o: sens_func.c
	gcc -c -o sens_func.o sens_func.c

clean:
	del *.o						
	del sens_prog.exe