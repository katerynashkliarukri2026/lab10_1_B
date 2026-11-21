
#include "functions.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <new>

// Вводить ціле число в заданому діапазоні.
int InputInteger(const std::string& prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            if (value >= minValue && value <= maxValue)
                return value;

            std::cout << "Invalid value! Enter a number from "
                << minValue << " to " << maxValue << ".\n";
        }
        else
        {
            std::cout << "Invalid input! Enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Створює динамічний масив студентів.
Student* CreateStudents(int n)
{
    return new (std::nothrow) Student[n]();
}

// Повертає назву спеціальності.
std::string GetSpecialtyName(Specialty specialty)
{
    switch (specialty)
    {
    case ComputerScience:
        return "Computer Science";
    case Informatics:
        return "Informatics";
    case MathematicsEconomics:
        return "Math and Economics";
    case PhysicsInformatics:
        return "Physics and Informatics";
    case LaborTraining:
        return "Labor Training";
    default:
        return "Unknown";
    }
}

// Повертає назву третього предмета для спеціальності.
std::string GetThirdSubjectName(Specialty specialty)
{
    switch (specialty)
    {
    case ComputerScience:
        return "Programming";
    case Informatics:
        return "Numerical methods";
    default:
        return "Pedagogy";
    }
}

// Вводить дані одного студента.
void InputStudent(Student& student)
{
    std::cout << "Enter surname: ";
    std::cin >> student.surname;

    student.course = InputInteger("Enter course (1-6): ", 1, 6);

    student.specialty = static_cast<Specialty>(
        InputInteger("Specialty (0-4): ", 0, 4));

    student.physics = InputInteger("Enter Physics grade (2-5): ", 2, 5);
    student.mathematics = InputInteger(
        "Enter Mathematics grade (2-5): ", 2, 5);

    int grade = InputInteger(
        "Enter " + GetThirdSubjectName(student.specialty) +
        " grade (2-5): ", 2, 5);

    switch (student.specialty)
    {
    case ComputerScience:
        student.thirdGrade.programming = grade;
        break;
    case Informatics:
        student.thirdGrade.numericalMethods = grade;
        break;
    default:
        student.thirdGrade.pedagogy = grade;
        break;
    }
}

// Повертає оцінку студента з указаного предмета.
// Для третього предмета враховує спеціальність студента.
int GetGrade(const Student& student, Subject subject)
{
    switch (subject)
    {
    case Physics:
        return student.physics;
    case Mathematics:
        return student.mathematics;
    case Programming:
        return student.specialty == ComputerScience
            ? student.thirdGrade.programming : 0;
    case NumericalMethods:
        return student.specialty == Informatics
            ? student.thirdGrade.numericalMethods : 0;
    case Pedagogy:
        return student.specialty != ComputerScience &&
            student.specialty != Informatics
            ? student.thirdGrade.pedagogy : 0;
    default:
        return 0;
    }
}

// Виводить таблицю з дев'ятьма стовпцями.
void PrintStudents(const Student students[], int n)
{
    const int widths[] = { 5, 16, 8, 25, 9, 12, 14, 18, 12 };
    const int columns = 9;

    auto printLine = [&]()
        {
            std::cout << '|';
            for (int i = 0; i < columns; i++)
                std::cout << std::string(widths[i] + 2, '-') << '|';
            std::cout << '\n';
        };

    auto printRow = [&](const std::string values[])
        {
            std::cout << '|';
            for (int i = 0; i < columns; i++)
            {
                std::string value = values[i];

                if (value.length() > static_cast<size_t>(widths[i]))
                    value = value.substr(0, widths[i]);

                std::cout << ' ' << std::left
                    << std::setw(widths[i]) << value << " |";
            }
            std::cout << '\n';
        };

    const std::string headers[] = {
        "No.", "Surname", "Course", "Specialty", "Physics",
        "Mathematics", "Programming", "Numerical methods", "Pedagogy"
    };

    std::cout << "\nSTUDENT PERFORMANCE\n";
    printLine();
    printRow(headers);
    printLine();

    for (int i = 0; i < n; i++)
    {
        std::string values[] = {
            std::to_string(i + 1),
            students[i].surname,
            std::to_string(students[i].course),
            GetSpecialtyName(students[i].specialty),
            std::to_string(students[i].physics),
            std::to_string(students[i].mathematics),
            GetGrade(students[i], Programming) == 0
                ? "-" : std::to_string(GetGrade(students[i], Programming)),
            GetGrade(students[i], NumericalMethods) == 0
                ? "-" : std::to_string(GetGrade(students[i], NumericalMethods)),
            GetGrade(students[i], Pedagogy) == 0
                ? "-" : std::to_string(GetGrade(students[i], Pedagogy))
        };

        printRow(values);
        printLine();
    }
}

// Підраховує кількість оцінок 3 з указаного предмета.
int CountGrade(const Student students[], int n, Subject subject)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (GetGrade(students[i], subject) == 3)
            count++;
    }

    return count;
}

// Перевіряє, чи має студент оцінки 4 або 5 з фізики та математики.
bool IsGoodInPhysicsAndMath(const Student& student)
{
    return (student.physics == 4 || student.physics == 5) &&
        (student.mathematics == 4 || student.mathematics == 5);
}

// Виводить прізвища студентів, які відповідають умові.
void PrintGoodStudents(const Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (IsGoodInPhysicsAndMath(students[i]))
            std::cout << students[i].surname << '\n';
    }
}

// Підраховує кількість студентів, які відповідають умові.
int CountGoodStudents(const Student students[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (IsGoodInPhysicsAndMath(students[i]))
            count++;
    }

    return count;
}
