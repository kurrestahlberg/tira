#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>

using namespace std;

class TreeNode;

class Tree {

public:
	Tree();
	~Tree();
	void generateTree(const char * data, int size);
	
	int getLeafCount();
	int getPackedSize();
	
	int writeTree(char * data);
	int pack(const char * input, int inputSize, char * output);
	
	int writeTree(ostream & stream);
	int pack(const char * input, int inputSize, ostream & stream);
	
	int readTree(const unsigned char * data, int entryCount);
	int unpack(const char * data, char * outputData, int outputDataSize);
	
	int dump();
	
private:
	TreeNode * m_root;
	TreeNode * m_leafNodes[256];
	int m_characterCounts[256];
	int m_leafCount;
	
	void countCharacters(const char * data, int size, int * counts);
	
	TreeNode * combineBranches(TreeNode * node1, TreeNode * node2);
	
	friend class TreeTester;
};

#endif // __TREE_H__