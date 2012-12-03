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

Huffman::Huffman(char * data, int dataSize) :
	m_unpackedData(data), m_dataSize(dataSize)
{
	m_tree.generateTree(data, dataSize);
}
Huffman::Huffman(std::string filename):
	m_unpackedData(0L), m_dataSize(0)
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
	char * data = new char[size + 4];

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
	
	int treeSize = m_tree.readTree((unsigned char *)(data + sizeof(*hdr)), hdr->treeEntryCount);
	
	//m_tree.dump();
	
	m_dataSize = hdr->unpackedSize;
	m_unpackedData = new char[m_dataSize];
	
	m_tree.unpack((const char *)(data + sizeof(*hdr) + treeSize), m_unpackedData, m_dataSize); 
	
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
	
	//m_tree.dump();
	
	cout << "Tree entries: " << header.treeEntryCount << ", unpackedSize: " << m_dataSize << endl;
	
	file.write((const char *)&header, sizeof(header));
	int treesize = m_tree.writeTree(file);
	
	int packedSize = m_tree.pack(m_unpackedData, m_dataSize, file);
	
	float pp = ((float)(packedSize + treesize + sizeof(header)) / (float)m_dataSize) * 100.0f;
	
	cout << "Tree size: " << treesize << ", packed data size: " << packedSize << 
		", pack percent: " << pp << endl;
	
	file.close();
}

const char * Huffman::getUnpackedData()
{
	return m_unpackedData;
}
int Huffman::getUnpackedDataSize()
{
	return m_dataSize;
}

