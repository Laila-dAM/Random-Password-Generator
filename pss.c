#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX_LENGTH 100

void generatePassword (int length, int includeUppercase, int includeLowercase, int includeNumbers, int includeSpecialChars) {

    const char upperChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     const char lowercaseChars[] = "abcdefghijklmnopqrstuvwxyz";
    const char numberChars[] = "0123456789";
    const char specialChars[] = "!@#$%^&*()-_+=";

srand((unsigned int)time(NULL));

if(!(includeUppercase || includeLowercase || includeNumbers || includeSpecialChars)) {
    printf("Select at least one type of character.\n");
    return;
}

int totalChars = 0;
if (includeUppercase) totalChars += sizeof(upperChars) - 1;
if (includeLowercase) totalChars += sizeof(lowercaseChars) - 1;
if (includeNumbers) totalChars += sizeof(numberChars) - 1;
if (includeSpecialChars) totalChars += sizeof(specialChars) - 1;
}