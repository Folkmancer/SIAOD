#include <iostream>
#include <string> 
#include <fstream>
#include <map>
#include <conio.h>
#include <Windows.h>


using namespace std;

struct staff
{
	int code;
	string department;
	string name;
	string education;
	string post;
};

void GetFromFile(ifstream &, map<int, staff, less<int>> *);
void AddInHashTable(map<int, staff, less<int>> *);
void SearchInHashTable(map<int, staff, less<int>> *, int &, int &);
void DelFromHashTable(map<int, staff, less<int>> *, int &);
void ShowHashTable(map<int, staff, less<int>> *);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<int, staff, less<int>> *HashTab = new map<int, staff, less<int>>;
	map<int, staff, less<int>>::iterator iter;
	ifstream file("C:\\Users\\Vault Hunter\\Desktop\\fireteam.txt");
	GetFromFile(file, HashTab);
	file.close();
	bool Done = false;
	while (Done != true)
	{
		int variant_menu;
		cout << "1 Добавить данные\n"
			<< "2 Найти данные\n"
			<< "3 Удалить данные\n"
			<< "0 Выход" << endl;
		variant_menu = (_getch() - 48);
		cout << variant_menu << endl;
		switch (variant_menu)
		{
		case 1:
		{
			AddInHashTable(HashTab);
			ShowHashTable(HashTab);
		}
		break;
		case 2:
		{
			cout << "Введите код: ";
			int v;
			cin >> v;
			int SHashKey;
			SearchInHashTable(HashTab, v, SHashKey);
			cout << SHashKey
				<< " " << (*HashTab)[SHashKey].code
				<< " " << (*HashTab)[SHashKey].department
				<< " " << (*HashTab)[SHashKey].name
				<< " " << (*HashTab)[SHashKey].education
				<< " " << (*HashTab)[SHashKey].post
				<< endl;
		}
		break;
		case 3:
		{
			cout << "Введите код: ";
			int v;
			cin >> v;
			int DHashKey;
			SearchInHashTable(HashTab, v, DHashKey);
			DelFromHashTable(HashTab, DHashKey);
			ShowHashTable(HashTab);
		}
		break;
		case 0:
		{
			system("cls");
			Done = true;
		}
		break;
		default:
		{
			cerr << "Такого варианта нет!" << endl;
			system("pause");
			return 0;
		}
		break;
		}
	}
	system("pause");
	return 0;
}

void GetFromFile(ifstream &datafile, map<int, staff, less<int>> *NewMap)
{
	int k = 0;
	string s;
	while (getline(datafile, s))
	{
		int HashKey;
		if (k == 0)
		{
			int Temp = atoi(s.c_str());
			bool Done = false;
			int n = 37;
			float a = 0.618033;
			HashKey = n * fmod(Temp * a, 1);
			while (Done != true)
			{
				if ((*NewMap)[HashKey].code == NULL)
				{
					(*NewMap)[HashKey].code = Temp;
					Done = true;
				}
				else
				{
					HashKey += 10;
				}
			}
			k++;
		}
		else if (k == 1)
		{
			(*NewMap)[HashKey].department = s;
			k++;
		}
		else if (k == 2)
		{
			(*NewMap)[HashKey].name = s;
			k++;
		}
		else if (k == 3)
		{
			(*NewMap)[HashKey].education = s;
			k++;
		}
		else if (k == 4)
		{
			(*NewMap)[HashKey].post = s;
			k = 0;
		}
	}
}

void AddInHashTable(map<int, staff, less<int>> *AddTempMap)
{
	bool Done = false;
	string TempString;
	cout << "Введите код:" << endl;
	cin >> TempString;
	int ValueKey = atoi(TempString.c_str());
	int n = 37;
	float a = 0.618033;
	int HashKey = n * fmod(ValueKey * a, 1);
	while (Done != true)
	{
		if ((*AddTempMap)[HashKey].code == NULL)
		{
			Done = true;
		}
		else
		{
			HashKey += 10;
		}
	}
	(*AddTempMap)[HashKey].code = ValueKey;
	cout << "Введите отдел:" << endl;
	cin >> TempString;
	(*AddTempMap)[HashKey].department = TempString;
	cout << "Введите ФИО:" << endl;
	cin >> TempString;
	(*AddTempMap)[HashKey].name = TempString;
	cout << "Введите образование:" << endl;
	cin >> TempString;
	(*AddTempMap)[HashKey].education = TempString;
	cout << "Введите должность:" << endl;
	cin >> TempString;
	(*AddTempMap)[HashKey].post = TempString;
}

void SearchInHashTable(map<int, staff, less<int>> *NewMap, int &ValueKey, int &HKey)
{
	bool Done = false;
	int n = 37;
	float a = 0.618033;
	int HashKey = n * fmod(ValueKey * a, 1);
	map<int, staff, less<int>>::iterator tempIter;
	tempIter = NewMap->end();
	while (Done != true)
	{
		if ((*(--tempIter)).first >= HashKey)
		{
			map<int, staff, less<int>>::iterator  it = NewMap->find(HashKey);
			if (it != NewMap->end())
			{
				if ((*it).second.code == ValueKey)
				{
					HKey = it->first;
					Done = true;
				}
				else
				{
					HashKey += 10;
				}
			}
		}
		else
		{
			cout << "false" << endl;
		}
	}
}

void DelFromHashTable(map<int, staff, less<int>> *DelTempMap, int &DelHashKey)
{
	DelTempMap->erase(DelHashKey);
}

void ShowHashTable(map<int, staff, less<int>> *TempHashTable)
{
	map<int, staff, less<int>>::iterator iter;
	for (iter = TempHashTable->begin(); iter != TempHashTable->end(); iter++)
	{
		cout << (*iter).first
			<< " " << (*iter).second.code
			<< " " << (*iter).second.department
			<< " " << (*iter).second.name
			<< " " << (*iter).second.education
			<< " " << (*iter).second.post
			<< endl;
	}
}

