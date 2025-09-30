#include <iostream>

using namespace std;

class Vertex {
public:
	int value;
	Vertex* next;
	Vertex(int v) {
		next = nullptr;
		value = v;
	}
};

class Queue {
private:
	Vertex* head, * tail;
public:

	Queue() {
		head = tail = nullptr;
	}

	void print();

	void enqueue(int val);
	int dequeue();
	void front();
	void back();

};

void Queue::print() {
	Vertex* temp = head;
	if (temp == nullptr) {
		cout << "La cola esta vacia." << endl;
		return;
	}

	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;

};

void Queue::enqueue(int val) {
	Vertex* temp_node = new Vertex(val);

	if (head == nullptr) head = temp_node, tail = temp_node;
	else {
		tail->next = temp_node;
		tail = temp_node;
	}
}

int Queue::dequeue() {
	if (head == nullptr) {
		cout << "La cola está vacía." << endl;
		return -1;
	}
	else {
		int temp_value = 0;
		Vertex* temp_node = head;

		temp_value = temp_node->value;
		head = head->next;

		if (head == nullptr) tail = head;

		delete temp_node;

		return temp_value;
	}

}

void Queue::front() {
	if (head == nullptr) {
		cout << "La cola esta vacia." << endl;
	}
	else {
		cout << "Valor del frente: " << head->value << endl;
	}
}

void Queue::back() {
	if (head == nullptr) {
		cout << "La cola esta vacia." << endl;
	}
	else {
		cout << "Valor de atras: " << tail->value << endl;
	}
}



int main() {
	Queue queue;

	return 0;
}
