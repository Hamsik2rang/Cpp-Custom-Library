#include "BinarySearchTree.hpp"

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	int arr[]{ 1,4,2,7,3,9,8,6 };

#ifdef SMART_POINTER

	shared_ptr<Node<int>> root = make_shared<Node<int>>(5);

	for (int i = 0; i < 8; i++)
	{
		Insert<int>(root, arr[i]);
	}

	PreOrderTraverse<int>(root, [](shared_ptr<Node<int>>& root)->void { cout << root->data << endl; });
	
	cout << boolalpha;
	cout << Search<int>(root, 2) << endl;
	cout << Search<int>(root, 10) << endl;

	PreOrderTraverse<int>(root, [](shared_ptr<Node<int>>& root)->void { cout << root->data << endl; });
	Delete(root, 7);
	PreOrderTraverse<int>(root, [](shared_ptr<Node<int>>& root)->void { cout << root->data << endl; });


#else
	
	Node<int>* root = new Node<int>(5);

	for (int i = 0; i < 8; i++)
	{
		Insert(root, arr[i]);
	}

	PreOrderTraverse<int>(root, [](Node<int>* node)->void { cout << node->data << endl; });

#endif

	return 0;
}