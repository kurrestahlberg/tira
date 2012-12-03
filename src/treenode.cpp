#include "treenode.h"

#include <iostream>

using namespace std;

TreeNode::TreeNode(char _value, int _weight):
	value(_value), weight(_weight), left(0L), right(0L),
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
		left->figureOutBits(bits, count + 1);
		right->figureOutBits(bits | (1 << count), count + 1);
	}
}


int TreeNode::print()
{
	if(!left && !right) 
	{		
		
		int bitcount = (bitCount * weight);
		cout << " " << value << "(" << weight << ", " << bitCount << ")" << endl;
		
		return bitcount;
	}
	
	if(!left || !right)
	{
		cout << "TREE IS NOT CORRECT!" << endl;
		return -1;
	}
	
	int rv = left->print();
	rv += right->print();
	
	return rv;
}

TreeNode * TreeNode::getChild(unsigned int bits)
{
	if(value > 0) return this;
	
	if(bits & 1) return right->getChild(bits >> 1);
	else return left->getChild(bits >> 1);
}


