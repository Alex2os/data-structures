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

    void removehead();

    void removetail();

    void removeinposition(int pos);


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

void LinkedList::removehead() {

    if (head == nullptr) cout << "List is empty." << endl;
    else {

        Vertex* temp = head; // we use a temporal object so the memory can be freed when the function ends. this stops memory leaks.
        head = head->next; // could be that head will point to nullptr. in this case we say the list will be empty.

        if (head == nullptr) tail = nullptr; 

        delete temp; // with delete we can delete the object.
    }
}

void LinkedList::removetail() {

    if (head == nullptr) cout << "List is empty." << endl;
    else {

        Vertex* temp_node = head;
        Vertex* previous_node = head;

        while (temp_node != nullptr) {

            if (temp_node->next == nullptr) {

                if (temp_node == head) { // this fires in case the tail is also the head.
                    head = nullptr;
                    tail = nullptr;
                }

                else {
                    previous_node->next = nullptr;
                    tail = previous_node;
                }

                break;

            }

            else {

                if (temp_node != head) previous_node = previous_node->next;

                temp_node = temp_node->next;
            }


        }

    }

}

void LinkedList::removeinposition(int pos) {
    if (head == nullptr) cout << "List is empty.";
    else {

        Vertex* temp_node = head;
        Vertex* previous_node = head;

        int searching_pos = 0;

        while (searching_pos <= pos) {

            if (searching_pos == pos) {

                if (temp_node == head && temp_node->next == nullptr) { // in case the wanted position is both the tail and the head.

                    head = nullptr;
                    tail = nullptr;

                }

                else if (temp_node->next == nullptr) {

                    previous_node->next = nullptr;
                    tail = previous_node;

                }

                else{

                    if (temp_node == head) head = temp_node->next;

                    
                    else previous_node->next = temp_node->next; // we assign the next node of the erased node (temp_node) so we jump the erased node and we now don't reference to it anymore on the previous node.

                    

                }

                break;

            }
            else {

                if (temp_node->next == nullptr) {
                    cout << "The position introduced is invalid." << endl;
                    break;
                }

                else {

                    if (temp_node != head) previous_node = previous_node->next;

                    temp_node = temp_node->next;

                }
            }
            
            searching_pos++;
        }

    }

    if (pos < 0) cout << "The position introduced is not valid." << endl;
}

int main() {
    LinkedList list; // memory leak --> search
    list.append(20); // 0
    list.removeinposition(0);
    list.print();

    return 0;
}
