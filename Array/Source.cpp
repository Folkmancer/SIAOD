﻿#include <iostream>
#include <string> 
#include <fstream> 
#include <cstdlib>
#include <conio.h>
using namespace std;

struct staff {
	int code;
	string department;
	string name;
	string education;
	string post;
};

void bubbleSort(staff *, int, int);
void binaryInsertionSort(staff *, int, int);
void quickSort(staff *, int, int, int);
void show(staff *, int);
void wait();
void main_menu(staff *, int);


int main()
{
	setlocale(0, "");
	staff *NewArray = new staff[5];
	string s;
	int z = 0, k = 0;
	ifstream file("C:\\Users\\Vault Hunter\\Desktop\\fireteam.txt");
	while (getline(file, s))
	{
		if (k == 0)
		{
			NewArray[z].code = atoi(s.c_str());;
			k++;
		}
		else if (k == 1)
		{
			NewArray[z].department = s;
			k++;
		}
		else if (k == 2)
		{
			NewArray[z].name = s;
			k++;
		}
		else if (k == 3)
		{
			NewArray[z].education = s;
			k++;
		}
		else if (k == 4)
		{
			NewArray[z].post = s;
			k = 0;
			z++;
		}
	}
	main_menu(NewArray, z);
	file.close();
	system("pause");
	return 1;
}

//сортировка пузырьком

void bubbleSort(staff *a, int length, int type)
{
	if (type == 0) {
		for (int i = 0; i < length - 1; i++) {
			bool swapped = false;
			for (int j = 0; j < length - i - 1; j++) {
				if (a[j].code > a[j + 1].code)
				{
					swap(a[j], a[j + 1]);
					swapped = true;
				}
			}
		}
	}
	else if (type == 1) {
		for (int i = 0; i < length - 1; i++) {
			bool swapped = false;
			for (int j = 0; j < length - i - 1; j++) {
				if (a[j].code < a[j + 1].code)
				{
					swap(a[j], a[j + 1]);
					swapped = true;
				}
			}
		}
	}
	else if (type == 2) {
		for (int i = 0; i < length - 1; i++) {
			bool swapped = false;
			for (int j = 0; j < length - 1; j++) {
				if (a[j].name > a[j + 1].name)
				{
					swap(a[j], a[j + 1]);
					swapped = true;
				}
			}
		}
	}
	else if (type == 3) {
		for (int i = 0; i < length - 1; i++) {
			bool swapped = false;
			for (int j = 0; j < length - 1; j++) {
				if (a[j].name < a[j + 1].name)
				{
					swap(a[j],a[j+1]);
					swapped = true;
				}
			}
		}
	}
}

//сортировка бинарными вставками

void binaryInsertionSort(staff *a, int length, int type)
{
	if (type == 0)
	{
		for (int i = 1; i < length; i++)
		{
			staff x = a[i];
			int f = 0;
			int l = i;
			while (f<l)
			{
				int c = (f + l) / 2;
				if (x.code < a[c].code)
					l = c;
				else
					f = c + 1;
			}
			for (int j = i - 1; j >= l; j--)
			{
				a[j + 1] = a[j];
			}
			a[l] = x;
		}
	}
	else if (type == 1)
	{
		for (int i = 1; i < length; i++)
		{
			staff x = a[i];
			int f = 0;
			int l = i;
			while (f<l)
			{
				int c = (f + l) / 2;
				if (x.code > a[c].code)
					l = c;
				else
					f = c + 1;
			}
			for (int j = i - 1; j >= l; j--)
			{
				a[j + 1] = a[j];
			}
			a[l] = x;
		}
	}
	else if (type == 2)
	{
		for (int i = 1; i < length; i++)
		{
			staff x = a[i];
			int f = 0;
			int l = i;
			while (f<l)
			{
				int c = (f + l) / 2;
				if (x.name < a[c].name)
					l = c;
				else
					f = c + 1;
			}
			for (int j = i - 1; j >= l; j--)
			{
				a[j + 1] = a[j];
			}
			a[l] = x;
		}
	}
	else if (type == 3)
	{
		for (int i = 1; i < length; i++)
		{
			staff x = a[i];
			int f = 0;
			int l = i;
			while (f<l)
			{
				int c = (f + l) / 2;
				if (x.name > a[c].name)
					l = c;
				else
					f = c + 1;
			}
			for (int j = i - 1; j >= l; j--)
			{
				a[j + 1] = a[j];
			}
			a[l] = x;
		}
	}
}

//быстрая сортировка

