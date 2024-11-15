#include "pch.h"

using namespace System;

int main()
{
    int M;
    double C;

    // Введення кількості водіїв та вартості за тоннa-кілометр
    Console::Write("Input amount of drivers: ");
    M = Int32::Parse(Console::ReadLine());

    Console::Write("Input the cost of transportation per 1 ton. km.: ");
    C = Double::Parse(Console::ReadLine());

    // Створення масивів для зберігання даних водіїв
    array<int>^ id = gcnew array<int>(M);
    array<double>^ weight = gcnew array<double>(M);
    array<double>^ distance = gcnew array<double>(M);
    array<double>^ wage = gcnew array<double>(M);

    // Введення даних для кожного водія
    for (int i = 0; i < M; ++i) {
        Console::Write("Input the personnel number of "+ (i + 1) +" driver: ");
        id[i] = Int32::Parse(Console::ReadLine());

        Console::Write("Input the weight of the cargo for the " + id[i] + " driver (tons): ");
        weight[i] = Double::Parse(Console::ReadLine());

        Console::Write("Input the distance for the " + id[i] + " driver (km): ");
        distance[i] = Double::Parse(Console::ReadLine());

        // Обчислення заробітної плати для водія
        wage[i] = weight[i] * distance[i] * C;
    }

    // Виведення відомості виплати заробітної платні
    Console::WriteLine("\nPayroll report:");

    for (int i = 0; i < M; ++i) {
        Console::WriteLine("Driver #" + id[i] + " gets a salary of " + wage[i]);
    }

    return 0;
}