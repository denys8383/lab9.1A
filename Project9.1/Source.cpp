#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int MAX_NAME_LENGTH = 20; // Максимальна довжина для прізвищ та спеціальностей

// Перерахування, яке представляє спеціальності
enum Specialty {
    MATH_ECONOMICS,    // Математика та економіка
    PHYSICS_CS,        // Фізика та інформатика
    COMPUTER_SCIENCE   // Інформатика
};

// Структура, що представляє інформацію про студента
struct Student {
int studentNumber;
char lastName[MAX_NAME_LENGTH];
int course;
Specialty specialty;
double physics;
double math;
double it;
};

// Функція для конвертації перерахування Specialty в рядок
const char* specialtiesToString(Specialty specialty) {
    switch (specialty) {
    case MATH_ECONOMICS:
        return "Mathematics and economics";
    case PHYSICS_CS:
        return "Physics and computer science";
    case COMPUTER_SCIENCE:
        return "Computer science";
    default:
        return "Unknown Specialty";
    }
}
// Функція для введення даних студента
void inputStudents(Student* students, int numberOfStudents) {
    // Значення перерахування для спеціальностей
    const Specialty specialties[] = { MATH_ECONOMICS, PHYSICS_CS, COMPUTER_SCIENCE };

    // Прізвища
    const char* lastNames[] = { "Vovk", "Mazurok", "Ushakov", "Kojushko", "Zarubich", "Simonenko", "Barchuk", "Osadchyi", "Kalyna" };

    for (int i = 0; i < numberOfStudents; ++i) {
        // Копіювання прізвища
        strncpy(students[i].lastName, lastNames[i % (sizeof(lastNames) / sizeof(lastNames[0]))], MAX_NAME_LENGTH - 1);
        students[i].lastName[MAX_NAME_LENGTH - 1] = '\0';

        // Встановлення спеціальності за допомогою перерахування
        students[i].specialty = specialties[i % (sizeof(specialties) / sizeof(specialties[0]))];

        // Генерація випадкового курсу (від 1 до 5)
        students[i].course = rand() % 5 + 1;

        // Генерація випадкових оцінок (від 3 до 5)
        students[i].physics = rand() % 3 + 3;
        students[i].math = rand() % 3 + 3;
        students[i].it = rand() % 3 + 3;

        students[i].studentNumber = i + 1;
    }
}

// Функція для виведення таблиці студентів та обчислення кількості та відсотка студентів
void displayTable(const Student* students, int numberOfStudents) {
    int countWithoutThrees = 0;
    int countBelowFour = 0;

    // Виведення заголовка
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << "| No |  Surname   |Course|            Speciality          |  P |  M | I  |" << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;

    // Виведення даних студента та обчислення
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << "| " << std::setw(2) << students[i].studentNumber << " | " << std::setw(10) << students[i].lastName << " | "
            << std::setw(4) << students[i].course << " | " << std::setw(30) << specialtiesToString(students[i].specialty) << " | "
            << std::setw(2) << students[i].physics << " | " << std::setw(2) << students[i].math << " | "
            << std::setw(2) << students[i].it << " |" << std::endl;

        // Обчислення
        if (students[i].physics >= 4 && students[i].math >= 4 && students[i].it >= 4) {
            countWithoutThrees++;
        }

        double averageGrade = (students[i].physics + students[i].math + students[i].it) / 3.0;
        if (averageGrade < 4.0) {
            countBelowFour++;
        }
    }

    std::cout << "--------------------------------------------------------------------------" << std::endl;

    // Виведення результатів обчислень
    std::cout << "1. Number of students without threes: " << countWithoutThrees << std::endl;
    std::cout << "2. Percentage of students with an average grade below 4: " << std::fixed << std::setprecision(2)
        << (static_cast<double>(countBelowFour) / numberOfStudents) * 100 << "%" << std::endl;
}

int main() {
    // Ініціалізація генератора випадкових чисел
    std::srand(static_cast<unsigned>(std::time(0)));

    int numberOfStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numberOfStudents;

    // Створення динамічного масиву студентів
    Student* students = new Student[numberOfStudents];

    // Введення даних студентів
    inputStudents(students, numberOfStudents);

    // Виведення таблиці та обчислень
    displayTable(students, numberOfStudents);

    // Вивільнення пам'яті
    delete[] students;

    return 0;
}