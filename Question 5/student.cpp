#include "student.h"
#include <algorithm>

Student::Student() : name(""), age(0) {}

Student::Student(const std::string& name, int age) : name(name), age(age) {}

Student::Student(const Student& other) : name(other.name), age(other.age) {}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

std::string Student::operator+(const Student& other) const {
    return name + " " + other.name;
}

bool Student::operator<(const Student& other) const {
    return age < other.age;
}

std::string getYoungestStudent(Student students[], int size) {
    if (size == 0) {
        return "";
    }

    Student youngest = students[0];
    for (int i = 1; i < size; i++) {
        if (students[i] < youngest) {
            youngest = students[i];
        }
    }

    return youngest.getName();
}
