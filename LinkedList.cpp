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

class LinkedList {
private:
	Vertex* head, * tail;
public:

	LinkedList() {
		head = tail = nullptr;
	}

	void print();

	void append(int val);

	void prepend(int val);

	void insert(int val, int pos);

	void removeHead();

	void removeTail();

	void removeInPosition(int pos);

	void removeAllInstances(int val);
};


void LinkedList::append(int val) {
	Vertex* temp = new Vertex(val);
	if (head == nullptr) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
};

void LinkedList::print() {
	Vertex* temp = head;
	if (temp == nullptr) {
		cout << "List is empty" << endl;
	}
	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
};

void LinkedList::insert(int val, int pos) {

	if (head == nullptr) {
		cout << "The list has not been initialized to insert anything." << endl;
		return;
	}

	if (pos < 0) {
		cout << "The position introduced is not valid." << endl;
		return;
	}

	int searching_pos = 0;
	Vertex* temp_node = head;
	Vertex* previous_node = nullptr;

	while (searching_pos <= pos) {

		if (searching_pos == pos) {
			Vertex* new_node = new Vertex(val);

			if (temp_node == head) {
				new_node->next = head;
				head = new_node;

				if (head->next == nullptr) tail = head;
			}

			else {
				previous_node->next = new_node;
				new_node->next = temp_node;

				if (temp_node->next == nullptr) tail = temp_node;
			}
		}
		else {
			if (temp_node->next == nullptr) {
				cout << "The position introduced is not valid." << endl;
				break;
			}
			else {
				previous_node = temp_node;
				temp_node = temp_node->next;
			}
		}

		searching_pos++;
	}
}

void LinkedList::prepend(int val) {
	Vertex* temp_node = new Vertex(val);
	if (head == nullptr) {
		head = temp_node;
		tail = temp_node;
	}

	else {
		temp_node->next = head;
		head = temp_node;
	}
}

void LinkedList::removeHead() {
	if (head == nullptr) {
		cout << "List is empty." << endl;
		return;
	}

	Vertex* temp = head; // we use a temporal object so the memory can be freed when the function ends. this stops memory leaks.
	head = head->next; // could be that head will point to nullptr. in this case we say the list will be empty.

	if (head == nullptr) tail = nullptr;

	delete temp; // with delete we can delete the object.
}

void LinkedList::removeTail() {

	if (head == nullptr) {
		cout << "List is empty." << endl;
		return;
	}

	Vertex* temp_node = head;
	Vertex* previous_node = nullptr;

	while (temp_node != nullptr) {

		if (temp_node->next == nullptr) {

			if (temp_node == head) {
				head = temp_node->next;
				if (head == nullptr) tail = nullptr;
			}
			else {
				previous_node->next = nullptr;
				tail = previous_node;
			}
			delete temp_node;
			break;

		}
		else {
			previous_node = temp_node;
			temp_node = temp_node->next;
		}
	}
}

void LinkedList::removeInPosition(int pos) {
	if (head == nullptr) {
		cout << "List is empty.";
		return;
	}

	if (pos < 0) {
		cout << "The position introduced is not valid.";
		return;
	}

	Vertex* temp_node = head;
	Vertex* previous_node = nullptr;
	int searching_pos = 0;

	while (searching_pos <= pos) {

		if (searching_pos == pos) {

			if (temp_node == head) {
				head = temp_node->next;
				if (head == nullptr) tail = nullptr;
			}
			else {
				previous_node->next = temp_node->next;
				if (previous_node->next == nullptr) tail = previous_node;
			}

			delete temp_node;

		}
		else {

			if (temp_node->next == nullptr) {
				cout << "The position introduced is invalid." << endl;
				break;
			}

			else {
				previous_node = temp_node;
				temp_node = temp_node->next;
			}
		}
		searching_pos++;
	}
}

void LinkedList::removeAllInstances(int val) {
	if (head == nullptr) {
		cout << "List is empty.";
		return;
	}

	Vertex* temp_node = head;
	Vertex* previous_node = nullptr;

	while (temp_node != nullptr) {

		if (temp_node->value == val) {

			if (temp_node == head) {
				head = temp_node->next;
				if (head == nullptr) tail = nullptr;
			}
			else {
				previous_node->next = temp_node->next;
				if (previous_node->next == nullptr) tail = previous_node;
			}

			Vertex* next_node = temp_node->next;
			delete temp_node;
			temp_node = next_node;
		}
		else {

			previous_node = temp_node;
			temp_node = temp_node->next;

		}
	}

	cout << "Erased all instances (if any)" << endl;
}

int main() {
	LinkedList list;
	list.append(3);
	list.append(20);
	list.append(20);
	list.append(20);
	list.append(20);
	list.append(20);
	list.append(1);
	list.removeInPosition(4);
	list.removeTail();
	list.removeHead();
	list.insert(2, 3);
	list.print();

	return 0;
}
