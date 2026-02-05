#include <iostream>
using namespace std;
class Employee{
    public:
    string name;
    int id;
    float basicSalary;
    float grossSalary;
    void calculategrossSalary(){
        float hra,da;
        hra=0.10*basicSalary;
        da=0.05*basicSalary;
        grossSalary=basicSalary+hra+da;
        cout<<"The Gross salary of the Employee is : "<<grossSalary<<endl;
    }
    void display(){
        cout<<"The name of the Employee : "<<name<<endl;
        cout<<"The id of the Employee : "<<id<<endl;
        cout<<"The basic salary of the Employee is : "<<basicSalary<<endl;
           
    }
}emp;
int main(){
    emp.name="Anubhab";
    emp.id=124242;
    emp.basicSalary=300000;
    emp.display();
    emp.calculategrossSalary(); 

    return 0;
}