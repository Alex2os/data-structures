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

class Stack {
private:
	Vertex* head, * tail;
public:

	Stack() {
		head = tail = nullptr;
	}

	void print();
	void push(int val);
	int pop();
	int peek();


};

void Stack::print() {
	Vertex* temp = head;
	if (temp == nullptr) {
		cout << "La pila esta vacia." << endl;
		return;
	}

	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;

};

int Stack::peek() {
	if (head == nullptr) {
		cout << "La cabeza es nullptr." << endl;
		return -1;
	}

	else return head->value;
}

int Stack::pop() {
	if (head == nullptr) {
		cout << "La cabeza es nullptr." << endl;
		return -1;
	}

	else {
		int temp_value = 0;
		Vertex* temp_node = head;

		temp_value = temp_node->value;
		head = head->next;

		if (head == nullptr) tail = head;
		else if (head->next == nullptr) tail = head;

		delete temp_node;

		return temp_value;
	}
}

void Stack::push(int val) {
	Vertex* temp_node = new Vertex(val);
	temp_node->next = head;
	head = temp_node;

	if (temp_node->next == nullptr) tail = temp_node;
}



int main() {
	Stack stack;

	return 0;
}
