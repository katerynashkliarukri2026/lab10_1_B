
#pragma once

#include <string>

// Перелік спеціальностей студента.
enum Specialty
{
    ComputerScience,
    Informatics,
    MathematicsEconomics,
    PhysicsInformatics,
    LaborTraining
};

// Перелік предметів для підрахунку оцінок.
enum Subject
{
    Physics,
    Mathematics,
    ThirdSubject
};

// Оцінка третього предмета, що залежить від спеціальності.
union ThirdGrade
{
    int programming;
    int numericalMethods;
    int pedagogy;
};

// Структура для зберігання інформації про студента.
struct Student
{
    std::string surname;
    int course;
    Specialty specialty;
    int physics;
    int mathematics;
    ThirdGrade thirdGrade;
};

// Створює динамічний масив студентів.
Student* CreateStudents(int n);

// Вводить і перевіряє дані одного студента.
void InputStudent(Student& student);

// Вводить ціле число в заданому діапазоні.
int InputInteger(const std::string& prompt, int minValue, int maxValue);

// Повертає назву спеціальності.
std::string GetSpecialtyName(Specialty specialty);

// Повертає назву третього предмета.
std::string GetThirdSubjectName(Specialty specialty);

// Виводить таблицю успішності студентів.
void PrintStudents(const Student students[], int n);

// Повертає оцінку студента з указаного предмета.
int GetGrade(const Student& student, Subject subject);

// Підраховує кількість оцінок 3 з указаного предмета.
int CountGrade(const Student students[], int n, Subject subject);

// Перевіряє, чи має студент оцінки 4 або 5 з фізики та математики.
bool IsGoodInPhysicsAndMath(const Student& student);

// Виводить прізвища студентів, які відповідають умові.
int PrintGoodStudents(const Student students[], int n);
