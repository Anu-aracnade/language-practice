#include <stdio.h>

int maximumWealth(int accounts[][100], int accountsSize, int accountsColSize)
{
    int maxWealth = 0;

    for (int i = 0; i < accountsSize; i++)
    {
        int sum = 0;
        for (int j = 0; j < accountsColSize; j++)
        {
            sum += accounts[i][j];
        }
        if (sum > maxWealth)
        {
            maxWealth = sum;
        }
    }
    return maxWealth;
}

int main()
{
    int accountsSize, accountsColSize;

    printf("Enter the number of persons: ");
    scanf("%d", &accountsSize);

    printf("Enter the number of bank accounts per person: ");
    scanf("%d", &accountsColSize);

    int accounts[accountsSize][100];  

    for (int i = 0; i < accountsSize; i++)
    {
        printf("Enter money for Person %d:\n", i + 1);
        for (int j = 0; j < accountsColSize; j++)
        {
            printf("  Bank %d: ", j + 1);
            scanf("%d", &accounts[i][j]);
        }
    }

    int result = maximumWealth(accounts, accountsSize, accountsColSize);
    printf("Maximum wealth is: %d\n", result);

    return 0;
}
