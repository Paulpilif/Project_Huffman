#include "fileConverter.h"

void converteTextToBinary(char* fileName) {

    FILE* frptr;
    FILE* fwptr;

    frptr = fopen(fileName, "r");
    fwptr = fopen("Output.txt", "w");

    if (frptr == NULL || fwptr == NULL) {
        printf("Error opening the file");
        exit(1);
    }

    char* binaryChar;
    binaryChar = (char *) malloc(8 * sizeof(char));

    char currentChar;

    while ((currentChar = fgetc(frptr)) != EOF) {
        binaryChar = converteCharToBinary(currentChar);

        fprintf(fwptr, "%s", binaryChar);
    }

    fclose(frptr);
    fclose(fwptr);

    return;
}

char* converteCharToBinary(char c){

    char* binaryString;
    int bin;

    binaryString = (char *) malloc(8 * sizeof(char));

    for (int i = 0; i < 8; i++) {
		bin = ((c << i) & 0x80) ? 1 : 0;
		binaryString[i] = bin+'0';
	}
    
    return binaryString;
}

int numberCharacterInFile(char* fileName) {

    int counter = 0;
    FILE* fptr;

    fptr = fopen(fileName, "r");

    if (fptr == NULL) {
        printf("Error opening th file");
        exit(1);
    }

    char currentChar;

    while ((currentChar = fgetc(fptr)) != EOF) {
        counter ++;
    }

    fclose(fptr);

    return counter;
}