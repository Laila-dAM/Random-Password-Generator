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

char password[MAX_LENGTH];
int index;


for (int i=0; i<length; i++) {
    int charType = rand() % totalChars;
    const char *chars;
    int arraySize;

    if(includeUppercase && charType < sizeof(upperChars) -1) {
        chars = upperChars;
        arraySize = sizeof(upperChars) - 1;

    }
    else if (includeLowercase && charType < sizeof(lowercaseChars) -1) {
        chars = lowercaseChars;
        arraySize = sizeof(lowercaseChars) - 1;
    }

    else if (includeNumbers && charType < sizeof(numberChars) -1){
        chars = numberChars;
        arraySize = sizeof(numberChars) -1;
    }

    else {
        chars = specialChars;
        arraySize = sizeof(specialChars) -1;

    }
    index = rand() % arraySize;
    password[i] = chars[index];

}
password[length] = '\0';
printf("Generated Password: %s\n", password);
}

int main() {
    setlocale(LC_ALL,"en_US");

    int length;
    int includeUppercase, includeLowercase, includeNumbers, includeSpecialChars;

    printf("=== Random Password Generator ===\n");
    printf("Password length:");
    scanf("%d", &length);
}