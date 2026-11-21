
#include <iostream>
#include <limits>
#include "functions.h"

int main()
{
    int n;

    std::cout << "STUDENT PERFORMANCE - LEVEL B\n\n";

    n = InputInteger("Enter number of students (1-100): ", 1, 100);

    Student* students = CreateStudents(n);

    if (students == nullptr)
    {
        std::cout << "Memory allocation error.\n";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "\nStudent " << i + 1 << ":\n";
        InputStudent(students[i]);
    }

    PrintStudents(students, n);

    std::cout << "\nNumber of grade 3 in Physics: "
        << CountGrade(students, n, Physics) << '\n';

    std::cout << "Number of grade 3 in Mathematics: "
        << CountGrade(students, n, Mathematics) << '\n';

    std::cout << "Number of grade 3 in the third subject: "
        << CountGrade(students, n, ThirdSubject) << '\n';

    std::cout << "\nStudents with grades 4 or 5 in Physics and Mathematics:\n";

    int count = PrintGoodStudents(students, n);

    if (count == 0)
        std::cout << "No students found.\n";

    delete[] students;

    return 0;
}
