BigNumber: BigNumber.o
	gcc BigNumber.o -lm -o BigNumber

BigNumber.o: BigNumber.c
	gcc -c BigNumber.c -lm -o BigNumber.o

clean:
	rm *.o BigNumber
