#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int age;
public:
    Student();
    Student(const std::string& name, int age);
    Student(const Student& other);

    void setName(const std::string& name);
    void setAge(int age);

    std::string getName() const;
    int getAge() const;

    std::string operator+(const Student& other) const;
    bool operator<(const Student& other) const;
};

std::string getYoungestStudent(Student students[], int size);

#endif
