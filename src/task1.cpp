
/*
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

vector <string> BubbleSort(vector<string> mas, bool function(string s1, string s2))
{
	for (int i = 0; i < mas.size()-1; i++)
	{
		for (int j = i+1; j < mas.size(); j++)
		{
			if (function(mas[i], mas[j]))
			{
				swap(mas[i], mas[j]);
			}
		}
	}
	return mas;
}

void main()
{

	vector <string> mas = { "apple", "orange", "banana", "tomato", "ananas" };
	int size = mas.size();
	
	vector <string> mas2;
	mas2 = BubbleSort(mas, [](string s1, string s2){return (s1 > s2); });
	for (int i = 0; i < size; i++)
	{
		cout << mas2[i] << " ";
	}
	printf("\n");

	mas2 = BubbleSort(mas, [](string s1, string s2){return (s1 < s2); });
	for (int i = 0; i < size; i++)
	{
		cout << mas2[i] << " ";
	}
	printf("\n");

	mas2 = BubbleSort(mas, [](string s1, string s2){return (s1.size() > s2.size()); });
	for (int i = 0; i < size; i++)
	{
		cout << mas2[i] << " ";
	}
	printf("\n");

	mas2 = BubbleSort(mas, [](string s1, string s2){return (s1.size() < s2.size()); });
	for (int i = 0; i < size; i++)
	{
		cout << mas2[i] << " ";
	}
	printf("\n");

	mas2 = BubbleSort(mas, [](string s1, string s2){return (s1.length() > s2.length()); });
	for (int i = 0; i < size; i++)
	{
		cout << mas2[i] << " ";
	}
	printf("\n");

	getch();
}

*/