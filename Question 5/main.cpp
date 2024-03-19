#include "student.h"
#include <iostream>

int main() {
    Student s1("Alice", 20);
    Student s2("Bob", 19);

    std::cout << "Combined names: " << (s1 + s2) << std::endl;
    
    if (s1 < s2) {
        std::cout << s1.getName() << " is younger than " << s2.getName() << std::endl;
    } else {
        std::cout << s2.getName() << " is younger than " << s1.getName() << std::endl;
    }

    Student students[] = {s1, s2};
    std::cout << "Youngest student: " << getYoungestStudent(students, 2) << std::endl;

    return 0;
}
