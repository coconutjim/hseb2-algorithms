#include"bin.h";
using namespace std;

Node::Node(Node par, bool leftOrNot) {
	parent = &par;
	if (leftOrNot) {
	}
}

void BinaryTree::Inorder_tree_walk(Node* x) {
	if (x != NULL) {
		Inorder_tree_walk((&x).left);
	}
}