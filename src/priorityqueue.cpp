#include "priorityqueue.h"
#include "treenode.h"

#include <iostream>

using namespace std;

class QueueItem {
public:
	QueueItem():item(0L),next(0L),prev(0L) {}
	TreeNode * item;
	QueueItem * next;
	QueueItem * prev;
};

PriorityQueue::PriorityQueue() :
	root(0L),itemCount(0)
{
}

PriorityQueue::~PriorityQueue() 
{
	while(root) 
	{
		QueueItem * temp = root;
		root = root->next;
		delete temp;
	}
}

void PriorityQueue::addItem(TreeNode * node) 
{
	itemCount++;
	
	//cout << "Add Item, item count after: " << itemCount << endl;

	if(!root) {
		root = new QueueItem();
		root->item = node;
		return;
	}
		
	QueueItem * item = root;
	while(item)
	{
		if(item->item->weight > node->weight) {
			QueueItem * newItem = new QueueItem();
			newItem->item = node;
			newItem->prev = item->prev;
			newItem->next = item;
			item->prev = newItem;
			if(newItem->prev) newItem->prev->next = newItem;
			else root = newItem;
			return;
		}
		
		if(!item->next) {
			QueueItem * newItem = new QueueItem();
			newItem->item = node;
			newItem->prev = item;
			item->next = newItem;
			return;
		}
		
		item = item->next;
	}
}

TreeNode * PriorityQueue::takeFirst() 
{
	//cout << "Take item, item count before: " << itemCount << endl;
	
	if(!root) return 0L;
	
	itemCount--;
	
	QueueItem * first = root;
	if(first->next) 
	{
		root = first->next;
		root->prev = 0L;
	}
	else
	{
		root = 0L;
	}
	
	TreeNode * node = first->item;
	delete first;
	return node;
}

bool PriorityQueue::hasNext() 
{
	 return (root != 0L);
}

int PriorityQueue::getFirstWeight() 
{
	if(!root) return -1;
	return root->item->weight;
}
