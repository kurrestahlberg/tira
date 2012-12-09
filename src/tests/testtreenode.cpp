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

TEST(TreeNodeFigureOutBitsTest)
{
	unsigned int bits = 0x0B;
	unsigned int count = 6;
	
	TreeNode node1;	
	TreeNode node2('b', 3);	
	TreeNode node3('a', 2);
	
	node1.left = &node2;
	node1.right = &node3;
	
	node1.figureOutBits(bits, count);
	
	CHECK_EQUAL(node2.bits, bits << 1);
	CHECK_EQUAL(node2.bitCount, count + 1);
	CHECK_EQUAL(node3.bits, (bits << 1) | 1);
	CHECK_EQUAL(node3.bitCount, count + 1);
	
	node1.left = 0L;
	node1.right = 0L;
}

TEST(TreeNodeGetChildTest)
{
	TreeNode node1;	
	TreeNode node2('b', 3);	
	TreeNode node3('a', 2);
	
	node1.left = &node2;
	node1.right = &node3;	
	
	TreeNode * rv = node1.getChild(0x80000000);
	CHECK_EQUAL(&node3, rv);
	
	rv = node1.getChild(0x70000000);
	CHECK_EQUAL(&node2, rv);
	
	node1.left = 0L;
	node1.right = 0L;	
}
