#include <iostream>
#include <vector>
#include <string>


class Human 
{
protected:
    std::string name;
    int age;
public:
    Human(std::string _name, int _age) : name(_name), age(_age) {}
    virtual void display() 
    {
        std::cout << "Ім'я: " << name << ", Вік: " << age;
    }
};


class Citizen : public Human 
{
protected:
    std::string nationality;
public:
    Citizen(std::string _name, int _age, std::string _nationality) : Human(_name, _age), nationality(_nationality) {}
    void display() override 
    {
        Human::display();
        std::cout << ", Національність: " << nationality;
    }
};


class Student : public Human 
{
protected:
    std::string university;
public:
    Student(std::string _name, int _age, std::string _university) : Human(_name, _age), university(_university) {}
    void display() override 
    {
        Human::display();
        std::cout << ", Університет: " << university;
    }
};


class Employee : public Human 
{
protected:
    std::string company;
public:
    Employee(std::string _name, int _age, std::string _company) : Human(_name, _age), company(_company) {}
    void display() override 
    {
        Human::display();
        std::cout << ", Компанія: " << company;
    }
};

int main() 
{
    std::vector<Human*> objects;

    objects.push_back(new Human("Іван", 30));
    objects.push_back(new Citizen("Марія", 25, "Українська"));
    objects.push_back(new Student("Олексій", 22, "Харківський Політехнічний Інститут"));
    objects.push_back(new Employee("Наталія", 35, "Dolby"));

    for (Human* obj : objects) 
    {
        obj->display();
        std::cout << std::endl;
    }

    
    for (Human* obj : objects) 
    {
        delete obj;
    }

    return 0;
}
