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
public:
	Vertex* root;

	BinarySearchTree() {
		root = nullptr;
	}

	void Insert(int val);
	void PreOrder(Vertex*);
	void PostOrder(Vertex*);
	void InOrder(Vertex*);

};

void BinarySearchTree::Insert(int val) {
	Vertex* new_vertex = new Vertex(val);

	if (root == nullptr) root = new_vertex;
	else {

		Vertex* searching_node = root;
		while (true){

			// greater than
			if (new_vertex->value > searching_node->value) {

				// if we found out that the searching node pointing to the right is nullptr, then we assign the vertex to that.
				if (searching_node->next_right == nullptr) {
					searching_node->next_right = new_vertex;
					break;
				}
				else searching_node = searching_node->next_right;
			}

			// if it's equal, then delete the new node and also show a message that it indeed is duplicated.
			else if (new_vertex->value == searching_node->value) {
				cout << "Duplicated value. Not adding it to the tree." << endl;
				delete new_vertex;
				break;
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


// in the case of the order functions (which are for printing the values of the tree itself) we just have to iterate in different ways, so basically just changing the position of the functions and the cout.
// basically, when the function hits a vertex that is nullptr, then returns, making the recursivity finish and start printing or doing all the things the function has to do, making this-
// a way to use recursivity to print the values of the tree.
void BinarySearchTree::InOrder(Vertex* v) {

	if (v == nullptr) return;

	InOrder(v->next_left);

	cout << v->value << " ";

	InOrder(v->next_right);
}

void BinarySearchTree::PreOrder(Vertex* v) {

	if (v == nullptr) return;

	cout << v->value << " ";

	PreOrder(v->next_left);

	PreOrder(v->next_right);
}

void BinarySearchTree::PostOrder(Vertex* v) {

	if (v == nullptr) return;

	PostOrder(v->next_left);
	PostOrder(v->next_right);

	cout << v->value << " ";
}

int main() {
	BinarySearchTree tree = BinarySearchTree();

	// in this case we insert the values of the image of reference to check if the order functions work correctly as intended.
	tree.Insert(20);
	tree.Insert(18);
	tree.Insert(13);
	tree.Insert(23);
	tree.Insert(30);
	tree.Insert(21);
	tree.Insert(19);
	tree.Insert(2);
	tree.Insert(15);

	// print preorder
	cout << "Printing PreOrder:" << endl;
	tree.PreOrder(tree.root); // in this case we have to use the tree.root to specify the root of the tree so these functions can start from there. the root attribute of the-
	// BinarySearchTree class is assigned to public for this to be possible, but should check another ways to use send the root to these functions.
	cout << endl;

	// print inorder
	cout << "Printing InOrder:" << endl;
	tree.InOrder(tree.root);
	cout << endl;

	// print postorder
	cout << "Printing PostOrder:" << endl;
	tree.PostOrder(tree.root);
	cout << endl;

	return 0;
}
