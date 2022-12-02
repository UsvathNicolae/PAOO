#include<iostream>

using namespace std;

enum car_type{
    pickup,
    van,
    wagon,
    sedan,
    coupe,
    hatchback
};

const std::string types[] ={"pickup","van", "wagon", "sedan", "coupe", "hatchback"};

class Car{
    std::string model;
    car_type type;
    std::string fabricationDate;

    public:
    Car(const std::string& model, car_type type, const std::string& fabricationDate);
    Car& operator=(const Car& car);
    void show();
    string toString();
};

 Car::Car(const std::string& model, car_type type, const std::string& fabricationDate):
    model(model),
    type(type),
    fabricationDate(fabricationDate){}

Car &Car::operator=(const Car& car){
    if(this == &car) return *this;

    model = car.model;
    type = car.type;
    fabricationDate = car.fabricationDate;

    return *this;
}


void Car::show(){
    cout<<model<<" type: "<<types[type]<<" made on"<<fabricationDate;
}

string Car::toString(){
    return model + types[type] + " made on " + fabricationDate;
}

class Person{

    std::string firstName;
    std::string lastName;
    int age;
    Car *car;

    public:
    Person(const std::string& firstName, const std::string& lastName, int age, const std::string& model, car_type type, const std::string& fabricationDate);
    Person(const Person& person);
    Person& operator=(const Person& person);
    void show();
    std::string toString();
};

Person::Person(const Person& person):
firstName(person.firstName),
lastName(person.lastName),
age(person.age),
car(person.car)
{}

Person::Person(const std::string& firstName, const std::string& lastName, const int age, const std::string& model, car_type type, const std::string& fabricationDate):
    firstName(firstName),
    lastName(lastName),
    age(age),
    car(new Car(model, type, fabricationDate))
    {}
    

void Person::show(){
    cout<<firstName<<" "<<lastName<<" age: "<<age<<", owns a "<< car->toString();
}

std::string Person::toString(){
    return firstName + " " + lastName + " age: " +  to_string(age) + ", owns a " + car->toString();
}

Person &Person::operator=(const Person& person){
    if(this == &person) 
        return *this;

    firstName = person.firstName;
    lastName = person.lastName;
    age = person.age;

    Car *OriginalCar = car;
    car = new Car(*person.car);
    delete OriginalCar;

    return *this;
}

class Employee:public Person{
private:
    std::string position;
public:
    Employee(Person person, const std::string& position);
    Employee& operator=(const Employee& employee);
    void show();
};

Employee::Employee(Person person, const std::string& position):
    Person(person),
    position(position)
{}

Employee& Employee::operator=(const Employee& employee){
    if(this == &employee)
        return *this;
    
    Person::operator=(employee);

    position = employee.position;

    return *this;
}

void Employee::show(){
    cout<<"Employee "<<Person::toString()<<" works as "<< position;
}

int main(){

    Person ana("Ana", "Popescu", 23, "Golf4", car_type::hatchback, "10-06-2000");
    Person ana2 = ana;
    ana.show();
    cout<<"\n";
    ana2.show();
    cout<<"\n";
    Employee employee1 = Employee(ana, "casier");
    Employee employee2 = employee1;
    employee1.show();
    cout<<"\n";
    employee2.show();
    cout<<"\n";


    return 0;
}