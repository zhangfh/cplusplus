all:FileReader

CC=g++
CPPFLAGS=-Wall  

FileReader:main.o FileReader.o
	$(CC) $(LDFLAGS) -o $@ $^

FileReader.o:FileReader.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^
main.o:Main.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm FileReader.o main.o FileReader
