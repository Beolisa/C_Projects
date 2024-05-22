#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNAME "log.txt"
#define MAXLENGF 5000

char fileStr[MAXLENGF];

//Protocals
int fileToStr(char* str);
int countNews(char mainStr[], char subStr[]);
void FilterStr(char userInputStr, char tokens[]);

int main()
{
    //Save details into a string
    int status = fileToStr(fileStr);
    
    //Question 1: Count the number of messages was sent
    // char requiredChar[] = "\"cmd\":\"set\"";
    // int nCount = countNews(fileStr, requiredChar);

    // printf("The amount of news being sent was: %i", nCount);

    //Question 2: Find a user's input
    char *tokens[MAXLENGF] = {0};  // Array to store tokens


    char breakLine[] = "\n";

    int countLines = countNews(fileStr,breakLine);

    FilterStr(fileStr, countLines, tokens);

    char userInputChar[MAXLENGF];
    


    printf("Enter the network address: ");
    scanf("%s", &userInputChar);

    return 0;
}

int fileToStr(char* str) { //Check the file availability and readability
    int status = 0;
    FILE* fp = NULL;

    fp = fopen(FNAME, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return -1;
    }

    status = fread(str, sizeof(char), MAXLENGF, fp);

    // printf("File details: \n%s", str);

    fclose(fp);
    fp = NULL;

    return status;
}

int countNews(char mainStr[], char subStr[]) { //Count the amount of news being sent with specific keywords
    int count = 0;
    char *pCount = strstr(mainStr, subStr);

    while (pCount != NULL) {
        count++;
        pCount = strstr(pCount + 1, subStr);
    }

    return count;
}

void FilterStr(char json[], int amount, char* tokens[]) {
    char *token = strtok(tokens, "\n");
    
    //Tokening the string into an array
    for (int i = 0; token != NULL; i++) {
        token = strtok(NULL, "\n");
    }

    //Count strings that contain cmd:set
    char temp[MAXLENGF];

    for (int i = 0; i < amount; i++) {
        if (strstr()) {

        }
    }

}



