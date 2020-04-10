#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *file;
    char buf[1002];

    file = fopen("e.txt", "r");

    if(file) {
        fscanf(file, "%s", buf);
    } else {
        printf("File loading went wrong!");
    }

    printf("%s\n", buf);

    // Get a 10-digit part of e, starting at index 2
    char slice[12];
    sprintf(slice, "%.10s\n", buf+2);

    printf("slice: %s\n", slice);
    char *ptr;
    long candidate;
    
    candidate = strtol(slice, &ptr, 10);
    printf("candidate: %lu\n", candidate);

    fclose(file);
    return 0;
}