// Advent of code helper functions
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int readFile(const char* name, char* buf)
{
    int size;
    FILE* fp = fopen(name, "r");

    fseek(fp, 0, SEEK_END); // Go to end of file
    size = ftell(fp) + 1;   // How big is this file anyway?
    fseek(fp, 0, SEEK_SET); // Rewind file

    buf = malloc(size);
    while(!feof(fp))
    {
       *buf++ = fgetc(fp);
    }
    return size;
}
