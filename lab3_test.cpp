#include "tree.h"
#include "assert.h"

void nr_nodes_test()
{
	tree baum = tree();
	for (int i = 0; i < 3; i++)
	{
		baum.insert(1 + i);
	}
	assert(3 == baum.nr_nodes());
}

void nr_edges_test()
{
	tree baum = tree();
	for (int i = 0; i < 3; i++)
	{
		baum.insert(1 + i);
	}
	assert(2 == baum.nr_edges());
}

void max_height_test()
{
	tree baum = tree();
	for (int i = 0; i < 3; i++)
	{
		baum.insert(1 + i);
	}
	assert(1 == baum.max_height());
}

int main()
{
	nr_nodes_test();
	nr_edges_test();
	max_height_test();
	return 1;
}