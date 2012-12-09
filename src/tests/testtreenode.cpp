#include "UnitTest++.h"
#include "../treenode.h"

TEST(TreeNodeConstructorTestWithValues)
{
	unsigned char testchar = 'a';
	unsigned int testweight = 10;
	TreeNode node(testchar, testweight);
	
	CHECK_EQUAL(node.value, testchar);
	CHECK_EQUAL(node.weight, testweight);
}

TEST(TreeNodeConstructorTestWithoutValues)
{
	TreeNode node;
	
	CHECK_EQUAL(node.value, 0);
	CHECK_EQUAL(node.weight, 0);
}


