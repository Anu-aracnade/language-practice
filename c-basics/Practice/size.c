# include <stdio.h>
int main ()
{
int a = 5;
unsigned short integer = 6;
long interger1 = 5;
short interger2 = 8;

double myfloat1 = 9.99;
long double myfloat2 = 8.9999997;
char c = 'h';


printf ("The size taken by int is %d bytes\n",sizeof(int));
printf ("The size taken by unsigned short int is %d bytes\n",sizeof(unsigned short int));
printf ("The size taken by float is %d bytes\n",sizeof(float));
printf ("The size taken by double is %d bytes\n",sizeof(double));
printf ("The size taken by long double is %d bytes\n",sizeof(long double));
printf ("The size taken by char is %d bytes\n",sizeof(char));
printf ("The size taken by short int is %d bytes\n",sizeof(short));

return 0;
}