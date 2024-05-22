#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FNAME "log.txt"
#define MAXLENGF 5000

char fileStr[MAXLENGF];

void fileToStr(char* str);

int main()
{

    fileToStr(fileStr);
    return 0;
}

void fileToStr(char* str) {
    FILE* fp = NULL;

    fp = fopen(FNAME, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return;
    }

    fread(str, MAXLENGF, 1, fp);

    printf("File details: \n%s", str);

    fclose(fp);
    fp = NULL;
}


