//Develop a C++ program that defines a user-defined exception class named InvalidAgeException . The program should accept an age value from the user and validate it to ensure that the age is within a realistic range . If the enterd age is less than 0 or greater than 120 , the program must throw an object of the custom exception calss and hadnle it appropriately using a catch block . The output should clearly display a meaningful message explaining why the input is invalid.
#include <iostream>
using namespace std;
class InvalidAgeException{
    public:
    cont char*message(){
        return "Invalid"
    }
    int age;
    cout<<"Enter age:";
    cin>>age;
    try{
        
    }
};
