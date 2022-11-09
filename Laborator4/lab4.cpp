#include<iostream>

using namespace std;

class Person{

    std::string firstName;
    std::string lastName;
    int age;

    public:
    Person(const std::string& firstName, const std::string& lastName, int age);
    void show();
};

Person::Person(const std::string& firstName, const std::string& lastName, const int age):
    firstName(firstName),
    lastName(lastName),
    age(age)
    {}

void Person::show(){
    cout<<firstName<<" "<<lastName<<" age: "<<age;
}
int main(){

    Person ana("Ana", "Popescu", 23);
    ana.show();

    cin.get();
    return 0;

}
