all:VectorClass

CC=g++
CPPFLAGS=-Wall  

VectorClass:main.o VectorClass.o
	$(CC) $(LDFLAGS) -o $@ $^

VectorClass.o:VectorClass.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^
main.o:Main.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm VectorClass.o main.o VectorClass
