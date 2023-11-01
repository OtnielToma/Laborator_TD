#include <stdio.h>
#include <stdlib.h>
#include "at.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <test_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening test file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        int result = at_parse(ch);
    printf(" %c %d ",ch, ch);
    if (result == 1) {
        printf("Ready OK.\n");
    } else if (result == 2) {
        printf("Syntax ERROR.\n");
    } else if (result == 0){
        printf("Not ready yet.\n");
    }
    }

    fclose(file);

    return 0;
}
