#include <stdio.h>
#include "common/helper.h"
#include <stdlib.h>

int main()
{
    char *buf;
    int bufsz = readFile("3.txt", buf);
    free(buf);
    return 0;
}
