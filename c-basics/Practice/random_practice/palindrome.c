#include <stdio.h>
const char * isPalindrome(int x){
    if (x<0||x%10==0&&x!=0)
    {return "Nope! It's not a Palindrome";}
    else{
        int rev=0;
        while(x>rev){
            rev=(rev*10)+x%10;
            x=x/10;
        }
        if (x==rev||x==rev/10){
            return "Yup! It's a Palindrome";
        }
        else {
            return "Nope! It's not a Palindrome";
        }
    }
}
int main (){
    int n;
    printf("Enter your number: ");
    scanf("%d",&n);
    isPalindrome(n);
    printf("%s\n",isPalindrome(n));
    return 0;
}