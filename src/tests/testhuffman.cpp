#include "UnitTest++.h"
#include "../huffman.h"
#include "../tree.h"

class HuffmanTester {
protected:
	Tree * getTree(Huffman& huffman)
	{
		return &(huffman.m_tree);
	}
};

TEST_FIXTURE(HuffmanTester, ConstructorTest)
{
	char * data = new char[6];
	data[0] = 'a';
	data[1] = 'v';
	data[2] = 's';
	data[3] = 'd';
	data[4] = 'f';
	data[5] = 'f';
	Huffman huffman(data, 6);
	
	CHECK_EQUAL(6, huffman.getUnpackedDataSize());
	CHECK_EQUAL(data[0], huffman.getUnpackedData()[0]);
	CHECK_EQUAL(data[4], huffman.getUnpackedData()[4]);
	
	CHECK_EQUAL(5, getTree(huffman)->getLeafCount());
}
