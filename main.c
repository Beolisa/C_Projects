#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNAME "log.txt"
#define MAXLENGTH 5000

char fileStr[MAXLENGTH];

// Prototypes
int fileToStr(char* str);
int countNews(char mainStr[], char subStr[]);
int tokenizeStr(char mainStr[], char *tokens[]);
void FilterStr(char *tokens[], char subStr[], int leng);

int main() {
    // Save details into a string
    int status = fileToStr(fileStr);

    // Question 1: Count the number of messages containing specific keywords
    char requiredChar[] = "\"cmd\":\"set\"";
    int nCount = countNews(fileStr, requiredChar);
    //printf("The number of messages containing the keyword \"%s\": %d\n", requiredChar, nCount);

    // Question 2: Find and store strings that match the substring
    char *tokens[MAXLENGTH]; // Array to store tokens

    //Tokenize the string into an array
    int leng = tokenizeStr(fileStr, tokens);

    // printf("\nTokens:\n");
    // for (int i = 0; i < leng; i++) {
    //     printf("Token %d: %s\n", i + 1, tokens[i]);
    // }
    FilterStr(tokens, requiredChar, leng);

    return 0;
}

int fileToStr(char* str) {
    FILE* fp = fopen(FNAME, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return -1;
    }

    int status = fread(str, sizeof(char), MAXLENGTH, fp);
    fclose(fp);
    
    return status;
}

int countNews(char mainStr[], char subStr[]) {
    int count = 0;
    char *pCount = strstr(mainStr, subStr);

    while (pCount != NULL) {
        count++;
        pCount = strstr(pCount + strlen(subStr), subStr);
    }

    return count;
}

int tokenizeStr(char mainStr[], char *tokens[]) { //Tokenizing the string to arrays
    char *token = strtok(mainStr, "\n");
    int i = 0;

    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, "\n");
    }

    return i;
}

void FilterStr(char *tokens[], char subStr[], int leng) {
    int i = 0;
    char *ptrStr = strstr(tokens[i], subStr);
    
    char *tempArr[MAXLENGTH]; //Array of pointers to store filtered tokens


}