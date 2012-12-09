#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <string>
#include "tree.h"

/**
 * Huffman-algoritmin pääluokka. Hallinnoi Huffman-puuta, lukee datan tiedostoista ja
 * kirjoittaa dataa tiedostoihin.
 */
class Huffman
{
public:
	/**
	 * Konstruktori joka muodostaa puun annetusta datasta.
	 */
	Huffman(char * data, int dataSize);
	/**
	 * Konstruktori joka lukee pakatun datan ja puun tiedostosta
	 */
	Huffman(std::string filename);
	
	/**
	 * Pakkaa olioon tallennetun datan tiedostoon
	 */
	void writeToFile(std::string & filename);
	
	/**
	 * Lukee ja purkaa pakatun datan tiedostosta
	 */
	void unpack(std::string & filename);
	
	/**
	 * Palauttaa puretun datan
	 */
	const char * getUnpackedData();
	/**
	 * Palauttaa puretun datan koon
	 */
	int getUnpackedDataSize();
	
private:
	char * m_unpackedData;
	int m_dataSize;
	
	Tree m_tree;
	
	friend class TestHuffman;
};

#endif