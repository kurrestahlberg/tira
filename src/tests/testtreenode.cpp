#include "UnitTest++.h"
#include "../treenode.h"

TEST(TreeNodeTest)
{
	char testchar = 'a';
	int testweight = 10;
	TreeNode node(testchar, testweight);
	
	CHECK_EQUAL(node.value, testchar);
	CHECK_EQUAL(node.weight, testweight);
}
