#include <stdio.h>
//---- Call by Value -----
// void test(int x)
// {
//     x = 100;
// }

// int main()
// {
//     int a = 50;
//     test(a);
//     printf("Our required number is :%d", a);
//     return 0;
// }

// --- Call by Reference ----
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;
    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("After swapping we get :%d , %d ", a, b);
    return 0;
}
