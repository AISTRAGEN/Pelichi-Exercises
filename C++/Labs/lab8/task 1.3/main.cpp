#include <iostream>
#include <cstring>
#include "macros.h"

struct studentData 
{
    unsigned int studentCard;
    char surname[MAX_NAME_LENGTH];
    int mark[MAX_MARKS];
};

void outputData(studentData data);

void sortStudentsByAverageMark(studentData* students[], int numStudents) 
{
    std::cout << "Сортування студентів за збільшенням середнього балу" << std::endl;

    
    float averageMarks[MAX_STUDENTS];

    
    for (int i = 0; i < numStudents; ++i) 
    {
        int sum = 0;
        for (int j = 0; j < MAX_MARKS; ++j) 
        {
            sum += students[i]->mark[j];
        }
        averageMarks[i] = static_cast<float>(sum) / MAX_MARKS;
    }

   
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) 
        {
            if (averageMarks[j] > averageMarks[j + 1]) 
            {
                std::swap(students[j], students[j + 1]);
                std::swap(averageMarks[j], averageMarks[j + 1]);
            }
        }
    }
}

void printStudentsEndingA(studentData* students[], int numStudents) 
{
    std::cout << "Студенти з прізвищами, що закінчуються на 'а':" << std::endl;
    for (int i = 0; i < numStudents; ++i) 
    {
        int len = strlen(students[i]->surname);
        if (students[i]->surname[len - 1] == 'a' || students[i]->surname[len - 1] == 'A')
        {
            outputData(*(students[i]));
        }
    }
}

void printAllStudents(studentData* students[], int numStudents) 
{
    std::cout << "Всі студенти, прізвище яких не закінчується на 'а':\n";
    for (int i = 0; i < numStudents; ++i) 
    {
        int len = strlen(students[i]->surname);
        if (students[i]->surname[len - 1] != 'a' && students[i]->surname[len - 1] != 'A')
        {
            outputData(*(students[i]));
        }
    }
}

void outputData(studentData data) 
{
    std::cout << "Номер студентської картки: " << data.studentCard << std::endl;
    std::cout << "Прізвище: " << data.surname << std::endl;
    std::cout << "Оцінки: ";
    for (int i = 0; i < MAX_MARKS; ++i) 
    {
        std::cout << data.mark[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{

    studentData Students[]=
    {
        {1, "Ковальовa", {80, 75, 60, 85, 95}},
        {2, "Петрушенкa", {70, 95, 60, 75, 80}},
        {3, "Скуфенко", {90, 85, 80, 95, 70}},
        {4, "Коваленченкович", {93, 80, 80, 100, 60}},
        {5, "Маркарян", {100, 95, 70, 95, 90}},
        {6, "Сорвиголовa", {60, 70, 70, 100, 60}}
    }; 

    int numStudents = sizeof(Students) / sizeof(Students[0]); 

    studentData* studentsPtrs[numStudents];
    for (int i = 0; i < numStudents; ++i) 
    {
        studentsPtrs[i] = &Students[i];
    }

    sortStudentsByAverageMark(studentsPtrs, numStudents);

   
    printStudentsEndingA(studentsPtrs, numStudents);

    
    printAllStudents(studentsPtrs, numStudents);

    return 0;

}
