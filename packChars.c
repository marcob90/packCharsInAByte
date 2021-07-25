/* Copyright (C) 2020 Marco B. Shafer. All rights reserved.

Read four characters from keyboard and pack them in a byte.
Unpacking function also present*/

#include <stdio.h>
#include <limits.h>

unsigned packCharacters(const char[]);
void unpackCharacters(const unsigned);
void displayBinary(const unsigned);

int main(){
	char array[4];
	unsigned pack;
	int counter;
	
	for(counter = 0; counter < 4; counter++){
		puts("Insert character:");
		array[counter] = getchar();
		getchar();
	}	
	
	for(counter = 0; counter < 4; counter++){
		displayBinary(array[counter]);
	}
	
	pack = packCharacters(array);
	displayBinary(pack);
	
	unpackCharacters(pack);
	
	return 0;
}

unsigned packCharacters(const char wArray[]){
	unsigned p = 0u;
	int i;
	
	for(i = 0; i < 4; i++){
		p |= ((unsigned)wArray[i] << (24 - 8 * i));
	}
	
	return p;
}

void unpackCharacters(const unsigned p){
	char cArray[4];
	int i;
	unsigned mask = 0xff000000U;
	
	for(i = 0; i < 4; i++){
		cArray[i] = (p & mask) >> (24 - 8 * i);
		mask >>= 8;
	}
	
	for(i = 0; i < 4; i++){
		displayBinary(cArray[i]);
	}
}

void displayBinary(const unsigned n){
	unsigned mask = 1 << CHAR_BIT * sizeof(unsigned) - 1;
	int c; //counter
	
	printf("%u = ", n);
	
	for(c = 1; c <= CHAR_BIT * sizeof(unsigned); c++){
		putchar(n & mask ? '1' : '0');
		mask >>= 1;
		
		if(c % 8 == 0)
			putchar(' ');
	}
	putchar('\n');
}
