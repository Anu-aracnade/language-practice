#include <stdio.h>
int main()
{
    int a;
    printf("Enter the registered number of the day from (1-7)\n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("The day is Sunday\n");
        break;
    case 2:
        printf("The day is Monday\n");
        break;
    case 3:
        printf("The day is Tuesday\n");
        break;
    case 4:
        printf("The day is Wednesday\n");
        break;
    case 5:
        printf("The day is Thursday\n");
        break;
    case 6:
        printf("The day is Friday\n");
        break;
    case 7:
        printf("The day is Saturday\n");
        break;
    default:
        printf("The day is Invalid day\n");
    }
    return 0;
}