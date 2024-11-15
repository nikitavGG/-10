#include "pch.h"

using namespace System;

int main()
{
    int M;
    double C;

    // �������� ������� ��䳿� �� ������� �� ����a-�������
    Console::Write("Input amount of drivers: ");
    M = Int32::Parse(Console::ReadLine());

    Console::Write("Input the cost of transportation per 1 ton. km.: ");
    C = Double::Parse(Console::ReadLine());

    // ��������� ������ ��� ��������� ����� ��䳿�
    array<int>^ id = gcnew array<int>(M);
    array<double>^ weight = gcnew array<double>(M);
    array<double>^ distance = gcnew array<double>(M);
    array<double>^ wage = gcnew array<double>(M);

    // �������� ����� ��� ������� ����
    for (int i = 0; i < M; ++i) {
        Console::Write("Input the personnel number of "+ (i + 1) +" driver: ");
        id[i] = Int32::Parse(Console::ReadLine());

        Console::Write("Input the weight of the cargo for the " + id[i] + " driver (tons): ");
        weight[i] = Double::Parse(Console::ReadLine());

        Console::Write("Input the distance for the " + id[i] + " driver (km): ");
        distance[i] = Double::Parse(Console::ReadLine());

        // ���������� �������� ����� ��� ����
        wage[i] = weight[i] * distance[i] * C;
    }

    // ��������� ������� ������� �������� �����
    Console::WriteLine("\nPayroll report:");

    for (int i = 0; i < M; ++i) {
        Console::WriteLine("Driver #" + id[i] + " gets a salary of " + wage[i]);
    }

    return 0;
}