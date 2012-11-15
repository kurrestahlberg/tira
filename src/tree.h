#ifndef __TREE_H__
#define __TREE_H__

class TreeNode;

class Tree {

public:
	Tree();
	~Tree();
	void generateTree(const char * data, int size);
	
	void dump();
	
private:
	TreeNode * root;
	
	int * countCharacters(const char * data, int size);
	
	TreeNode * combineBranches(TreeNode * node1, TreeNode * node2);
	
	friend class TreeTester;
};

#endif // __TREE_H__