#include "at.h"
#include <stdio.h>

static int stare = 0;
static int state = 0;
static int k = 0;

int at_parse(char ch) {
    switch (stare) {
        case 0:
            if (ch == 13) {
                stare = 1;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 1:
            if (ch == 10) {
                stare = 2;
            } else {
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
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 29:
            if(ch == 'K')
            {
                k = 1;
                stare = 41;
            }
            else
                        stare = 31;
            break;



        case 30:
             if(ch != '+')
            stare = 31;
        break;

        case 31:
            if (ch == 13) {
                stare = 32;
            } else if (ch != 13) {
           // printf("   %c   ", ch);
                stare = 30;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 32:
            if (ch == 10) {
                stare = 33;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 33:

                    if (ch == 'O') {
                       stare = 40;
                   } else if (ch == 'E') {
                       stare = 50;
                   } else
                   if (ch == '+') {
                       stare = 30;
                   } else if(ch==13)
                        stare = 34;
                   else
                   {
                       state = 2;
                       stare = 7;
                   }
                   break;

        case 34:
            if (ch == 10) {
                stare = 35;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 35:
            if (ch == 'O') {
                //printf(" ESTE O ");
                stare = 40;
            } else
             if (ch == 'E') {
                stare = 50;
            } else {
                //printf(" NU ESTE O ");
                state = 2;
                stare = 7;
            }
            break;

        case 36:
            if (ch == 'K') {
                k = 1;
                stare = 37;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 37:
            if (ch == 13) {
                stare = 6;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 40:
            if (ch == 'K') {
               // printf(" ESTE K ");
                k = 1;
                stare = 41;
            } else {
            //printf(" NU ESTE K ");
                state = 2;
                stare = 7;
            }
            break;

        case 41:
            if (ch == 13) {
                stare = 6;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 50:
            if (ch == 'R') {
                stare = 51;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 51:
            if (ch == 'R') {
                stare = 52;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 52:
            if (ch == 'O') {
                stare = 53;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 53:
            if (ch == 'R') {
                k = 3;
                stare = 54;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 54:
            if (ch == 13) {
                stare = 6;
            } else {
                state = 2;
                stare = 7;
            }
            break;

        case 6:
            if (ch == 10) {
                state = k;
                stare = 7;

            } else {
                state = 2;
            }
            break;

        case 7:
            if (state != 2 && ch == 13) {
                stare = 1;
                state = 0;
                k = 0;
            }
            else
            stare = 0;
            break;
    }

    return state;
}
