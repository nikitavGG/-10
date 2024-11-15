#include "pch.h"

using namespace System;

int main(array<System::String^>^ args)
{
    int N, M;

    // Введення розмірів матриці
    Console::Write("Input the number of rows, N: ");
    N = Int32::Parse(Console::ReadLine());

    Console::Write("Input the number of columns, M: ");
    M = Int32::Parse(Console::ReadLine());

    // Створення матриці A
    array<int, 2>^ A (gcnew array<int, 2>(N, M));
    // Масив для зберігання індексів рядків на основі найменших елементів
    array<int>^ minIndices = gcnew array<int>(N);

    // Генерація випадкових чисел для елементів матриці
    Random^ rand = gcnew Random();
    Console::WriteLine("Matrix A:");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Генерація випадкових чисел
            A[i, j] = rand->Next(-10, 10);
            Console::Write(A[i, j] + "\t");
        }
        Console::WriteLine();
    }

    // Знаходимо найменші елементи для кожного рядка
    for (int i = 0; i < N; ++i) {
        int minVal = A[i, 0];
        for (int j = 1; j < M; ++j) {
            if (A[i, j] < minVal) {
                minVal = A[i, j];
            }
        }
        minIndices[i] = minVal;
    }

    // Перестановка рядків бальбашкою
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (minIndices[i] > minIndices[j]) {
                for (int k = 0; k < M; ++k) {
                    int temp = A[i, k];
                    A[i, k] = A[j, k];
                    A[j, k] = temp;
                }

                // Міняємо місцями відповідні значення в масиві найменших елементів
                int tempMin = minIndices[i];
                minIndices[i] = minIndices[j];
                minIndices[j] = tempMin;
            }
        }
    }
    // Виведення нової матриці
    Console::WriteLine("\nNew matrix:");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Console::Write(A[i, j] + "\t");
        }
        Console::WriteLine();
    }
    return 0;
}
