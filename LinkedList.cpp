#include <iostream>

using namespace std;

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
    int searching_pos = 0;

    Vertex* temp_node = head;
    Vertex* previous_node = nullptr;

    if (head == nullptr) cout << "The list has not been initialized to insert anything." << endl;
    else {

        while (searching_pos <= pos) {

            if (searching_pos == pos) {

                Vertex* new_node = new Vertex(val);

                if (temp_node == head) {

                    new_node->next = head;
                    if (head->next == nullptr) tail = head;
                    head = new_node;

                }

                else {

                    previous_node->next = new_node;
                    new_node->next = temp_node;

                }

                if (temp_node->next == nullptr) {

                    tail = temp_node;

                }
                break;
            }

            else if (searching_pos + 1 == pos) {

                previous_node = temp_node;

            }

            if (temp_node->next == nullptr) {

                cout << "The position introduced is not valid." << endl;
                break;

            }

            else temp_node = temp_node->next;


            searching_pos++;
        }

    }

    if (pos < 0) cout << "The position introduced is not valid." << endl;
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



int main() {
    LinkedList list;
    list.append(20);
    list.insert(30, 0);
    list.append(20);
    list.append(20);
    list.append(20);
    list.append(20);
    list.insert(30, 0);
    list.print();

    return 0;
}
