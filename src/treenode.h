#ifndef __TREENODE_H__
#define __TREENODE_H__

class TreeNode {
public:
	TreeNode(char _value, int _weight);
	
	void print(unsigned long bits);
	
	unsigned char value;
	unsigned int weight;
	TreeNode * left;
	TreeNode * right;
};

#endif // __TREENODE_H__