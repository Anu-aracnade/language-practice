#include <stdio.h>
int main()
{
    char name[30];
    int age;
    int uid;
    int mark;
    printf("Hello student !\n\n");
    printf("Please enter your first name : ");
    scanf("%s", &name);
    printf("Please enter your age : ");
    scanf("%d", &age);
    printf("Please enter your UID : ");
    scanf("%d", &uid);
    printf("Please enter your marks : ");
    scanf("%d", &mark);

    printf("\n\n*******THE STUDENT'S DETAILS*********\n\n");
    printf("The student's first name is : %s\n The student's age is : %d\n  The student's UID is : %d\n The student's marks is : %d\n", name, age, uid, mark);
    
    return 0;
}