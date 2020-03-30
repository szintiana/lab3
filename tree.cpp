#include "tree.h"
#include <iostream>
#include <vector>
#include <algorithm>

tree::tree()
{
	this->left = nullptr;
	this->right = nullptr;
	this->root = nullptr;
}

tree::~tree()
{
	delete []left;
	delete []right;
	delete []root;
}

void tree::insert(int data)
{
	node* temp = new node;
	node* parent;
	temp->value = data;
	temp->right = nullptr;
	temp->left = nullptr;
	parent = nullptr;
	if (root == 0)
	{
		root = temp;
	}
	else
	{
		node* current;
		current = root;
		while (current != 0)
		{
			parent = current;
			if (temp->value > current->value)
				current = current->right;
			else
				current = current->left;
		}
		if (temp->value < parent->value)
		{
			parent->left = temp;
			parent->left->root = parent;
		}
		else
		{
			parent->right = temp;
			parent->right->root = parent;
		}
	}
}

node* tree::search(int my_value)
{
	node* found = root;
	while (found->value != my_value)
	{
		if (found->value < my_value) found = found->right;
		else found = found->left;
	}

	return found;
}

void tree::remove(int value)
{
	node* my_node = this->search(value);
	if (my_node == nullptr) std::cout << "Kein solcher Knoten!";
	else if (my_node->left == nullptr && my_node->right == nullptr)
	{
		if (my_node->root->left == my_node) my_node->root->left = nullptr;
		else my_node->root->right = nullptr;
		delete my_node;
	}
	else 
	{
		if ((my_node->left != nullptr && my_node->right == nullptr))
		{
			if (my_node->root->left == my_node)
			{
				my_node->root->left = my_node->left;
				my_node->left->root = my_node->root;
				my_node->left = nullptr;
				my_node->root = nullptr;
				my_node->~node();
			}

			else if (my_node->root->right == my_node)
			{
				my_node->root->right = my_node->left;
				my_node->right->root = my_node->root;
				my_node->left = nullptr;
				my_node->root = nullptr;
				my_node->~node();
			}

		}
		if ((my_node->left == nullptr) && (my_node->right != nullptr))
		{
			if (my_node->root->left == my_node) 
			{
				my_node->root->left = my_node->right;
				my_node->left->root = my_node->root;
				my_node->right = nullptr;
				my_node->root = nullptr;
				my_node->~node();
			}

			else if (my_node->root->right == my_node) 
			{
				my_node->root->right = my_node->right;
				my_node->right->root = my_node->root;
				my_node->root = nullptr;
				my_node->right = nullptr;
				my_node->~node();
			}
		}

		if (my_node->left != nullptr && my_node->right != nullptr)
		{
			node* smol_bean = my_node->right;
			while (smol_bean->left != nullptr) smol_bean = smol_bean->left;
			my_node->value = smol_bean->value;
			smol_bean->root = nullptr;
			my_node->right = nullptr;
		}
	}
}

void tree::inorder(node* my_node)
{
	if (my_node != nullptr)
	{
		if (my_node->left != nullptr) inorder(my_node->left);
		std::cout << my_node->value << " ";
		if (my_node->right != nullptr) this->inorder(my_node->right);
	}
	else return;
}

void tree::inorder()
{
	this->inorder(root);
}

void tree::preorder(node* my_node)
{
	if (my_node != nullptr)
	{
		std::cout << my_node->value << " ";
		if (my_node->left != nullptr) preorder(my_node->left);
		if (my_node->right != nullptr) preorder(my_node->right);
	}
	else return;
}

void tree::preorder()
{
	this->inorder(root);
}

void tree::postorder(node* my_node)
{
	if (my_node != nullptr)
	{
		if (my_node->left) inorder(my_node->left);
		if (my_node->right) inorder(my_node->right);
		std::cout << my_node->value << " ";
	}
	else return;
}

void tree::postorder()
{
	this->postorder(root);
}

int tree::nr_nodes(node* my_node)
{
	int count = 1;
	if (my_node == nullptr)
		return 0;
	else
	{
		count += nr_nodes(my_node->left);
		count += nr_nodes(my_node->right);
	}
	return count;
}

int tree::nr_nodes()
{
	return this->nr_nodes(root);
}

int tree::nr_edges()
{
	return this->nr_nodes() - 1;
}

int tree::max_height(node* my_node)
{
	if (my_node == nullptr)
	{
		return -1;
	}
	node* new_node = my_node->left;
	int left = max_height(new_node);
	my_node = my_node->right;
	int right = max_height(my_node);
	return (std::max(left, right) + 1);
};

int tree::max_height()
{
	return this->max_height(root);
}