#include "UnitTest++.h"
#include "../treenode.h"
#include "../tree.h"

class TreeTester {
protected:
	TreeNode * cb(TreeNode * n1, TreeNode * n2)
	{
		Tree tree;
		return tree.combineBranches(n1, n2);
	}
	
	int * cc(const char * data, int size)
	{
		Tree tree;
		int * characterCounts = new int[256]; 
		tree.countCharacters(data, size, characterCounts);
		return characterCounts;
	}
};

TEST_FIXTURE(TreeTester, BranchCombineTest)
{
	TreeNode *node1 = new TreeNode('a', 10);
	TreeNode *node2 = new TreeNode('b', 11);
	
	TreeNode * newNode = cb(node1, node2);
	
	CHECK(newNode != node1);
	CHECK(newNode != node2);
	CHECK_EQUAL(node1, newNode->left);
	CHECK_EQUAL(node2, newNode->right);
	
	delete newNode;
}

TEST_FIXTURE(TreeTester, CharacterCountTest)
{
	const char * chars = "abceff";
	int * counts = cc(chars, 6);
	for(int i = 0; i < 4; i++)
	{
		CHECK_EQUAL(1, counts[chars[i]]);
	}
	
	CHECK_EQUAL(2, counts[chars[4]]);
	
	CHECK_EQUAL(0, counts['d']);
	CHECK_EQUAL(0, counts['x']);
	
	delete [] counts;
}

TEST(TreeGetLeafCountTest)
{
	const char * chars = "abceff";
	Tree tree;
	tree.generateTree(chars, 6);
	
	int rv = tree.getLeafCount();
	CHECK_EQUAL(5, rv);
	
}

TEST(TreeGetPackedSizeTest)
{
	const char * chars = "abceff";
	Tree tree;
	tree.generateTree(chars, 6);
	
	int rv = tree.getPackedSize();
	CHECK_EQUAL(4, rv);
}