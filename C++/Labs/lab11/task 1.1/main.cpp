#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Student 
{
private:
    unsigned int studentCard;
    std::string surname;
    std::vector<int> marks;

public:
    Student() : studentCard(0) {}
    Student(unsigned int card, const std::string& name, const std::vector<int>& marks) : studentCard(card), surname(name), marks(marks) {}

    unsigned int getStudentCard() const { return studentCard; }
    const std::string& getSurname() const { return surname; }
    const std::vector<int>& getMarks() const { return marks; }

    void setStudentCard(unsigned int card) { studentCard = card; }
    void setSurname(const std::string& name) { surname = name; }
    void setMarks(const std::vector<int>& marks) { this->marks = marks; }

    
    double computeSortMetric() const 
    {
       
        double sum = 0.0;
        for (int mark : marks) 
        {
            sum += mark;
        }
        return sum / marks.size();
    }

    bool checkCondition() const 
    {
        
        for (int mark : marks) 
        {
            if (mark < 60) 
            {
                return false;
            }
        }
        return true;
    }

    bool operator<(const Student& other) const 
    {
        return computeSortMetric() < other.computeSortMetric();
    }
};

// Overload for printing student info
std::ostream& operator<<(std::ostream& os, const Student& student) 
{
    os << "Student Card Number: " << student.getStudentCard() << std::endl;
    os << "Surname: " << student.getSurname() << std::endl;
    os << "Marks: ";
    for (int mark : student.getMarks()) 
    {
        os << mark << " ";
    }
    os << std::endl;
    return os;
}

class Group 
{
private:
    std::vector<Student> students;

public:
    
    void addStudent(const Student& student) 
    {
        students.push_back(student);
    }

   
    void sortByMetric() 
    {
        std::sort(students.begin(), students.end());
    }

    void findStudentsByCondition() 
    {
        for (const Student& student : students) 
        {
            if (student.checkCondition()) 
            {
                std::cout << "Student passed all subjects: " << student.getSurname() << std::endl;
            }
        }
    }

    void prioritizeByAverageMark() 
    {
        std::priority_queue<Student> pq(students.begin(), students.end());
        while (!pq.empty()) 
        {
            std::cout << pq.top().getSurname() << " - Average Mark: " << pq.top().computeSortMetric() << std::endl;
            pq.pop();
        }
    }
};

int main() 
{
    Group group;

    group.addStudent(Student(1, "Kovalova", {80, 75, 60, 85, 95}));
    group.addStudent(Student(2, "Petrushenko", {70, 95, 60, 75, 80}));

   
    group.sortByMetric();
    group.findStudentsByCondition();
    group.prioritizeByAverageMark();

    return 0;
}
