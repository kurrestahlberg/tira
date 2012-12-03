#include "huffman.h"

#include <fstream>

#define HEADER_VERSION 2

class HuffmanFileHeader 
{
public:
	char magic1;
	char magic2;
	char magic3;
	char magic4;
	unsigned int headerVersion;
	unsigned int treeEntryCount;
	unsigned int unpackedSize;
};

Huffman::Huffman(const char * data, int dataSize) :
	m_unpackedData(data), m_dataSize(dataSize)
{
	m_tree.generateTree(data, dataSize);
}
Huffman::Huffman(std::string filename)
{
	unpack(filename);	
}

void Huffman::unpack(std::string& filename)
{
	ifstream file;
	file.open(filename.c_str(), ios::in | ios::binary | ios::ate);
	if(!file.is_open()) 
	{
		cout << "Can't open " << filename << endl;
		return;
	}
	
	int size = 0;
	size = (int)file.tellg();
	char * data = new char[size];

	file.seekg(0, ios::beg);
	file.read(data, size);
	file.close();
	
	HuffmanFileHeader * hdr = (HuffmanFileHeader*)data;
	if(hdr->headerVersion != HEADER_VERSION) 
	{
		cout << "INVALID HEADER VERSION" << endl;
		return;
	}
	
	cout << "Tree entries: " << hdr->treeEntryCount << ", unpackedSize: " << hdr->unpackedSize << endl;
	
	m_tree.readTree((unsigned char *)(data + sizeof(*hdr)), hdr->treeEntryCount);
	
	m_tree.dump();
	
}
	
void Huffman::writeToFile(std::string& filename)
{
	ofstream file;
	file.open(filename.c_str(), ios::out | ios::binary | ios::ate);
	HuffmanFileHeader header;
	header.magic1 = 'H';
	header.magic2 = 'U';
	header.magic3 = 'F';
	header.magic4 = 'F';
	header.headerVersion = HEADER_VERSION;
	header.treeEntryCount = m_tree.getLeafCount();
	header.unpackedSize = m_dataSize;
	
	m_tree.dump();
	
	cout << "Tree entries: " << header.treeEntryCount << ", unpackedSize: " << m_dataSize << endl;
	
	file.write((const char *)&header, sizeof(header));
	m_tree.writeTree(file);
	m_tree.pack(m_unpackedData, m_dataSize, file);
	
	file.close();
}
