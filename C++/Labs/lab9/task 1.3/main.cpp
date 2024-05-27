#include <iostream>
#include <cstring>
#include "macros.h"

class studentData 
{
private:
    unsigned int studentCard;
    char* surname;
    int* marks;
    // Посилання на об'єкт класу "Група"
    // group *groupPtr;

public:
    studentData() : studentCard(0), surname(nullptr), marks(nullptr) {}
    studentData(unsigned int card, const char* name, const int* marks) : studentCard(card) 
    {
        surname = new char[MAX_NAME_LENGTH];
        strcpy(surname, name);

        this->marks = new int[MAX_MARKS];
        for (int i = 0; i < MAX_MARKS; ++i) 
        {
            this->marks[i] = marks[i];
        }
    }
    // Конструктор копіювання
    studentData(const studentData& other) : studentCard(other.studentCard) 
    {
        surname = new char[MAX_NAME_LENGTH];
        strcpy(surname, other.surname);

        marks = new int[MAX_MARKS];
        for (int i = 0; i < MAX_MARKS; ++i) 
        {
            marks[i] = other.marks[i];
        }
    }
    ~studentData() 
    {
        delete[] surname;
        delete[] marks;
    }
    studentData& operator=(const studentData& other) 
    {
        if (this == &other) 
        {
            return *this;
        }

        studentCard = other.studentCard;

        delete[] surname;
        surname = new char[MAX_NAME_LENGTH];
        strcpy(surname, other.surname);

        delete[] marks;
        marks = new int[MAX_MARKS];
        for (int i = 0; i < MAX_MARKS; ++i) 
        {
            marks[i] = other.marks[i];
        }

        return *this;
    }

    unsigned int getStudentCard() const { return studentCard; }
    const char* getSurname() const { return surname; }
    const int* getMarks() const { return marks; }

    void setStudentCard(unsigned int card) { studentCard = card; }
    void setSurname(const char* name) {
        delete[] surname;
        surname = new char[MAX_NAME_LENGTH];
        strcpy(surname, name);
    }
    void setMarks(const int* marks) 
    {
        delete[] this->marks;
        this->marks = new int[MAX_MARKS];
        for (int i = 0; i < MAX_MARKS; ++i) 
        {
            this->marks[i] = marks[i];
        }
    }
};

// Оператор виведення
std::ostream& operator<<(std::ostream& os, const studentData& student) 
{
    os << "Номер студентського квитка: " << student.getStudentCard() << std::endl;
    os << "Прізвище: " << student.getSurname() << std::endl;
    os << "Оцінки: ";
    const int* marks = student.getMarks();
    for (int i = 0; i < MAX_MARKS; ++i) 
    {
        os << marks[i] << " ";
    }
    os << std::endl;
    return os;
}

// Клас "Група"
// Клас "Група"
class Group 
{
private:
    int index;
    studentData* students[MAX_STUDENTS];
    int numStudents;

public:
    Group() : index(0), numStudents(0) {}
    Group(int idx) : index(idx), numStudents(0) {}
    ~Group() 
    {
        for (int i = 0; i < numStudents; ++i) 
        {
            delete students[i];
        }
    }

    // Метод для отримання кількості студентів у групі
    int getNumStudents() const { return numStudents; }

    // Метод для отримання студента за певним індексом
    studentData* getStudent(int index) const 
    {
        if (index >= 0 && index < numStudents) 
        {
            return students[index];
        } 
        else 
        {
            return nullptr;
        }
    }

    void addStudent(studentData* student) 
    {
        if (numStudents < MAX_STUDENTS) 
        {
            students[numStudents++] = student;
        } else {
            std::cout << "Максимальна кількість студентів в групі досягнута." << std::endl;
        }
    }

    // Реалізуйте інші методи, зазначені у завданні, за необхідності
};


int main() 
{
    // Створення групи
    Group group(1);

    // Додавання студентів до групи
    group.addStudent(new studentData(1, "Ковальовa", new int[MAX_MARKS]{80, 75, 60, 85, 95}));
    group.addStudent(new studentData(2, "Петрушенкa", new int[MAX_MARKS]{70, 95, 60, 75, 80}));
    // Додавання інших студентів...

    // Виведення інформації про студентів
    for (int i = 0; i < group.getNumStudents(); ++i) 
    {
        std::cout << *(group.getStudent(i)) << std::endl;
    }

    return 0;
}

