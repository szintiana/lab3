#pragma once
#include "C:\Users\szint\source\repos\oop_hausaufgabe_lab3\node.h"
#include <vector>

class tree
{
public:
	/*
	Paramter:
	left, right, root: node*
	*/
	node* left;
	node* right;
	node* root;

	/*
	Konstruktor
	*/
	tree(node* left, node* righgt, node* root);

	/*
	Konstruktor
	*/
	tree();
	/*
	Destruktor
	*/
	~tree();

	/*
	insert Prozedur
	Parameter: value- int
	Fuegt einen node zur Baum hin.
	*/
	void insert(int value);

	/*
	search Funktion
	Parameter: value- int
	Sucht einen node im Baum nach seiner Wert.
	Gibt einen node Pointer zurueck.
	*/
	node* search(int my_value);

	/*
	Funktion: remove
	Paramter: value - int
	Hier haben wir 3 Faelle:
	1. Wir loeschen einen Blatt.
	2. Wir loeschen einen Knoten mit einen einzigen Nachfoger
	3. Wir loeschen einen Knoten mit zwei Nachfolgern
	*/
	void remove(int value);

	/*
	Hilfsfunktion
	*/
	void inorder(node* my_node);

	/*
	inorder Prozedur
	Zeigt die Elemente des Baumes im inorder Folge.
	*/
	void inorder();

	/*
	Hilfsfunktion
	*/
	void preorder(node* my_node);

	/*
	preorder Prozedur
	Zeigt die Elemente des Baumes im preorder Folge.
	*/
	void preorder();

	/*
	Hilfsfunktion
	*/
	void postorder(node* my_node);

	/*
	postorder Prozedur
	Zeigt die Elemente des Baumes im postorder Folge.
	*/
	void postorder();

	/*
	Hilfsfunktion
	*/
	int nr_nodes(node* my_node);

	/*
	nr_nodes Funktion
	Zeigt wie viele Knoten ein Baum hat.
	Gibt einen int zurueck.
	*/
	int nr_nodes();

	/*
	nr_edges Funktion
	Zeigt wie viele Kanten ein Baum hat.
	Gibt einen int zurueck.
	*/
	int nr_edges();

	/*
	Hilfsfunktion
	*/
	int max_height(node* my_node);

	/*
	max_height Funktion
	Zeigt die maximae Hoehe eines Baumes
	Gibt einen int zurueck.
	*/
	int max_height();
};