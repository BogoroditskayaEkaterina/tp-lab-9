#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <queue>
#include <mutex>

using namespace std;

const int max_goods_amount = 10; 
const int max_customers_amount = 15;
const int max_queue_size = 5;
mutex mx;

class customer {
private:
	vector<int> goods; // ��� �������� ���� �������
	int goods_amount = 0;
	int id; 
public:
	customer(int id) {
		this->id = id;
		goods_amount = 1 + rand() % (max_goods_amount - 1); // � ���������� ������ ���� ���� �� ���� �����
		for (int i = 0; i < goods_amount; i++) {
			goods.push_back(50*(rand() % 10)); // ��������� ���� � �������� �� 50 �� 500
		}
	}

	vector<int>& getGoods() {
		return goods;
	}

	int getId() {
		return id;
	}
};

void serve_line(queue<customer>* line) {
	while (!line->empty()) { // �����������, ���� ������� �� ����� 
		customer current_customer = line->front();
		int sum = 0; 
		for (int i = 0; i < current_customer.getGoods().size(); i++) {
			sum += current_customer.getGoods()[i];
			mx.lock(); // ��� ����������� ������ 
			cout << '\a' << "BLEEP! from the cash register " << this_thread::get_id() << " serving a customer with id " << current_customer.getId();
			cout << " - current total: " << sum << endl;
			mx.unlock();
			this_thread::sleep_for(chrono::milliseconds(500)); // ������ �����-�� ����� �� ��, ����� ������� �����
		}
		line->pop();
	}
}

int main() {
	srand(time(nullptr));
	cout << "MAIN: " << this_thread::get_id() << endl;
	
	int customers_amount = rand() % max_customers_amount;
	vector<queue<customer>*> queues; // ������ ��������
	vector<thread*> threads; // ������ ������� (����)
	int id = 0;
	
	for (int i = 0; i < customers_amount; i++) {
		this_thread::sleep_for(chrono::milliseconds(600 + (rand()% 4)*100)); // ���������� ���������� �� ���������� �����������
		customer new_customer(id);
		id++;

		if (queues.size() == 0) { // ���� ���������� "��������", � �������� ���
			queue<customer>* temp_q = new queue<customer>; // ����� �������
			temp_q->push(new_customer); // ��������� � ��� ����������
			queues.push_back(temp_q); // ��������� ������� � ������ ��������
			threads.push_back(new thread(serve_line, queues[0])); // "���������" �����
		}
		else {
			int full_q_count = 0;
			for (int j = 0; j < queues.size(); j++) { // ���������� "����" �������, ��� ������ 5 ������ �����������
				if (queues[j]->size() == max_queue_size) {
					full_q_count++; // ������� ���������� ����������� ��������
					continue;
				}
				else {
					queues[j]->push(new_customer); // ���� � ������� ������ 5 �����������, ��������� ���� ������ ����������
				}
			}
			if (full_q_count == queues.size()) { // ���� ��� ������� ������
				queue<customer>* temp_q = new queue<customer>; // ����� �������
				temp_q->push(new_customer); // ��������� � ��� ����������
				queues.push_back(temp_q); // ��������� ������� � ������ ��������
				threads.push_back(new thread(serve_line, queues.back())); // "���������" ����� 
			}
		}
	}

	for (auto th : threads) {
		th->join();
	}

	return 0;
}