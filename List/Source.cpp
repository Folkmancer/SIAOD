//#include <conio.h>
#include <iostream>
using namespace std;

class list
{
public:
	list() 
	{ 
		Head = NULL;
	} //Конструктор

	~list()
	{
		while (Head != NULL)
		{
			element *Temp = Head->Next;
			delete Head; 
			Head = Temp;
		}
	} //Деструктор

	void push_front_list(int &NewData) 
	{
		if (element* Node = new element)
		{
			Node->Data = NewData;
			Node->Next = Head;
			Head = Node;
			Count++;
		}
	} //Функция добавления в корень

	void insert_list(int &Index, int &NewData)
	{
		if ((Head != NULL) && (Index <= Count))
		{
			element *TempHead = Head;
			element *TempNode = new element;
			for (int i = 1; i < Index; i++)
			{
				TempHead = TempHead->Next;
			}
			TempNode->Data = TempHead->Data;
			TempNode->Next = TempHead->Next;
			TempHead->Data = NewData;
			TempHead->Next = TempNode;
			Count++;
		}
		else
		{
			push_back_list(NewData);
		}
	} //Функция вставки в список

	void push_back_list(int &NewData) 
	{
			element *TempHead = Head;
			if (TempHead != NULL) 
			{
				while (TempHead->Next != NULL)
				{
					TempHead = TempHead->Next;
				}
				TempHead->Next = new element;
				TempHead->Next->Data = NewData;
				TempHead->Next->Next = NULL;
				Count++;
			}
			else
			{
				Head = new element;
				Head->Data = NewData;
				Head->Next = NULL;
				Count++;
			}
	} //Функция добавления в узел
	
	void show_list() 
	{
		if (Head != NULL)
		{
			element *TempHead = Head;
			while (TempHead != NULL)
			{
				cout << TempHead->Data << " ";
				TempHead = TempHead->Next;
			}
			cout << endl;
		}
	} //Функция вывода списка

	void show_node(int &Index)
	{
		if ((Head != NULL) && (Index <= Count))
		{
			element *TempHead = Head;
			for (int i = 1; i < Index; i++)
			{
				TempHead = TempHead->Next;
			}
			cout << TempHead->Data << endl;
		}	
	} //Функция вывода узла

	void pop_front_list() 
	{
		if (Head != NULL) 
		{ 	  
			element* TempHead = Head->Next;
			delete Head;
			Head = TempHead;
			Count--;
		}
	} //Функция удаления корня

	void pop_back_list()
	{
		if (Head != NULL)
		{
			element *Temp = Head;
			element *TempHead = Head;
			while (Temp->Next != NULL)
			{
				TempHead = Temp;
				Temp = Temp->Next;
			}
			TempHead->Next = NULL;
			Count--;
		}
	} //Функция удаления узла

	void erase_list(int &Index) //Переписать логику
	{
		if ((Head != NULL) && (Index <= Count)) 
		{
			element *TempHead = Head;
			if (Index == 1)
			{
				pop_front_list();
			}
			else if (Index == Count)
			{
				pop_back_list();
			}
			else
			{
				for (int i = 1; i < Index; i++)
				{
					TempHead = TempHead->Next;
				}
				element *Temp = Head;
				while (Temp->Next != TempHead)
				{
					Temp = Temp->Next;
				}
				Temp->Next = TempHead->Next;
				Count--;
			}
		}
	} //Функция удаления конкретного узла

private:
	int Count = 0;
	struct element 
	{
		int Data;
		element *Next;
	};
	element *Head;
};

void main()
{
	setlocale(0, "");
	int N;
	int x,z1,y,z2;
	list lst; 
	cout << "N = ";
	cin >> N; 
	for (int i = 0;i<N;i++)
	{
		cout << i + 1 << ". x = "; 
		cin >> x;
		lst.push_back_list(x);
	}
	cin >> z1;
	lst.erase_list(z1);
	lst.show_list();
	cin >> z1;
	lst.erase_list(z1);
	lst.show_list();
	cin >> z1;
	lst.erase_list(z1);
	lst.show_list();
	cin >> z1;
	lst.erase_list(z1);
	lst.show_list();
	cout << endl;
	system("pause");
}