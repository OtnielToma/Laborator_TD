#ifndef AT_H
#define AT_H

typedef struct {
    char command[32];
    char data[256];
} ATCommand;

int at_parse(char ch);

#endif
