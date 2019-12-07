#include <stdio.h>
#include <stdlib.h>

int fuelComputation(int mass)
{
    mass = (mass/3) - 2;
    if(mass < 1)
        return 0;

    int result = fuelComputation(mass);
    if(result < 0)
        result = 0;
    return result + mass;
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
