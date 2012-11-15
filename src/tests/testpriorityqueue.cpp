#include "UnitTest++.h"
#include "../priorityqueue.h"
#include "../treenode.h"

SUITE(PriorityQueueTests) {
	TEST(EmptyPriorityQueueTest)
	{
		PriorityQueue queue;
		
		CHECK(!queue.hasNext());
		CHECK_EQUAL(queue.getFirstWeight(), -1);
		CHECK_EQUAL(queue.takeFirst(), (TreeNode*)0L);
	}

	TEST(SingleItemPriorityQueueTest)
	{
		PriorityQueue queue;
		int testweight = 10;
		
		TreeNode node('a', testweight);
		queue.addItem(&node);
		
		CHECK(queue.hasNext());
		CHECK_EQUAL(queue.getFirstWeight(), testweight);
		CHECK_EQUAL(queue.takeFirst(), &node);
	}

	TEST(MultiItemPriorityQueueTest)
	{
		PriorityQueue queue;
		int testweights[10] = {10, 12, 3, 6, 2, 22, 41, 50, 91515135423, 10};
		int sortedorder[10] = {4, 2, 3, 0, 9, 1, 5, 6, 7, 8};
		TreeNode ** nodes = new TreeNode*[10];
		for(int i = 0; i < 10; i++) {
			nodes[i] = new TreeNode('s', testweights[i]);
			queue.addItem(nodes[i]);
		}
		
		for(int i = 0; i < 10; i++) {
			CHECK(queue.hasNext());
			CHECK_EQUAL(queue.getFirstWeight(), testweights[sortedorder[i]]);
			CHECK_EQUAL(queue.takeFirst(), nodes[sortedorder[i]]);
		}
	}

}

