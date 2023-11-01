#include "at.h"
#include <stdio.h>

static int stare = 1;
static int state = 0;
static int k = 0;

int at_parse(char ch)
{
    switch (stare)
    {
        case 1:
            if (ch == 10) {
                stare = 2;
            }
            else
            {
                 state = 2;
                 stare = 7;
            }
            break;

        case 2:
            if (ch == '+') {
                stare = 30;
            } else if (ch == 'O') {
                stare = 40;
            } else if (ch == 'E') {
                stare = 50;
            }
            break;

        case 30:
            if (ch == 'O') {
                stare = 31;
            } else if (ch == 'E') {
                stare = 51;
            }
            break;

        case 31:
            if (ch == 'K') {
                stare = 32;
            } else {
                stare = 2;
            }
            break;

        case 32:
            if (ch == 13) {
                stare = 6;
            }
            break;

        case 40:
            if (ch == 'K') {
                k = 1;
                stare = 6;
            } else {
                stare = 2;
            }
            break;

        case 50:
            if (ch == 'R') {
                stare = 51;
            } else {
                stare = 2;
            }
            break;

        case 51:
            if (ch == 'R') {
                stare = 52;
            } else {
                stare = 2;
            }
            break;

        case 52:
            if (ch == 'O') {
                stare = 53;
            } else {
                stare = 2;
            }
            break;

        case 53:
            if (ch == 'R') {
                k = 1;
                stare = 6;
            } else {
                stare = 2;
            }
            break;

        case 6:
            if (ch == 10) {
                state = k;
                stare = 7;
            }
            else
                state = 2;
            break;

        case 7:
            stare = 0;
            break;
    }

    return state;
}
