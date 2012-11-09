#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

class TreeNode;
class QueueItem;

class PriorityQueue {

public:
	PriorityQueue();
	~PriorityQueue();

	void addItem(TreeNode * node);
	TreeNode * takeFirst();
	bool hasNext();
	int getFirstWeight();

private:
	QueueItem * root;

	int itemCount;
};

#endif //__PRIORITYQUEUE_H__