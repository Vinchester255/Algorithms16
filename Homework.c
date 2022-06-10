#include <stdio.h>
#include <stdlib.h>
#define _SIZE 27
char alfabet[_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
					   'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					   'u', 'v', 'w', 'x', 'y', 'z', ' '};

char* encrypt(char* input, int key){
	int size = (int)input[0];
	char* aEncrypt = malloc(size * sizeof(char));
	for(int i = 1, j = 1; i < size; ++i){
		for(int j = 0; j < _SIZE; ++j){
			if(input[i] == alfabet[j]){
				aEncrypt[i] = alfabet[(j + key) % _SIZE];
				break;
			}
		}
	}
	aEncrypt[0] = (char)size;
	return aEncrypt;
}

char* decrypt(char* input, int key){
	int size = (int)input[0];
	char* aDecrypt = malloc(size * sizeof(char));
	for(int i = 1, j = 1; i < size; ++i){
		for(int j = 0; j < _SIZE; ++j){
			if(input[i] == alfabet[j]){
				aDecrypt[i] = alfabet[(j - key) % _SIZE];
				break;
			}
		}
	}
	aDecrypt[0] = (char)size;
	return aDecrypt;
}

// task 2
char* encrypt2(char* input, int key){
	int size = (int)input[0];
	key += 1;
	int row = (size-1) / key;
	if((size-1) % key) row += 1;
	int sizeOld = size;
	size = (row * key) + 1;
	input = realloc(input, size * sizeof(char));
	for(int i = sizeOld; i < size; ++i){
		input[i] = '\0';
	}
	char* aEncrypt = malloc(size * sizeof(char));
	for(int i = 1, j = 1, k = 1; i < size; ++i){
		aEncrypt[i] = input[j];
		if((j + key) < size){
			j += key;
		}
		else {
			k++;
			j = k;
		}
	}
	aEncrypt[0] = (char)size;
	return aEncrypt;
}


char* decrypt2(char* input, int key){
	int size = (int)input[0];
	key += 1;
	int row = (size-1) / key;
	if((size-1) % key) row += 1;
	char* aDecrypt = malloc(size * sizeof(char));
	for(int i = 1, j = 1, k = 1; i < size; ++i){
		aDecrypt[i] = input[j];
		if((j + row) < size){
			j += row;
		}
		else {
			k++;
			j = k;
		}
	}
	aDecrypt[0] = (char)size;
	return aDecrypt;
}

void printString(char* input) {
	int size = (int)input[0];
	for(int i = 1; i < size; ++i){
		printf("%c", input[i]);
	}
	printf("\n");
}

int main() {
    int size = 2;
    char* aWords = malloc(size * sizeof(char));
    char s = getchar();
    int i = 1;
    while(s != '\n'){
		if(i == size){
    		size += 1;
			aWords = realloc(aWords, size * sizeof(char));
		}
		aWords[i] = s;
    	s = getchar();
    	i++;
	}
	aWords[0] = (char)i;
	
	printf("Input encrypt key: ");
	int key = 0;
	scanf("%d", &key);
	char *enc = encrypt(aWords, key);
	printString(enc);
	char *decr = decrypt(enc, key);
	printString(decr);
	printf("\nEncrypt by row-column permutation:\n");
	printString(aWords);
	char *enc2 = encrypt2(aWords, key);
	printString(enc2);
	char *decr2 = decrypt2(enc2, key);
	printString(decr2);
	
    return 0;
}