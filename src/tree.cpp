#include "tree.h"
#include "priorityqueue.h"
#include "treenode.h"

#include <iostream>

using namespace std;

Tree::Tree() 
{

}

Tree::~Tree() 
{

}

void Tree::generateTree(const char * data, int size) 
{
	int * characterCounts = countCharacters(data, size);
	
	PriorityQueue q;
	for(int i = 0; i < 256; i++) 
	{
		if(characterCounts[i] > 0) 
		{
			q.addItem(new TreeNode((char)i, characterCounts[i]));
		}
	}
	
	
	while(q.hasNext())
	{
		TreeNode * node1 = q.takeFirst();
		TreeNode * node2 = q.takeFirst();
		
		if(!node2) 
		{
			root = node1;
			return;
		}
		
		q.addItem(combineBranches(node1, node2));
	}
}

TreeNode * Tree::combineBranches(TreeNode * node1, TreeNode * node2)
{
	TreeNode * newNode = new TreeNode(0, node1->weight + node2->weight);
	newNode->left = node1;
	newNode->right = node2;
	return newNode;
}

int * Tree::countCharacters(const char * data, int size) 
{
	int * characterCounts = new int[256];
	
	for(int k = 0; k < 256; k++) 
	{
		characterCounts[k] = 0;
	}

	for(int i = 0; i < size; i++) 
	{
		unsigned char d = (unsigned char)data[i];
		characterCounts[d]++;
	}
	
	/*
	int charcount = 0;
	for(int j = 0; j < 256; j++) 
	{
		if(characterCounts[j] > 0) 
		{
			cout << j << ": " << characterCounts[j] << endl;
			charcount++;
		}
	}
	
	cout << "Total different chars " << charcount << endl;
	*/
	return characterCounts;
}

void Tree::dump() 
{
	if(root) root->print(1);
}