
#include <iostream>
#include "functions.h"

int main()
{
    std::cout << "STUDENT PERFORMANCE - LEVEL B\n\n";

    int n = InputInteger("Enter number of students (1-100): ", 1, 100);

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

    std::cout << "Number of grade 3 in Programming: "
        << CountGrade(students, n, Programming) << '\n';

    std::cout << "Number of grade 3 in Numerical methods: "
        << CountGrade(students, n, NumericalMethods) << '\n';

    std::cout << "Number of grade 3 in Pedagogy: "
        << CountGrade(students, n, Pedagogy) << '\n';

    std::cout
        << "\nStudents with grades 4 or 5 in Physics and Mathematics:\n";

    if (CountGoodStudents(students, n) == 0)
    {
        std::cout << "No students found.\n";
    }
    else
    {
        PrintGoodStudents(students, n);
    }

    delete[] students;

    return 0;
}
