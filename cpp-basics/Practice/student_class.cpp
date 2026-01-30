#include <iostream>
using namespace std;
class student {
    public:
    string name;
    int age;
    char grade;
    void displayfucn(){
    cout<< "The name of the student : "<< name<< endl ;
    cout<< "The age of the student : "<< age<< endl;
    cout << "The grade of the student : "<< grade<<endl;
}
}s1,s2;
int main(){
    s1.name="Anubhab";
    s1.age=19;
    s1.grade='B';
    s2.name="Rohak";
    s2.age=18;
    s2.grade='A';
    s1.displayfucn();
    cout<<"\n";
    s2.displayfucn(); 
    return 0;
} 
