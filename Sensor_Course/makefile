# если в clean не срабатывает del попробовать: rm -rf *.o prog

all: sens_prog

sens_prog: main.o temp_api.o
	gcc -o sens_prog main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c -I./temp_api.h

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	del *.o						
	del sens_prog.exe