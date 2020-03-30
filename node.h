#pragma once
class node {
public:
	/*
	Parameter:
	left, right, root: node*
	value: int
	*/
	node* left;
	node* right;
	node* root;
	int value;

	/*
	Konstruktor
	*/
	node(int value);

	/*
	Konstruktor
	*/
	node();

	/*
	Konstruktor
	*/
	node(node* left, node* right, node* root, int value);

	/*
	Destruktor
	*/
	~node();
};