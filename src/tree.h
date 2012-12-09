#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>

using namespace std;

class TreeNode;

/**
 * Huffman-puu.
 * Puu rakentaa itsensä annetun datan mukaan laskien ensin jokaisen yksittäisen tavun 
 * esiintymistiheyden ja näin saaduilla painokertoimilla järjestelee tasapainoisen
 * binääripuun.
 */
class Tree {

public:
	Tree();
	~Tree();
	/**
	 * Luo puun.
	 */
	void generateTree(const char * data, int size);
	
	/**
	 * Palauttaa lehtisolmujen määrän.
	 */
	int getLeafCount();
	/**
	 * Palauttaa annetun datan pakatun muodon koon tavuina.
	 */
	int getPackedSize();
	
	/**
	 * Kirjoittaa puun dataesityksen parametrina annettuun bufferiin
	 */
	int writeTree(char * data);
	/**
	 * Pakkaa annetun datan ja kirjoittaa sen annettuun bufferiin
	 */
	int pack(const char * input, int inputSize, char * output);
	
	/**
	 * Kirjoittaa puun dataesityksen annettuun streamiin
	 */
	int writeTree(ostream & stream);
	/**
	 * Pakkaa annetun datan ja kirjoittaa sen annettuun streamiin
	 */
	int pack(const char * input, int inputSize, ostream & stream);
	
	/**
	 * Lukee ja muodostaa puun annetusta datasta
	 */
	int readTree(const unsigned char * data, int entryCount);
	/**
	 * Purkaa annetun datan ja kirjoittaa sen annettuun bufferiin
	 */
	int unpack(const char * data, char * outputData, int outputDataSize);
	
	/**
	 * Tulostaa puun rakenteen
	 */
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