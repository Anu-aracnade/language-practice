#include <iostream>
using namespace std;
class bankAccount{
    public:
    int accountNumber;
    string accountHolderName;
    float balance;
    void withdraw(float amount){
        if(balance<amount){
            cout<<"Insufficient Balance "<<endl;
        }
        else{
        balance=balance-amount;
        cout<<"The Amount withdraw : "<<amount<<endl;}
    }
    void deposit(float amount){
        balance=balance+amount;
        cout<<"The Amount deposited : "<<amount<<endl;
    }
    void display(){
        cout<<"\n---Account Details----\n";
        cout<<"The Account Number of the customer : "<<accountNumber<<endl;
        cout<<"The Account Holder name : "<<accountHolderName<<endl;
        cout<<"Balance : "<<balance<<endl;
    }
}acc;

int main(){
    acc.accountNumber=112987987;
    acc.accountHolderName="Anubhab";
    acc.balance=50000;
    acc.display();
    acc.withdraw(1000);
    acc.deposit(500);
    return 0;
}
