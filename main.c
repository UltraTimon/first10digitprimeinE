#include <stdio.h>

#define NR_OF_DIGITS 1002 // length of the file

int main () {
    int c;
    FILE *file;
    file = fopen("e.txt", "r");
    char buffer[NR_OF_DIGITS];

    if(file) {
        fscanf(file, "%s", buffer);
    } else {
        printf("File loading went wrong!");
    }

    // int i = 0;
    // while(i < NR_OF_DIGITS) {
    //     printf(buffer[i]);
    // }
    // printf("\n");

    printf("%s\n", buffer);

    fclose(file);
    return 0;
}