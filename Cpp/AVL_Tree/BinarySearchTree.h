#pragma once

#include <iostream>
#include <utility>
#include <memory>
#include <functional>
#include <cassert>
#include <vector>

namespace hsrang
{
	template <typename T>
	struct Node;
	template <typename T>
	void ReBalance(T& root);
	template <typename T>
	void LLRotation(T& node);
	template <typename T>
	void RRRotation(T& node);
	template <typename T>
	void SetLeftSubTree(T& target, const T& sub);
	template <typename T>
	void SetRightSubTree(T& target, const T& sub);

	template <typename T>
	struct Node
	{
		T data;
		std::shared_ptr<Node<T>> left;
		std::shared_ptr<Node<T>> right;
		int leftHeight;
		int rightHeight;

		Node(const T& data, const std::shared_ptr<Node<T>>& left = nullptr, const std::shared_ptr<Node<T>>& right = nullptr)
			:data(data), left(left), right(left), leftHeight(0), rightHeight(0)
		{}
	};

	template <typename T>
	inline std::shared_ptr<Node<T>> MakeNode(const T& data)
	{
		return std::make_shared<Node<T>>(data);
	}

	template <typename T>
	T GetLeftSubTree(const T& node)
	{
		return node->left;
	}

	template <typename T>
	T GetRightSubTree(const T& node)
	{
		return node->right;
	}

	template <typename T>
	void SetLeftSubTree(T& target, const T& sub)
	{
		target->left = sub;
		if (sub)
		{
			target->leftHeight = sub->leftHeight > sub->rightHeight ? sub->leftHeight + 1 : sub->rightHeight + 1;
		}
		else
		{
			target->leftHeight = 0;
		}
	}

	template <typename T>
	void SetRightSubTree(T& target, const T& sub)
	{
		target->right = sub;
		if (sub)
		{
			target->rightHeight = sub->leftHeight > sub->rightHeight ? sub->leftHeight + 1 : sub->rightHeight + 1;
		}
		else
		{
			target->rightHeight = 0;
		}
	}

	template <typename T, typename F>
	void PreorderTraverse(T& root, F callback)
	{
		if (!root)
		{
			return;
		}
		callback(root);
		PreorderTraverse(root->left, callback);
		PreorderTraverse(root->right, callback);
	}

	template <typename T, typename F>
	void PostorderTraverse(T& root, F callback)
	{
		if (!root)
		{
			return;
		}
		PostorderTraverse(root->left, callback);
		PostorderTraverse(root->right, callback);
		callback(root);
	}

	template <typename T>
	void Insert(T& root, const T node)
	{
		std::vector<T> rebalanceTarget;
		T child = root;
		T parent = root;
		while (child)
		{
			if (child->data == node->data)
			{
				return;
			}
			parent = child;
			if (child->data > node->data)
			{
				child->leftHeight++;
				child = child->left;
			}
			else
			{
				child->rightHeight++;
				child = child->right;
			}
			rebalanceTarget.push_back(parent);
		}
		if (parent->data > node->data)
		{
			SetLeftSubTree(parent, node);
		}
		else
		{
			SetRightSubTree(parent, node);
		}

		// what is the problem?
		//for (auto& e : rebalanceTarget)
		//{
		//	ReBalance(e);
		//}
		PostorderTraverse(root, ReBalance<T>);
	}

	template <typename T, typename U>
	void Delete(T& root, const U& data)
	{
		T target = root;
		T parent = nullptr;
		while (target)
		{
			if (target->data == data)
			{
				break;
			}
			parent = target;
			if (target->data > data)
			{
				target->leftHeight++;
				target = target->left;
			}
			else
			{
				target->rightHeight++;
				target = target->right;
			}
		}
		assert(target != nullptr);


		if (!(target->left || target->right))
		{
			if (parent->left == target)
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
		}
		else if ((target->left || target->right) && !(target->left && target->right))
		{

			if (parent->left == target)
			{
				if (target->left)
				{
					parent->left = target->left;
				}
				else
				{
					parent->left = target->right;
				}
			}
			else
			{
				if (target->left)
				{
					parent->right = target->left;
				}
				else
				{
					parent->right = target->right;
				}
			}
		}
		else
		{
			auto temp = target->right;
			auto tempParent = temp;
			while (temp->left)
			{
				tempParent = temp;
				temp = temp->left;
			}
			target->data = temp->data;
			if (temp->right)
			{
				tempParent->left = temp->right;
			}
		}
	}
	template <typename T>
	void ReBalance(T& root)
	{
		if (root->leftHeight - root->rightHeight >= 2)
		{
			// LR Rotation
			if (root->left->leftHeight - root->left->rightHeight < 0)
			{
				RRRotation(root->left);
			}
			LLRotation(root);
		}
		else if (root->leftHeight - root->rightHeight <= -2)
		{
			// RL Rotation
			if (root->right->leftHeight - root->right->rightHeight > 0)
			{
				LLRotation(root->right);
			}
			RRRotation(root);
		}
	}

	template <typename T>
	void LLRotation(T& node)
	{
		auto temp = node->left;
		SetLeftSubTree(node, temp->right);
		SetRightSubTree(temp, node);
		node = temp;
	}

	template <typename T>
	void RRRotation(T& node)
	{
		auto temp = node->right;
		SetRightSubTree(node, temp->left);
		SetLeftSubTree(temp, node);
		node = temp;
	}
}

