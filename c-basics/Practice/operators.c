# include <stdio.h>
int main ()
{
//Arithmetic operators
int a = 1,b = 2;
printf("The sum of the two numbers is %d\n",a+b);
printf("The remainder of the two numbers is %d\n",b%a);
printf("The size of the int is %d\n",sizeof(int));
printf("The increament of the first number is %d\n",++a);

//Relational operators
int c = 1 , d = 2;
printf("%d\n",c!=d);
printf("%d\n",c<d);
printf("%d\n",c==d);
printf("%d\n",c>d);

//Logical Operators
int h = 0 , j = 1;
printf("The logical operator returned %d\n",h&&j);
printf("The logical operator returned %d\n",h||j);
printf("The logical operator returned %d\n",!j); 
printf("The logical operator returned %d\n",!h); 

//Bitwise Operators 
/*Example : 
A = 00111100
B = 00001101
R = 00001100*/

int A = 60, B = 14;
printf("Bitwise and operator returned %d\n",A&B);
printf("Bitwise or operator returned %d\n",A|B);
printf("Bitwise xor operator returned %d\n",A^B);
printf("Bitwise ones complement operator returned %d\n",~B);
printf("Bitwise left shift operator returned %d\n",A<<B);
printf("Bitwise right shift operator returned %d\n",A>>B);


// Assignment Operators 
// =,+=,-=,*=,%=,etc
int ha = 9;
ha += 9;
printf("ha is %d\n",ha);


// Misc Operators :- & , * , ?:

return 0;
}
