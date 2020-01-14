class Node {
public:
	int key;
	Node(Node, bool);
	Node* parent;
	Node* left;
	Node* right;
};

class BinaryTree {
	Node* root;
	void Inorder_tree_walk(Node*);
};