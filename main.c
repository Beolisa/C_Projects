#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FNAME "log.txt"
#define MAXLENGF 5000

char fileStr[MAXLENGF];

int fileToStr(char* str);

int main()
{

    fileToStr(fileStr);
    return 0;
}

int fileToStr(char* str) {
    int status;
    FILE* fp = NULL;

    fp = fopen(FNAME, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return -1;
    }
    status = fread(str, MAXLENGF, 1, fp);

    printf("Noi dung cua file log.txt: \n%s", str);

    fclose(fp);
    fp = NULL;
    return status;
}


