/*
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <conio.h>

using namespace std;

condition_variable cv;
mutex mtx;
bool endProgram = false;
bool sortAccess = false;
bool mainAccess = true;

void BubbleSort(vector<string> &mas, bool function(string str1, string str2))
{
	for (int i = 0; i < mas.size() - 1; i++)
	{
		unique_lock<mutex> lk(mtx);
		cv.wait(lk, [] {return (sortAccess); });
		for (int j = i+1; j < mas.size(); j++)
		{
			if (function(mas[i], mas[j]))
			{
				swap(mas[i], mas[j]);
			}
		}
		sortAccess = false;
		mainAccess = true;

		lk.unlock();
		cv.notify_all();
	}

	endProgram = true;
}

void main()
{
	vector <string> mas = { "apple", "orange", "banana", "tomato", "ananas" };

	thread function(BubbleSort, ref(mas), [](string s1, string s2) { return s1 > s2; });

	while (1)
	{
		unique_lock<mutex> lk(mtx);
		cv.wait(lk, []() { return mainAccess; });

		for (int i = 0; i < mas.size(); i++)
		{
			cout << mas[i] << " ";
		}
		printf("\n");
		mainAccess = false;
		sortAccess = true;
		lk.unlock();
		cv.notify_all();
	}

	function.join();

	getch();
}

*/