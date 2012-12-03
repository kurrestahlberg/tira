#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <string>
#include "tree.h"

class Huffman
{
public:
	Huffman(const char * data, int dataSize);
	Huffman(std::string filename);
	
	void writeToFile(std::string & filename);
	
	void unpack(std::string & filename);
	
private:
	const char * m_unpackedData;
	int m_dataSize;
	
	Tree m_tree;
	
};

#endif