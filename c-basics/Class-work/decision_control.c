#include <stdio.h>

int main() {
    int e;
    char q;
    char g;

    printf("Enter your gender (M : Male, F : Female) :-\n");
    scanf(" %c", &g);

    printf("Enter your number of years of experience in the job market :-\n");
    scanf("%d", &e);

    printf("Enter your qualification details (G : Graduation , P : Post-Graduation) :-\n");
    scanf(" %c", &q);

    if(g=='M' && e>=10 && q=='P')
        {printf("Your salary will be : ₹15000\n");}
    else if(g=='M' && e<10 && q=='P')
       { printf("Your salary will be : ₹10000\n");}
    else if(g=='M' && e>=10 && q=='G')
       { printf("Your salary will be : ₹10000\n");}
    else if(g=='M' && e<10 && q=='G')
       { printf("Your salary will be : ₹7000\n");}
    else if(g=='F' && e>=10 && q=='P')
       { printf("Your salary will be : ₹12000\n");}
    else if(g=='F' && e<10 && q=='P')
        {printf("Your salary will be : ₹9000\n");}
    else if(g=='F' && e>=10 && q=='G')
        {printf("Your salary will be : ₹10000\n");}
    else if(g=='F' && e<10 && q=='G')
       { printf("Your salary will be : ₹6000\n");}

    return 0;
}

