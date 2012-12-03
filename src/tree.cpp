#include "tree.h"
#include "priorityqueue.h"
#include "treenode.h"

#include <iostream>
#include <iomanip>

using namespace std;

Tree::Tree() 
{
}

Tree::~Tree() 
{
	if(m_root) {
		delete m_root;
	}
}

void Tree::generateTree(const char * data, int size) 
{
	if(m_root) delete m_root;
	for(int i = 0; i < 256; i++)
	{
		m_leafNodes[i] = 0L;
	}

	countCharacters(data, size, m_characterCounts);
	m_leafCount = 0;
	
	PriorityQueue q;
	for(int i = 0; i < 256; i++) 
	{
		if(m_characterCounts[i] > 0) 
		{
			TreeNode * node = new TreeNode((char)i, m_characterCounts[i]);
			q.addItem(node);
			m_leafNodes[i] = node;
			m_leafCount++;
		}
	}
	
	while(q.hasNext())
	{
		TreeNode * node1 = q.takeFirst();
		TreeNode * node2 = q.takeFirst();
		
		if(!node2) 
		{
			m_root = node1;
			m_root->figureOutBits(1, 0);
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

void Tree::countCharacters(const char * data, int size, int * characterCounts) 
{
	for(int k = 0; k < 256; k++) 
	{
		characterCounts[k] = 0;
	}

	for(int i = 0; i < size; i++) 
	{
		unsigned char d = (unsigned char)data[i];
		characterCounts[d]++;
	}
}

int Tree::dump() 
{
	if(m_root) return m_root->print(1);
	return -1;
}

int Tree::getLeafCount()
{
	return m_leafCount;
}

int Tree::writeTree(char * data)
{
	int counter = 0;
	
	for(int i = 0; i < 256; i++)
	{
		if(m_leafNodes[i] != 0L)
		{
			data[counter++] = (char)i;
			data[counter++] = (char)(m_leafNodes[i]->bits >> 24);
			data[counter++] = (char)(m_leafNodes[i]->bits >> 16);
			data[counter++] = (char)(m_leafNodes[i]->bits >> 8);
			data[counter++] = (char)(m_leafNodes[i]->bits);
		}
	}		
	return counter;
}
	
int Tree::pack(const char * input, int inputSize, char * output)
{
	int counter = 0;
	int bitcounter = 32;
	unsigned int * ptr = (unsigned int*) output;
	
	for(int i = 0; i < inputSize; i++)
	{
		TreeNode * inputNode = m_leafNodes[input[i]];
		bitcounter -= inputNode->bitCount;

		if(bitcounter < 0)
		{
			ptr[counter] |= inputNode->bits >> (-bitcounter);
			bitcounter += 32;
			counter++;
		}

		ptr[counter] |= inputNode->bits << bitcounter;
	}
	
	return counter * 4;
}

void Tree::writeTree(ostream & stream)
{
	for(int i = 0; i < 256; i++)
	{
		if(m_leafNodes[i] != 0L)
		{
			stream << (char)i;
			stream << (char)(m_leafNodes[i]->bits >> 24);
			stream << (char)(m_leafNodes[i]->bits >> 16);
			stream << (char)(m_leafNodes[i]->bits >> 8);
			stream << (char)(m_leafNodes[i]->bits);
		}
	}
}
	
void Tree::pack(const char * input, int inputSize, ostream & stream)
{
	int bitcounter = 32;
	unsigned int data = 0;
	int counter = 0;
	
	for(int i = 0; i < inputSize; i++)
	{
		TreeNode * inputNode = m_leafNodes[(unsigned char)(input[i])];
		bitcounter -= inputNode->bitCount;

		if(bitcounter <= 0)
		{
			data |= (inputNode->bits >> (-bitcounter));
			stream.write((const char *)&data, 4);
			data = 0;
			bitcounter += 32;
			counter ++;
		}

		data |= (inputNode->bits << bitcounter);
	}
	
	if(bitcounter != 32) 
	{
		stream << data;
		counter++;
	}
	
	cout << "Wrote " << (counter * 4) << " bytes" << endl;
}


int Tree::getPackedSize()
{
	int total = 0;
	for(int i = 0; i < 256; i++) 
	{
		if(m_characterCounts[i] > 0) total += m_leafNodes[i]->bitCount * m_characterCounts[i];
	}
	
	if(total % 32) return (((total / 32) + 1) * 4);
	
	return (total / 8);
}

int Tree::readTree(const unsigned char * data, int entryCount)
{
	int counter = 0;
	unsigned int bits = 0;
	
	if(m_root) delete m_root;
	m_root = new TreeNode(0, 0);
	
	for(int i = 0; i < entryCount; i++)
	{
		unsigned char c = data[i * 5];
		bits = data[i * 5 + 1] << 24;
		bits |= data[i * 5 + 2] << 16;
		bits |= data[i * 5 + 3] << 8;
		bits |= data[i * 5 + 4];
		
		int firstOneAt = -1;
		for(int j = 31; j >= 0; j--) 
		{
			if((bits >> j) & 1) 
			{
				firstOneAt = j;
				break;
			}
		}
		
		TreeNode * cur = m_root;
		for(int j = (firstOneAt - 1); j >= 0; j--) 
		{
			if((bits >> j) & 1)
			{
				if(!cur->right) cur->right = new TreeNode(0, 0); 
				
				cur = cur->right;
			}
			else
			{
				if(!cur->left) cur->left = new TreeNode(0, 0); 
				
				cur = cur->left;
			}
		}
		
		if(cur->bits != 0)
		{
			cout << "UH OH! " << cur->value << "-" << c << ", bits " << hex << cur->bits << "-" << bits << dec << endl;
		}
		cur->value = c;
		cur->bits = bits;
		cur->bitCount = firstOneAt - 1;
				
	}		
	return entryCount * 5;
}
	
int Tree::unpack(const char * input, char * output, int outputSize)
{
	int counter = 0;
	int bitcounter = 32;
	unsigned int * ptr = (unsigned int*) input;
	
	for(int i = 0; i < outputSize; i++)
	{
		TreeNode * inputNode = m_leafNodes[input[i]];
		bitcounter -= inputNode->bitCount;

		if(bitcounter < 0)
		{
			ptr[counter] |= inputNode->bits >> (-bitcounter);
			bitcounter += 32;
			counter++;
		}

		ptr[counter] |= inputNode->bits << bitcounter;
	}
	
	return counter * 4;
}