void quickSort(staff *aq, int firstQ, int lastQ, int typeQ)
{
	if (typeQ == 0) 
	{
		int i = firstQ, j = lastQ - 1;
		staff x = aq[(i + j) / 2];
		do
		{
			while (aq[i].code < x.code) i++;
			while (aq[j].code > x.code) j--;
			if (i <= j)
			{
				if (i < j)
				{
					swap(aq[i],aq[j]);
				}
				i++;
				j--;
			}
		} while (i <= j);
		if (i < lastQ) quickSort(aq, i, lastQ, 0);
		if (firstQ < j) quickSort(aq, firstQ, j, 0);
	}
	else if (typeQ == 1) 
	{
		int i = firstQ, j = lastQ - 1;
		staff x = aq[(i + j) / 2];
		do
		{
			while (aq[i].code > x.code) i++;
			while (aq[j].code < x.code) j--;
			if (i <= j)
			{
				if (i < j)
				{
					swap(aq[i],aq[j]);
				}
				i++;
				j--;
			}
		} while (i <= j);
		if (i < lastQ) quickSort(aq, i, lastQ, 1);
		if (firstQ < j) quickSort(aq, firstQ, j, 1);
	}
	else if (typeQ == 2) 
	{
		int i = firstQ, j = lastQ - 1;
		staff x = aq[(i + j) / 2];
		do
		{
			while (aq[i].name < x.name) i++;
			while (aq[j].name > x.name) j--;
			if (i <= j)
			{
				if (i < j)
				{
					swap(aq[i],aq[j]);
				}
				i++;
				j--;
			}
		} while (i <= j);
		if (i < lastQ) quickSort(aq, i, lastQ, 2);
		if (firstQ < j) quickSort(aq, firstQ, j, 2);
	}
	else if (typeQ == 3) 
	{
		int i = firstQ, j = lastQ - 1;
		staff x = aq[(i + j) / 2];
		do
		{
			while (aq[i].name > x.name) i++;
			while (aq[j].name < x.name) j--;
			if (i <= j)
			{
				if (i < j)
				{
					swap(aq[i],aq[j]);
				}
				i++;
				j--;
			}
		} while (i <= j);
		if (i < lastQ) quickSort(aq, i, lastQ, 3);
		if (firstQ < j) quickSort(aq, firstQ, j, 3);
	}
}

//вывод

void show(staff *NewArray, int z)
{
	for (int i = 0; i < z; i++)
	{
		cout << NewArray[i].code << " ";
		cout << NewArray[i].department << " ";
		cout << NewArray[i].name << " ";
		cout << NewArray[i].education << " ";
		cout << NewArray[i].post << endl;
	}
}

//ожидание

void wait()
{
	system("pause");
	system("cls");
}

void main_menu(staff *NewArray, int z)
{
	int done = 1;
	while (done != 0)
	{
		int variant_menu;
		cout << "1 Пузырьковая сортировка\n"
			<< "2 Сортировка бинарными вставками\n"
			<< "3 Быстрая сортировка\n"
			<< "0 Выход" << endl;
		variant_menu = (_getch() - 48);
		cout << variant_menu << endl;
		switch (variant_menu) 
		{
		case 1:
		{
			system("cls");
			cout << "1 Пузырьковая сортировка" << endl;
			cout << "1 Первое поле (по возрастанию)\n"
				<< "2 Первое поле (по убыванию)\n"
				<< "3 Третье поле (по возрастанию)\n"
				<< "4 Третье поле (по убыванию)" << endl;
			int variant_type = (_getch() - 48);
			system("cls");
			switch (variant_type)
			{
			case 1:
			{
				bubbleSort(NewArray, z, 0);
				show(NewArray, z);
				wait();
			}
			break;
			case 2:
			{
				bubbleSort(NewArray, z, 1);
				show(NewArray, z);
				wait();
			}
			break;
			case 3:
			{
				bubbleSort(NewArray, z, 2);
				show(NewArray, z);
				wait();
			}
			break;
			case 4:
			{
				bubbleSort(NewArray, z, 3);
				show(NewArray, z);
				wait();
			}
			break;
			default:
			{
				cerr << "Такого варианта нет!" << endl;
				wait();
			}
			break;
			}
		}
		break;
		case 2:
		{
			system("cls");
			cout << "2 Сортировка бинарными вставками" << endl;
			cout << "1 Первое поле (по возрастанию)\n"
				<< "2 Первое поле (по убыванию)\n"
				<< "3 Третье поле (по возрастанию)\n"
				<< "4 Третье поле (по убыванию)" << endl;
			int variant_type = (_getch() - 48);
			system("cls");
			switch (variant_type)
			{
			case 1:
			{
				binaryInsertionSort(NewArray, z, 0);
				show(NewArray, z);
				wait();
			}
			break;
			case 2:
			{
				binaryInsertionSort(NewArray, z, 1);
				show(NewArray, z);
				wait();
			}
			break;
			case 3:
			{
				binaryInsertionSort(NewArray, z, 2);
				show(NewArray, z);
				wait();
			}
			break;
			case 4:
			{
				binaryInsertionSort(NewArray, z, 3);
				show(NewArray, z);
				wait();
			}
			break;
			default:
			{
				cerr << "Такого варианта нет!" << endl;
				wait();
			}
			break;
			}
		}
		break;
		case 3:
		{
			system("cls");
			cout << "3 Быстрая сортировка" << endl;
			cout << "1 Первое поле (по возрастанию)\n"
				<< "2 Первое поле (по убыванию)\n"
				<< "3 Третье поле (по возрастанию)\n"
				<< "4 Третье поле (по убыванию)" << endl;
			int variant_type = (_getch() - 48);
			system("cls");
			switch (variant_type)
			{
			case 1:
			{
				quickSort(NewArray, 0, z, 0);
				show(NewArray, z);
				wait();
			}
			break;
			case 2:
			{
				quickSort(NewArray, 0, z, 1);
				show(NewArray, z);
				wait();
			}
			break;
			case 3:
			{
				quickSort(NewArray, 0, z, 2);
				show(NewArray, z);
				wait();
			}
			break;
			case 4:
			{
				quickSort(NewArray, 0, z, 3);
				show(NewArray, z);
				wait();
			}
			break;
			default:
			{
				cerr << "Такого варианта нет!" << endl;
				wait();
			}
			break;
			}
		}
		break;
		case 0:
		{
			system("cls");
			done = NULL;
		}
		break;
		default:
		{
			cerr << "Такого варианта нет!" << endl;
			wait();
		}
		break;
		}
	}
}