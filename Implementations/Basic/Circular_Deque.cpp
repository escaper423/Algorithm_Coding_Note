#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>

using namespace std;

class CircularDeque {
public:

	CircularDeque(int n): size(n) {
		front = -1;
		rear = 0;
		elements = new int[size];
	}

	bool isFull() { return (front == 0 && rear == size - 1) || (front == rear + 1); }
	bool isEmpty() { return front == -1; }
	void insertFront(int key) {
		if (isFull()) {
			cout << "Overflowed" << endl;
			return;
		}

		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else if (front == 0) {
			front = size - 1;
		}
		else
			front = front - 1;

		cout << "Insert at front " << front << ": " << key << endl;
		elements[front] = key;
	}
	void insertRear(int key) {
		if (isFull()) {
			cout << "Overflowed" << endl;
			return;
		}

		if (front == -1) {
			front = 0;
			rear = 0;
		}

		else if (rear == size - 1) {
			rear = 0;
		}
		else
			rear = rear + 1;

		cout << "Insert at rear " << rear << ": " << key << endl;
		elements[rear] = key;
	}

	void deleteFront() {
		if (isEmpty()) {
			cout << "Underflowed" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			rear = 0;
		}
		else {
			if (front == size - 1)
				front = 0;
			else
				front = front + 1;
		}
	}

	void deleteRear() {
		if (isEmpty()) {
			cout << "Underflowed" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			rear = 0;
		}
		else if (rear == 0)
			rear = size - 1;
		else
			rear = rear - 1;
	}
	
	void printQueue() {
		int s = front;
		int e = rear;
		if (s == -1) {
			cout << "The queue is empty" << endl;
			return;
		}
			
		cout << "Printing queue" << endl;
		while (s != e) {
			cout << elements[s++] << " ";
			if (s == size)
				s = 0;
		}
		cout << elements[e] << endl;
	}
	~CircularDeque() {
		delete[] elements;
	}
	
private:
	int front;
	int rear;
	int size;
	int* elements;
};
int main() {
	CircularDeque dq(3);

	int cmd;
	bool isQuit = false;
	while (!isQuit) {
		int mod;
		int key;
		cout << "1: Insert" << endl << "2: Delete" << endl << "3: Print" << endl << "0: Exit" << endl;
		cin >> cmd;
		switch (cmd) {
		case 1:
			cout << "Front: 1" << endl << "Rear: 2" << endl;
			cin >> mod;
			if (mod == 1) {
				cout << "Key: ";
				cin >> key;
				dq.insertFront(key);
			}
			else if (mod == 2) {
				cout << "Key: ";
				cin >> key;
				dq.insertRear(key);
			}
			else {
				cout << "Error" << endl;
			}
			break;
		case 2:
			cout << "Front: 1" << endl << "Rear: 2" << endl;
			cin >> mod;
			if (mod == 1) {
				dq.deleteFront();
			}
			else if (mod == 2) {
				dq.deleteRear();
			}
			else {
				cout << "Error" << endl;
			}
			break;
		case 3:
			dq.printQueue();
			break;
		case 0:
			isQuit = true;
			break;
		}
	}
	return 0;
}
