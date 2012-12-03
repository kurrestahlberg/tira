#include "treenode.h"

#include <iostream>

using namespace std;

TreeNode::TreeNode(char _value, int _weight):
	value(_value), weight(_weight), left(0L), right(0L),
	bits(0), bitCount(0)
{
}

TreeNode::TreeNode():
	value(0), weight(0), left(0L), right(0L),
	bits(0), bitCount(0)
{
}

TreeNode::~TreeNode() 
{
	if(left) delete left;
	if(right) delete right;
}

void TreeNode::figureOutBits(unsigned int bits, int count)
{
	this->bits = bits;
	bitCount = count;

	if(left && right) 
	{
		left->figureOutBits(bits << 1, count + 1);
		right->figureOutBits((bits << 1) | 1, count + 1);
	}
}


int TreeNode::print()
{
	if(!left && !right) 
	{		
		for(int i = 31; i >= 0; i--)
		{
			cout << ((bits >> i) & 1);
		}
		
		int bitcount = (bitCount * weight);
		cout << " " << value << "(" << weight << ", " << bitCount << ")" << endl;
		
		return bitcount;
	}
	
	if(!left || !right)
	{
		cout << "TREE IS NOT CORRECT!" << endl;
		return 0;
	}
	
	int rv = left->print();
	rv += right->print();
	
	return rv;
}

TreeNode * TreeNode::getChild(unsigned int bits)
{
	if(!left && !right) return this;
	
	if(!left || !right)
	{
		cout << "TREE IS BROKEN!" << endl;
		return this;
	}
	
	if(bits & 0x80000000) return right->getChild(bits << 1);
	else return left->getChild(bits << 1);
}


