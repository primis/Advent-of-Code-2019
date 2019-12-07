#include <stdio.h>
#include <stdlib.h>

int fuelComputation(int mass)
{
    return (mass/3) - 2;
}

int main()
{
    FILE* fp = fopen("1.txt", "r");
    int mass;
    int runningTotal = 0;
    while(fscanf(fp, "%d", &mass) != EOF)
    {
        runningTotal += fuelComputation(mass);
    }

    printf("%d\n", runningTotal);
    return 0;
}
