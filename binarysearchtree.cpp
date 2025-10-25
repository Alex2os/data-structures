#include <iostream>

using namespace std;

class Vertex {
public:
	int value;
	Vertex* next_right;
	Vertex* next_left;
	Vertex(int v) {
		next_right = nullptr;
		next_left = nullptr;
		value = v;
	}
};

class BinarySearchTree {
private:
	Vertex* root;
public:

	BinarySearchTree() {
		root = nullptr;
	}

	void Insert(int val);

};

void BinarySearchTree::Insert(int val) {
	Vertex* new_vertex = new Vertex(val);

	if (root == nullptr) root = new_vertex;
	else {

		Vertex* searching_node = root;
		for (int i = 0; i > -1; i++) {

			// greater than
			if (new_vertex->value > searching_node->value) {

				// if we found out that the searching node pointing to the right is nullptr, then we assign the vertex to that.
				if (searching_node->next_right == nullptr) {
					searching_node->next_right = new_vertex;
					break;
				}
				else searching_node = searching_node->next_right;
			}

			// less than
			else {

				// same as the greater than, if we found out is pointing to the left as nullptr, then we assign that.
				if (searching_node->next_left == nullptr) {
					searching_node->next_left = new_vertex;
					break;
				}
				else searching_node = searching_node->next_left;

			}
		}

	}
}

int main() {
	BinarySearchTree tree = BinarySearchTree();

	tree.Insert(3);
	tree.Insert(10);
	tree.Insert(1);
	tree.Insert(2);
	tree.Insert(6);

	return 0;
}
