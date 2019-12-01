all: myBanks mains

main.o: main.c
	gcc -Wall -fPIC -c main.c

myBank.o: myBank.c myBank.h
	gcc -Wall -fPIC -c myBank.c

myBanks: myBank.o myBank.h
	ar -rcs libmybank.a myBank.o

mains: main.o myBanks
	gcc -Wall -fPIC -o mains main.o libmybank.a

clean:
	rm -f *.o *.a mains 



