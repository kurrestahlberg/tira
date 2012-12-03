#ifndef __TREENODE_H__
#define __TREENODE_H__

class TreeNode {
public:
	TreeNode(char _value, int _weight);
	TreeNode();
	~TreeNode();
	
	int print();
	void figureOutBits(unsigned int bits, int count);
	
	TreeNode * getChild(unsigned int bits);
	
	unsigned char value;
	unsigned int weight;
	TreeNode * left;
	TreeNode * right;
	
	unsigned int bits;
	int bitCount;
};

#endif // __TREENODE_H__