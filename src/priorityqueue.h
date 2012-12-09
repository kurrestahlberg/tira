#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

class TreeNode;
class QueueItem;

/**
 * Prioriteettijono. Järjestää annetut TreeNode-oliot siten että pienin weight-arvolla
 * päätyy jonon kärkeen ja suurimmalla perälle.
 */
class PriorityQueue {

public:
	PriorityQueue();
	~PriorityQueue();

	/**
	 * Lisää TreeNode-olion jonoon
	 */
	void addItem(TreeNode * node);
	/**
	 * Poistaa jonon ensimmäisen olion jonosta ja palauttaa sen. Mikäli jono on tyhjä
	 * palauttaa NULL-arvon.
	 */
	TreeNode * takeFirst();
	/**
	 * Tarkistaa onko jonossa vielä olioita
	 */
	bool hasNext();
	/**
	 * Palauttaa jonon ensimmäisen olion weight-arvon
	 */
	int getFirstWeight();

private:
	QueueItem * root;

	int itemCount;
};

#endif //__PRIORITYQUEUE_H__