#include <stdio.h>

int is_valid(int val)
{
    char buf[16];
    int hasDouble = 0, valid = 1;
    int i, len;

    len = sprintf(buf, "%d", val);

    for(i = 1; i < len; i++)
    {
        if(buf[i] < buf[i-1])
        {
            valid = 0;
            break;
        }
        if(buf[i-1] == buf[i])
        {
            hasDouble = 1;
        }
    }
    return (valid && hasDouble);
}

int part1(int start, int end)
{
    int sum = 0;
    int i;
    for(i = start; i <= end; i++)
    {
        if(is_valid(i))
        {
            sum++;
        }
    }
    return sum;
}


int main(int argc, char* argv[])
{
    int start, end, status;
    if(argc != 3)
    {
        fprintf(stderr, "%s takes 2 arguments. Start & End numbers\n", argv[0]);
        return -1;
    }

    status =  sscanf(argv[1], "%d", &start);
    status += sscanf(argv[2], "%d", &end);
    if(status != 2)
    {
        fprintf(stderr, "%s requires 2 numbers as input\n", argv[0]);
        return -1;
    }

    int result = part1(start, end);
    printf("%d\n", result);
    return 0;
}
