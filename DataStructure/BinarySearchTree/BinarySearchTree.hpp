#pragma once
#include <memory>
#include <utility>
#include <cassert>
// 이진 탐색 트리의 규칙
// 1. 노드에 저장된 key는 유일하다.
// 2. 루트 노드의 key가 왼쪽 서브트리를 구성하는 어떠한 노드의 key보다 크다.
// 3. 루트 노드의 key가 오른쪽 서브트리를 구성하는 어떠한 노드의 key보다 작다.
// 4. 왼쪽, 오른쪽 서브트리도 이진탐색트리이다.
//
#define SMART_POINTER

#ifdef SMART_POINTER
/* Using smart pointer*/


template <class T>
struct Node
{
	T data;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;

	Node(T _data)
		: data(_data), left(nullptr), right(nullptr)
	{}
};

template <typename T>
void Insert(std::shared_ptr<Node<T>>& root, const T& data)
{
	std::shared_ptr<Node<T>> parent = nullptr;
	std::shared_ptr<Node<T>> cur = root;
	while (cur)
	{
		if (cur->data == data)
		{
			return;
		}
		parent = cur;
		if (cur->data > data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}

	if (parent)
	{
		if (parent->data > data)
		{
			parent->left = std::make_shared<Node<T>>(data);
		}
		else
		{
			parent->right = std::make_shared<Node<T>>(data);
		}
	}
}

template <typename T>
bool Search(std::shared_ptr<Node<T>>& root, const T& data)
{
	auto cur = root;
	while (cur)
	{
		if (cur->data == data)
		{
			return true;
		}
		else if (cur->data > data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}

	return false;
}

template <typename T>
void Delete(std::shared_ptr<Node<T>>& root, const T& data)
{
	std::shared_ptr<Node<T>> parent;
	std::shared_ptr<Node<T>> cur = root;

	while (cur->data)
	{
		if (cur->data == data)
		{
			break;
		}
		parent = cur;
		if (cur->data > data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}	
	}

	assert(cur);

	// If node what will be deleted is terminal.
	if (!cur->left && !cur->right)
	{
		parent->data = cur->data;
		if (parent->left == cur)
		{
			parent->left = nullptr;
		}
		else
		{
			parent->right = nullptr;
		}
	}
	// else than has a child.
	else if ((cur->left || cur->right) && !(cur->left && cur->right))
	{
		parent->data = cur->data;
		if (parent->left == cur)
		{
			if (cur->left)
			{
				parent->left = cur->left;
			}
			else
			{
				parent->left = cur->right;
			}
		}
		else
		{
			if (cur->left)
			{
				parent->right = cur->left;
			}
			else
			{
				parent->right = cur->right;
			}
		}
	}
	// else has both.
	else
	{
		auto targetParent = parent;
		auto target = cur;
		while (target->left)
		{
			targetParent = target;
			target = target->left;
		}

		cur->data = target->data;
		if (target->right)
		{
			cur->left = target->right;
		}
		else
		{
			cur->left = nullptr;
		}
	}
}

template <typename T>
void PreOrderTraverse(std::shared_ptr<Node<T>>& root, void(*callback)(std::shared_ptr<Node<T>>&) = nullptr)
{
	callback(root);
	if (root->left)
	{
		PreOrderTraverse<T>(root->left, callback);
	}
	if (root->right)
	{
		PreOrderTraverse<T>(root->right, callback);
	}
}

template <typename T>
void InOrderTraverse(std::shared_ptr<Node<T>>& root, void(*callback)(std::shared_ptr<Node<T>>&) = nullptr)
{
	if (root->left)
	{
		InOrderTraverse<T>(root->left, callback);
	}
	callback(root);
	if (root->right)
	{
		InOrderTraverse<T>(root->right, callback);
	}
}

template <typename T>
void PostOrderTraverse(std::shared_ptr<Node<T>>& root, void(*callback)(std::shared_ptr<Node<T>>&) = nullptr)
{
	if (root->left)
	{
		PostOrderTraverse<T>(root->left, callback);
	}
	if (root->rignt)
	{
		PostOrderTraverse<T>(root->right, callback);
	}
	callback(root);
}

#else

template <typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;

	Node(T _data)
		:data(_data), left(nullptr), right(nullptr)
	{}
};

template <typename T>
void Insert(Node<T>* root, const T& data)
{
	Node<T>* parent = nullptr;
	Node<T>* cur = root;

	while (cur)
	{
		if (cur->data == data)
		{
			return;
		}
		parent = cur;
		if (cur->data > data)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}

	if (parent)
	{
		if (parent->data > data)
		{
			parent->left = new Node<T>(data);
		}
		else
		{
			parent->right = new Node<T>(data);
		}
	}
}
template <typename T>
void PreOrderTraverse(Node<T>* root, void(*callback)(Node<T>*))
{
	callback(root);
	if (root->left)
	{
		PreOrderTraverse(root->left, callback);
	}
	if (root->right)
	{
		PreOrderTraverse(root->right, callback);
	}
}


#endif