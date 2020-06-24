#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include <conio.h>

using namespace std;

mutex mtx;

void Service(queue<vector<int>> mas)
{
	lock_guard<mutex> lockGuard(mtx);
	while (!mas.empty())
	{
		for (int i = 0; i < mas.front().size(); i++)
		{
			this_thread::sleep_for(chrono::milliseconds(200));
		}
		mas.pop();
	}
}

void main()
{
	srand(time(0));

	vector <int> cart;
	vector <thread*> threads;
	queue <vector<int>> customers;

	int clientsNum = 26;
	int productsNum;
	for (int i = 1; i < clientsNum; i++)
	{
		productsNum = 1 + rand() % 7;

		for (int j = 0; j < productsNum; j++)
		{
			cart.push_back(j);
		}

		customers.push(cart);
		cart.clear();

		if ((i % 5 == 0) ||( i == clientsNum))
		{
			threads.push_back(new thread(Service, customers));
			while (!customers.empty())
			{
				customers.pop();
			}
		}
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->join();
	}

	getch();
}