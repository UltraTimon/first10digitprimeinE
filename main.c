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


    int maxLoop = 1002 - 10 - 1; // the amount of loops that can be done with 1002 chars
    char slice[12]; // placeholder to hold the relevant chars that will be converted to a long, which then will be checked on being prime or not
    char *ptr; // return value for sprintf
    long candidate; // variable that holds potential prime number. The sieve will be called on this number.

    // loop over the digits of E, getting them in slices of 10
    for (int i = 0; i < maxLoop; i++)
    {
        sprintf(slice, "%.10s\n", buf + 2 + i); // get a slice of 10 digits from the file (from where we left off)
        candidate = strtol(slice, &ptr, 10); // convert this slice to a long
        // printf("candidate %d: %ld\n", i, candidate);
        printf("Testing the following candidate on prime-ness: %ld\n", candidate);
        if(isPrime(candidate) == 1) {
            printf("THE PRIME IS: %ld\n", candidate);
            return 0;
        }
    }

    fclose(file);
    return 0;
}

// calculates whether or not the given long is prime
// returns 1 if the given long is prime, 0 if not
int isPrime (long candidate) {
    for (long i = 2; i < candidate; i++)
    {
        if(candidate % i == 0) {
            return 0;
        }
    }
    return 1;
}
