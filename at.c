#include "at.h"
#include <stdio.h>
#include <stdlib.h>

int at_parse(char ch)
{


static int stare = 0;

switch (stare)
{
    case 0:
        if(ch==13)
        stare = 1;
        break;

    case 1:
        if(ch==12)
        stare = 2;
        break;

    case 2:
        switch(ch)
        {
            case '+':
                stare = 30;
            break;

            case 'O':
                stare = 40;
            break;


            case 'E':
                stare = 50;
            break;
        }
        break;

    case 50:
            if(ch==82)
            stare = 51;
        break;

    case 51:
            if(ch==82)
            stare = 52;
        break;

    case 52:
            if(ch==79)
            stare = 53;
        break;

    case 53:
            if(ch==82)
            stare = 54;
        break;

    case 54:
            if(ch==13)
            stare = 6;
        break;

    case 6:
            if(ch==12)
            stare = 7;
        break;

}


}