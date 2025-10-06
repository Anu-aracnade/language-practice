#include <stdio.h>
void goodMorning();
void goodAfternoon();
void goodEvening();
int main()
{
    int a;
    goodMorning();
    goodAfternoon();
    goodEvening();

    return 0;
}

void goodMorning()
{
    printf("Good morning !\n");
}
void goodAfternoon()
{
    printf("Good afternoon !\n");
}
void goodEvening() { printf("Good evening !\n"); }