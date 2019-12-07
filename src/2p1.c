#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tryInstance(int noun, int verb);
int main()
{
    int result = tryInstance(12, 2);
    printf("Output is %d\n", result);
    return 0;
}

int tryInstance(int noun, int verb)
{
    int sz = 1, i = 0;
    int ip = 0, ax, bx, cx;
    int opcode = 0;
    FILE *fp = fopen("2.txt", "r");
    char in;
    int *memory;
    int ret = 0;

    // Count number of instances of , (indicating the number of memory locations
    while(!feof(fp))
    {
        in = fgetc(fp);
        if (in == ',')
            sz++;
    }

    // Malloc() a buffer of int's
    memory = malloc((sz * sizeof(int)) + 4);
    rewind(fp);
    // Populate memory
    for(i = 0; i < (sz - 1); i++)
    {
        fscanf(fp, "%d,", &memory[i]);
    }
    fscanf(fp, "%d", &memory[sz-1]);
    fclose(fp);

    // Patch the program
    memory[1] = noun;
    memory[2] = verb;
    // Start running the processor
    while(opcode != 99)
    {
        opcode = memory[ip];
        ax = memory[ip + 1];
        bx = memory[ip + 2];
        cx = memory[ip + 3];
        switch(opcode)
        {
            case 1:
                memory[cx] = memory[ax] + memory[bx];
                ip += 4;
                break;
            case 2:
                memory[cx] = memory[ax] * memory[bx];
                ip += 4;
                break;
            case 99:
                break;
            default:
                printf("Halted! OP=%d\t 0=%d\n", opcode, memory[0]);
                opcode = 99;
                break;
        }
    }
    ret = memory[0];
    free(memory);
    return ret;
}
