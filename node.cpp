#include <C:\Users\szint\source\repos\oop_hausaufgabe_lab3\node.h>
#include <iostream>

using namespace std;

node::node(int val)
{
	this->left = nullptr;
	this->right = nullptr;
	this->root = nullptr;
	this->value = val;
}

node::node(node* left, node* right, node* root, int value)
{
	this->left = left;
	this->right = right;
	this->root = root;
	this->value = value;
}

node::node(){};

node::~node(){};