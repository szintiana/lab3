#include "tree.h"
#include <iostream>
#include <vector>

using namespace std;

int nicht_main()
{
	tree binaer_baum = tree();
	bool semafor = true;
	while (semafor)
	{
		cout << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " 1. insert " << endl;
		cout << " 2. inorder" << endl;
		cout << " 3. preorder" << endl;
		cout << " 4. postorder" << endl;
		cout << " 5. delete" << endl;
		cout << " 6. nr_nodes" << endl;
		cout << " 7. nr_edges" << endl;
		cout << " 8. height" << endl;
		cout << " 9. exit" << endl;
		cout << " Pick your poison: ";

		int nr;
		cin >> nr;
		if (nr == floor(nr))
		{
			if (nr == 1)
			{
				int n;
				cout << "nr of nodes: ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					int node_val;
					cout << "node " << i + 1 << ": ";
					cin >> node_val;
					binaer_baum.insert(node_val);
				}
			}
			if (nr == 2)
			{
				binaer_baum.inorder();
			}

			if (nr == 3)
			{
				binaer_baum.preorder();
			}

			if (nr == 4)
			{
				binaer_baum.postorder();
			}

			if (nr == 5)
			{
				int node_value;
				cout << "node: ";
				cin >> node_value;
				binaer_baum.remove(node_value);
			}

			if (nr == 6)
			{
				cout << binaer_baum.nr_nodes();
			}

			if (nr == 7)
			{
				cout << binaer_baum.nr_edges();
			}

			if (nr == 8)
			{
				cout << binaer_baum.max_height();
			}

			if (nr == 9)
			{
				semafor = false;
			}
		}
	}
	return 0;
}