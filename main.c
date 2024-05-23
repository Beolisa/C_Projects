#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNAME "log.txt"
#define MAXLENGTH 5000

char fileStr[MAXLENGTH];

// Prototypes
int fileToStr(char* str);
int countNews(char mainStr[], char subStr[]);
void matchStr(char json[], char* tokens[], char subStr[]);
void TokenizeStr(char json[], char* tokens[]);

int main() {
    // Save details into a string
    int status = fileToStr(fileStr);

    // Question 1: Count the number of messages containing specific keywords
    char requiredChar[] = "\"cmd\":\"set\"";
    // int nCount = countNews(fileStr, requiredChar);
    // printf("The number of messages containing the keyword \"%s\": %d\n", requiredChar, nCount);

    // Question 2: Find and store strings that match the substring
    char *tokens[MAXLENGTH]; // Array to store tokens

    // Tokenize the string into an array based on newline delimiter
    TokenizeStr(fileStr, tokens);

    matchStr(fileStr, tokens, requiredChar);

    // printf("\nStrings matching the keyword \"%s\":\n", requiredChar);
    // for (int i = 0; tokens[i] != NULL; i++) {
    //     printf("Token %d: %s\n", i+1, tokens[i]);
    // }

    
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

void matchStr(char json[], char* tokens[], char subStr[]) {
    int i = 0;
    char *ptrStr = strstr(tokens[i], subStr);


    while (ptrStr != NULL) {
        tokens[i] = ptrStr;
        printf("%s \n", tokens[i]);
        i++;
        // ptrStr = strstr(ptrStr + 1, subStr);
    }
}

void TokenizeStr(char json[], char* tokens[]) {
    char *token = strtok(json, "\n");
    int i = 0;

    // Tokenizing the string into an array based on newline delimiter
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, "\n");
    }

    tokens[i] = NULL; // Mark the end of tokens with NULL
}