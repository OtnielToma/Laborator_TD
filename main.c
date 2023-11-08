#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "at.h"

#define MAX_RESPONSE_LINES 100
#define MAX_LINE_LENGTH 4096

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <test_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening test file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];
    int command_length = 0;
    int row = 1;

    char response_lines[MAX_RESPONSE_LINES][MAX_LINE_LENGTH];
    int response_rows[MAX_RESPONSE_LINES];
    int response_count = 0;

    int result;

    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i] != '\0') {
            int ch = line[i];
            result = at_parse(ch);

            printf("Command %d     ", row);
            if (ch != 13 && ch != 10)
                printf("%c ", ch);
            if (ch == 13 || ch == 10)
                printf("  ");
            if (result == 1) {
               printf("Ready OK.\n");
                } else if (result == 3) {
                   printf("Ready ERROR.\n");
                } else if (result == 2) {
                   printf("Syntax ERROR.\n");
                } else if (result == 0) {
                   printf("Not ready yet.\n");
                }

            if (ch == '\n') {
                row++;
                if (command_length > 0) {
                    if (result == 1 || result == 3) {
                        strcpy(response_lines[response_count], command);
                        response_rows[response_count] = row;
                        response_count++;
                    }
                    memset(command, 0, sizeof(command));
                    command_length = 0;
                }
            } else {
                command[command_length++] = ch;
            }

            i++;
        }
    }

    fclose(file);

    printf("\n");
    for (int i = 0; i < response_count; i++) {
        printf("Command %d: %s\n", response_rows[i], response_lines[i]);
    }

    return 0;
}


