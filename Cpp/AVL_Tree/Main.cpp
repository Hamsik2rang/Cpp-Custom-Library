#include "BinarySearchTree.h"

#include <iostream>



int main()
{
	using namespace std;
	using namespace hsrang;

	auto root = MakeNode(1);
	Insert(root, MakeNode(2));
	Insert(root, MakeNode(3));
	Insert(root, MakeNode(4));
	Insert(root, MakeNode(6));
	Insert(root, MakeNode(7));
	Insert(root, MakeNode(8));
	Insert(root, MakeNode(10));
	Insert(root, MakeNode(15));

	PreorderTraverse(root, [](shared_ptr<Node<int>> node)->void { cout << node->data << endl; });

	return 0;
}