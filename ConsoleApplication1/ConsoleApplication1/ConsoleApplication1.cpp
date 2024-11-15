#include "pch.h"

using namespace System;

int main()
{	
	int lenght(0), counter[4], index;
	wchar_t chars[4];

	Console::Write(L"Input the string: ");
	String^ inputStr = Console::ReadLine();

	String^ line = inputStr->Trim(); //������������� �� ������ ������� "���������" �������
	
	String^ newline(line->ToLower()); //���������� ����� � ����� ������

	//����� �������
	for (int i = 0; i < 4; i++) {
		Console::Write(L"input the symbol{0}: ", i + 1);
		String^ input = Console::ReadLine();

		// ������������ ������ ������ � ����� ������ �� ��������� � ����� char
		chars[i] = Char::ToLower(input[0]);
	}
	//���������� ������� ���������� ������� �������
	for (int i = 0; i < 4; i++) {
		counter[i] = 0;
		index = 0;
		while ((index = newline->IndexOf(chars[i], index)) >= 0)
		{
			++index;
			++counter[i];
		}
	}
	//��������� ����������
	for (int i = 0; i < 4; i++) {
		Console::WriteLine(L"{0} - {1}", chars[i], counter[i]);
	}
	return 0;
}