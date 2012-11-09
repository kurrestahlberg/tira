#include "treenode.h"

#include <iostream>

using namespace std;

TreeNode::TreeNode(char _value, int _weight):
	value(_value), weight(_weight), left(0L), right(0L)
{
}

void TreeNode::print(unsigned long bits)
{
	if(!left && !right) 
	{
		for(int i = 31; i >= 0; i--) 
		{
			cout << ((bits >> i) & 1);
		}
		
		cout << " " << value << "(" << weight << ")" << endl;
		return;
	}
	
	left->print(bits << 1);
	right->print((bits << 1) | 1);
}