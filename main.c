#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "at.h"


#define MAX_LINE_LENGTH 4096
#define MAX_COMMANDS 2000
#define MAX_COMMAND_LENGTH 256


int isSpecialChar(char ch) {
    return ch == 13 || ch == 10;
}

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int row;
} ExtractedCommand;


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
    int row = 1;
    ExtractedCommand extractedCommands[MAX_COMMANDS];
    int extractedCount = 0;

    char commandBuffer[MAX_COMMAND_LENGTH] = "";
    int commandBufferIndex = 0;

    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i] != '\0') {

            int ch = line[i];
            int result = at_parse(ch);

            if (!isSpecialChar(ch)) {
                printf("Command %d     %c ", row, ch);

                if (result == 1) {
                    printf("Ready OK.\n");
                } else if (result == 3) {
                    printf("Ready ERROR.\n");
                } else if (result == 2) {
                    printf("Syntax ERROR.\n");
                } else if (result == 0) {
                    printf("Not ready yet.\n");
                }
                commandBuffer[commandBufferIndex++] = ch;
            }
            else
            {

                printf("Command %d        ", row);
                if (result == 1) {
                    printf("Ready OK.\n");
                } else if (result == 3) {
                    printf("Ready ERROR.\n");
                } else if (result == 2) {
                    printf("Syntax ERROR.\n");
                } else if (result == 0) {
                    printf("Not ready yet.\n");
                }

            }


            if (ch == '\n') {
                    commandBuffer[commandBufferIndex] = '\0';
                    if (commandBufferIndex > 0) {
                        if(strcmp(commandBuffer, "OK") != 0 && strcmp(commandBuffer, "ERROR") != 0)
                        {strcpy(extractedCommands[extractedCount].command, commandBuffer);
                        extractedCommands[extractedCount].row = row;
                        extractedCount++;
                        }
                    }
                    commandBufferIndex = 0;
                row++;
            }
        i++;
        }
    }

    fclose(file);

    printf("Extracted Commands:\n");
    for (int i = 0; i < extractedCount; i++)
        printf("Command %d (Row %d): %s\n", i + 1, extractedCommands[i].row, extractedCommands[i].command);

    return 0;
}


